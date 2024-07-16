import java.util.Scanner;

public class Colours extends LinkedList{
    public static void main(String[] args) {

        LinkedList list1 = new LinkedList();
        LinkedList list2 = new LinkedList();
        int n;
        String s;
        Scanner sc = new Scanner(System.in);
        System.out.print(" Enter no.of colours in sets : ");
        n = sc.nextInt();
        for(int i = 0; i < 2; i++){
            System.out.println(" Enter colours to set");
            for(int j = 1; j <= n; j++){
                System.out.print(" Enter colour "+j+" : ");
                s = sc.next();
                if( i == 0)
                    list1 = Insert(list1,s);
                else
                    list2 = Insert(list2,s);
            }
        }
        System.out.println("\n Common colours ");
        Compare(list1,list2);
        sc.close();
    }
}

class LinkedList{

    public static class Node{
        String data;
        Node next;
    }

    Node head;

    public static LinkedList Insert(LinkedList list,String d){

        Node newNode = new Node();
        newNode.data = d;
        newNode.next = null;

        if(list.head == null)
            list.head = newNode;
        else{
            Node last = list.head;
            while(last.next != null)
                last = last.next;
            last.next = newNode;
        }
        return list;
    }

    public static void Compare(LinkedList list1,LinkedList list2){
        Node l1 = list1.head;
        Node l2 = list2.head;

        while(l1 != null){
            while(l2 != null){
                if(l1.data.equals(l2.data)){
                    System.out.println(" "+l1.data);
                }
                l2 = l2.next;
            }
            l2 = list2.head;
            l1 = l1.next;
        }
    }
}

