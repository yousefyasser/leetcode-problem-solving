class GameOfLife {
    public static void solution(int[][] board){
        int[][] nextGen = new int[board.length][board[0].length];
        
        for (int i = 0; i < board.length; i++) {
            for(int j = 0; j < board[0].length; j++){
                int aliveCount = getNeighbours(board, i, j);
                if(board[i][j] == 1){
                    if(aliveCount == 2 || aliveCount == 3){
                        nextGen[i][j] = 1;
                    }
                }else{
                    if(aliveCount == 3){
                        nextGen[i][j] = 1;
                    }
                }
            }
        }
        for (int i = 0; i < board.length; i++) 
            for(int j = 0; j < board[0].length; j++)
                board[i][j] = nextGen[i][j];
    }
    public static int getNeighbours(int[][] board, int x, int y){
        int aliveCount = 0;
        for(int i = Math.max(x-1, 0); i <= Math.min(x+1, board.length-1); i++){
            for(int j = Math.max(y-1, 0); j <= Math.min(y+1, board[0].length-1); j++){
                if((i != x || j != y) && board[i][j] == 1){
                    aliveCount++;
                }
            }
        }
        return aliveCount;
    }
}
