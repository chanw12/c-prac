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
        for(int i=0;i <n;i++){
            int s = Integer.parseInt(br.readLine());
            mm[i] = s;
        }
        for(int i=0; i<n;i++){
            dp[0] = 1;
            for(int j=mm[i];j<=k;j++){
                dp[j] = dp[j] + dp[j-mm[i]];
            }
        }
        System.out.println(dp[k]);


    }
}
