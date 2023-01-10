public class ListNode {
    int val;
    ListNode next;
    ListNode() {
        
    }
    ListNode(int val) { 
        this.val = val; 
    }
    ListNode(int val, ListNode next) { 
        this.val = val; 
        this.next = next; 
    }
    
    public String toString() {
        String s = "";
        ListNode curr = this;
        while(curr != null){
            s += curr.val+" ";
            curr = curr.next;
        }
        return s;
    }
}
