/*
// Definition for a Node.
class Node {
    public int val;
    public Node left;
    public Node right;
    public Node next;

    public Node() {}
    
    public Node(int _val) {
        val = _val;
    }

    public Node(int _val, Node _left, Node _right, Node _next) {
        val = _val;
        left = _left;
        right = _right;
        next = _next;
    }
};
*/

class Solution {
    public Node connect(Node root) {
        if(root == null) return root;
        Queue<Node> levelnodes = new LinkedList<Node>();
        
        levelnodes.add(root);
        
        while(!levelnodes.isEmpty()){
            int len = levelnodes.size();
            
            for(int i=0;i<len;i++){
                Node top = levelnodes.poll();
                
                if(i == len - 1){
                    top.next = null;
                }
                else {
                    top.next = levelnodes.peek();
                }
                
                if(top.left != null) levelnodes.add(top.left);
                if(top.right != null) levelnodes.add(top.right);
            }
        }
        return root;
    }
}