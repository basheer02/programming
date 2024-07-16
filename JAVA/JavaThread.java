public class JavaThread{
    public static void main(String[] args) {
        
        Fibonacci f = new Fibonacci();
        Reverse r = new Reverse();
        try {
            f.start();
            f.join();
            r.start();
            r.join();
        } catch (InterruptedException e) {
            System.out.println(e);
        }
    }
}

class Fibonacci extends Thread{

    int n1 = 0,n2 = 1,sum;
    public void run(){
        System.out.println("\n 10  terms of fibonacci series \n");
        System.out.println(" "+n1+"\n "+n2);
        for(int i = 3; i <= 10; i++){

            sum = n1 + n2;
            n1 = n2;
            n2 = sum;
            System.out.println(" "+sum);
        }
    }
}

class Reverse extends Thread{

    public void run(){

        System.out.println("\n Reverse order of 1 to 10 \n");
        for(int i = 10; i > 0; i--){
            System.out.println(" "+i);
        }
    }
}
