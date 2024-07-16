import java.io.FileInputStream;
import java.io.FileNotFoundException;
import java.io.FileOutputStream;
import java.io.FileReader;
import java.io.FileWriter;
import java.io.IOException;

public class FileCopy extends IOException{
    public static void main(String[] args) throws IOException {
        
        int s;
        try {
            FileInputStream fis = new FileInputStream("file1.txt");
            FileOutputStream fout = new FileOutputStream("file2.txt");
            
            s = fis.read();
            System.out.println(s);
           /* while( s != -1){
                fout.write(s);
                s = fis.read();
            }*/
            fis.close();
            fout.close();
            System.out.println(" File content copied successfully ");
        } catch (FileNotFoundException e) {
            // TODO Auto-generated catch block
            e.printStackTrace();
        }

    }
}
