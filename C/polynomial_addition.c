#include<stdio.h>
#include<math.h>

struct polynomial{
    int coeff,exp;
}temp;

void read( struct polynomial p[],int size){

    printf("\n");
    for(int i = 0; i < size; i++){
        printf(" Enter coefficient : ");
        scanf("%d",&p[i].coeff);
        printf(" Enter exponent : ");
        scanf("%d",&p[i].exp);
    }
}

void sort(struct polynomial p[],int size){

    for(int i = 0; i < size; i++){
        for(int j = i+1; j < size; j++){
            if( p[i].exp < p[j].exp ){
                temp = p[i];
                p[i] = p[j];
                p[j] = temp;
            }
        }  
    }
}

int polyadd(struct polynomial p1[],struct polynomial p2[],struct polynomial p3[],int s1,int s2){

    int x = 0,y = 0,s = -1;

    while( x < s1 && y < s2){

        s++;
        if( p1[x].exp == p2[y].exp){
            p3[s].coeff = p1[x].coeff + p2[y].coeff;
            p3[s].exp = p1[x].exp;
            x++;
            y++;
        }
        else if( p1[x].exp > p2[y].exp){
            p3[s].coeff = p1[x].coeff;
            p3[s].exp = p1[x].exp;
            x++;
        }
        else{
            p3[s].coeff = p2[y].coeff;
            p3[s].exp = p2[y].exp;
            y++;
        }
    }

    while( x < s1){
        s++;
        p3[s].coeff = p1[x].coeff;
        p3[s].exp = p1[x].exp;
        x++;
    }
    while( y < s2){
        s++;
        p3[s].coeff = p2[y].coeff;
        p3[s].exp = p2[y].exp;
        y++;
    }

    return s+1;
}

void display( struct polynomial p[],int size,int n){

    printf("\n");
    if(n == 1 || n == 2)
        printf(" Expression of polynomial %d : ",n);
    else
        printf(" Sum of polynomials : ");
    for(int i = 0; i < size; i++){
        if( p[i].coeff != 0 ){
            if(p[i].exp == 0)
                printf("%d",p[i].coeff);
            else if(p[i].exp == 1)
                printf("%dx",p[i].coeff);
            else
                printf("%dx^%d ",p[i].coeff,p[i].exp);
            if(i != size - 1)
                printf(" + ");
        }
    }
    printf("\n");
}

int main(){

    int s1,s2,s;
    printf("\n *********************\n\n");
    printf(" First polynomial\n\n");
    printf(" Enter number of terms in first polynomial : ");
    scanf("%d",&s1);

    struct polynomial p1[s1];
    read(p1,s1);
    sort(p1,s1);
    display(p1,s1,1);

    printf("\n *********************\n\n");
    printf(" Second polynomial\n\n");
    printf(" Enter number of terms in second polynomial : ");
    scanf("%d",&s2);

    struct polynomial p2[s2];
    read(p2,s2);
    sort(p2,s2);
    display(p2,s2,2);

    struct polynomial p3[20];
    int s3 = polyadd(p1,p2,p3,s1,s2);
    sort(p3,s3);
    printf("\n *********************\n");
    display(p3,s3,0);
    printf("\n *********************\n");

    return 0;
}

