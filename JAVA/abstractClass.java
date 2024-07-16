import java.util.Scanner;

public class abstractClass {
    public static void main(String[] args) {
        
        Scanner sc = new Scanner(System.in);
        int ch;
        do{
            System.out.print("\n Options \n\n 1 : Rectangle \n 2 : Triangle \n 3 : Hexagon \n 0 : Exit \n");
            System.out.print("\n Enter option : ");
            ch = sc.nextInt();
            switch(ch){
                case 0:
                    return;
                case 1:
                    Shape r = new Rectangle();
                    r.numberofSides();
                    break;
                case 2:
                    Shape t = new Triangle();
                    t.numberofSides();
                    break;
                case 3:
                    Shape h = new Hexagon();
                    h.numberofSides();
                    break;
            }

        }while(ch >=0 && ch < 4);
    }
}

abstract class Shape{
   abstract void numberofSides();
}

class Rectangle extends Shape{
    void numberofSides(){
        System.out.println(" number of sides in rectangle is 4");
    }
}

class Triangle extends Shape{
    void numberofSides(){
        System.out.println(" number of sides in triangle is 3");
    }
}

class Hexagon extends Shape{
    void numberofSides(){
        System.out.println(" number of sides in hexagon is 6");
    }
}
