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
    public int counter;
    int solve(TreeNode root){
        
        if(root == null){
            return -1;
        }
        else if(counter == 0){
            return root.val;
        }
        
        int l = solve(root.left);
        if(l != -1){
            return l;
        }
        counter--;
        if(counter == 0){
            return root.val;
        }
        int r = solve(root.right);
        if(r != -1){
            return r;
        }
        return -1;
    }
    public int kthSmallest(TreeNode root, int k) {
        counter = k;
        return solve(root);
    }
}