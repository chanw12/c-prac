import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;
import java.util.*;


public class Main {

    static class Node implements Comparable<Node> {


        int weight;
        int start;
        int end;


        public Node(int start,int end,int weight) {
            this.weight = weight;
            this.start = start;
            this.end = end;
        }
        @Override
        public int compareTo(Node o) {
            return this.weight- o.weight;
        }

    }

    static ArrayList<Node> li;
    static PriorityQueue<Node> pq;
    static int M;
    static int[] parent;
    public static void union(int a,int b){
        a = find(a);
        b = find(b);
        if(a<b) parent[b] = a;
        else parent[a] = b;
    }

    public static int find(int a){
        if(parent[a] == a){
            return a;
        }else{
            return find(parent[a]);
        }
    }

    public static void kruskal(){
        int cost = 0;
        for(int i=0;i<M;i++){
            Node node = pq.poll();
            if(find(node.start) != find(node.end)){
                cost += node.weight;
                union(node.start, node.end);
            }

        }
        System.out.println(cost);
    }


    public static void main(String[] args) throws IOException {

        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        StringTokenizer st = new StringTokenizer(br.readLine());
        pq = new PriorityQueue<>();
        int N = Integer.parseInt(st.nextToken());
        st = new StringTokenizer(br.readLine());
        M = Integer.parseInt(st.nextToken());
        parent = new int[N+1];
        for(int i=0;i<=N;i++){
            parent[i] = i;
        }

        for(int i=0;i <M;i++){
            st = new StringTokenizer(br.readLine());
            int a = Integer.parseInt(st.nextToken());
            int b = Integer.parseInt(st.nextToken());
            int c = Integer.parseInt(st.nextToken());
            Node n = new Node(a,b,c);
            pq.offer(n);
        }
        kruskal();
    }

}


