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
    private void helper(TreeNode root,int targetSum,int currSum,List<Integer> path,List<List<Integer>> result){
        if(root == null) return;
        if(root.left == null && root.right == null){
            if(currSum + root.val == targetSum){
                List<Integer> temp = new ArrayList<>(path);
                temp.add(root.val);
                result.add(temp);
            }
            return;
        }
        // if(targetSum < 0) return;
        path.add(root.val);
        
        helper(root.left,targetSum,currSum + root.val ,path,result);
        helper(root.right,targetSum ,currSum + root.val,path,result);
        path.remove(path.size() - 1);
    }
    public List<List<Integer>> pathSum(TreeNode root, int targetSum) {
        List<List<Integer>> result = new ArrayList<>();
        
        helper(root,targetSum,0,new ArrayList<Integer>(),result);
        return result;
    }
}