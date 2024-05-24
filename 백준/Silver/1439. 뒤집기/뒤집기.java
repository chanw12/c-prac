import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;
import java.util.*;

public class Main {
    static int[] dx = {0,0,1,-1};
    static int[] dy = {1,-1,0,0};
    static int N,M;
    static int arr[][];
    public static void main(String[] args) throws IOException {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        StringTokenizer st = new StringTokenizer(br.readLine());
        String N = st.nextToken();
        char[] arr = N.toCharArray();
        int cnt1 = 0;
        int cnt2 = 0;
        for(int i=0; i<arr.length; i++) {
            if (arr[i] == '0') {
                if (i == 0 || arr[i - 1] == '1') {
                    cnt1++;
                }
            }
        }
        for(int i=0; i<arr.length; i++){
            if(arr[i] == '1'){
                if (i == 0 || arr[i-1] == '0'){
                    cnt2++;
                }
            }
        }

        System.out.println(Math.min(cnt1,cnt2));
    }
}
