#include<stdio.h>

int main(){ 

    int element,ch;
    int front = -1, rear = -1,limit;
    printf("\n enter limit of queue : ");
    scanf("%d",&limit);

    int que[limit];
    do
    {
        printf(" \n **************\n\n");
        printf(" Options  \n\n 1. Insert \n 2. Delete \n 3. Print \n 0.exit \n\n");
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
                if(rear == limit - 1){
                    printf("\n **************\n\n");
                    printf(" Queue is full \n");
                }
                else{
                    printf(" \n **************\n\n");
                    printf(" Enter element : ");
                    scanf("%d",&element);
                    rear++;
                    que[rear] = element;
                    if(front == -1)
                        front++;
                    printf("\n %d added to queue ",element);
                    printf("\n");
                }
                break; 
            case 2:
                if(front == -1 || front == rear + 1){
                    printf("\n **************\n\n");
                    printf(" Queue is empty \n");
                }
                else{
                    printf("\n ************** \n\n");
                    printf(" %d deleted from queue \n",que[front]);
                    front++;
                }
                break;
            case 3:
                if(front == -1 || front == rear + 1){
                    printf(" \n **************\n\n");
                    printf(" Queue is empty \n");
                }
                else{
                    printf("\n **************\n\n");
                    int i;
                    printf(" Elements in queue : ");
                    for( i = front; i != rear+1; i++){
                        printf(" %d ",que[i]);
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
