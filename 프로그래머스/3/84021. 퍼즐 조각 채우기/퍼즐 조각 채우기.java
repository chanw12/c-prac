import java.util.*;
class Solution {
    static List<Integer> cnt = new ArrayList<>();
    public int solution(int[][] game_board, int[][] table) {
        List<int[][]> game_list = extract(game_board,0);
        List<int[][]> table_list = extract(table,1);


        

        int answer = 0;
        boolean[] used = new boolean[table_list.size()];
        Arrays.fill(used,false);
        
        
        for(int[][] gameList : game_list){
            for(int i=0;i<table_list.size();i++){
                if(used[i]) continue;
                int[][] tableList = table_list.get(i);
                
                for(int r=0;r<4;r++){
                    if(matches(gameList,tableList)){
                       
                        answer += cnt.get(i);
                        used[i] = true;
                        break;
                    }
                    tableList = rotate90(tableList);
                    
                }
                if(used[i]) break;
                
            }
        }
        
        return answer;
    }
    public boolean matches(int[][] game,int[][] tab){
        if(game.length != tab.length || game[0].length != tab[0].length){
            return false;
        }
        
        for(int i=0; i<game.length;i++){
            for(int j=0;j<game[0].length;j++){
                if(game[i][j] != tab[i][j]){
                    return false;
                }
            }
        }
        return true;
    }
    
    public int[][] rotate90(int[][] matrix){
        int m = matrix.length;
        int n = matrix[0].length;
        int[][] rotated = new int[n][m];
        
        for (int i = 0; i < m; i++) {
            for (int j = 0; j < n; j++) {
                rotated[j][m - 1 - i] = matrix[i][j];
            }
        }
        return rotated;
    }
    
    public List<int[][]> extract(int[][] ll,int target){
    
        int n = ll.length;
        boolean[][] visited = new boolean[n][n];
        List<int[][]> pieces = new ArrayList<>();
        for(int i=0;i<n;i++){
            for(int j=0;j<n;j++){
                if( ll[i][j] == target && !visited[i][j]){
                    List<int[]> piece = new ArrayList<>();
                    Queue<int[]> queue = new LinkedList<>();
                    
                    queue.add(new int[]{i,j});
                    visited[i][j] = true;
                    int minX = i;
                    int maxX = i;
                    int minY = j;
                    int maxY = j;
                    int count = 0;
                    while(!queue.isEmpty()){
                        int[] cur = queue.poll();
                        piece.add(cur);
                        int x = cur[0];
                        int y =cur[1];
                        count +=1;
                        
                        minX = Math.min(minX,x);
                        minY = Math.min(minY,y);
                        maxX = Math.max(maxX,x);
                        maxY = Math.max(maxY,y);
                        
                        
                        int[] dx = {0,1,0,-1};
                        int[] dy = {1,0,-1,0};
                        
                        for(int k=0;k<4;k++){
                            int nx = dx[k] + x;
                            int ny = y + dy[k];
                            if(nx>=0 && nx<n && ny>=0 && ny<n && ll[nx][ny] == target && !visited[nx][ny]){
                                queue.add(new int[]{nx,ny});
                                visited[nx][ny] = true;
                            }
                        }
                    }
                    int pieceWidth = maxX - minX+1;
                    int pieceHeight = maxY - minY +1;
                    int[][] pieceArray = new int[pieceWidth][pieceHeight];
                    for(int[] lll: piece){
                        pieceArray[lll[0] - minX][lll[1] - minY] = 1;
                    }
                    pieces.add(pieceArray);
                    if(target == 1){
                        cnt.add(count);
                    }
                    
                }
            }
        }
        return pieces;
    }
}

