# include "solver.hpp"
int main(){
    Sudoku s;
    int board[9][9];
    s.take_input(board);
    if(s.solve(board,0,0)){
        s.out_board(board);
        cout<<"Check the file 'output.txt' to view your solved Sudoku Puzzle!\n";
    }
    else{
        cout<<"Solution doesn't exist!\n";
        s.out_board(board);
    }
}