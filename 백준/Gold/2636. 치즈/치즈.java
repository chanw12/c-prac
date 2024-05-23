import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;
import java.util.*;

public class Main {
    static int[] dx = {0,0,1,-1};
    static int[] dy = {1,-1,0,0};
    static int N,M;
    static int arr[][];
    public static void main(String[] args) throws IOException {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        StringTokenizer st = new StringTokenizer(br.readLine());
        N = Integer.parseInt(st.nextToken());
        M = Integer.parseInt(st.nextToken());
        arr = new int[N][M];
        for(int i=0;i <N;i++){
            st = new StringTokenizer(br.readLine());

            for(int j=0; j<M;j++){
                arr[i][j] = Integer.parseInt(st.nextToken());
            }
        }
        int cnt = 0;
        List<Integer> cheez = new ArrayList<>();
        if(check()==0){
            System.out.println(0);
            System.out.println(0);
            return;
        }
        cheez.add(check());
        while(true){
            bfs(0,0);
            cnt +=1;
            cheez.add(check());
            if(cheez.get(cheez.size()-1)==0){
                break;
            }
        }
        if(cnt == 1){
            System.out.println(cnt);
            System.out.println(cheez.get(0));
        }else{
            System.out.println(cnt);
            System.out.println(cheez.get(cheez.size()-2));
        }

    }
    public static void bfs(int x,int y){
        boolean[][] visited = new boolean[N][M];
        Queue<int[]> queue = new LinkedList<>();
        queue.offer(new int[]{x,y});
        visited[x][y] = true;
        while(!queue.isEmpty()){
            int[] current = queue.poll();
            int a = current[0];
            int b = current[1];
            for(int i=0; i<4;i++){
                int nx = a + dx[i];
                int ny = b + dy[i];
                if(nx>=0 && ny>=0 && nx<N && ny<M){
                    if(arr[nx][ny] == 0 && !visited[nx][ny]){
                        visited[nx][ny] = true;
                        arr[nx][ny] = -1;
                        queue.offer(new int[]{nx,ny});

                    } else if (arr[nx][ny] == 1 && !visited[nx][ny]){
                        visited[nx][ny] = true;
                        arr[nx][ny] = -1;
                    } else if (arr[nx][ny] == -1 && !visited[nx][ny]) {
                        visited[nx][ny] = true;
                        queue.offer(new int[]{nx,ny});
                    }
                }
            }


        }

    }
    public static int check(){
        int cnt  =0;
        for(int i=0;i<N;i++){
            for(int j=0;j<M;j++){
                if(arr[i][j] == 1){
                    cnt+=1;
                }
            }
        }
        return cnt;
    }
}
