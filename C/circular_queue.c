#include<stdio.h>

int main(){ 

    int element,ch;
    int front = -1, rear = -1,limit;
    printf(" enter limit of queue : ");
    scanf("%d",&limit);

    int cque[limit];
    do
    {
        printf(" \n **************\n\n");
        printf(" Options  \n\n 1. Insert \n 2. Delete \n 3. Print \n 0. Exit \n\n");
        printf(" **************\n\n");
        printf(" Enter your option number : ");
        scanf("%d",&ch);
        
        switch (ch)
        {
            case 0:
                printf("\n Exit from program \n");
                printf("\n **************\n\n");
                return 0;  
            case 1:
                if(front == (rear + 1) % limit){
                    printf("\n **************\n\n");
                    printf(" Queue is full \n");
                }
                else{
                    printf(" \n **************\n\n");
                    printf(" Enter element : ");
                    scanf("%d",&element);
                    rear = (rear + 1) % limit;
                    cque[rear] = element;
                    if(front == -1)
                        front++;
                    printf("\n %d added to queue ",element);
                    printf("\n");
                }
                break; 
            case 2:
                if(front == -1 || rear == -1){
                    printf("\n **************\n\n");
                    printf(" Queue is empty \n");
                }
                else{
                    printf("\n ************** \n\n");
                    int x = cque[front];
                    if(front == rear)
                        front = rear = -1;
                    else
                        front = (front + 1) % limit;
                    printf(" %d deleted from queue \n",x);
                }
                break;
            case 3:
                if(front == -1 || rear == -1){
                    printf(" \n **************\n\n");
                    printf(" Queue is empty \n");
                }
                else{
                    printf("\n **************\n\n");
                    int i;
                    printf(" Elements in queue : ");
                    for( i = front; i != rear; i = (i+1) % limit){
                        printf(" %d ",cque[i]);
                    }
                    printf(" %d ",cque[i]);
                    printf("\n");
                }
                break;
            default:
                printf(" Invalid option ");
                break;
        }
    } while (ch<5 && ch>=0);
    printf("\n");
    return 0;
}