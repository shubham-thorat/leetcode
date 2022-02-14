class Solution {
    int len(int x,int y){
        return (x*x) + (y*y);
    }
    class Tuple {
        int length,x,y;
        Tuple(int l,int x,int y){
            this.length = l;
            this.x = x;
            this.y = y;
        }
    }
    
    class mysort implements Comparator<Tuple> {
        public int compare(Tuple t1,Tuple t2){
            return t2.length - t1.length;
        }
    }
    public int[][] kClosest(int[][] points, int k) {
        PriorityQueue<Tuple> pq = new PriorityQueue<>(new mysort());
        
        for(int point[]:points){
            int x = point[0] , y = point[1];
            
            pq.offer(new Tuple(len(x,y),x,y));
            if(pq.size() > k) pq.poll();
        }
        
        int result[][] = new int[pq.size()][2];
        int i = 0;
        while(!pq.isEmpty()){
            result[i] = new int[]{pq.peek().x,pq.peek().y};
            pq.poll();
            i++;
        }
        return result;
    }
}