/**
 * Definition for a binary tree node.
 * public class TreeNode {
 *     int val;
 *     TreeNode left;
 *     TreeNode right;
 *     TreeNode(int x) { val = x; }
 * }
 */
public class Codec {

    // Encodes a tree to a single string.
    public String serialize(TreeNode root) {
        if(root == null) return "N,";
        
        StringBuilder sb = new StringBuilder(String.valueOf(root.val));
        sb.append(",");
        sb.append(serialize(root.left));
        sb.append(serialize(root.right));
        return sb.toString();
    }
    int idx = 0;
    private TreeNode solve(String str[]){
        if(idx == str.length) return null;
        if(str[idx].equals("N")) return null;
        
        TreeNode root = new TreeNode(Integer.valueOf(str[idx]));
        idx++;
        root.left = solve(str);
        idx++;
        root.right = solve(str);
        return root;
        
    }
    // Decodes your encoded data to tree.
    public TreeNode deserialize(String data) {
        String str[] = data.split(",");
        
        return solve(str);
    }
}

// Your Codec object will be instantiated and called as such:
// Codec ser = new Codec();
// Codec deser = new Codec();
// TreeNode ans = deser.deserialize(ser.serialize(root));