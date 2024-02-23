
import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;
import java.sql.Array;
import java.util.*;
import java.util.stream.IntStream;

public class Main {

    static int[][] dist;


    public static void main(String[] args) throws IOException {

        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        StringTokenizer st = new StringTokenizer(br.readLine());
        int n = Integer.parseInt(st.nextToken());
        int k = Integer.parseInt(st.nextToken());

        dist = new int[n+1][n+1];

        for(int i=1;i <=n;i++){
            for(int j=1;j<=n;j++){
                if(i==j){
                    dist[i][j] = 0;
                    continue;
                }
                dist[i][j] = 100_000_000;
            }
        }
        for(int i=0;i<k;i++){
            st = new StringTokenizer(br.readLine());
            int a = Integer.parseInt(st.nextToken());
            int b = Integer.parseInt(st.nextToken());
            int cost = 1;
            dist[a][b] = Math.min(dist[a][b],cost);
        }

        for (int p =1; p<=n;p++){
            for(int i=1;i<=n;i++){
                for(int j=1;j<=n;j++){
                    dist[i][j] = Math.min(dist[i][j],dist[i][p]+dist[p][j]);
                }
            }
        }
        st = new StringTokenizer(br.readLine());
        int s = Integer.parseInt(st.nextToken());

        for(int i=0;i<s;i++){
            st = new StringTokenizer(br.readLine());
            int a = Integer.parseInt(st.nextToken());
            int b = Integer.parseInt(st.nextToken());
            if(dist[a][b] == 100_000_000 && dist[b][a] == 100_000_000){
                System.out.println(0);
            } else if (dist[a][b] == 100_000_000 && dist[b][a] != 100_000_000) {
                System.out.println(1);
            }else {
                System.out.println(-1);
            }

        }
        


    }

}
