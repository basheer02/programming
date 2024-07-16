import java.util.Scanner;

public class DoublyLinkedList extends LinkedList{

    public static void main(String[] args) {
        
        Scanner sc = new Scanner(System.in);
        int ch,data,pos;

        LinkedList list = new LinkedList();

        do{
            System.out.print("\n\n Options \n\n 1. Insert at first \n 2. Insert at end \n 3. Insert at given position \n 4. Delete given data node\n 5. Print linked list\n 6. Length of linked list \n 0. Exit ");
            System.out.print("\n\n Enter your option : ");
            ch = sc.nextInt();

            switch(ch){
                case 0: 
                    System.out.println(" Exit from program");
                    return;
                case 1:
                    System.out.print("\n Enter data : ");
                    data = sc.nextInt();
                    list = insertAtFirst(list, data);
                    break;
                case 2:
                    System.out.print("\n Enter data : ");
                    data = sc.nextInt();
                    list = insertAtLast(list, data);
                    break;
                case 3:
                    System.out.print("\n Enter data : ");
                    data = sc.nextInt();
                    System.out.print(" Enter a position to insert : ");
                    pos = sc.nextInt();
                    if(pos > Length(list))
                        System.out.print("\n Position is greater than linked list");
                    else
                       insertAtPosition(list, data, pos);
                    break;
                case 4:
                    if( list.head == null)
                        System.out.print("\n Linked List is empty ");
                    else{
                        System.out.print("\n Enter data for delete : ");
                        data = sc.nextInt();
                        deleteNode(list, data);
                    }
                    break;
                case 5:
                    Print(list);
                    break;
                case 6:
                    int l = Length(list);
                    System.out.print("\n Length of linked list : "+l);
                    break;
                default:
                    System.out.print("\n Invalid option ");
                    break;
            }
        }while( ch >= 0 );
        sc.close();
    }
    
}

class LinkedList{

    public static class Node{

        int data;
        Node next,prev;

        Node(int d){
            
            data = d;
            next = null;
            prev = null;
        }
    }

    Node head;

    public static LinkedList insertAtFirst(LinkedList list,int d){

        Node newNode = new Node(d);
        Node ptr = list.head;
        if(ptr != null){
            newNode.next = ptr;
            ptr.prev = newNode;
        }
        list.head = newNode;
        return list;
    }

    public static LinkedList insertAtLast(LinkedList list,int d){
        
        Node newNode = new Node(d);
        Node ptr = list.head; 
        if(ptr != null){
            while(ptr.next != null)
                ptr = ptr.next;
            newNode.prev = ptr;
            ptr.next = newNode;
        }
        else
            list.head = newNode;
        return list;
    }

    public static void insertAtPosition(LinkedList list,int d,int p){
        
        Node newNode = new Node(d);
        Node ptr = list.head; 
        for( int i = 1; i < p - 1 ; i++)
            ptr = ptr.next;
        Node temp = ptr.next;
        newNode.next = temp;
        newNode.prev = ptr;
        temp.prev = newNode;
        ptr.next = newNode;
        
    }

    public static void deleteNode(LinkedList list,int d){
        
        Node ptr = list.head;
        if(ptr == null){
            System.out.print("\n Linked list is empty ");
            return;
        }
        else{
            while(ptr != null){
                if(ptr.data == d){
                    if(ptr.next == null && ptr.prev == null)
                        list.head = null;
                    else if( ptr.next == null){
                        ptr.prev.next = null;
                        ptr.prev = null;
                    }
                    else if( ptr.prev == null ){
                        list.head = ptr.next;
                        ptr.next.prev = null;
                        ptr.next = null;
                    }
                    else{
                        ptr.prev.next = ptr.next;
                        ptr.next.prev = ptr.prev;
                    }
                    System.out.print("\n "+d+" deleted from list");
                    return;
                }
                ptr = ptr.next;
            }
        }
        System.out.print("\n "+d+" not present in the list ");
    }

    public static void Print(LinkedList list){
        
        Node ptr = list.head; 
        if(ptr == null )
            System.out.print("\n Linked List is empty ");
        else{
            System.out.print("\n Linked List : ");
            System.out.print(" "+ptr.data);
            ptr = ptr.next;
            while( ptr != null){
                System.out.print(" <-> "+ptr.data);
                ptr = ptr.next;
            }
        }
    }
    public static int Length(LinkedList list){
        int l = 0;
        Node ptr = list.head;
        while(ptr != null){
            l++;
            ptr = ptr.next;
        }

        return l;
    }
}