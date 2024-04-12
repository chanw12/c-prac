import java.util.*;
class Solution {
    static int[] visited;
    static List<List<Integer>> maps;
    public List<Integer> solution(int n, int[][] roads, int[] sources, int destination) {
        List<Integer> answer = new ArrayList<>();
        visited = new int[n+1];
        maps = new ArrayList<>();
        Arrays.fill(visited,1000000);
        for(int i=0; i<n+1;i++){
            maps.add(new ArrayList<>());
        }
        for(int i=0; i<roads.length;i++){
            maps.get(roads[i][0]).add(roads[i][1]);
            maps.get(roads[i][1]).add(roads[i][0]);
        }
        bfs(destination);
        
        for(int source: sources){
            answer.add(visited[source]!=1000000?visited[source]:-1);
        }

        
        return answer;
    }
    public void bfs(int start){
        Queue<Integer> queue = new LinkedList<Integer>();
        queue.offer(start);
        visited[start] = 0;
        while(!queue.isEmpty()){
            int current = queue.poll();
            for(int i=0; i<maps.get(current).size();i++){
                int temp = maps.get(current).get(i);
                if(visited[temp]>visited[current]+1){
                    queue.offer(temp);
                    visited[temp] = visited[current]+1;
                }
            }
        }
        
    }
}