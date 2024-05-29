import java.util.*;
class Solution {
    public long solution(int n, int[] times) {
        long answer = 0;
        Arrays.sort(times);
        long left = 0;
        long right = times[times.length-1]*(long)n;
 
        while(left<right){
            long cnt = 0;
            long mid = (left+right)/2;
            
            for(int i=0;i<times.length;i++){
                cnt += mid/times[i];
            }
            if(n<=cnt){
                right = mid;
                
            }else{
                left = mid+1;
            }
        }
        
        return left;
    }
}