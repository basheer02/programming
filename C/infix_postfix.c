#include<stdio.h>
#include<ctype.h>
#include <stdbool.h>

char stack[20];
int stack1[20];
int top = 0;

void pushchar(char x)
{
    stack[++top] = x;
}

char popchar()
{
    if(top == -1)
        return -1;
    else
        return stack[top--];
}

void pushvalue(int x){
    stack1[++top] = x;
}

int popvalue(){
    return stack1[top--];
}
int priority(char x)
{
    if(x == '(')
        return 0;
    if(x == '+' || x == '-')
        return 1;
    if(x == '*' || x == '/')
        return 2;
    if(x == '^')
        return 3;
    return 0;
}

bool isOperand(char c){
    if((c >= 'a' && c <= 'z') || (c >= 'A' && c <= 'Z') || (c >= '0' && c <= '9'))
        return true;
    else    
        return false;
}

void main()
{
    int ch;
    int num,n1,n2,res;
    int n;
    char exp1[20];
    char exp2[20];
    char *e, x;
    do{

        printf("\n Options  \n\n 1. Postfix expression \n 2. Postfix evaluation \n 0. Exit \n");
        printf("\n Enter your option : ");
        scanf("%d",&ch);
        switch(ch){

            case 0:
                return;
            case 1:
                top = -1;
                printf("\n Postfix expression ");
                printf("\n\n Enter the expression : ");
                scanf("%s",exp1);
                e = exp1;

                printf("\n Postfix expression : ");
                while(*e != '\0')
                {
                    if(isOperand(*e))
                        printf("%c",*e);
                    else if(*e == '(')
                        pushchar(*e);
                    else if(*e == ')')
                    {
                        while((x = popchar()) != '(')
                            printf("%c", x);
                    }
                    else
                    {
                        while(priority(stack[top]) >= priority(*e))
                            printf("%c",popchar());
                        pushchar(*e);
                    }
                    e++;
                }
                while(top != -1)
                    printf("%c",popchar());
                printf("\n");
                break;
            case 2:
                res = 0;
                top = -1;
                printf("\n\n Postfix Evaluation ");
                printf("\n\n Enter postfix expression : ");
                scanf("%s",exp2);
                e = exp2;
                printf("\n");
                while(*e != '\0')
                {
                    if(isOperand(*e)){
                        printf(" Enter value of %c : ",*e);
                        scanf("%d",&num);
                        pushvalue(num);
                    }
                    else{
                        n1 = popvalue();
                        n2 = popvalue();
                        switch(*e){
                            case '+':
                                res = n1 + n2;
                                break;
                            case '-':
                                res = n2 - n1;
                                break;
                            case '*':
                                res = n1 * n2;
                                break;
                            case '/':
                                res = n2 / n1;
                                break;
                            case '^':
                                n = 1;
                                for(int i = 0; i < n1; i++)
                                    n = n * n2;
                                res = n;
                                break;
                        }
                        pushvalue(res);
                    }
                    e++;
                }
                printf("\n Result of postfix expression : %d\n",popvalue());
                break;

        }
    }while(ch >= 0 && ch < 3);
}