import java.util.Scanner;

public class stringOperation {
    public static void main(String[] args) {
        
        Scanner sc = new Scanner(System.in);
        String str,newstr;
        int p;
        System.out.print(" Enter a string : ");
        str = sc.nextLine();
        StringBuffer sb = new StringBuffer(str);
        int ch;
        do {

            System.out.print("\n Options \n\n 1 : Insert a string at given position of the above string\n 2 : Modify character at given position of the string \n 3 : Append a string at the end of the string \n 0 : Exit \n");
            System.out.print("\n Enter option : ");
            ch = sc.nextInt();

            switch (ch) {
                case 0:
                    System.out.println("\n Exit \n");
                    return;
                case 1:
                    System.out.print("\n Enter new string : ");
                    newstr = sc.next();
                    System.out.print(" Enter position to insert the new string : ");
                    p = sc.nextInt();
                    sb.insert(p, newstr);
                    System.out.print("\n After insertion : "+sb);
                    break;

                case 2:
                    System.out.print("\n Enter a character : ");
                    char chara = sc.next().charAt(0);
                    System.out.print(" Enter position to modify character : ");
                    p = sc.nextInt();
                    sb.setCharAt(p, chara);
                    System.out.print("\n After modification : "+sb+"\n");
                    break;

                case 3:
                    System.out.print("\n Enter a new string to append at the end of the string : ");
                    newstr = sc.next();
                    sb.append(newstr);
                    System.out.print("\n After append : "+sb+"\n");
                default:
                    break;
            }
        } while(ch < 4);
        sc.close();
    }
}
