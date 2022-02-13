class Solution {
    class mysort implements Comparator<Integer> {
        public int compare(Integer a,Integer b){
            return b-a;
        }
    }
    public int findKthLargest(int[] nums, int k) {
        PriorityQueue<Integer> pq = new PriorityQueue<>(new mysort());
        
        for(int val:nums) pq.offer(val);
        
        k--;
        while(k > 0){
            // pq.poll();
            System.out.println(pq.poll());
            k--;
        }
        
        return pq.peek();
    }
}