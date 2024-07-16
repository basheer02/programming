#include<stdio.h>
#include<stdlib.h>

struct PQueue{
    int data,prio;
};

int main(){ 

    int element,l,ch,pr;
    int front = -1,rear = -1;
    printf(" enter limit of queue : ");
    scanf("%d",&l);
    struct PQueue pque[l],temp;
    do
    {
        printf(" \n **************\n\n");
        printf(" Options  \n\n 1. Insert \n 2. Delete  \n 3. Print \n 0. exit \n\n");
        printf(" **************\n\n");
        printf(" Enter your option : ");
        scanf("%d",&ch);
        
        switch (ch)
        {
            case 0:
                printf("\n Exit from program \n");
                printf("\n **************\n\n");
                return 0;  
            case 1:
                if(rear == l-1){
                    printf("\n **************\n\n");
                    printf(" Queue is full \n");
                }
                else{
                    printf(" \n **************\n\n");
                    printf(" Enter element : ");
                    scanf("%d",&element);
                    printf(" Enter priority : ");
                    scanf("%d",&pr);
                    if(front == -1)
                        front++;
                    rear++;
                    pque[rear].data = element;
                    pque[rear].prio = pr;
                    if( rear > 0){
                        for(int i = rear; i > front; i--){
                            if(pque[i].prio > pque[i-1].prio){
                                temp = pque[i];
                                pque[i] = pque[i-1];
                                pque[i-1] = temp;
                            }
                        }
                    }
                }
                break; 
            case 2:
                if(front == -1 || front == rear + 1){
                    printf("\n **************\n\n");
                    printf(" Queue is empty \n");
                }
                else{
                    printf("\n ************** \n\n");
                    printf(" %d deleted from queue \n",pque[front].data);
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
                    printf(" Elements in priority queue \n\n");
                    printf(" Element    priority \n\n");
                    for( i = front; i != rear+1; i++){
                        printf(" %4d ",pque[i].data);
                        printf(" %9d ",pque[i].prio);
                        printf("\n");
                    }
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