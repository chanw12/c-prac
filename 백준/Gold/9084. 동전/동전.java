import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;
import java.util.*;

public class Main {

    public static void main(String[] args) throws IOException {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        StringTokenizer st = new StringTokenizer(br.readLine());

        int T = Integer.parseInt(st.nextToken());
        for(int i = 0; i < T; i++) {
            st = new StringTokenizer(br.readLine());
            int N = Integer.parseInt(st.nextToken());

            int[] coins = new int[N];
            st = new StringTokenizer(br.readLine());
            for(int j = 0; j < N; j++) {
                coins[j] = Integer.parseInt(st.nextToken());
            }
            st = new StringTokenizer(br.readLine());
            int M = Integer.parseInt(st.nextToken());

            int[] dp = new int[M + 1];
            dp[0] = 1;  // 0원을 만드는 방법은 1가지 (아무 동전도 사용하지 않는 경우)

            for(int coin : coins) {
                for(int amount = coin; amount <= M; amount++) {
                    dp[amount] += dp[amount - coin];
                }
            }
            System.out.println(dp[M]);
        }
    }
}
