import org.w3c.dom.ls.LSOutput;

import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;
import java.util.*;

public class Main {


    public static void main(String[] args) throws IOException {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        StringTokenizer st = new StringTokenizer(br.readLine());

        int N = Integer.parseInt(st.nextToken());
        List<Integer> li = new ArrayList<>();
        st = new StringTokenizer(br.readLine());
        for(int i=0;i<N;i++){
            li.add(Integer.parseInt(st.nextToken()));
        }

        long[][] dp = new long[N][21];
        dp[0][li.get(0)] = 1;
        for(int i=1; i<N-1;i++){
            for(int j=0; j<=20;j++){
                if(dp[i-1][j] != 0){
                    if(j+li.get(i) >=0 && j+li.get(i)<=20){
                        dp[i][j+li.get(i)] += dp[i-1][j];
                    }
                    if(j-li.get(i) >=0 && j-li.get(i)<=20){
                        dp[i][j-li.get(i)] += dp[i-1][j];
                    }
                }
            }
        }
        System.out.println(dp[N-2][li.get(N-1)]);


    }






}
