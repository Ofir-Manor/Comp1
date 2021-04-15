#include "tokens.hpp"
#include <string>
#include <string.h>
using namespace std;

string text;
string token_name(int token);
string lexeme_string(char* lexeme);

static bool isHexa(char let)
{
  return ((let>='0'&&let<='9')||(let>='a'&&let<='f')||(let>='A'&&let<='F'));
}

int main()
{
    int token;
    while((token = yylex())) {
        if (token == -1)
        {
            if(strcmp(yytext, "\"") == 0 )
            {
              printf("Error unclosed string\n");
            }
            else printf("Error %s\n", yytext);
            exit(0);
        }
		if(token == COMMENT)
		{
			printf("%d %s //\n", yylineno, token_name(token).c_str());
			continue;
		}
        if (token == STRING)
        {
            printf("%d %s %s\n", yylineno, token_name(token).c_str(),lexeme_string(yytext).c_str());
        }
        else
        {
            printf("%d %s %s\n", yylineno, token_name(token).c_str() , yytext);
        }

    }
    return 0;
}

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


//Transforms the lexeme of a string into a printable string
string lexeme_string(char * lexeme)
{
    string print_lexeme;
    char* index = lexeme+1;
    int cont;
    if(*(lexeme+yyleng-2)=='\\')
    {
      printf("Error unclosed string\n");
      exit(0); 
    }
    while (*(index+1) != '\0')
    {
        cont = 1;
        if(*index == '\\')
        {
            switch (*(index+1))
            {
                case '0':
                    cont = 0;
                    *index = '\0';
                    break;

                case 't':
                    cont = 2;
                    print_lexeme += '\t';
                    break;

                case 'r':
                    cont = 2;
                    print_lexeme += '\r';
                    break;

                case 'n':
                    cont = 2;
                    print_lexeme += '\n';
                    break;

                case '"':
                    cont = 2;
                    print_lexeme += '"';
                    break;

                case '\\':
                    cont = 2;
                    print_lexeme += '\\';
                    break;

                case 'x':
                {
                    if((*(index+2)=='"'||!isHexa(*(index+2)))||
                    (*(index+3)=='"'||!isHexa(*(index+3))))
                    {
                      printf("Error undefined escape sequence x%c%c\n",*(index+2),*(index+3));
                      exit(0);
                    }
                    
                    string hex;
                    hex += (*(index+2));
                    hex += (*(index+3));
                    int hex_val = stoi(hex, 0, 16);
                    print_lexeme += hex_val;
                    cont = 4;
                    break;
                }
                    
                default:
                  printf("Error undefined escape sequence %c\n", *(index+1));
                  exit(0);
            }
        }
        else
        {
            print_lexeme += (*index);
        }
        index += cont;
    }
    return print_lexeme;
}
