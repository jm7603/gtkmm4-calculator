//
// Created by jm on 2024/6/18.
//

#include "parser.hpp"

void Parser::nextToken(TokenType type) {
  if (m_current_token.type == type) {
    m_current_token = m_lexer.getNextToken();
    return;
  }
  throw std::runtime_error("Syntax error");
}

double Parser::factor() {
  Token token = m_current_token;

  if (token.type == TokenType::NUMBER) {
    nextToken(TokenType::NUMBER);
    return token.value;
  } else if (token.type == TokenType::LPAREN) {
    nextToken(TokenType::LPAREN);
    double result = expression();
    nextToken(TokenType::RPAREN);
    return result;
  }

  throw std::runtime_error("Syntax error");
}

double Parser::term() {
  double result = factor();

  while (m_current_token.type == TokenType::MULTIPLY || m_current_token.type == TokenType::DIVIDE) {
    Token token = m_current_token;
    if (token.type == TokenType::MULTIPLY) {
      nextToken(TokenType::MULTIPLY);
      result *= factor();
    } else if (token.type == TokenType::DIVIDE) {
      nextToken(TokenType::DIVIDE);
      double right = factor();
      if (right == 0) {
        throw std::runtime_error("Divided by zero");
      }
      result /= right;
    }
  }

  return result;
}

double Parser::expression() {
  double result = term();

  while (m_current_token.type == TokenType::PLUS || m_current_token.type == TokenType::MINUS) {
    Token token = m_current_token;
    if (token.type == TokenType::PLUS) {
      nextToken(TokenType::PLUS);
      result += term();
    } else if (token.type == TokenType::MINUS) {
      nextToken(TokenType::MINUS);
      result -= term();
    }
  }

  return result;
}

double Parser::parse() {
  return expression();
}
