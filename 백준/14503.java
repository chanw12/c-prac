import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;
import java.util.*;

class Town implements Comparable<Town>{
    int end;
    int weight;

    Town(int end, int weight){
        this.end = end;
        this.weight = weight;
    }
    @Override
    public int compareTo(Town arg0){
        return weight - arg0.weight;
    }
}

public class Main {

    static int[][] map;
    static int cnt;

    public static void main(String[] args) throws IOException {

        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        StringTokenizer st = new StringTokenizer(br.readLine());

        int n = Integer.parseInt(st.nextToken());
        int m = Integer.parseInt(st.nextToken());

        st = new StringTokenizer(br.readLine());

        int r = Integer.parseInt(st.nextToken());
        int c = Integer.parseInt(st.nextToken());
        int d = Integer.parseInt(st.nextToken());

        map = new int[n][m];

        for(int i=0;i<n;i++){
            st = new StringTokenizer(br.readLine());
            for(int j=0;j<m;j++){
                map[i][j] = Integer.parseInt(st.nextToken());
            }

        }
        while(true){
            if(map[r][c] == 0){
                map[r][c] = 2;
                cnt +=1;
            }
            if(!(map[r-1][c] == 0 || map[r][c-1] ==0 || map[r+1][c] ==0 || map[r][c+1]==0)){
                if(d == 0){
                    if(map[r+1][c] == 1){
                        break;
                    }
                    r+=1;
                    continue;
                } else if (d == 1) {
                    if(map[r][c-1] == 1){
                        break;
                    }
                    c-=1;
                    continue;
                }else if (d == 2) {
                    if(map[r-1][c] == 1){
                        break;
                    }
                    r-=1;
                    continue;
                }else if (d == 3) {
                    if(map[r][c+1] == 1){
                        break;
                    }
                    c+=1;
                    continue;
                }
            }

            if(map[r-1][c] == 0 || map[r][c-1] ==0 || map[r+1][c] ==0 || map[r][c+1]==0){
                d = (d - 1) < 0 ? 3 : (d - 1);
                if(d == 0){
                    if(map[r-1][c] == 0){
                        r-=1;
                    }
                } else if (d == 1) {
                    if(map[r][c+1] == 0){
                        c+=1;
                    }

                } else if (d == 2) {
                    if(map[r+1][c] == 0){
                        r+=1;
                    }

                } else if (d == 3) {
                    if(map[r][c-1] == 0){
                        c-=1;
                    }
                }
            }
        }
        System.out.println(cnt);

    }


}
