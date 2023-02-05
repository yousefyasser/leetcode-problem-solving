class sortedListToBST {
   public static TreeNode sortedListToBST1(ListNode head) {
       if(head == null){
           return null;
       }

       TreeNode res = getSubRoot(head);
       constructTree(res, head);
       return res;
   }
   public static TreeNode getSubRoot(ListNode curr){
       int size = size(curr);
       ListNode tmp = curr;

       for(int i = 0; i < size/2; i++){
           tmp = tmp.next;
       }
       if(tmp == null)
            return null;

       return new TreeNode(tmp.val);
   }
   public static int size(ListNode curr){
       ListNode tmp = curr;
       int size = 0;
       while(tmp != null){
           tmp = tmp.next;
           size++;
       }
       return size;
   }
   public static void constructTree(TreeNode res, ListNode curr){
       if(curr != null){
           ListNode[] children = getChildren(res, curr);
           res.left = getSubRoot(children[0]);
           res.right = getSubRoot(children[1]);
           constructTree(res.left, children[0]);
           constructTree(res.right, children[1]);
       }
   }
   public static ListNode[] getChildren(TreeNode res, ListNode curr){
       ListNode[] children = new ListNode[2];
       children[0] = new ListNode();
       children[1] = new ListNode();
       ListNode tmp = curr;
       ListNode last = curr;
       ListNode leftChild = null;
       ListNode rightChild = null;
       boolean left = true;

        while(tmp != null){
            if(tmp.next != null) last = last.next;
            if(tmp.val == res.val){
               left = false;
               tmp = tmp.next;
               continue;
            }
            ListNode input = new ListNode(tmp.val);
            if(left){
               if(leftChild == null){
                   leftChild = input;
                   children[0] = input;
               }else{
                   leftChild.next = input;
                   leftChild = leftChild.next;
               }
           }else{
               if(rightChild == null){
                   rightChild = input;
                   children[1] = input;
               }else{
                   rightChild.next = input;
                   rightChild = rightChild.next;
               }
           }
           tmp = tmp.next;
       }
       if(res.val == curr.val){
            children[0] = null;
       }
       if(res.val == last.val){
            children[1] = null;
       }
       return children;
   }
}
