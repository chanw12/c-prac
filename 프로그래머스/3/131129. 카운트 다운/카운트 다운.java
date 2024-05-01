class Solution {
    int[][] dp;
    public int[] solution(int target) {
        int[] answer = {};
        dp = new int[target+1][2];
        
        for (int t = 0; t <= target; t++)
            dp[t] = new int[] {10000000, -10000000};

        dp[0][0] = 0;
        dp[0][1] = 0;
        
        for(int i=0; i<target; i++){
            for(int s = 1; s<=20; s++){
                if( i+s > target) break;
                
                if(dp[i+s][0] > dp[i][0]+1){
                    dp[i+s][0] = dp[i][0] + 1;
                    dp[i+s][1] = dp[i][1] + 1;
                }else if(dp[i+s][0] == dp[i][0]+1 && dp[i+s][1] < dp[i][1]+1){
                    dp[i+s][1] = dp[i][1]+1;
                }
            }
            for(int d = 2;d<=40; d+=2){
                if( i+d > target) break;
                
                if(dp[i+d][0] > dp[i][0]+1){
                    dp[i+d][0] = dp[i][0] + 1;
                    dp[i+d][1] = dp[i][1];
                }else if(dp[i+d][0] == dp[i][0]+1 && dp[i+d][1] < dp[i][1]+1){
                    dp[i+d][1] = dp[i][1];
                }
            }
            for(int t = 3; t<=60;t+=3){
                if( i+t > target) break;
                
                if(dp[i+t][0] > dp[i][0]+1){
                    dp[i+t][0] = dp[i][0] + 1;
                    dp[i+t][1] = dp[i][1];
                }else if(dp[i+t][0] == dp[i][0]+1 && dp[i+t][1] < dp[i][1]+1){
                    dp[i+t][1] = dp[i][1];
                }
            }
            if (i + 50 > target) continue;

            if (dp[i][0] + 1 < dp[i + 50][0]) {
                dp[i + 50][0] = dp[i][0] + 1;
                dp[i + 50][1] = dp[i][1] + 1;
            } else if (dp[i][0] + 1 == dp[i + 50][0] && dp[i][1] + 1 > dp[i+ 50][1])
                dp[i + 50][1] = dp[i][1] + 1;
        }
        answer = dp[target];
        return answer;
    }
}