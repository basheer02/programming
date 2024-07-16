import java.util.Scanner;

public class multipleInheritance {
    public static void main(String[] args) {

        Scanner sc = new Scanner(System.in);
        int n;
        float m1,m2;

        System.out.print("\n Enter Roll number : ");
        n = sc.nextInt();
        System.out.print(" Enter part1 score : ");
        m1 = sc.nextFloat();
        System.out.print(" Enter part2 score : ");
        m2 = sc.nextFloat();
        sc.close();

        Result res = new Result();
        res.getNumber(n);
        res.getMarks(m1, m2);
        System.out.println("\n Student details ");
        res.display();
    }
}

interface Sport{
    int sportWt = 6;
    abstract void putWt();
}

class Student{

    int rollNumber;

    void getNumber(int n){
        rollNumber = n;
    }

    void putNumber(){
        System.out.println("\n Roll number : "+rollNumber);
    }
}

class Test extends Student{

    float part1,part2;

    void getMarks(float m1,float m2){
        part1 = m1;
        part2 = m2;
    }

    void putMarks(){
        System.out.println("\n part1 : "+part1);
        System.out.println(" part2 : "+part2);
    }
}

class Result extends Test implements Sport{

    @Override
    public void putWt() {
        System.out.println(" SportsWt : "+sportWt);
    }

    void display(){
        putNumber();
        System.out.println("\n Marks obtained ");
        putMarks();
        putWt();
        float total = sportWt + part1 + part2;
        System.out.println("\n Total Score : "+total+"\n");
    }

}