#include <stdio.h>

int main(){ 

    int element,max,ch,top = -1;
    printf("\n enter limit of stack : ");
    scanf("%d",&max);
    int stack[max];
    do
    {
        printf("\n Options  \n\n 1.push \n 2.pop  \n 3.print \n 0.exit \n\n");
        printf(" Enter your option : ");
        scanf("%d",&ch);
        
        switch (ch)
        {
            case 0:
                printf("\n Exit from program \n");
                return 0; 
            case 1:
                if(top == max - 1){
                    printf("\n stack is full \n");
                }
                else{
                    printf("\n Enter element : ");
                    scanf("%d",&element);
                    top++;
                    stack[top] = element;
                    printf("\n %d pushed to stack\n",element);
                }
                break; 
            case 2:
                if(top == -1){
                    printf("\n stack is empty \n");
                }
                else{
                    printf("\n ************** \n\n");
                    printf(" %d poped from stack\n",stack[top]);
                    top--;
                }
                break;
            case 3:
                if(top == -1){
                    printf(" \n **************\n\n");
                    printf(" stack is empty \n");
                }
                else{
                    printf("\n **************\n\n");
                    printf(" elements in stack : ");
                    for(int i = top; i >= 0; i--){
                        printf(" %d ",stack[i]);
                    }
                    printf("\n");
                }
                break;
            default:
                printf(" Invalid option ");
                break;
        }
    } while (ch < 4 && ch >= 0);
    printf("\n");
    return 0;
}         