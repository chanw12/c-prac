
import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;
import java.util.Arrays;
import java.util.StringTokenizer;

public class Main {
    static int n,k;
    static int[] mm;
    static int[] dp;
    public static void main(String[] args) throws IOException {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        StringTokenizer st = new StringTokenizer(br.readLine());

        n = Integer.parseInt(st.nextToken());
        k = Integer.parseInt(st.nextToken());
        mm = new int[n];
        dp = new int [k+1];
        for(int i=0;i<k+1;i++){
            dp[i] = 100000;
        }
        for(int i=0;i <n;i++){
            int s = Integer.parseInt(br.readLine());
            mm[i] = s;
        }
        Arrays.sort(mm);
        dp[0] = 0;
        for(int i =mm[0];i<=k;i++){
            for(int j=0;j<n;j++){
                if(i>=mm[j]){
                    dp[i] = Math.min(dp[i],dp[i-mm[j]] + 1);
                }

            }
        }
        if(dp[k] == 100000){
            System.out.println("-1");
        }else{
            System.out.println(dp[k]);

        }


    }
}
