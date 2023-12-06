import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;
import java.util.Arrays;
import java.util.StringTokenizer;

public class Main {
        static int n,m;
        static int[] parent;
    public static void main(String[] args) throws IOException {

        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        StringTokenizer st = new StringTokenizer(br.readLine());
        n = Integer.parseInt(st.nextToken());
        m = Integer.parseInt(st.nextToken());

        parent = new int[n+1];
        for(int i=0;i<=n;i++){
            parent[i] = i;
        }
        for(int i=0; i<m;i++){
            st = new StringTokenizer(br.readLine());
            int a = Integer.parseInt(st.nextToken());
            int b = Integer.parseInt(st.nextToken());
            int c = Integer.parseInt(st.nextToken());
            if(a ==0 ){
                union(b,c);
            }
            else{
                if(isSame(b,c)){
                    System.out.println("YES");
                }else{
                    System.out.println("NO");
                }
            }

        }
    }
    static int find_parent(int a){
        if(parent[a] !=a){
            a = find_parent(parent[a]);
        }
        return a;

    }
    static void union(int a,int b){
        a = find_parent(a);
        b = find_parent(b);
        if(a>b){
            parent[b] = a;
        }
        else{
            parent[a] = b;
        }

    }
    static boolean isSame(int a,int b){
        a = find_parent(a);
        b = find_parent(b);
        return a==b;
    }


}
