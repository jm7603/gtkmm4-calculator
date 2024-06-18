//
// Created by jm on 2024/6/18.
//

#include <sstream>

#include "lexer.hpp"

static inline bool isNumber(int c) {
  return isdigit(c) || c == '.';
}

void Lexer::skipWhitespace() {
  while (m_position < m_input.size() && isspace(m_input[m_position])) {
    m_position++;
  }
}

Token Lexer::getNextToken() {
  skipWhitespace();

  if (m_position >= m_input.size()) {
    return Token(TokenType::END);
  }

  char current_char = m_input[m_position++];

  // Return a Number
  if (isNumber(current_char)) {
    std::stringstream ss;
    ss << current_char;

    while (m_position < m_input.size() && isNumber(m_input[m_position])) {
      ss << m_input[m_position++];
    }

    double number;
    ss >> number;
    return {TokenType::NUMBER, number};
  }

  // Other Tokens
  switch (current_char) {
    case '+': return Token(TokenType::PLUS);
    case '-': return Token(TokenType::MINUS);
    case '*': return Token(TokenType::MULTIPLY);
    case '/': return Token(TokenType::DIVIDE);
    case '(': return Token(TokenType::LPAREN);
    case ')': return Token(TokenType::RPAREN);
    default: throw std::runtime_error("Invalid character");
  }
}
