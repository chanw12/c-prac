import java.util.PriorityQueue;
import java.util.Arrays;
class Solution {
    public int solution(int[][] jobs) {
        int answer = 0;
        // 소요시간 우선순위 큐
        PriorityQueue<int[]> workQue = new PriorityQueue<>((o1,o2) -> o1[1] - o2[1]);
        // 작업 요청 시점 우선순위 큐
        PriorityQueue<int[]> inQue = new PriorityQueue<>((o1,o2) -> o1[0] - o2[0]);
        
        for(int i=0; i<jobs.length;i++){
            inQue.offer(jobs[i]);
        }
        int curTime = 0;
        while(!inQue.isEmpty()){
            int[] temp = inQue.peek();
            
            if(temp[0]<=curTime){
                temp = inQue.poll();
                workQue.offer(temp);
                continue;
            }else{
                if(workQue.isEmpty()){
                    curTime +=1;
                }
                else{
                    temp = workQue.poll();
                    curTime += temp[1];
                    answer += curTime-temp[0];                    
                }

                
            }


        }
        while(!workQue.isEmpty()){
                int[] temp = workQue.poll();
                curTime += temp[1];
                answer += curTime-temp[0];
        }
        answer /= jobs.length;
        
        return answer;
    }
}