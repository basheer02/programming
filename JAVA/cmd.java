import java.io.BufferedReader;
import java.io.BufferedWriter;
import java.io.FileInputStream;
import java.io.FileOutputStream;
import java.io.FileReader;
import java.io.FileWriter;
import java.io.IOException;

public class cmd {
    public static void main(String[] args) throws IOException{

         StringBuffer bf = new StringBuffer();
 
        for(int i =0;i<args.length;i++)
            bf.append(args[i] + " ");  
                      //System.out.println(args[i]);
        try {
          //  String[] v = bf.

            BufferedWriter bb = new BufferedWriter(new FileWriter("file1.txt"));
      //  bb.write(bf);
      //  StringBuffer sb = new StringBuffer("null");
        bb.append(bf);
        bb.flush();
        

        BufferedWriter bd = new BufferedWriter(new FileWriter("file3.txt"));
        BufferedReader br = new BufferedReader(new FileReader("file1.txt"));
        //String s = br.readLine();
        String s;
        int i = 0;
        while((s=br.readLine())!=null)
        {
            bd.write(++i+"."+s);
            //s = br.readLine();
            
        }
    
        bd.flush();
        
        } catch (Exception e) {
            //TODO: handle exception
        }
        
    }
}
