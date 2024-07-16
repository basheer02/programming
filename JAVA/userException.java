public class userException extends Exception{

    public static void main(String[] args) {
        try{
            throw new user("Caught user defined exception ");
        }
        catch(user ue){
            System.out.println(ue.getMessage());
        }
    }
}

class user extends Exception{
    public user(String s){
        super(s);
    }
}
