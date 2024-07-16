import java.util.Scanner;

public class Pallindrome_Not {

    public static void main(String[] args) {
        Scanner sc = new Scanner(System.in);
        String s,rev = "";
        System.out.print(" Enter a string : ");
        s = sc.next();
        for(int i = s.length() - 1; i >= 0; i--){
            rev = rev + s.charAt(i);
        }
        if(s.equals(rev))
            System.out.print(" Pallindrome ");
        else
            System.out.print(" Not pallindrome ");
    }    
}
