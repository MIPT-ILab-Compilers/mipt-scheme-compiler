/**
 * @file:schemelexer.l
 * Implementation of lexer
 */
/**
 * Copyright 2012 MIPT-COMPILER team
 */

%{
#include <cstdlib>
#include <string>
#include <map>
#include "identifiers_table.hpp"
#include "token.hpp"

extern bool token_boolean_value;
extern int token_number_value;
extern std::string token_string_value;
extern int token_identifier_number_value;
extern parser::IdentifiersTable identifiers;
extern char token_quote_value;
extern char token_open_bracket_value;
extern char token_close_bracket_value;
extern char token_character_value;

%}

%option noyywrap

LETTER [a-zA-Z]

DIGIT [0-9]

%%

#[fF] {
    token_boolean_value = false;
    return parser::tokens::BOOLEAN;
}

#[tT] {
    token_boolean_value = true;
    return parser::tokens::BOOLEAN;
}

[\+\-]?{DIGIT}+\.?{DIGIT}+ {
    token_number_value = atof( YYText());
    return parser::tokens::NUMBER;
}

\. {
    return parser::tokens::DOT;
}

([\!\$\%\&\*\+\-\.\/:\<\=\>\?\@\^\_\~]|{LETTER})[^ \n\t\r\(\)\[\]]* {
    token_identifier_number_value = identifiers.insert( YYText());
    return parser::tokens::IDENTIFIER;
}

\"[^\"]*\" {
    token_string_value = YYText();
    return parser::tokens::STRING;
}

['`] {
    token_quote_value = *YYText();
    return parser::tokens::QUOTE;
}

#\( {
    return parser::tokens::OPENVBRACKET;
}

#vu8\( {
    return parser::tokens::OPENBITVBRACKET;
}

[\[\(] {
    token_open_bracket_value = *YYText();
    return parser::tokens::OPENBRACKET;
}

[\)\]] {
    token_close_bracket_value = *YYText();
    return parser::tokens::CLOSEBRACKET;
}

\'.\' {
    token_character_value = *YYText();
    return parser::tokens::CHARACTER;
}

[. \n\r\t] {
    // For now, just skip all the rest
}
%%
