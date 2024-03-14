import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;
import java.util.*;


public class Main {

    static class Node implements Comparable<Node> {

        int weight;
        int x;
        int y;

        public Node(int x,int y,int weight) {
            this.weight = weight;
            this.x = x;
            this.y = y;
        }
        @Override
        public int compareTo(Node o) {
            return this.weight- o.weight;
        }

    }


    static int[][] dist;
    static boolean[][] check;

    static ArrayList<ArrayList<Integer>> map;

    static int[] dx = {0,1,0,-1};
    static int[] dy = {1,0,-1,0};
    static int T;


    public static void main(String[] args) throws IOException {



            BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
            StringTokenizer st = new StringTokenizer(br.readLine());

            T = Integer.parseInt(st.nextToken());
            int cnt = 1;
            while(T != 0){

                map = new ArrayList<>();
                for(int i=0;i<T;i++){
                    st = new StringTokenizer(br.readLine());
                    ArrayList<Integer> li = new ArrayList<>();

                    for(int j=0; j<T;j++){
                        int a = Integer.parseInt(st.nextToken());
                        li.add(a);
                    }
                    map.add(li);
                }
                dist = new int[T+1][T+1];
                check = new boolean[T+1][T+1];
                for(int i=0;i<T+1;i++) {
                    Arrays.fill(dist[i],Integer.MAX_VALUE);
                    Arrays.fill(check[i],false);
                }
                dijk();
                System.out.printf("Problem %d: %d\n",cnt,dist[T-1][T-1]);
                cnt+=1;
                st = new StringTokenizer(br.readLine());
                T = Integer.parseInt(st.nextToken());
            }
            




        }
        public static void dijk() {
            int x = 0;
            int y =0;
            int cweight = map.get(x).get(y);

            dist[x][y] = cweight;
            PriorityQueue<Node> pq = new PriorityQueue<Node>();
            pq.offer(new Node(x,y,cweight));

            while(!pq.isEmpty()) {

                Node node = pq.poll();
                if(!check[node.x][node.y]) {
                    check[node.x][node.y] = true;
                    for(int i=0;i<4;i++) {
                        int nx = node.x + dx[i];
                        int ny = node.y + dy[i];
                        if(nx>=0 && nx<T && ny >=0 && ny<T) {
                            if(!check[nx][ny] && dist[nx][ny]>dist[node.x][node.y]+ map.get(nx).get(ny)) {
                                dist[nx][ny] = dist[node.x][node.y]+map.get(nx).get(ny);
                                pq.add(new Node(nx,ny,dist[nx][ny]));
                            }

                        }
                    }
                }




            }



        }

    }


