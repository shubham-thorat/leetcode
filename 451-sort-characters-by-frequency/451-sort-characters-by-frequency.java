class Solution {
   class Pair {
        int first;
        char second;
        Pair(int first,char second){
                this.first = first;
            this.second = second;
        }
    }
    class mysort implements Comparator<Pair>{
        public int compare(Pair p1,Pair p2){
            return p2.first - p1.first;
        }
    }
    public String frequencySort(String s) {
        HashMap<Character,Integer> count = new HashMap<>();
        for(int i=0;i<s.length();i++){
            char ch  = s.charAt(i);
            count.put(ch,count.getOrDefault(ch,0) + 1);
        }
        
        PriorityQueue<Pair> pq = new PriorityQueue<>(new mysort());
        
        for(Map.Entry<Character,Integer> entry:count.entrySet()){
            pq.offer(new Pair(entry.getValue(),entry.getKey()));
        }
        
        StringBuilder sb = new StringBuilder();
        
        while(!pq.isEmpty()){
            int val = pq.peek().first;
            char ch = pq.poll().second;
            while(val > 0){
                sb.append(ch);
                val--;
            }
        }
        return sb.toString();
    }
}