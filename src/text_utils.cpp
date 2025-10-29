#include "text_utils.hpp"
#include <sstream>
#include <algorithm>
#include <cctype>

namespace textlib::util {

// -----------------------------------
// TODO: Implement to_upper()
// Converts all letters in input to uppercase
std::string to_upper(const std::string& input) {
    std::string result = input; // make a copy
    std::transform(result.begin(), result.end(), result.begin(),
                   [](unsigned char c){ return std::toupper(c); });
    return result;
}

// -----------------------------------
// TODO: Implement find_longest()
// Return the longest string or std::nullopt if empty
std::optional<std::string> find_longest(const std::vector<std::string>& words) {
    if (words.empty()) return std::nullopt;
    return *std::max_element(words.begin(), words.end(),
                             [](const std::string& a, const std::string& b){
                                 return a.size() < b.size();
                             });
}

// -----------------------------------
// TODO: Implement join()
// Concatenate words separated by 'sep'
std::string join(const std::vector<std::string>& words, char sep) {
    if (words.empty()) return "";
    std::ostringstream oss;
    for (size_t i = 0; i < words.size(); ++i) {
        oss << words[i];
        if (i != words.size() - 1)
            oss << sep;
    }
    return oss.str();
}

// -----------------------------------
// TODO: Implement log_summary()
// Only logs if ENABLE_LOG is defined
void log_summary(const std::vector<std::string>& words) {
#ifdef ENABLE_LOG
    auto longest = find_longest(words);
    std::cout << "[LOG] Count: " << words.size() 
              << ", Longest: " 
              << (longest ? *longest : "N/A") << '\n';
#endif
}

// -----------------------------------
// TODO: Implement summary()
// Calls log_summary and returns a string
std::string summary(const std::vector<std::string>& words) {
    log_summary(words);
    auto longest = find_longest(words);
    std::ostringstream oss;
    oss << "Count=" << words.size()
        << ", Longest=" << (longest ? *longest : "N/A");
    return oss.str();
}

} // namespace textlib::util
