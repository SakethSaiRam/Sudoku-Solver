# include <iostream>
# include <fstream>
# define N 9
# define input "input.txt"
# define output "output.txt"
using namespace std;
class Sudoku{
    public:
        void take_input(int b[N][N]);
        void out_board(int b[N][N]);
        void printboard(int b[N][N]);
        bool isSafe(int b[N][N], int row, int col, int val);
        bool solve(int b[N][N], int row, int col);
};
void Sudoku :: take_input(int b[N][N]){
    ifstream inFile(input);
    string line;
    int row = 0;
    while(getline(inFile,line)){
        int col = 0;
        int len = line.length();
        for(int i=0;i<len;i++){
            if(i%2 == 0){
                b[row][col] = int(line[i])-48;
                col++;
            }
        }
        row++;
    }
    inFile.close();
}
void Sudoku :: out_board(int b[N][N]){
    ofstream outFile(output);
    for(int i=0;i<N;i++){
        for(int j=0;j<N-1;j++){
            outFile<<b[i][j]<<" ";
        }
        outFile<<b[i][N-1]<<endl;
    }
    outFile.close();
}
void Sudoku :: printboard(int b[N][N]){
    for(int i=0;i<N;i++){
        for(int j=0;j<N-1;j++){
            cout<<b[i][j]<<" ";
        }
        cout<<b[i][N-1]<<endl;
    }
}
bool Sudoku :: isSafe(int b[N][N], int row, int col, int val){
    for(int i=0;i<N;i++){
        if(b[row][i] == val){
            return false;
        }
    }
    for(int i=0;i<N;i++){
        if(b[i][col] == val){
            return false;
        }
    }
    int start_row = row - row%3, start_col = col - col%3;
    for(int i=0;i<3;i++){
        for(int j=0;j<3;j++){
            if(b[i+start_row][j+start_col] == val){
                return false;
            }
        }
    }
    return true;
}
bool Sudoku :: solve(int b[N][N], int row, int col){
    if (row == N - 1 && col == N){
        return true;
    }
    if (col == N) {
        row++; col = 0;
    }
    if (b[row][col] > 0){
        return solve(b, row, col + 1);
    }
    for(int n=1;n<=N;n++){
        if(isSafe(b, row, col, n)){
            b[row][col] = n;
            if(solve(b,row,col+1)){
                return true;
            }
        }
        b[row][col] = 0;
    }
    return false;
}