import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;
import java.util.*;

public class Main {

    static int M,N,L,count;


    public static void main(String[] args) throws IOException {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        StringTokenizer st = new StringTokenizer(br.readLine());
        M = Integer.parseInt(st.nextToken());
        N = Integer.parseInt(st.nextToken());
        L = Integer.parseInt(st.nextToken());
        Node[] n = new Node[N];
        int[] saro = Arrays.stream(br.readLine().split(" ")).mapToInt(i -> Integer.parseInt(i)).toArray();
        Arrays.sort(saro);
        for(int i=0;i<N;i++){
            st = new StringTokenizer(br.readLine());
            int a = Integer.parseInt(st.nextToken());
            int b = Integer.parseInt(st.nextToken());
            int left=0;
            int right = saro.length-1;
            int mid = (left + right)/2;
            while(left<=right){
//                System.out.printf("%s %s",a,b);
//                System.out.println();
//                System.out.println(String.format("left: %s right:%s",left,right));

                if(Math.abs(a-saro[mid])+b <=L){
//                    System.out.println(String.format("%s %s %s",a,b,mid));
                    count++;
                    break;
                } else if(a-saro[mid] <0){
                    right = mid-1;
                    mid = (left+right)/2;
                } else {
                    left = mid+1;
                    mid = (left+right)/2;
                }
            }
        }
        System.out.println(count);

    }
    static class Node{
        int x;
        int y;

        public Node(int x, int y) {
            this.x = x;
            this.y = y;
        }
    }
}