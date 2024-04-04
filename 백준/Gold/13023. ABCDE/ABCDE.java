import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;
import java.lang.reflect.Array;
import java.util.*;


public class Main {
    static boolean[] visited;
    static int answer;
    static int temp  =0;
    static int[][] map;
    static List<List<Integer>> li;
    static final int INF = 10000000;

    public static void main(String[] args) throws IOException {

     BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
     StringTokenizer st = new StringTokenizer(br.readLine());

     li = new ArrayList<>();

     int N = Integer.parseInt(st.nextToken());
     int M = Integer.parseInt(st.nextToken());
     visited = new boolean[N+1];

     for(int i =0;i<N;i++){
        li.add(new ArrayList<>());
     }

     for(int i=0; i< M;i++){
         st = new StringTokenizer(br.readLine());
         int a = Integer.parseInt(st.nextToken());
         int b = Integer.parseInt(st.nextToken());
         li.get(a).add(b);
         li.get(b).add(a);
     }
     int chan = 0;

     for(int i=0; i<N;i++){
         visited[i] = true;
         dfs(i, 0);
         if(answer == 1){
             break;
         }
         Arrays.fill(visited,false);
     }
     System.out.println(answer);
    }

    public static void dfs(int s,int cnt){
        if(cnt >=4 || answer == 1){
            answer = 1;
            return;
        }
        for(int i=0;i<li.get(s).size();i++){
            int k = li.get(s).get(i);
            if(!visited[k]){
                visited[k] = true;
                dfs(k,cnt+1);
                visited[k] = false;
            }
        }

    }



}


