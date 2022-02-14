class Solution {
       public int maxPoints(int points[][]) {
  
            int n = points.length;
        if(n==0||n==1||n==2)return n;
        int max = 0;
        double slope = 0;
     for(int i=0;i<n-1;i++){
         Map<Double,Integer> mp = new HashMap<>();  
         for(int j=i+1;j<n;j++){    
             //evaluate Slope
             if(points[j][0]==points[i][0])slope = Double.MAX_VALUE;
             else if(points[j][1]==points[i][1]) slope = 0;
             else slope = (double)(points[j][1]-points[i][1])/(points[j][0]-points[i][0]);
             //Check in map if present
             if(mp.containsKey(slope)) mp.put(slope,mp.get(slope)+1);
             else  mp.put(slope,2);
             //update max at every iteration
             max = Math.max(max,mp.get(slope));
         }
     }  
    return max;       
    }
}