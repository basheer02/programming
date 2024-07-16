import java.util.Scanner;

public class primeorNot {
    public static void main(String[] args) {
        
        int num;
        boolean flag = false;
        Scanner sc = new Scanner(System.in);
        System.out.println(" ****************** \n");
        System.out.print(" Enter a number : ");
        num = sc.nextInt();

        for( int i =2; i <= num / 2; i++){
            if( num % i == 0){
                flag = true;
                break;
            }
        }
        System.out.println("\n ****************** \n");
        if(flag)
            System.out.println( num +" is not prime number ");
        else
            System.out.println(" "+ num +" is prime number");
        System.out.println("\n ****************** ");
        sc.close();
    }
}