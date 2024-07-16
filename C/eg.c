#include<stdio.h>
#include<stdlib.h>
#include<malloc.h>
#include<string.h>

struct Node{

    char data[10];
    struct Node *next;
};

void main(){

    struct Node *ptr = NULL,*head;
    char *data;
    int n;
    for(int i = 0; i < 3; i++){
        
        printf(" Enter string : ");
        scanf("%s",data);
        struct Node *temp = (struct Node*)malloc(sizeof(struct Node));
        strcpy(temp->data,data);
        temp->next = NULL;
        if(ptr == NULL){
            head = temp;
            ptr = temp;}
        else{
            ptr->next = temp;
            ptr = temp;
        }
    }
    struct Node *ptr1 = head;
    while(ptr1 != NULL){
        printf(" %s",ptr1->data);
        ptr1 = ptr1->next;
    }
    printf("\n");
}
