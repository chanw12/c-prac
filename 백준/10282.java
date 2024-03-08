import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;
import java.sql.Array;
import java.util.*;
import java.util.stream.IntStream;

class Node implements Comparable<Node>{
    int end;
    int weight;

    Node(int end,int weight){
        this.end = end;
        this.weight = weight;
    }
    @Override
    public int compareTo(Node o){
        return weight - o.weight;
    }
}


public class Main {

    static boolean[] check;
    static int[] dist;

    static ArrayList<ArrayList<Node>> map;





    public static void main(String[] args) throws IOException {
        BufferedReader br= new BufferedReader(new InputStreamReader(System.in));
        StringTokenizer st = new StringTokenizer(br.readLine());
        int t = Integer.parseInt(st.nextToken());

        for(int i=0;i<t;i++){
            st = new StringTokenizer(br.readLine());
            map = new ArrayList<>();
            int n = Integer.parseInt(st.nextToken());
            int d = Integer.parseInt(st.nextToken());
            int c = Integer.parseInt(st.nextToken());
            for(int k=0;k<=n;k++){
                map.add(new ArrayList<>());
            }
            check = new boolean[n+1];
            dist = new int[n+1];


            for(int j=0;j<d;j++){
                st = new StringTokenizer(br.readLine());
                int a = Integer.parseInt(st.nextToken());
                int b = Integer.parseInt(st.nextToken());
                int s = Integer.parseInt(st.nextToken());
                map.get(b).add(new Node(a,s));

            }

            dijk(c);

            int asInt = Arrays.stream(dist).filter(s->s!=Integer.MAX_VALUE).max().getAsInt();
            long count = Arrays.stream(dist).filter(s -> s != Integer.MAX_VALUE).count();
            System.out.printf("%d %d",count,asInt);
            System.out.println();


        }

    }

    public static void dijk(int start){
        Arrays.fill(dist, Integer.MAX_VALUE);
        Arrays.fill(check,false);

        PriorityQueue<Node> pq = new PriorityQueue<>();
        pq.offer(new Node(start,0));
        dist[start] = 0;

        while(!pq.isEmpty()){
            Node curNode = pq.poll();
            int current = curNode.end;



            if(!check[current]){
                check[current] = true;
                for(Node node:map.get(current)){
                    if(!check[node.end] && dist[node.end] > dist[current] + node.weight){
                        dist[node.end] = dist[current] + node.weight;
                        pq.add(new Node(node.end,dist[node.end]));
                    }
                }
            }

        }

    }




}
