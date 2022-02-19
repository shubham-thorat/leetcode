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
    int diameter = 0;
    int solve(TreeNode root){
        if(root == null) return 0;
        
        int l = solve(root.left);
        int r = solve(root.right);
        diameter = Math.max(diameter,l + r);
        return Math.max(l,r) + 1;
    }
    public int diameterOfBinaryTree(TreeNode root) {
        if(root == null) return 0;
        solve(root);
        return diameter;
    }
}