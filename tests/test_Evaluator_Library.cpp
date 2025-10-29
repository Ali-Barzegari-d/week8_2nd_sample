#include "Evaluator_Library.hpp"
#include <cassert>
#include <string>

using namespace csi::expr;

int main() {
    
    assert(parse_operator("+") == Operator::Add);
    assert(parse_operator("/") == Operator::Divide);
    assert(parse_operator("?") == Operator::Unknown);

    Expression e = parse_expression("3 + 4 * 2");
    assert(!e.tokens.empty());

    double result = evaluate(e);
    assert(result == 14);

    Expression bad = parse_expression("5 / 0");
    assert(evaluate(bad) == 0);

    std::string s = summarize(e);
    assert(s.find("final result") != std::string::npos);

    return 0;
}
