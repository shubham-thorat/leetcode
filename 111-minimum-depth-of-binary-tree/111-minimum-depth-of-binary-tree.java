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
class Solution {
    private int inf = (int)1e5;
    public int minDepth(TreeNode root) {
        if(root == null) return 0;
        if(root.left == null && root.right == null) return 1;
        int opt1 = inf,opt2 = inf;
        if(root.left != null){
            opt1 = minDepth(root.left);
        }
        
        if(root.right != null){
            opt2 = minDepth(root.right);
        }
        return Math.min(opt1,opt2) + 1;
    }
}