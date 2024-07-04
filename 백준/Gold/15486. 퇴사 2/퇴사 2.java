import org.w3c.dom.ls.LSOutput;

import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;
import java.util.*;

public class Main {


    public static void main(String[] args) throws IOException {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        StringTokenizer st = new StringTokenizer(br.readLine());

        int n = Integer.parseInt(st.nextToken());
        List<int[]> li = new ArrayList<>();
        li.add(new int[]{0,0});
        for(int i=0;i<n;i++){
            st = new StringTokenizer(br.readLine());
            int a = Integer.parseInt(st.nextToken());
            int b = Integer.parseInt(st.nextToken());
            li.add(new int[]{a,b});
        }
        int[] dp = new int[n+2];
        for(int i=0;i<n+1;i++){
            dp[i] = 0;
        }
        for(int i=1;i<n+2;i++){
            dp[i] = Math.max(dp[i],dp[i-1]);
            if(i==n+1||i+li.get(i)[0]>n+1){
                continue;
            }
            dp[i+li.get(i)[0]] = Math.max(dp[i+li.get(i)[0]],dp[i]+li.get(i)[1]);
        }
        System.out.println(dp[n+1]);


    }






}
