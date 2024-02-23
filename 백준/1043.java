import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;
import java.util.*;

public class Main {
    static int[] parent;
    static int cnt = 0;


    public static void main(String[] args) throws IOException {

        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        StringTokenizer st = new StringTokenizer(br.readLine());

        int n = Integer.parseInt(st.nextToken());
        int m = Integer.parseInt(st.nextToken());
        parent = new int[n+1];
        for (int i = 0; i < parent.length; i++) {
            parent[i] = i;
        }

        st = new StringTokenizer(br.readLine());
        int k = Integer.parseInt(st.nextToken());

        ArrayList<Integer> li = new ArrayList<>();
        for(int i=0;i<k;i++){
            int a = Integer.parseInt(st.nextToken());
            li.add(a);
        }
        ArrayList<ArrayList<Integer>> doubleList = new ArrayList<>();
        for(int i=0;i<m;i++){
            st = new StringTokenizer(br.readLine());
            int s = Integer.parseInt(st.nextToken());
            ArrayList<Integer> si = new ArrayList<>();
            int first = Integer.parseInt(st.nextToken());
            si.add(first);
            for(int j=1;j<s;j++){
                int b = Integer.parseInt(st.nextToken());
                si.add(b);
                union(first,b);
            }
            doubleList.add(si);
        }
        Set<Integer> set = new HashSet<>();
        for(int i=0;i<li.size();i++){
            set.add(parent[li.get(i)]);
        }
        boolean check = true;
        for(int i=0;i<m;i++){
            for(int j=0;j<doubleList.get(i).size();j++){
                if(set.contains(parent[doubleList.get(i).get(j)])){
                    check = false;
                    break;
                }

            }
            if(check){
                cnt+=1;
            }
            check = true;

        }
        System.out.println(cnt);
    }

    public static void union(int a, int b){
        int x = isParent(a);
        int y = isParent(b);
        if(x !=y){
            if(x<y) {
                parent[b] = x;
                for(int i=0;i<parent.length;i++){
                    if(parent[i]==y){
                        parent[i] = x;
                    }
                }
            }
            else{
                parent[a] = y;
                for(int i=0;i<parent.length;i++){
                    if(parent[i]==x){
                        parent[i] = y;
                    }
                }
            }

        }

    }

    public static int isParent(int a){
        if (parent[a] == a) return a;
        // 거쳐간 모든 노드의 집합을 갱신함 -> 시간 복잡도 ↓
        return parent[a] = isParent(parent[a]);
    }


}
