import java.io.BufferedReader;
import java.io.BufferedWriter;
import java.io.FileReader;
import java.io.FileWriter;
import java.io.File;
import java.io.IOException;
import java.io.PrintWriter;
import java.io.RandomAccessFile;
import java.util.Scanner;
import java.util.StringTokenizer;

public class eg {
    public static void main(String[] args) throws IOException {
        
        Scanner scr = new Scanner(System.in);
        String str = null,name = null,roll,mark;

        BufferedReader bf = new BufferedReader(new FileReader("file2.txt"));
        bf.readLine();
       
        while((str = bf.readLine()) != null){
            StringTokenizer st = new StringTokenizer(str);
            while(st.hasMoreTokens()){
                name = st.nextToken();
                System.out.println(" Name of student : "+name);
                roll = st.nextToken();
                System.out.println(" Roll no.of student : "+roll);
                mark = st.nextToken();
                System.out.println(" mark of student : "+mark);
            }

            Scanner sc = new Scanner(new File("file2.txt"));
            StringBuffer sb = new StringBuffer();
            while(sc.hasNextLine())
                sb.append(sc.nextLine()+System.lineSeparator());

            if(name.equals("rinshad")){
                String newstr = sb.toString();
                newstr = newstr.replaceAll("37","34");
                FileWriter bw = new FileWriter("file2.txt");
                bw.append(newstr);
                bw.flush();
            }
            if(name.equals("subin")){
                String newstr = sb.toString();
                newstr = newstr.replaceAll("35","37");
                FileWriter bw = new FileWriter("file2.txt");
                bw.append(newstr);
                bw.flush();
            }
           // str = bf.readLine();
         //  System.out.println(sb.toString());
        }
        
    }
}
