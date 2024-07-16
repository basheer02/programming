public class Thread2 {
    public static void main(String[] args) {
        
        oddNumber odd = new oddNumber();
        evenNumber even = new evenNumber();
        Thread t1 = new Thread(odd);
        Thread t2 = new Thread(even);
        try {
            t1.start();
            t1.join(); // make sure t1 is terminated. if t1 is interrupted it throws exception
            Thread.sleep(1000);
            t2.start();
            t2.join();
        } catch(InterruptedException e) {
            e.printStackTrace();
        }
    }
}


class oddNumber implements Runnable{

    public void run(){
        
        System.out.println(" ODD NUMBERS UPTO 100 \n");
        for(int i = 1; i <= 100; i = i+2){
            System.out.println("\t"+i);
        }
    }
}

class evenNumber implements Runnable{

    public void run() {
        System.out.println("\n EVEN NUMBERS UPTO 100 \n");
        for(int i = 2; i <= 100; i = i+2){
            System.out.println("\t"+i);
        }
    }
}
