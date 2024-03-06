
import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;
import java.sql.Array;
import java.util.*;

class Node implements Comparable<Node>{
    int end;
    int weight;

    Node(int end,int weight){
        this.end = end;
        this.weight = weight;
    }

    public int compareTo(Node o){
        return weight - o.weight;
    }
}


public class Main {

    static int n,e;
    static ArrayList<ArrayList<Node>> li;

    static int[] dist;
    static boolean[] check;

    static final int INF = 200000000;


    public static void main(String[] args) throws IOException {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        StringTokenizer st = new StringTokenizer(br.readLine());

        n = Integer.parseInt(st.nextToken());
        e = Integer.parseInt(st.nextToken());


        li = new ArrayList<>();
        dist = new int[n+1];
        check = new boolean[n+1];
        Arrays.fill(dist,INF);
        for(int i=0;i<=n;i++){
            li.add(new ArrayList<Node>());
        }

        for(int i=0;i<e;i++){
            st = new StringTokenizer(br.readLine());
            int a = Integer.parseInt(st.nextToken());
            int b = Integer.parseInt(st.nextToken());
            int c = Integer.parseInt(st.nextToken());

            li.get(a).add(new Node(b,c));
            li.get(b).add(new Node(a,c));

        }
        st = new StringTokenizer(br.readLine());
        int v1 = Integer.parseInt(st.nextToken());
        int v2 = Integer.parseInt(st.nextToken());

        int cnt1 = 0;
        cnt1 += dijk(1,v1);
        cnt1+= dijk(v1,v2);
        cnt1+= dijk(v2,n);

        int cnt2=0;
        cnt2 += dijk(1,v2);
        cnt2+= dijk(v2,v1);
        cnt2 += dijk(v1,n);


        int rst = (cnt1>= INF && cnt2>=INF) ? -1:Math.min(cnt1,cnt2);

        System.out.println(rst);


    }

    public static int dijk(int start, int end){
        Arrays.fill(dist,INF);
        Arrays.fill(check,false);

        PriorityQueue<Node> pq = new PriorityQueue<>();
        pq.add(new Node(start,0));
        dist[start] = 0;
        while(!pq.isEmpty()){
            Node curNode = pq.poll();
            int cur = curNode.end;

            if(!check[cur]){
                check[cur] = true;
                for(Node node:li.get(cur)){
                    if(!check[node.end] && dist[node.end]>dist[cur]+node.weight){
                        dist[node.end] = dist[cur]+node.weight;
                        pq.add(new Node(node.end,dist[node.end]));
                    }
                }
            }
        }
        return dist[end];


    }


}
