import java.lang.Math;
class Solution {
    public int solution(int[] a) {
        int answer = 2;
        int[] left = new int[a.length];
        int[] right = new int[a.length];
        left[0] = a[0];
        for(int i=1; i<a.length;i++ ){
            left[i] = Math.min(left[i-1],a[i]);
        }
        
        right[a.length-1] = a[a.length-1];
        for(int i=a.length-2;i>=0;i--){
            right[i]= Math.min(right[i+1],a[i]);
        }
        
        for(int i=1;i<a.length-1;i++){
            if(a[i] == left[i] || right[i] == a[i]){
                answer +=1;
            }
        }

        return answer;
    }
}