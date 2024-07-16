import java.util.Scanner;

public class classInterface implements CharSequence{

    public static int main(String[] args) {
        
        CharSequence cs;
        Scanner sc = new Scanner(System.in);
        int ch;
        
        System.out.print(" Enter a char sequence : ");
        cs = sc.next();
        do {
            System.out.println(" \n Options \n\n 1. String of char sequence \n 2. Reverse of the char sequence \n 3. Print char at specified index \n 4. Length of the char sequence \n 5. Sub sequence \n 0. Exit \n");
            System.out.print(" Enter your option : ");
            ch = sc.nextInt();
            StringBuilder sb = new StringBuilder(cs);
            CharSequence = 
            switch(ch){
                case 0:
                    return;
                case 1:
                    System.out.println("\n String of char sequence : "+sb);
                    break;
                case 2:
                    System.out.println("\n Reverse of the char sequence : "+sb.reverse());
                    break;
                case 3:
                    int i;
                    System.out.print("\n Enter index number : ");
                    i = sc.nextInt();
                    if( i >= cs.length())
                        System.out.println("\n out of index ");
                    else
                        System.out.println("\n Char at index "+i+" : "+cs.charAt(i));
                    break;
                case 4:
                    System.out.println("\n Length of char sequence : "+cs.length());
                    break;
                case 5:
                    int st,end;
                    System.out.print("\n Enter starting index number : ");
                    st = sc.nextInt();
                    System.out.print("\n Enter ending index number : ");
                    end = sc.nextInt();
                    System.out.println("\n Sub sequence : "+cs.subSequence(st,end));
                    break;
                default:
            }                       
        } while (ch >= 0 && ch < 6);
        sc.close();
    }

    @Override
    public char charAt(int index) {   
        return 0;
    }

    @Override
    public CharSequence subSequence(int start, int end) {
        
        return null;
    }

    @Override
    public int length() {
        return 0;
    }
}
