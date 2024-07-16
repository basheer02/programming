import javax.swing.*;
import java.awt.*;

public class SWING {

    JButton n1,n2,n3,n4,n5,add,sub,eq,reset;
        j.setVisible(true);
        j.setSize(200,200);
        jt.setEditable(false);

        n1.addActionListener(this);
        n2.addActionListener(this);
        n3.addActionListener(this);
        n4.addActionListener(this);
        n5.addActionListener(this);
        add.addActionListener(this);
        sub.addActionListener(this);
        reset.addActionListener(this);
    }

    /*public void actionPerformed(ActionEvent ae){
        JButton jb = ac.getSource();
    }*/


    public static void main(String[] args) {
        SWING s = new SWING();
    }
    
}
