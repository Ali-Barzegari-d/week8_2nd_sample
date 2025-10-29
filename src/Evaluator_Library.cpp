#include "Evaluator_Library.hpp"
#include <sstream>
#include <cctype>

namespace csi::expr {

// Converts string to enum operator
Operator parse_operator(const std::string& symbol) {
    if (symbol == "+") return Operator::Add;
    if (symbol == "-") return Operator::Subtract;
    if (symbol == "*") return Operator::Multiply;
    if (symbol == "/") return Operator::Divide;
    return Operator::Unknown;
}

// Parses an expression string like "3 + 4 * 2"
Expression parse_expression(const std::string& input) {
    Expression expr;
    std::istringstream iss(input);
    std::string token;

    // Expected pattern: number op number op ...
    double last_value = 0;
    bool expect_number = true;
    Operator current_op = Operator::Unknown;

    while (iss >> token) {
        if (expect_number) {
            // try to parse a number
            bool valid = true;
            for (char c : token) {
                if (!std::isdigit(c) && c != '.') { valid = false; break; }
            }
            if (valid) {
                last_value = std::stod(token);
                expr.tokens.push_back({last_value, current_op});
                expect_number = false;
            }
        } else {
            // parse operator
            current_op = parse_operator(token);
            expect_number = true;
        }
    }

    return expr;
}

// Evaluate expression sequentially (no operator precedence)
double evaluate(const Expression& expr) {
    if (expr.tokens.empty()) return 0;

    double result = expr.tokens.front().value;

    for (size_t i = 1; i < expr.tokens.size(); ++i) {
        Operator op = expr.tokens[i].op;
        double val = expr.tokens[i].value;

        switch (op) {
            case Operator::Add:
                result += val;
                break;
            case Operator::Subtract:
                result -= val;
                break;
            case Operator::Multiply:
                result *= val;
                break;
            case Operator::Divide:
                if (val == 0) return 0; // division by zero
                result /= val;
                break;
            default:
                break;
        }
    }
    return result;
}

std::string summarize(const Expression& expr) {
    std::ostringstream oss;
    int op_count = 0;
    for (const auto& t : expr.tokens)
        if (t.op != Operator::Unknown)
            ++op_count;

    double result = evaluate(expr);
    oss << "Expression with " << op_count
        << " operations, final result = " << result;
    return oss.str();
}

} // namespace csi::expr
