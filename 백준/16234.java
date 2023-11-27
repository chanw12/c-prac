
import java.io.BufferedInputStream;
import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;
import java.util.*;

public class Main {
    static int N;
    static int L;
    static int R;

    static boolean[][] visited;
    static int[][] map;
    static List<int[]> list;

    static Map<Integer,Integer> summ;
    static Map<Integer,Integer> cc;

    public static void main(String[] args) throws IOException {

        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        StringTokenizer st = new StringTokenizer(br.readLine());
        N = Integer.parseInt(st.nextToken());
        L = Integer.parseInt(st.nextToken());
        R = Integer.parseInt(st.nextToken());
        map = new int[N + 1][N + 1];
        for (int i = 0; i < N; i++) {
            st = new StringTokenizer(br.readLine());
            for (int j = 0; j < N; j++) {
                map[i][j] = Integer.parseInt(st.nextToken());
            }
        }
        int result = 0;

        while (true){
            boolean isMove = false;

            visited = new boolean[N][N];

            for(int i=0;i<N;i++){
                for (int j=0; j<N;j++){
                    if(!visited[i][j]){
                        int sum = bfs(i,j);
                        if(list.size()>1){
                            isMove = true;
                            for(int[] li:list){
                                map[li[0]][li[1]] = sum/list.size();
                            }
                        }
                    }
                }
            }
            if(!isMove){
                break;
            }
            result++;
        }
        System.out.println(result);
    }

    static int bfs(int a, int b){
        Queue<int[]> queue = new LinkedList<>();
        queue.add(new int[]{a,b});
        int sum = map[a][b];
        int[] dx = {0,1,0,-1};
        int[] dy = {1,0,-1,0};
        list = new ArrayList<>();
        list.add(new int[]{a,b});
        visited[a][b] = true;
        while(!queue.isEmpty()){
            int[] current =queue.poll();
            int cura = current[0];
            int curb = current[1];
            for(int i=0;i <4;i++){
                int nx = dx[i] + cura;
                int ny = dy[i] + curb;
                if(nx>=0 && nx<N && ny>=0 && ny<N && !visited[nx][ny]
                        && L <=Math.abs(map[nx][ny]-map[cura][curb])
                        && Math.abs(map[nx][ny]-map[cura][curb])<=R){
                    queue.add(new int[]{nx,ny});
                    list.add(new int[]{nx,ny});
                    sum += map[nx][ny];
                    visited[nx][ny] = visited[cura][curb];
                }
            }

        }

        return sum;
    }
}