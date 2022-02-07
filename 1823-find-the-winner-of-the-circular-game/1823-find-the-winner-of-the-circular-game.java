class Solution {
    public int findTheWinner(int n, int k) {
        ArrayList<Integer> arr = new ArrayList<>();
        
        for(int i=1;i<=n;i++){
            arr.add(i);
        }
        k--;
        int currIdx = 0;
        while(n > 1){
            int index = (currIdx + k)%n;
            
            arr.remove(index);
            currIdx = index;
            n--;
        }
        
        return arr.get(0);
    }
}