import java.util.Random;

public class Thread1 {
    public static void main(String[] args) {
        
        randomThread r = new randomThread();
        r.start();
    }
}

class randomThread extends Thread{

    public void run(){

        Random random = new Random();

        for( int i = 0 ; i < 5; i++){

            int number = random.nextInt(100);
            System.out.println("\n Random number : "+number);
           
            try{
                if( number % 2 == 0){
                    squareThread sq = new squareThread(number);
                    System.out.print(" Square of "+number+" : ");
                    sq.start();
                }
                else{
                    cubeThread cb = new cubeThread(number);
                    System.out.print(" Cube of "+number+" : ");
                    cb.start();
                }
                Thread.sleep(1000);
            }catch (InterruptedException e) {
                e.printStackTrace();
            }
        }
    }

    synchronized void display(int n){
        System.out.print(n);
    }
}

class squareThread extends Thread{
    
    int number;
    randomThread r = new randomThread();

    squareThread(int n){
        number = n;
    }

    public void run(){
        r.display(number*number);
    }
}

class cubeThread extends Thread{

    int number;
    randomThread r = new randomThread();

    cubeThread(int n){
        number = n;
    }

    public void run(){
        r.display(number*number*number);
    }

}
