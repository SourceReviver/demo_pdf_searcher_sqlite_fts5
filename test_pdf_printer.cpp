#include <memory>
#include <mupdf/classes.h>

#include <print>

using namespace mupdf;


int main()
{
    auto doc = std::make_unique<FzDocument>("../test_file.pdf");

    auto* stextOptions = new FzStextOptions();

    for (int i = 0; i < doc->fz_count_pages(); ++i) {

        std::println("\n\nPage -> {}", i);

        const FzPage& p = doc->fz_load_page(i);
        auto* page = new FzStextPage(p, *stextOptions);

        for (FzStextBlock block : *page) {
            for (FzStextLine line : block) {
                std::string s;
                for (FzStextChar c : line) {
                    s.append(reinterpret_cast<char*>(&c.m_internal->c));
                }
                std::println("{}", s);
            }
        }

    }

    return 0;
}
