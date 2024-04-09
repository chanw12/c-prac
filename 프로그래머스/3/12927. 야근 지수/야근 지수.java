import java.util.*;

class Solution {
    public long solution(int n, int[] works) {
        long answer = 0;
        long cnt = 0;
        PriorityQueue<Integer> pq = new PriorityQueue<>(Comparator.reverseOrder());
        
        for(int i=0; i<works.length;i++){
            cnt += works[i];
            pq.offer(works[i]);
        }
        
        if(n >= cnt){
            return 0;
        }
        for(int i=0; i<n;i++){
            int k = pq.poll();
            k -= 1;
            pq.offer(k);
        }
        

        while(!pq.isEmpty()){
            int k = pq.poll();
            answer += k*k;
        }
        return answer;
    }
    

}