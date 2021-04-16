#include "tokens.hpp"
#include <stack>
#include <string>
using namespace std;

string token_name(int token);

int main()
{
    int token;
    int spaces = 0;
    int i;
    stack <tokentype> paren_stack;
    while(token = yylex()) {

        switch (token){
            case LPAREN:
                for (i = 0; i < spaces; i ++)
                {
                    printf("\t");
                }

                printf("(\n");

                spaces++;

                paren_stack.push(LPAREN);

                break;

            case RPAREN:
            
                if(paren_stack.size() == 0)
                {
                  printf("Error: Bad Expression\n");
                  exit(0);
                }
                
                if (paren_stack.top() == LPAREN)
                {
                    spaces--;

                    for (i = 0; i < spaces; i ++)
                    {
                        printf("\t");
                    }

                    printf(")\n");

                    paren_stack.pop();

                    break;
                }
                else
                {
                    printf("Error: Bad Expression\n");
                    exit(0);
                }

            case LBRACE:
                for (i = 0; i < spaces; i ++)
                {
                    printf("\t");
                }

                printf("{\n");

                spaces++;

                paren_stack.push(LBRACE);

                break;

            case RBRACE:
            
                 if(paren_stack.size() == 0)
                {
                  printf("Error: Bad Expression\n");
                  exit(0);
                }
                
                if (paren_stack.top() == LBRACE)
                {
                    spaces--;

                    for (i = 0; i < spaces; i ++)
                    {
                        printf("\t");
                    }

                    printf("}\n");

                    paren_stack.pop();

                    break;
                }
                else
                {
                    printf("Error: Bad Expression\n");
                    exit(0);
                }

            default:
                if (token == -1)
                {
                    printf("Error %s\n", yytext);
                    exit(0);
                }
                else
                {
                    printf("Error: %s\n", token_name(token).c_str());
                    exit(0);
                }
        }

    }
    if(paren_stack.size() != 0)
    {
        printf("Error: Bad Expression\n");
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