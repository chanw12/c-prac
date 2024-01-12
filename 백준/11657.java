

import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;
import java.sql.Array;
import java.util.*;
import java.util.stream.IntStream;

public class Main {


    public static void main(String[] args) throws IOException {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        StringTokenizer st = new StringTokenizer(br.readLine());

        int N = Integer.parseInt(st.nextToken());
        int M = Integer.parseInt(st.nextToken());

        List<Edge> edges = new ArrayList<>();

        long[] dist = new long[N+1];
        Arrays.fill(dist,Integer.MAX_VALUE);
        dist[1] = 0;
        for(int i=0;i<M;i++){
            st = new StringTokenizer(br.readLine());
            long A = Integer.parseInt(st.nextToken());
            long B = Integer.parseInt(st.nextToken());
            long C = Integer.parseInt(st.nextToken());
            if(A==B){
                continue;
            }
            edges.add(new Edge(A,B,C));
        }

        for(int i=1;i<=N;i++){

            for(Edge edge: edges){
                int start = (int) edge.start;
                int end = (int) edge.end;
                long cost = edge.cost;

                if(dist[start] == Integer.MAX_VALUE){
                    continue;
                }
                if(dist[end] > dist[start] + cost){
                    dist[end] = dist[start] + cost;
                    if(i == N){
                        System.out.println(-1);
                        System.exit(0);
                    }
                }
            }
        }
        for(int i=2;i<=N;i++){
            if(dist[i] == Integer.MAX_VALUE){
                System.out.println(-1);
            }else{
                System.out.println(dist[i]);
            }
        }








    }

    static class Edge {
        long start, end, cost;

        public Edge(long start, long end, long cost) {
            this.start = start;
            this.end = end;
            this.cost = cost;
        }
    }

}
