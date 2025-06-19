project(
    'demo_pdf_searcher_sqlite_fts5',
    'cpp',
    version : '1.0.0',
    meson_version : '>= 1.8',
    default_options : ['warning_level=3', 'cpp_std=gnu++23'],
)

cc = meson.get_compiler('cpp')

add_project_arguments('-DNDEBUG', language: 'cpp')

deps = []
deps+=cc.find_library(
    'mupdf',
    has_headers : ['mupdf/fitz/version.h', 'mupdf/fitz.h', 'mupdf/pdf.h'],
)
deps+=cc.find_library(
    'mupdfcpp',
    has_headers : ['mupdf/classes.h'],
)
deps += dependency('icu-i18n')
deps += dependency('icu-io')
deps += dependency('icu-uc')
deps += dependency('sqlite3')

message('the depencies are: ')
foreach dep : deps
    message(' - ', dep.name())
endforeach

demo_1 = executable(
    'test_sqlite_fts5',
    'test_sqlite_fts5.cpp',
    dependencies : deps,
    install : true,
)

demo_2 = executable(
    'test_icu_seg_cjk',
    'test_icu_seg_cjk.cpp',
    dependencies : deps,
    install : true,
)

demo_3 = executable(
    'test_pdf_printer',
    'test_pdf_printer.cpp',
    dependencies : deps,
    install : true,
)



