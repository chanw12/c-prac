import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;
import java.util.*;


public class Main {

    static int[][] map;
    static final int INF = 10000000;

    public static void main(String[] args) throws IOException {

      BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
      StringTokenizer st = new StringTokenizer(br.readLine());

      int n = Integer.parseInt(st.nextToken());
      map = new int[n+1][n+1];
      for(int i=0;i<=n;i++){
          Arrays.fill(map[i],INF);
          map[i][i] = 0;
      }

      st = new StringTokenizer(br.readLine());
      int m = Integer.parseInt(st.nextToken());
      for(int i=0; i<m;i++){
          st = new StringTokenizer(br.readLine());
          int a = Integer.parseInt(st.nextToken());
          int b = Integer.parseInt(st.nextToken());
          int c = Integer.parseInt(st.nextToken());

          map[a][b] = Math.min(map[a][b],c);
      }
      for(int i=1;i<=n;i++){
          for(int j=1;j<=n;j++){
              for(int k=1;k<=n;k++){
                  map[j][k]= Math.min(map[j][k],map[j][i]+map[i][k]);
              }
          }
      }
        for (int i = 1; i <= n; i++) {
            for (int j = 1; j <= n; j++) {
                if (map[i][j] == INF) {
                    System.out.print("0 ");
                } else {
                    System.out.print(map[i][j] + " ");
                }
            }
            System.out.println();
        }


    }

}


