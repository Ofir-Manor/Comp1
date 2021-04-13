#include "tokens.hpp"
#include <stack>
using namespace std;
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
                if (paren_stack.top() == LPAREN)
                {
                    for (i = 0; i < spaces; i ++)
                    {
                        printf("\t");
                    }

                    printf(")\n");

                    spaces--;

                    paren_stack.pop();

                    break;
                }
                else
                {
                    printf("Error: Bad Expression\n")
                    exit(0);
                }

            case LBRACE:
                for (i = 0; i < spaces; i ++)
                {
                    printf("\t");
                }

                printf("{\n");

                spaces++;

                paren_stack.push(LPAREN);

                break;

            case RBRACE:
                if (paren_stack.top() == LBRACE)
                {
                    for (i = 0; i < spaces; i ++)
                    {
                        printf("\t");
                    }

                    printf("}\n");

                    spaces--;

                    paren_stack.pop();

                    break;
                }
                else
                {
                    printf("Error: Bad Expression\n")
                    exit(0);
                }

            default:
                if (token == -1)
                {
                    printf("Error: %s\n", yytext);
                }
                else
                {
                    printf("Error: ")
                }
        }

    }
    return 0;
}