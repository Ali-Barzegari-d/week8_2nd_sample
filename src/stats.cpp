#include "stats.hpp"
#include <sstream>
#include <iostream>
#include <cmath>
#include <limits>

namespace mathlib::stats {

    double mean(const std::vector<double>& nums) {
        if (nums.empty()) return 0.0;
        double sum = 0.0;
        for (double n : nums)
            sum += n;
        return sum / static_cast<double>(nums.size());
    }

    double variance(const std::vector<double>& nums) {
        if (nums.size() < 2) return 0.0;
        double m = mean(nums);
        double acc = 0.0;
        for (double n : nums)
            acc += (n - m) * (n - m);
        return acc / static_cast<double>(nums.size());
    }

    std::optional<double> find_max(const std::vector<double>& nums) {
        if (nums.empty()) return std::nullopt;
        double max_val = std::numeric_limits<double>::lowest();
        for (double n : nums)
            if (n > max_val)
                max_val = n;
        return max_val;
    }

    Stats::Stats(const std::vector<double>& data)
        : data_(data) {}

    std::string Stats::summary() const {
    #ifdef DEBUG_MODE
        std::cout << "[DEBUG] Computing summary for "
                  << data_.size() << " elements\n";
    #endif

        double m = mean(data_);
        double v = variance(data_);
        auto mx = find_max(data_);

        std::ostringstream oss;
        oss << "mean=" << m
            << ", variance=" << v
            << ", max=" << (mx.has_value() ? std::to_string(*mx) : "N/A");
        return oss.str();
    }

} // namespace mathlib::stats
