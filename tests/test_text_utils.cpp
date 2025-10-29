#include "text_utils.hpp"
#include <cassert>
#include <iostream>

using namespace textlib::util;

int main() {
    std::vector<std::string> words = {"apple", "banana", "kiwi", "grapefruit"};

    assert(to_upper("Hi!") == "HI!");

    auto longest = find_longest(words);
    assert(longest.has_value() && *longest == "grapefruit");

    assert(join({"a","b","c"}, ',') == "a,b,c");

    std::string s = summary(words);
    assert(s.find("Count=4") != std::string::npos);
    assert(s.find("Longest=grapefruit") != std::string::npos);

    std::cout << "All tests passed successfully!\n";
}
