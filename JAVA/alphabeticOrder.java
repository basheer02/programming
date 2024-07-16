import java.util.Scanner;

public class alphabeticOrder {
    public static void main(String[] args) {

        Scanner sc = new Scanner(System.in);
        String str;
        int n;
        System.out.println(" Enter total no.of strings : ");
        n = sc.nextInt();
        String[] alph = new String[n];
        int x = 1;
        for(int i = 0; i < n; i++){
            System.out.print(" Enter string "+x+" : ");
            str = sc.next();
            alph[i] = str;
            x++;
        }
        String temp;
        for(int i = 0; i < n;i++){
            for (int j = i + 1; j < n; j++) {
                if (alph[i].compareTo(alph[j]) > 0) {
                    temp = alph[i];
                    alph[i] = alph[j];
                    alph[j] = temp;
                }
            }
        }
        System.out.print("\n Strings in alphabetical order ");
        for(int i = 0; i < n;i++){
            System.out.println(" "+alph[i]);
        }
        sc.close();
    }
}
