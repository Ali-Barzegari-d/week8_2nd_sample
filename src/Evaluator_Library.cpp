#include "Evaluator_Library.hpp"
#include <sstream>
#include <cctype>

namespace csi::expr {

// TODO: Implement parse_operator()
// Hint: Compare the string symbol with "+", "-", "*", "/"
// and return the corresponding enum value.

Operator parse_operator(const std::string& symbol) {
    // TODO: your code here
}

// TODO: Implement parse_expression()
// Hint: use std::istringstream to read tokens (numbers and operators)
// and push them into expr.tokens vector.
// Alternate between reading numbers and operators.

Expression parse_expression(const std::string& input) {
    // TODO: your code here
}

// TODO: Implement evaluate()
// Hint: sequentially apply each operation (no operator precedence).
// Handle division by zero safely (return 0).

double evaluate(const Expression& expr) {
    // TODO: your code here
}

// TODO: Implement summarize()
// Hint: Count how many operations exist and compute final result.

std::string summarize(const Expression& expr) {
    // TODO: your code here
}

} // namespace csi::expr
