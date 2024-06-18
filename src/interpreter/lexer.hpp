//
// Created by jm on 2024/6/18.
//

#ifndef CALCULATOR_UI_SRC_INTERPRETER_LEXER_HPP_
#define CALCULATOR_UI_SRC_INTERPRETER_LEXER_HPP_

#include <iostream>

#include "token.hpp"

class Lexer {
 public:
  explicit Lexer(std::string s) : m_input(std::move(s)), m_position(0) {}

 public:
  void skipWhitespace();
  Token getNextToken();

 private:
  std::string m_input;
  size_t m_position;
};

#endif //CALCULATOR_UI_SRC_INTERPRETER_LEXER_HPP_
