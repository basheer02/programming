import java.util.Scanner;

public class perimeterOfRectangle {

    static int l1,l2,w1,w2;

    perimeterOfRectangle(int a,int b,int x,int y){
        l1 = a;
        w1 = b;
        l2 = x;
        w2 = y;
    }
    public static void main(String[] args) {

        int a,b,x,y;
        Scanner sc = new Scanner(System.in);

        System.out.print("\n Enter length of first rectangle : ");
        a = sc.nextInt();
        System.out.print(" Enter width of first rectangle : ");
        b = sc.nextInt();
        System.out.print("\n Enter length of second rectangle : ");
        x = sc.nextInt();
        System.out.print(" Enter width of second rectangle : ");
        y = sc.nextInt();

        perimeterOfRectangle p = new perimeterOfRectangle(a,b,x,y);

        int p1,p2;
        p1 = 2 * (l1 + w1);
        p2 = 2 * (l2 + w2);

        System.out.print("\n Perimeter of first rectangle : "+p1);
        System.out.println("\n Perimeter of second rectangle : "+p2);

        sc.close();
    }    
}
