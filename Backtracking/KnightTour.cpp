#define N 8

int dx[] = {  2, 1, -1, -2, -2, -1,  1,  2 };
int dy[] = {  1, 2,  2,  1, -1, -2, -2, -1 };

int sol[N][N];

bool isValid(int x, int y){
    return ( x >= 0 && x < N && y >= 0 && y < N && sol[x][y] == -1 ) ;
}

bool back(int x, int y, int Cnt){
   if (Cnt == N*N) return true;
   rep(i,8){
       int nx = x + dx[i];
       int ny = y + dy[i];
       if (isValid(nx, ny)){
            sol[nx][ny] = Cnt ;
            if( back(nx, ny, Cnt+1) ) return true;
            else sol[nx][ny] = -1; // backtracking
       }
   }
   return false;
}

void printSolution(){
    rep(i,N){
        rep(j,N) printf(" %2d ", sol[i][j]);
        printf("\n");
    }
}

void KnightTour(){
    memset(sol,-1,sizeof sol);
    sol[0][0]  = 0;  // Since the Knight is initially at the first block
    if( back(0, 0, 1) == false) {
        printf("Solution does not exist");
        return ;
    }
    printSolution();
}
