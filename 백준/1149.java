import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;
import java.util.*;

public class Main {
    static int[][] rgb;
    static int cnt = 0;
    static int[][] house;


    public static void main(String[] args) throws IOException {

        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        StringTokenizer st = new StringTokenizer(br.readLine());

        int n = Integer.parseInt(st.nextToken());
        rgb = new int[n][3];
        house = new int[n][3];
        for(int i=0;i<n;i++){
            st = new StringTokenizer(br.readLine());
            int r = Integer.parseInt(st.nextToken());
            int g = Integer.parseInt(st.nextToken());
            int b = Integer.parseInt(st.nextToken());

            int[] temp = {r,g,b};
            rgb[i] = temp;
        }

        for(int i=0; i<n;i++){
            if(i==0){
                house[i][0] = rgb[i][0];
                house[i][1] = rgb[i][1];
                house[i][2] = rgb[i][2];
            }else{
                house[i][0] =Math.min(house[i-1][1]+rgb[i][0],house[i-1][2]+rgb[i][0]);
                house[i][1] =Math.min(house[i-1][0]+rgb[i][1],house[i-1][2]+rgb[i][1]);
                house[i][2] =Math.min(house[i-1][1]+rgb[i][2],house[i-1][0]+rgb[i][2]);
            }
        }

        System.out.println(Arrays.stream(house[n-1]).min().getAsInt());



    }
}
