class Solution {
    static int result = 0;
    public int solution(int[] numbers, int target) {
        int answer = 0;
        dfs(numbers,numbers[0],0,target,numbers.length);
        dfs(numbers,-numbers[0],0,target,numbers.length);
        return result;
    }
    public void dfs(int[] numbers,int num, int cnt,int target,int targetcnt){ // cnt 는 횟수 
        if(cnt == targetcnt-1){
            if(num == target){
                result += 1;
            }
            
        }else{
            dfs(numbers,num+numbers[cnt+1],cnt+1,target,targetcnt);
            dfs(numbers,num-numbers[cnt+1],cnt+1,target,targetcnt);
        }
    }
}