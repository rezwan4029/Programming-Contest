#define NQ 8
int cnt = 0 ;
int sol[95][10];

bool canPlace(int k,int i,int *x){
    rep(j,k) if( i==x[j]  ||  abs(k-j) == abs(i-x[j]) ) return false;
    return true;
}

void Nqueen(int k){
    static int x[NQ];
    rep(i,NQ){
        if(canPlace(k,i,x)){
            x[k]=i;
            if(k==NQ-1){
                cnt++;
                rep(j,NQ) sol[cnt][j] = x[j];
            }
            else Nqueen(k+1);
        }
    }
}
int main(){
    Nqueen(0);
}

//There are 92 solutions in traditional 8-Queen porblem .
// here , sol[cnt][j] means : In  Solution no cnt , at jth row and (sol[cnt][j] ) th column a Queen can be placed.
