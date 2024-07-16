import java.io.BufferedReader;
import java.io.FileInputStream;
import java.io.FileNotFoundException;
import java.io.FileReader;
import java.io.IOException;

public class FileLine {
    public static void main(String[] args) throws IOException {
            
        try {
            BufferedReader br = new BufferedReader(new FileReader("file1.txt"));
            /*String s = br.readLine();
            int i = 0;
            while( s != null){
                System.out.println(++i+". "+s);
                s = br.readLine();
            }
            br.close();*/
            int s =br.read();
            int l = 0, w = 0, c = 0;
            while(s != -1){
                if( s == 32)
                    w++;
                else if(s == 10)
                    l++;
                else
                    c++;
                s = br.read();
            }
            System.out.println(" "+(w+l-1)+" "+l+" "+c);
        } catch (FileNotFoundException e) {
            System.out.println(e);
        }
    }
}
