public class javaClass {
    public static void main(String[] args) {
        Engineer engineer = new Engineer();
        engineer.display();
        engineer.calcSalary();
    }
}
class Employee{
         public void display(){
        System.out.println("\n Name of class is Employee ");
    }
    public void calcSalary(){
        System.out.println(" Salary of Employee is 10000 ");
    }
}

class Engineer extends Employee{

    public void display(){
        super.display();
        super.calcSalary();
        System.out.println("\n Name of class is Engineer ");
    }

    public void calcSalary(){
        System.out.println(" Salary of Engineer is 20000 \n");
    }
}
