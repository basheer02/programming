
public class garbageCollector{
    
    public static void main(String[] args) {

        Test s1 = new Test();
        Test s2 = new Test();
        s1 = s2 = null;
        System.gc();
        s1 = s2;
    }
}

class Test{
    @Deprecated
    protected void finalize(){
        System.out.println("object is garbage collected");
    }  
}