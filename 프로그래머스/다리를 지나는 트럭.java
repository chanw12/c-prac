
import java.util.*;
class Solution {
    public int solution(int bridge_length, int weight, int[] truck_weights) {
        int answer = 0;
        Queue<Integer> queue = new LinkedList<>();
        int temp = 0;
        int temp2 = 0;
        int[] time = new int[truck_weights.length];
        int cur_time = 0;
        while(temp < truck_weights.length){
            if(queue.stream().mapToInt(Integer::intValue).sum() + truck_weights[temp]<=weight){
                queue.offer(truck_weights[temp]); 
                time[temp] = cur_time+bridge_length;
                temp +=1;
            }

            
            cur_time+=1;
            if(time[temp2] <= cur_time){
                temp2 +=1;
                queue.poll();
            }
        }
        
        return time[truck_weights.length-1]+1;
    }
}