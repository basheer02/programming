#include<stdio.h>
#include<malloc.h>
#include<stdlib.h>

#define Node struct node

int s = 1;
Node{
    int coeff,exp;
    Node *next;
};

Node* read(Node *eq,int n){

    Node *temp = NULL,*ptr = NULL;
    int coeff,exp;

    for(int i = 0; i < n; i++){

        printf(" Enter coefficient : ");
        scanf("%d",&coeff);
        printf(" Enter exponent : ");
        scanf("%d",&exp);
        temp = (Node*)malloc(sizeof(Node));
        temp->next = NULL;
        temp->coeff = coeff;
        temp->exp = exp;

        if(ptr == NULL){
            ptr = temp;
            eq = temp;
        }
        else{
            ptr->next = temp;
            ptr = temp;
        }
    }
    return eq;
}

Node* addNode(Node *start,int coeff,int exp){

    Node *temp = (Node*)malloc(sizeof(Node));
    temp->coeff = coeff;
    temp->exp = exp;
    temp->next = NULL;

    if (start == NULL)
        return temp;

    Node *ptr = start;
    while (ptr->next != NULL)
        ptr = ptr->next;
    ptr->next = temp;
 
    return start;
}

void display(Node *eq,int n){

    Node *ptr;
    ptr = eq;
    int i = 0;

    while(ptr != NULL){

        if(ptr->coeff != 0){

            if(ptr->exp == 0)
                printf("%d",ptr->coeff);
            else if(ptr->exp == 1)
                printf("%dx",ptr->coeff);
            else
                printf("%dx^%d",ptr->coeff,ptr->exp);
            if( i < n-1)
                printf(" + ");
            i++;
        }
        ptr = ptr->next;
    }
}

int removeDuplicates(Node* start){

    Node *ptr1, *ptr2, *dup;
    ptr1 = start;
 
    /* Pick elements one by one */
    while (ptr1 != NULL && ptr1->next != NULL) {
        ptr2 = ptr1;
        s++;
    
        while (ptr2->next != NULL) {
 
            if (ptr1->exp == ptr2->next->exp) {
 
                ptr1->coeff = ptr1->coeff + ptr2->next->coeff;
                dup = ptr2->next;
                ptr2->next = ptr2->next->next;
 
                free(dup);
            }
            else
                ptr2 = ptr2->next;
        }
        ptr1 = ptr1->next;
    }
    return s;
}

Node* prodPoly(Node* poly1,Node* poly2,Node* poly3){

    Node *a = poly1;
    Node *b = poly2;

    while( a != NULL){
        while( b != NULL){
            int coeff,exp;
            coeff = a->coeff * b->coeff;
            exp = a->exp + b->exp;
            poly3 = addNode(poly3,coeff,exp);
            b = b->next;
        }
        b = poly2;
        a = a->next;
    }
    s = removeDuplicates(poly3);
    return poly3;
}

void main(){

    int n1,n2;
    Node *poly1,*poly2,*poly3;
    poly1 = poly2 = poly3 = NULL;

    printf("\n First polynomial\n\n");
    printf(" Enter number of terms in first polynomial : ");
    scanf("%d",&n1);

    printf("\n");
    poly1 = read(poly1,n1);
    printf("\n Polynomial expression : ");
    display(poly1,n1);

    printf("\n\n Second polynomial\n\n");
    printf(" Enter number of terms in second polynomial : ");
    scanf("%d",&n2);

    printf("\n");
    poly2 = read(poly2,n2);
    printf("\n Polynomial expression : ");
    display(poly2,n2);

    poly3 = prodPoly(poly1,poly2,poly3);
    printf("\n\n Product of polynomials : ");
    display(poly3,s);
    printf("\n\n");
}