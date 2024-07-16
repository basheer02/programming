public class Exp19 {

    public static void main(String[] args) {

        try{
            int a=1/0;
            a=a+10;//To remove unused variable warning
        }catch (ArithmeticException ae){
            System.out.println(" Caught exception from try : "+ae);
        }
        try{
            throw new ArrayIndexOutOfBoundsException();
        }catch (ArrayIndexOutOfBoundsException ai){
            System.out.println(" Caught exception from throw : "+ai);
        }
        finally{
            System.out.println(" finally : always execute");
        }
    }
    
}
