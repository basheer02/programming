import java.io.StreamCorruptedException;
import java.util.Scanner;

public class QuickSort {
    public static void main(String[] args) {

        Scanner sc = new Scanner(System.in);
        int size,j = 0;
        System.out.print("\n Enter no.of strings : ");
        size = sc.nextInt();

        String[] str = new String[size];
        for(int i = 0; i < size; i++){
            System.out.print(" Enter string "+ ++j +" : ");
            str[i]  = sc.next();
        }

        quickSort(str,0,size-1);
        System.out.println(" After Sorting ");
        for(int i = 0; i < size; i++){
            System.out.println(" "+str[i]);
        }

    }

    public static void quickSort(String arr[],int left,int right){

        String pivot;
        int i,j;

        if( left < right){
            i = left;
            j = right+1;
            pivot = arr[left];

            do{
                do i++; while( i < right && arr[i].compareToIgnoreCase(pivot) <= 0);
                do j--; while( j > left && arr[j].compareToIgnoreCase(pivot) > 0); 
                if(i < j) 
                    swap(arr,i,j); 
            }while( i < j);

            swap(arr,left,j);
            quickSort(arr, left, j-1);
            quickSort(arr, j+1, right); 

        }

    }

    public static void swap(String arr[],int i,int j){
        String temp = arr[i];
        arr[i] = arr[j];
        arr[j] = temp;
    }

}
