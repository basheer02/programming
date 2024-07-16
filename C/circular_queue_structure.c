#include<stdio.h>
#include<stdlib.h>

struct CQueue{
    int front,rear,limit;
    int* cque;
};

struct CQueue* createCQueue(int limit){
    struct CQueue* cqueue = (struct CQueue*)malloc(sizeof(struct CQueue));
    cqueue->front = -1;
    cqueue->rear = -1;
    cqueue->limit = limit;
    cqueue->cque = (int*)malloc(cqueue->limit * sizeof(int));
    return cqueue;
}

int cqueueFull(struct CQueue* cqueue){
    return cqueue->front == (cqueue->rear + 1) % cqueue->limit;
}

int cqueueEmpty(struct CQueue* cqueue){
    return cqueue->front == -1 || cqueue->rear == -1;
}

void cenQueue(struct CQueue* cqueue, int element){
    cqueue->rear = (cqueue->rear + 1) % cqueue->limit;
    cqueue->cque[cqueue->rear] = element;
    if(cqueue->front == -1)
        cqueue->front++;
}

void cdeQueue(struct CQueue* cqueue){
    int x = cqueue->cque[cqueue->front];
    if(cqueue->front == cqueue->rear)
        cqueue->front = cqueue->rear = -1;
    else
        cqueue->front = (cqueue->front + 1) % cqueue->limit;
    printf(" %d deleted from queue \n",x);
}

void peek(struct CQueue* cqueue){
    printf(" Peek element in queue : %d",cqueue->cque[cqueue->front]);
}

void print(struct CQueue* cqueue){
    int i;
    printf(" Elements in queue : ");
    for( i = cqueue->front; i != cqueue->rear; i = (i+1) % cqueue->limit){
        printf(" %d ",cqueue->cque[i]);
    }
    printf(" %d ",cqueue->cque[i]);
}

int main(){ 

    int v,l,ch;
    printf(" enter limit of queue : ");
    scanf("%d",&l);
    struct CQueue* cq = createCQueue(l);
    do
    {
        printf(" \n **************\n\n");
        printf(" Options  \n\n 1. Insert \n 2. Delete \n 3. Peek value \n 4. Print \n 0.exit \n\n");
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
                if(cqueueFull(cq)){
                    printf("\n **************\n\n");
                    printf(" Queue is full \n");
                }
                else{
                    printf(" \n **************\n\n");
                    printf(" Enter element : ");
                    scanf("%d",&v);
                    cenQueue(cq,v);
                }
                break; 
            case 2:
                if(cqueueEmpty(cq)){
                    printf("\n **************\n\n");
                    printf(" Queue is empty \n");
                }
                else{
                    printf("\n ************** \n\n");
                    cdeQueue(cq);
                }
                break;
            case 3:
                if(cqueueEmpty(cq)){
                    printf(" \n **************\n\n");
                    printf(" Queue is empty \n");
                }
                else{
                    printf(" \n **************\n\n");
                    peek(cq);
                }
                break;
            case 4:
                if(cqueueEmpty(cq)){
                    printf(" \n **************\n\n");
                    printf(" Queue is empty \n");
                }
                else{
                    printf("\n **************\n\n");
                    print(cq);
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

