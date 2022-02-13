class Solution {
    class mysort implements Comparator<int[]> {
        public int compare(int a[],int b[]){
            return b[1] - a[1];
        }
    }
    public int[] topKFrequent(int[] nums, int k) {
        HashMap<Integer,Integer> map = new HashMap<>();
        
        for(int val:nums) map.put(val,map.getOrDefault(val,0) + 1);
        
        ArrayList<int[]> list = new ArrayList<>();
        
        for(Map.Entry<Integer,Integer> entry:map.entrySet()){
            list.add(new int[]{entry.getKey(),entry.getValue()});
        }
        Collections.sort(list,new mysort());
        
        
        int result[] = new int[k];
        for(int i=0;i<k;i++){
            result[i] = list.get(i)[0];
        }
        return result;
    }
}