#include<stdio.h>
#include<malloc.h>

#define Node struct node

Node{
    int data;
    Node *next;
};

void printStack(Node* top){
    printf("\n Elements in stack : ");
    while( top != NULL){
        printf(" %d ",top->data);
        top = top->next;
    }
    printf("\n");
}

void printQueue(Node* front){
    printf("\n Elements in queue : ");
    while( front != NULL){
        printf(" %d ",front->data);
        front = front->next;
    }
    printf("\n");
}

void main(){

    Node *top = NULL, *front = NULL, *rear = NULL;
    Node *temp = NULL;
    int ch,op,n;

    do{
        printf(" \n Options \n\n 1. Stack \n 2. Queue \n 0. Exit \n\n");
        printf(" Enter option : ");
        scanf("%d",&ch);
        switch(ch){
            case 0:
                return;
            case 1:
                printf("\n Stack \n");
                do{
                    printf(" \n Options \n\n 1. Push \n 2. Pop \n 3. Print \n 0. Exit \n\n");
                    printf(" Enter option : ");
                    scanf("%d",&op);
                    switch(op){
                        case 0:
                            printf("\n Exit from stack \n");
                            op = -1;
                            break;
                        case 1:
                            temp = (Node*)malloc(sizeof(Node));
                            printf("\n Enter element : ");
                            scanf("%d",&n);
                            temp->data = n;
                            if(top == NULL){
                                top = temp;
                                top->next = NULL;
                            }
                            else{
                                temp->next = top;
                                top = temp;
                            }
                            printf("\n %d pushed to stack \n",n);
                            break;
                        case 2:
                            temp = top;
                            if(temp == NULL)
                                printf("\n Stack is empty \n");
                            else{
                                printf("\n %d poped from stack \n",top->data);
                                top = top->next;
                                free(temp);
                            }
                            break;
                        case 3:
                            if(top == NULL)
                                printf("\n Stack is empty \n");
                            else
                                printStack(top);
                            break;
                    }

                }while(op >= 0 && op < 4);
                break;
            case 2:
                printf("\n Queue \n");
                do{
                    printf(" \n Options \n\n 1. Insert \n 2. Delete \n 3. Print \n 0. Exit \n\n");
                    printf(" Enter option : ");
                    scanf("%d",&op);
                    switch(op){
                        case 0:
                            printf("\n Exit from queue \n");
                            op = -1;
                            break;
                        case 1:
                            temp = (Node*)malloc(sizeof(Node));
                            printf("\n Enter element : ");
                            scanf("%d",&n);
                            temp->data = n;
                            temp->next = NULL;
                            if(front == NULL)
                                front = rear = temp;
                            else{
                                rear->next = temp;
                                rear = temp;
                            }
                            printf("\n %d inserted to queue \n",n);
                            break;
                        case 2:
                            temp = front;
                            if(temp == NULL)
                                printf("\n Queue is empty \n");
                            else{
                                printf("\n %d deleted from queue \n",front->data);
                                front = front->next;
                                free(temp);
                            }
                            break;
                        case 3:
                            if(front == NULL)
                                printf("\n Queue is empty \n");
                            else
                                printQueue(front);
                            break;
                    }

                }while(op >= 0 && op < 4);
                break;
        }
    }while(ch >=0 && ch < 3);
}