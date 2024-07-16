import java.util.Scanner;

public class BinarySearch {
    public static void main(String[] args) {
        
        Scanner sc = new Scanner(System.in);
        int size,search;
        System.out.print("\n Enter no. of elements : ");
        size = sc.nextInt();
        int num[] = new int[size];

        System.out.print("\n Enter elements : ");
        for(int i = 0; i < size; i++)
            num[i] = sc.nextInt();

        for(int i = 0; i < size; i++){
            for(int j = i+1; j < size; j++){
                if(num[i] > num[j]){
                    int temp = num[i];
                    num[i] = num[j];
                    num[j] = temp;
                }
            }
        }
        
        System.out.print("\n Enter a element to search : ");
        search = sc.nextInt();

        int index = binarySearch(num,size-1,search);
        if( index != -1)
            System.out.println("\n "+search+" found at position "+index);
        else  
            System.out.println("\n "+search+" not found ");
        sc.close();
    }

    public static int binarySearch(int arr[],int high,int x){
        
        int low = 0;

        while( low <= high){

            int mid = low + (high - low)/2;

            if(arr[mid] == x)
                return mid;
            else if(arr[mid] > x)
                high = mid - 1;
            else
                low = mid + 1;
        }
        return -1;

    }
}
