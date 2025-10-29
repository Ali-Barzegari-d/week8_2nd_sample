#pragma once
#include <vector>
#include <string>
#include <optional>

namespace mathlib::stats {

    // DEBUG_MODE will control whether extra logs appear
    #define DEBUG_MODE 1

    // Returns the arithmetic mean of a vector.
    // Returns 0.0 if the vector is empty.
    double mean(const std::vector<double>& nums);

    // Returns the variance of a vector (population variance).
    // Returns 0.0 if fewer than 2 elements exist.
    double variance(const std::vector<double>& nums);

    // Returns the maximum value in a vector, or std::nullopt if empty.
    std::optional<double> find_max(const std::vector<double>& nums);

    // Class to compute and summarize basic statistics.
    class Stats {
    public:
        explicit Stats(const std::vector<double>& data);

        // Returns formatted string:
        // "mean=..., variance=..., max=..."
        std::string summary() const;

    private:
        std::vector<double> data_;
    };

} // namespace mathlib::stats
