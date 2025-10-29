#pragma once
#include <vector>
#include <string>
#include <optional>

namespace mathlib::stats {

    #define DEBUG_MODE 1

    // TODO: Declare a function double mean(const std::vector<double>& nums)
    //  - Return 0.0 if the vector is empty

    // TODO: Declare a function double variance(const std::vector<double>& nums)
    //  - Use the mean() function
    //  - Return 0.0 if the vector has less than 2 elements

    // TODO: Declare a helper function std::optional<double> find_max(const std::vector<double>& nums)
    //  - Return std::nullopt if empty, otherwise the maximum element

    // TODO: Define a class Stats
    //  - Constructor takes a const std::vector<double>&
    //  - Method summary() returns a formatted std::string:
    //        "mean=..., variance=..., max=..."
    //  - When DEBUG_MODE is defined, summary() should also print to console:
    //        "[DEBUG] Computing summary for N elements"

}
