import java.util.Scanner;

public class arraySmallest {
    public static void main(String[] args) {
        
        int n;
        Scanner sc = new Scanner(System.in);
        System.out.print(" Enter size of array : ");
        n = sc.nextInt();

        int[] number = new int[n];
        System.out.print(" Enter array elements : ");
        for (int i = 0; i < n; i++) {
            number[i] = sc.nextInt();
        }
        int lower = number[0];
        int result = 0;
        for (int i = 0; i < n-1; i++) {
            if( lower > number[i+1]){
                result = lower;
                lower = number[i+1];
            }
            else{ 
                if(result == 0){
                    result = number[i+1];
                }
                if(result > number[i+1])
                    result = number[i+1];
            }
        }

        System.out.print(" 2nd smallest number in array elements : "+result);
        System.out.println("\n");
        sc.close();
    }
}