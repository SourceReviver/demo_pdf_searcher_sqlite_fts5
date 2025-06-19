#include <iostream>
#include <print>
#include <unicode/brkiter.h>
int main()
{
    UErrorCode err = U_ZERO_ERROR;

    auto* wordBreaker = icu::BreakIterator::createWordInstance(icu::Locale::getSimplifiedChinese(), err);
    icu::UnicodeString ms = R"(我能吞下玻璃而不伤身体（英語：I Can Eat Glass）是由 Ethan Mollick 在早期互联网上发起的语言学项目。该项目的目的是收集不同语言中「I can eat glass, it does not hurt me」这句话的翻译。该项目的原始网页于2004年消失。)";
    wordBreaker->setText(ms);

    for ( int i = 0; wordBreaker->next() != icu::BreakIterator::DONE;) {
        std::string a;
        std::println("{} -> {}", ms.tempSubStringBetween(i, wordBreaker->current()).toUTF8String(a), wordBreaker->current());
        i = wordBreaker->current();
    }

    return 0;
}