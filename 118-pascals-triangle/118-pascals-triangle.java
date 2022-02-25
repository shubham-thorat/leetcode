class Solution {
    public List<List<Integer>> generate(int numRows) {
        List<List<Integer>> list = new ArrayList<>();
        List<Integer> curr = null;
        
        for(int i=0;i<numRows;i++){
            curr = new ArrayList<Integer>();
            
            for(int j=0;j<=i;j++){
                if(j == 0 || j == i){
                    curr.add(1);
                }
                else {
                    curr.add(list.get(i-1).get(j-1) + list.get(i-1).get(j));
                }
            }
            list.add(curr);
        }
        return list;
    }
}