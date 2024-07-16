import javax.swing.*;
import java.awt.*;
//import java.awt.event.*;


public class TrafficLight {

    TrafficLight(){
        JFrame f = new JFrame();
          
        JPanel p = new JPanel();
        p.setBounds(200,150,125, 60);
        p.setBackground(Color.black);
        f.add(p);
    }
    public static void main(String[] args) {
        
        new TrafficLight();
    }
}
