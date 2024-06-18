//
// Created by jm on 2024/6/18.
//

#ifndef CALCULATOR_UI_SRC_INTERPRETER_PARSER_HPP_
#define CALCULATOR_UI_SRC_INTERPRETER_PARSER_HPP_

/*
 * Grammar:
 *
 * Expression: Term | Expression + Term | Expression - Term
 * Term: Factor | Term * Factor | Term / Factor
 * Factor: Number
 * Number: Integer | Decimal
 * */

#include "lexer.hpp"
class Parser {

 public:
  explicit Parser(const std::string &s) : m_lexer(s), m_current_token(m_lexer.getNextToken()) {}

 public:
  double parse();

 private:
  void nextToken(TokenType type);
  double factor();
  double term();
  double expression();

 private:
  Lexer m_lexer;
  Token m_current_token;
};

#endif //CALCULATOR_UI_SRC_INTERPRETER_PARSER_HPP_
