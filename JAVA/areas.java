import java.util.Scanner;

public class areas {
    public static void main(String[] args) {

        float r,h,b;
        int l,w,ch;
        Scanner sc = new Scanner(System.in);

        do {

            System.out.print("\n Options \n\n 1 : Area of circle \n 2 : Area of rectangle \n 3 : Area of triangle \n 0 : Exit \n");
            System.out.print("\n Enter option : ");
            ch = sc.nextInt();

            switch (ch) {
                case 0:
                    System.out.println("\n Exit \n");
                    return;
                case 1:
                    System.out.print("\n Enter radius of circle : ");
                    r = sc.nextFloat();
                    double circArea = area(r);
                    System.out.print("\n Area of circle : "+circArea+"\n");
                    break;
            
                case 2:
                    System.out.print("\n Enter length of rectangle : ");
                    l = sc.nextInt();
                    System.out.print("\n Enter width of rectangle : ");
                    w = sc.nextInt();
                    int rectArea = area(l,w);
                    System.out.print("\n Area of rectangle : "+rectArea+"\n");
                    break;

                case 3:
                    System.out.print("\n Enter base of triangle : ");
                    b = sc.nextFloat();
                    System.out.print("\n Enter height of triangle : ");
                    h = sc.nextFloat();
                    float triaArea = area(b,h);
                    System.out.print("\n Area of triangle : "+triaArea+"\n");
                    break;
                default:
                    return;
            }
        } while (ch < 4);
        sc.close();
    }

    static double area(float r){
        return 3.14 * r * r;
    }

    static int area(int l,int w){
        return l * w;
    }

    static float area(float b,float h){
        return  (b * h)/2;
    }
}
