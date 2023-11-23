
import java.io.BufferedInputStream;
import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;
import java.util.*;

public class Main {
    static int n;
    static int m;

    static int[] visited;
    static int answer;

    public static void main(String[] args) throws IOException {

        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        StringTokenizer st = new StringTokenizer(br.readLine());
        n = Integer.parseInt(st.nextToken());
        m = Integer.parseInt(st.nextToken());

        if(n>m){
            System.out.println(n-m);
        }else{
            visited = new int[m*3];
            for(int i=0; i<=m*2;i++){
                visited[i] = Integer.MAX_VALUE;
            }
            bfs(n);
            System.out.println(answer);

        }


    }

    static void bfs(int a){
        Queue<Integer> queue = new LinkedList<Integer>();
        queue.add(a);
        visited[a] = 0;

        while(!queue.isEmpty()){
            int x = queue.poll();
            if(x == m){
               answer = visited[x];
            }
            if(x<m && visited[x*2] > visited[x]){
                queue.add(x*2);
                visited[x*2] = Math.min(visited[x],visited[x*2]);
            }

            if(x>0 && x<m){
                if(visited[x+1] > visited[x]+1){
                    queue.add(x+1);
                    visited[x+1] = Math.min(visited[x]+1,visited[x+1]);
                }
                if(visited[x-1] > visited[x]+1){
                    queue.add(x-1);
                    visited[x-1] = Math.min(visited[x]+1,visited[x-1]);
                }

            }else if(x==0){
                if(visited[x+1] > visited[x]+1){
                    queue.add(x+1);
                    visited[x+1] = Math.min(visited[x]+1,visited[x+1]);

                }
            }else if(x>m){
                if(visited[x-1] > visited[x]+1){
                    queue.add(x-1);
                    visited[x-1] = visited[x]+1;
                }
            }

        }
    }




}
