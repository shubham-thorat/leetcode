/**
 * Definition for a binary tree node.
 * public class TreeNode {
 *     int val;
 *     TreeNode left;
 *     TreeNode right;
 *     TreeNode() {}
 *     TreeNode(int val) { this.val = val; }
 *     TreeNode(int val, TreeNode left, TreeNode right) {
 *         this.val = val;
 *         this.left = left;
 *         this.right = right;
 *     }
 * }
 */
class BSTIterator {
    ArrayList<Integer> inorder;
    int curr;
    private void Inorder(TreeNode root){
        if(root == null) return;
        Inorder(root.left);
        inorder.add(root.val);
        Inorder(root.right);
    }
    public BSTIterator(TreeNode root) {
        inorder = new ArrayList<>();
        curr = 0;
        Inorder(root);
    }
    
    public int next() {
        curr += 1;
        return inorder.get(curr - 1);
    }
    
    public boolean hasNext() {
        return (curr != inorder.size());
    }
}

/**
 * Your BSTIterator object will be instantiated and called as such:
 * BSTIterator obj = new BSTIterator(root);
 * int param_1 = obj.next();
 * boolean param_2 = obj.hasNext();
 */