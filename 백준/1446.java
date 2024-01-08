package com.example.codingtest;


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
        int D = Integer.parseInt(st.nextToken());

        int[] dis = new int[D+1];
        for(int i=0;i<D+1;i++){
            dis[i] = i;
        }
        List<Temp>[] mapp = new List[10000];
        Arrays.fill(mapp,new ArrayList<Temp>());
        for(int i=0;i<D+1;i++){
            mapp[i] = new ArrayList<>();
        }
        for(int i=0; i<N;i++){
            st = new StringTokenizer(br.readLine());
            int a = Integer.parseInt(st.nextToken());
            int b = Integer.parseInt(st.nextToken());
            int c = Integer.parseInt(st.nextToken());
            Temp temp = new Temp(a,c);

            if(b-a > c){
                mapp[b].add(temp);
            }

        }
        dis[0] = 0;

        for(int i=1;i<=D;i++){
            if(mapp[i].size()>0){
                for(Temp t:mapp[i]){
                    if(dis[t.a]+t.c > dis[i])continue;
                    dis[i] = Math.min(dis[i-1]+1,dis[t.a]+t.c);
                }
                continue;
            }
            dis[i] = dis[i-1]+1;
        }
        System.out.println(dis[D]);






    }

    static class Temp{
        int a;
        int c;

        public Temp(int a,int c){
            this.a = a;
            this.c = c;
        }
    }

}
