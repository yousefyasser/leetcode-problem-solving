import java.util.LinkedList;
import java.util.Queue;

class minesweeper {
    public static char[][] updateBoard(char[][] board, int[] click) {
        if(board[click[0]][click[1]] == 'M'){
            board[click[0]][click[1]] = 'X';
        }else{
            revealNeighbours(board, click);
        }
        return board;
    }
    public static void revealNeighbours(char[][] board, int[] point){
        boolean[][] visited = new boolean[board.length][board[0].length];
        Queue<int[]> neighbours = new LinkedList<>();
        neighbours.add(point);

        while(!neighbours.isEmpty()){
            int[] pos = neighbours.remove();
            int mines = countNeighbouringMines(board, pos);
            visited[pos[0]][pos[1]] = true;

            if(mines == 0){
                board[pos[0]][pos[1]] = 'B';
                updateNeighbours(neighbours, board, pos, visited);
            }else{
                board[pos[0]][pos[1]] = (mines+"").charAt(0);
            }
        }
    }

    public static int countNeighbouringMines(char[][] board, int[] pos){
        int mines = 0;
        for(int i = Math.max(pos[0] - 1, 0); i <= Math.min(pos[0] + 1, board.length-1); i++){
            for(int j = Math.max(pos[1] - 1, 0); j <= Math.min(pos[1] + 1, board[0].length-1); j++){
                if((i != pos[0] || j != pos[1]) && board[i][j] == 'M'){
                    mines++;
                }
            }
        }
        return mines;
    }

    public static void updateNeighbours(Queue<int[]> neighbours, char[][] board, int[] pos, boolean[][] visited){
        for(int i = Math.max(pos[0] - 1, 0); i <= Math.min(pos[0] + 1, board.length-1); i++){
            for(int j = Math.max(pos[1] - 1, 0); j <= Math.min(pos[1] + 1, board[0].length-1); j++){
                if((i != pos[0] || j != pos[1]) && !visited[i][j]){
                    neighbours.add(new int[]{i, j});
                    visited[i][j] = true;
                }
            }
        }
    }
}