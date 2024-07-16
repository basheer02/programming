import java.util.Scanner;

public class detailedClass {

    
    public static void main(String[] args) {
        
        Officer officer = new Officer();
        Manager manager = new Manager();
        officer.read();
        manager.read();
        officer.print();
        manager.print();
        officer.printSalary();
    }
}

class Employee{

    int age;
    String salary,phone,name,address;

    void printSalary(){
        System.out.println("\n Salary of Employee : 25000\n");
    }
}

class Officer extends Employee{
    String spec;
    Scanner sc = new Scanner(System.in);

    void read(){
        System.out.print(" Enter Officer Details  ");
        System.out.print("\n\n Enter name of officer : ");
        name = sc.next();
        System.out.print(" Enter age of officer : ");
        age = sc.nextInt();
        System.out.print(" Enter phone number of officer : ");
        phone = sc.next();
        System.out.print(" Enter address of officer : ");
        address = sc.next();
        System.out.print(" Enter salary of officer : ");
        salary = sc.next();
        System.out.print(" Enter specialization of officer : ");
        spec = sc.next();
    }

    void print(){
        System.out.println("\n Officer Details  ");
        System.out.println("\n Name of officer : "+name);
        System.out.println(" Age of officer : "+age);
        System.out.println(" Phone number of officer : "+phone);
        System.out.println(" Address of officer : "+address);
        System.out.println(" Salary of officer : "+salary);
        System.out.print(" Specialization of officer : "+spec);
    }
}

class Manager extends Employee{

    String dep;
    Scanner sc = new Scanner(System.in);

    void read(){
        System.out.print("\n Enter Manager Details ");
        System.out.print("\n\n Enter name of manager : ");
        name = sc.next();
        System.out.print(" Enter age of manager : ");
        age = sc.nextInt();
        System.out.print(" Enter phone number of manager : ");
        phone = sc.next();
        System.out.print(" Enter address of manager : ");
        address = sc.next();
        System.out.print(" Enter department of manager : ");
        dep = sc.next();
        System.out.print(" Enter salary of manager : ");
        salary = sc.next();
    }

    void print(){
        System.out.print("\n Manager Details ");
        System.out.print("\n\n Name of officer : "+name);
        System.out.print("\n Age of officer : "+age);
        System.out.print("\n Phone number of officer : "+phone);
        System.out.print("\n Address of officer : "+address);
        System.out.print("\n Department of manager : "+dep);
        System.out.println("\n Salary of officer : "+salary);
    }
}
