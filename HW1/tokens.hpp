#ifndef TOKENS_HPP_
#define TOKENS_HPP_
#include <cstdlib>
enum tokentype {
    VOID = 1,
    INT = 2,
    BYTE = 3,
    B = 4,
    BOOL = 5,
    AND = 6,
    OR = 7,
    NOT = 8,
    TRUE = 9,
    FALSE = 10,
    RETURN = 11,
    IF = 12,
    ELSE = 13,
    WHILE = 14,
    BREAK = 15,
    CONTINUE = 16,
    SWITCH = 17,
    CASE = 18,
    DEFAULT = 19,
    COLON = 20,
    SC = 21,
    COMMA = 22,
    LPAREN = 23,
    RPAREN = 24,
    LBRACE = 25,
    RBRACE = 26,
    ASSIGN = 27,
    RELOP = 28,
    BINOP = 29,
    COMMENT = 30,
    ID = 31,
    NUM = 32,
    STRING = 33
};

//Returns the token type
string token_name(int token) {
    switch (token) {
        case VOID:
            return "VOID";

        case INT:
            return "INT";

        case BYTE:
            return "BYTE";

        case B:
            return "B";

        case BOOL:
            return "BOOL";

        case AND:
            return "AND";

        case OR:
            return "OR";

        case NOT:
            return "NOT";

        case TRUE:
            return "TRUE";

        case FALSE:
            return "FALSE";

        case RETURN:
            return "RETURN";

        case IF:
            return "IF";

        case ELSE:
            return "ELSE";

        case WHILE:
            return "WHILE";

        case BREAK:
            return "BREAK";

        case CONTINUE:
            return "CONTINUE";

        case SWITCH:
            return "SWITCH";

        case CASE:
            return "CASE";

        case DEFAULT:
            return "DEFAULT";

        case COLON:
            return "COLON";

        case SC:
            return "SC";

        case COMMA:
            return "COMMA";

        case LPAREN:
            return "LPAREN";

        case RPAREN:
            return "RPAREN";

        case LBRACE:
            return "LBRACE";

        case RBRACE:
            return "RBRACE";

        case ASSIGN:
            return "ASSIGN";

        case RELOP:
            return "RELOP";

        case BINOP:
            return "BINOP";

        case COMMENT:
            return "COMMENT";

        case ID:
            return "ID";

        case NUM:
            return "NUM";

        case STRING:
            return "STRING";

        default:
            return "Unknown Token";
    }
}
extern int yylineno;
extern char* yytext;
extern int yyleng;
extern int yylex();
#endif /* TOKENS_HPP_ */
