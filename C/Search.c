#include<stdio.h>

int search(int arr[],int low,int high,int n){

    while( low <= high){
        int mid = low + (high - low)/2;
        if(arr[mid] == n)
            return mid;
        else if(arr[mid] < n)
            //low = mid + 1;
            return search(arr,mid + 1,high,n);
        else
            //high = mid - 1;
            return search(arr,low,mid -1,n);
    }
    return -1;
}

void main(){
    
    int size,n,ch,flag = 0,res;

    printf(" Enter total no.of elements : ");
    scanf("%d",&size);
    int arr[size];

    printf(" Enter elements : ");
    for(int i = 0; i < size; i++)
        scanf("%d",&arr[i]);

    do{

        printf("\n Options  \n\n 1. Linear search \n 2. Binary search \n 0. Exit \n");
        printf("\n Enter your option : ");
        scanf("%d",&ch);
        switch(ch){
            case 0:
                return;
            case 1 :
                printf("\n Enter a element to search : ");
                scanf("%d",&n);
                for(int i = 0; i < size; i++){
                    if(arr[i] == n){
                        printf("\n %d found in position %d\n",n,i+1);
                        flag = 1;
                    }       
                }
                if(flag == 0)
                    printf("\n %d not found\n",n);
                break;
            case 2: 
                printf("\n Enter a element to search : ");
                scanf("%d",&n);
                int temp;
                for(int i = 0; i < size;i++){
                    for(int j = i+1; j < size; j++){
                        if(arr[j] < arr[i]){
                           temp = arr[i];
                           arr[i] = arr[j];
                           arr[j] = temp;     
                        }
                    }
                }
                res = search(arr,0,size-1,n);
                if(res != -1)
                    printf("\n %d found in position %d \n",n,res+1);
                else    
                    printf("\n %d not found\n",n);
                break;
        }
    }while( ch > 0 && ch < 3);
}