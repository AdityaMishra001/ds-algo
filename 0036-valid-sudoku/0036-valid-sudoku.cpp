class Solution {
public:
    using vi=vector<int>;
    using vc=vector<char>;
    using vb=vector<bool>;
    using vvi=vector<vi>;
    using vvb=vector<vb>;
    using vvc=vector<vc>;
    // bool valid(vvc&board, vi& r, vi& c, vi& g,int i,int j){
    //     if(board[i][j]=='.')
    //         return 1;
            
    //     int bit= (1<<(board[i][j]-'1'));
    //     if( (r[i] & bit )||
    //         (c[j]& bit )||
    //         (g[(i/3)*3 +(j/3)] & bit) )
    //             return 0;

    //     for(int row=0;row<9;row++){
    //         if(board[row][j]==board[i][j])
    //             return 0;
    //     }   
    //     for(int col=0;col<9;col++){
    //         if(board[i][col]==board[i][j])
    //             return 0;
    //     }   
    //     for(int grid=0;grid<9;grid++){
    //         if(board[(grid/3)*3+(grid/3)][ (grid/3)*3+(grid%3)])
    //             return 0;
    //     }    
    //     r[i]|=bit;
    //     c[j]|=bit;
    //     g[(i/3)*3+(j/3)]|=bit;
    //     return 1;
    // }
    // bool isValidSudoku(vector<vector<char>>& board) {
    //     vi r(9),c(9),g(9);

    //     for(int i=0;i<9;i++){
    //         for(int j=0;j<9;j++){
    //             if(!valid(board,r,c,g,i,j))
    //                 return 0;
    //         }
    //     }
    //     return 1;
    // }


bool isValidSudoku(vector<vector<char>>& board) {
    vector<int> row(9, 0), col(9, 0), grid(9, 0);

        for(int i = 0; i < 9; i++) {
            for(int j = 0; j < 9; j++) {
                if(board[i][j] == '.') continue;

                int bit = 1 << (board[i][j] - '1');
                int g = (i / 3) * 3 + (j / 3);

                if(row[i] & bit) return false;
                if(col[j] & bit) return false;
                if(grid[g] & bit) return false;

                row[i] |= bit;
                col[j] |= bit;
                grid[g] |= bit;
            }
        }
        return true;
    }

};