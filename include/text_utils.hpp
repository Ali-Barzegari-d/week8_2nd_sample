#pragma once
#include <string>
#include <vector>
#include <optional>

namespace textlib::util {

    #ifdef ENABLE_LOG
    #include <iostream>
    #endif

    // Converts all characters in the string to uppercase
    std::string to_upper(const std::string& input);

    // Returns the longest string in a vector, or std::nullopt if empty
    std::optional<std::string> find_longest(const std::vector<std::string>& words);

    // Concatenates all words separated by the given character
    std::string join(const std::vector<std::string>& words, char sep);

    // Logs a short summary (only if ENABLE_LOG is defined)
    void log_summary(const std::vector<std::string>& words);

    // Returns "Count=X, Longest=Y"
    // Must call log_summary internally
    std::string summary(const std::vector<std::string>& words);

} // namespace textlib::util
