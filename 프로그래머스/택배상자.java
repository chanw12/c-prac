import java.util.*;
class Solution {
    public int solution(int[] order) {
        int answer = 0;
        Stack<Integer> main = new Stack<Integer>();
        Stack<Integer> sub = new Stack<Integer>();
        int ordernum = 0;
        for(int i=order.length; i>0;i--){
            main.push(i);
        }
        
        while(true){
            if(main.isEmpty()){
                break;
            }
            else if(main.peek() == order[ordernum]){
                main.pop();
                answer += 1;
                ordernum += 1;
            }

            else if(sub.isEmpty() && main.peek() != order[ordernum]){
                int temp = main.pop();
                sub.push(temp);
            }
            else if(sub.peek() == order[ordernum]){
                sub.pop();
                answer += 1;
                ordernum += 1;
            }
            else if(main.peek() != order[ordernum] && sub.peek() != order[ordernum]){
                sub.push(main.pop());
            }
        }
        
        while(!sub.isEmpty() && sub.peek() == order[ordernum]){
            sub.pop();
            answer += 1;
            ordernum += 1;
        }
        
        
        return answer;
    }
}