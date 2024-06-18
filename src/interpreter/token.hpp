//
// Created by jm on 2024/6/18.
//

#ifndef CALCULATOR_UI_SRC_INTERPRETER_TOKEN_HPP_
#define CALCULATOR_UI_SRC_INTERPRETER_TOKEN_HPP_

enum class TokenType {
  NUMBER,   // Number(Integer or Decimal)
  PLUS,     // +
  MINUS,    // -
  MULTIPLY, // *
  DIVIDE,   // /
  LPAREN,   // (
  RPAREN,   // )
  END       // EOF
};

struct Token {
  TokenType type;
  double value;

  explicit Token(TokenType t) : type(t), value(0) {}
  Token(TokenType t, double v) : type(t), value(v) {}
};

#endif //CALCULATOR_UI_SRC_INTERPRETER_TOKEN_HPP_
