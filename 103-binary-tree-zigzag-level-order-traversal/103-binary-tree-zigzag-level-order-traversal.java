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
    public List<List<Integer>> zigzagLevelOrder(TreeNode root) {
        if(root == null) return new ArrayList<>();
        List<List<Integer>> zigzag = new ArrayList<>();
        Queue<TreeNode> levelnodes = new LinkedList<>();
        levelnodes.add(root);
        int level = 0;
        while(!levelnodes.isEmpty()){
            int len = levelnodes.size();
            ArrayList<Integer> temp = new ArrayList<>();
            for(int i=0;i<len;i++){
                TreeNode top = levelnodes.poll();
                temp.add(top.val);
                if(top.left != null) {
                    levelnodes.add(top.left);
                }
                if(top.right != null) {
                    levelnodes.add(top.right);
                }
            }
            if(level % 2 != 0){
                Collections.reverse(temp);
            }
            zigzag.add(temp);
            level++;
        }
        return zigzag;
    }
}