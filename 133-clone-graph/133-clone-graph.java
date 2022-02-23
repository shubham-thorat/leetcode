/*
// Definition for a Node.
class Node {
    public int val;
    public List<Node> neighbors;
    public Node() {
        val = 0;
        neighbors = new ArrayList<Node>();
    }
    public Node(int _val) {
        val = _val;
        neighbors = new ArrayList<Node>();
    }
    public Node(int _val, ArrayList<Node> _neighbors) {
        val = _val;
        neighbors = _neighbors;
    }
}
*/

class Solution {
    private void dfs(Node node,Node copy,HashMap<Node,Node> visited){
        visited.put(node,copy);
        List<Node> nbr = node.neighbors;
        
        for(Node currnode:nbr){
            if(!visited.containsKey(currnode)){
                Node neighborcopy = new Node(currnode.val);
                
                copy.neighbors.add(neighborcopy);
                
                dfs(currnode,neighborcopy,visited);
            }
            else {
                copy.neighbors.add(visited.get(currnode));
            }
        }
    }
    public Node cloneGraph(Node node) {
        if(node == null) return null;
        HashMap<Node,Node> visited = new HashMap<>();
        
        Node copy = new Node(node.val);
        dfs(node,copy,visited);
        return copy;
    }
}