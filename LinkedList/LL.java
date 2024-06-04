public class LL  {
    private Node head;
    private Node tail;
    private int size;
    
    public LL(){
        this.size = 0;
    }
    
    
    public void insertFirst(int val){
        Node node = new Node(val); 
        node.next = head;
        head = node;
        
        if(tail == null){
            tail = head;
        }
        size = size +1;
    }
    
    public void display() {
        Node temp = head;
        
        while(temp != null){
            System.out.print(temp.value+ "->");
            temp = temp.next;
        }
        System.out.println("end");
        
    }
    
    private static class Node {
        int value;
        Node next;
        
        public Node (int value) {
                this.value = value;
            }
        
        //  public  Node (int value, Node next) {
        //         this.value = value;
        //         this.next = next;
        //     }
    }
    
     
          public static void main(String[] args) {
        LL list = new LL();
        list.insertFirst(15);
        list.insertFirst(18);
        list.insertFirst(188);
        list.insertFirst(120);
        list.display();
    }
   
}
