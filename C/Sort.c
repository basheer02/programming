#include<stdio.h>

void interChange(int arr[],int i,int j){

    int temp = arr[i];
    arr[i] = arr[j];
    arr[j] = temp;
}

void quickSort(int arr[],int left,int right){

    int i,j,pivot;
    if(left < right){
        i = left;
        j = right+1;
        pivot = arr[left];

        do{
            do i++;while(arr[i] < pivot);
            do j--;while(arr[j] > pivot);
            if(i < j) interChange(arr,i,j);
        }while(i < j);

        interChange(arr,left,j);
        quickSort(arr,left,j-1);
        quickSort(arr,j+1,right);
    }
}

void mergeSort(int arr[],int n){

    int l1,l2,u1,u2,aux[n],i,j,k,size;
    size = 1;

    while(size < n){

        l1 = 0;
        k = 0;

        while((l1 + size) < n){
            
            l2 = l1 + size;
            u1 = l2 - 1;
            u2 = ((l2 + size - 1) < n) ? (l2 + size - 1) : n-1;

            for( i = l1,j = l2; i <= u1 && j <= u2 ; k++){
                if(arr[i] <= arr[j])
                    aux[k] = arr[i++];
                else
                    aux[k] = arr[j++];
            }

            for(; i <= u1; k++) 
                aux[k] = arr[i++];
            for(; j <= u2; k++)
                aux[k] = arr[j++];

            l1 = u2 + 1;
        }

        for( i = l1; k < n; i++)
            aux[k++] = arr[i];
        
        for( i = 0 ; i < n; i++)
            arr[i] = aux[i];
        size *= 2;
    }
}

void swap(int *i,int *j){
    int temp = *i;
    *i = *j;
    *j = temp;
}

void prec_down(int arr[],int i,int n){

    int child,temp;

    for(temp = arr[i]; i * 2 <= n; i = child){
        child = i * 2;
        if((child != n) && arr[child+1] > arr[child])
            child++;
        if(temp < arr[child])
            arr[i] = arr[child];
        else
            break;
    }
    arr[i] = temp;
}

void heapSort(int arr[],int n){
    int i;
    for( i = n/2; i > 0; i--)
        prec_down(arr,i,n);
    for( i = n; i >= 2; i--){
        swap(&arr[1],&arr[i]);
        prec_down(arr,1,i-1);
    }
}

void main(){
    int ch,n;
    printf("\n Enter no.of elements : ");
    scanf("%d",&n);
    int merge[n],quick[n],heap[n];
    do{
        printf("\n Options \n\n 1. Quick sort\n 2. Merge sort\n 3. Heap sort\n 0. Exit\n");
        printf("\n Enter option : ");
        scanf("%d",&ch);
        
        switch(ch){
            case 0:
                printf(" Exit...\n");
                return;
            case 1:
                printf("\n Enter elements : ");
                for( int i = 0; i < n; i++)
                    scanf("%d",&quick[i]);
                quickSort(quick,0,n-1);
                printf("\n After sorting : ");
                for( int i = 0; i < n; i++)
                    printf(" %d",quick[i]);
                printf("\n");
                break;
            case 2:
                printf("\n Enter elements : ");
                for( int i = 0; i < n; i++)
                    scanf("%d",&merge[i]);
                mergeSort(merge,n);
                printf("\n After sorting : ");
                for( int i = 0; i < n; i++)
                    printf(" %d",merge[i]);
                printf("\n");
                break;
            case 3:
                printf("\n Enter elements : ");
                for( int i = 1; i <= n; i++)
                    scanf("%d",&heap[i]);
                heapSort(heap,n);
                printf("\n After sorting : ");
                for( int i = 1; i <= n; i++)
                    printf(" %d",heap[i]);
                printf("\n");
                break;
            default:
                printf("\n Invalid option \n");
        }
    }while( ch >= 0);
}