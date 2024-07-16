#include <stdio.h>
#include <stdlib.h>

struct Stack {
    int top,capacity;
    int* array;
};

struct  Stack* createStack(int capacity)
{
    struct Stack* stack = (struct Stack*)malloc(sizeof(struct Stack));
    stack->capacity = capacity;
    stack->top = -1;
    stack->array = (int*)malloc(stack->capacity * sizeof(int));
    return stack;
};

int stackFull(struct Stack* stack){
    return stack->top == stack->capacity - 1;
}

int stackEmpty(struct Stack* stack){
    return stack->top == -1;
}

void push(struct Stack* stack,int element){
   /* if(stackFull(stack))
        printf(" stack is full\n");
    else{*/
        stack->top++;
        stack->array[stack->top] = element;
        printf("\n %d pushed to stack\n",element);
   // }
}

void pop(struct Stack* stack){
   // if(stackEmpty(stack))
    //    printf(" stack is empty\n");
    //else{
        int x = stack->array[stack->top];
        stack->top--;
        printf(" %d poped from stack\n",x);
   // }
}

void peek(struct Stack* stack){
    printf(" peek element : %d \n",stack->array[stack->top]);
}

void print(struct Stack* stack){
    printf(" elements in stack : ");
    for(int i = stack->top; i >= 0; i--){
        printf("%d",stack->array[i]);
        printf(" ");
    }
    printf("\n");
}

int main(){ 

    int t,ls,ch;
    printf(" enter limit of stack : ");
    scanf("%d",&ls);
    struct Stack* st = createStack(ls);
    do
    {
        printf(" \n **************\n\n");
        printf(" Options  \n 1.push \n 2.pop \n 3.peek value \n 4.print \n 0.exit \n\n");
        printf(" **************\n\n");
        printf(" Enter your option : ");
        scanf("%d",&ch);
        
        switch (ch)
        {
            case 0:
                return 0;
              //  break;  
            case 1:
                if(stackFull(st)){
                    printf("\n **************\n\n");
                    printf(" stack is full \n");
                }
                else{
                    printf(" \n **************\n\n");
                    printf(" Enter element : ");
                    scanf("%d",&t);
                    push(st, t);
                }
                break; 
            case 2:
                if(stackEmpty(st)){
                    printf("\n **************\n\n");
                    printf(" stack is empty \n");
                }
                else{
                    printf("\n ************** \n\n");
                    pop(st);
                }
                break;
            case 3:
                if(stackEmpty(st)){
                    printf(" \n **************\n\n");
                    printf(" stack is empty \n");
                }
                else{
                    printf(" \n **************\n\n");
                    peek(st);
                }
                break;
            case 4:
                if(stackEmpty(st)){
                    printf(" \n **************\n\n");
                    printf(" stack is empty \n");
                }
                else{
                    printf("\n **************\n\n");
                    print(st);
                }
                break;
            default:
                return 0;
                //break;
        }
    } while (ch<5 && ch>=0);
    printf("\n");
    return 0;
}         