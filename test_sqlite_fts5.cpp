#include <exception>
#include <iostream>
#include <print>
#include <sqlite3.h>

#define DIE                               \
    if (rc != SQLITE_OK) {                \
        throw std::runtime_error("Ops!"); \
    }

auto str_c_tbl = R"(
DROP TABLE IF EXISTS yo;
CREATE VIRTUAL TABLE yo USING fts5(mstr);)";

auto str_ins_d = R"(
INSERT INTO yo(mstr)
VALUES
    ('a lambda'),
    ('b lambda'),
    ('c lambda'),
    ('d'),
    ('e'),
    ('f'),
    ('g lambda');
)";

auto str_query = R"(
    SELECT * from yo WHERE mstr MATCH 'lambda';
)";

static int cb(void* _, int argc, char** argv, char** colName)
{

    for (int i = 0; i < argc; ++i) {
        std::println("{} -> {}", colName[i], argv[i] ? argv[i] : "NULL");
    }
    return SQLITE_OK;
};

int main()
{

    sqlite3* db = nullptr;
    int rc = SQLITE_OK;

    char* errmsg = nullptr;

    rc = sqlite3_open("../test.sqlite", &db);
    DIE;

    rc = sqlite3_exec(db, str_c_tbl, nullptr, nullptr, &errmsg);
    if (rc != SQLITE_OK) {
        std::printf("%s", errmsg);
        DIE;
    }

    rc = sqlite3_exec(db, str_ins_d, nullptr, nullptr, &errmsg);
    DIE;

    rc = sqlite3_exec(db, str_query, cb, nullptr, &errmsg);
    DIE;

    sqlite3_close(db);

    return 0;
}
