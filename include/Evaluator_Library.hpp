#ifndef EVALUATOR_LIBRARY_HPP
#define EVALUATOR_LIBRARY_HPP

#include <string>
#include <vector>

namespace csi::expr {

    // Represents supported arithmetic operators
    enum class Operator {
        Add,
        Subtract,
        Multiply,
        Divide,
        Unknown
    };

    // Represents a single element (token) of an expression
    struct Token {
        double value;
        Operator op;
    };

    // Represents a parsed arithmetic expression
    struct Expression {
        std::vector<Token> tokens;
    };

    // TODO: Implement this function in the .cpp file.
    // It should convert a string symbol ("+", "-", "*", "/")
    // into the corresponding Operator enum value.
    Operator parse_operator(const std::string& symbol);

    // TODO: Implement this function in the .cpp file.
    // It should parse a string expression like:
    // "3 + 4 * 2"
    // and produce a vector of tokens inside an Expression object.
    // Ignore any invalid tokens.
    Expression parse_expression(const std::string& input);

    // TODO: Implement this function in the .cpp file.
    // It should evaluate the parsed Expression *from left to right*.
    // Example: "3 + 4 * 2" → (((3 + 4) * 2)) = 14
    // If division by zero occurs, return 0.
    double evaluate(const Expression& expr);

    // TODO: Implement this function in the .cpp file.
    // It should return a summary string like:
    // "Expression with 3 operations, final result = 14"
    std::string summarize(const Expression& expr);

} // namespace csi::expr

#endif // EVALUATOR_LIBRARY
