#include "stats.hpp"
#include <cassert>
#include <iostream>
#include <assert.h>

using namespace mathlib::stats;

int main() {
    std::vector<double> data1 = {1.0, 2.0, 3.0, 4.0};
    std::vector<double> data2 = {};

    assert(std::abs(mean(data1) - 2.5) < 1e-6);
    assert(mean(data2) == 0.0);

    assert(std::abs(variance(data1) - 1.25) < 1e-6);
    assert(variance(data2) == 0.0);

    auto m1 = find_max(data1);
    auto m2 = find_max(data2);
    assert(m1.has_value() && *m1 == 4.0);
    assert(!m2.has_value());

    Stats st(data1);
    std::string summary = st.summary();

    assert(summary.find("mean=2.5") != std::string::npos);
    assert(summary.find("variance=1.25") != std::string::npos);
    assert(summary.find("max=4") != std::string::npos);

    std::cout << "All tests passed successfully!\n";
}
