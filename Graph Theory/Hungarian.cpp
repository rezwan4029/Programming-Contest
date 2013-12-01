/*
 * Algorithm : Hungarian algorithm
 *             Max Weighted Bi-partite Matching
 * Complexity : O( N^3 )
 * Note : 0 base indexing
 */

const int MX = 52;
const int INF = 1e8 ;

int cost[MX][MX];        // cost matrix
int N,mxMatch;          // N workers and N jobs
int lx[MX], ly[MX];    // Labels of X and Y parts
int xy[MX];           // xy[x] - vertex that is matched with x,
int yx[MX];          // yx[y] - vertex that is matched with y
bool S[MX], T[MX];  // Sets S and T in algorithm
int slack[MX];
int slackX[MX];   // slackX[y] such a vertex, that
                 // l(slackX[y]) + l(y) - w(slackX[y],y) = slack[y]
int prev[MX];   // Array for memorizing alternating paths

void initLabels() {
    ms(lx,0);
    ms(ly,0);
    rep(x,N) rep(y,N) lx[x] = max(lx[x], cost[x][y]);
}

void Update_Labels(){
    int delta = INF;
    rep(y,N) if(!T[y]) delta = min(delta, slack[y]);
    rep(x,N) if( S[x]) lx[x] -= delta;
    rep(y,N) if( T[y]) ly[y] += delta;
    rep(y,N) if(!T[y]) slack[y] -= delta;
}

void Add_To_Tree(int x, int prevx) {
    S[x] = true;
    prev[x] = prevx;
    rep(y,N)
        if (lx[x] + ly[y] - cost[x][y] < slack[y]){
            slack[y] = lx[x] + ly[y] - cost[x][y];
            slackX[y] = x;
        }
}

void Augment(){
    if (mxMatch == N) return;
    int x, y, root;
    int q[MX], wr = 0, rd = 0;
    ms(S,false);
    ms(T,false);
    ms(prev,-1);
    for( x=0;x<N;x++ )
        if (xy[x] == -1){
            q[wr++] = root = x;
            prev[x] = -2;
            S[x] = true;
            break;
        }
    for( y=0;y<N;y++ ){
        slack[y] = lx[root] + ly[y] - cost[root][y];
        slackX[y] = root;
    }
    while( true ){
        while (rd < wr){
            x = q[rd++];
            for( y=0;y<N;y++ ){
                if (cost[x][y] == lx[x] + ly[y] &&  !T[y]){
                    if (yx[y] == -1) break;

                    T[y] = true;
                    q[wr++] = yx[y];

                    Add_To_Tree(yx[y], x);
                }
            }
            if (y < N) break;
        }
        if (y < N) break;
        Update_Labels();
        wr = rd = 0;
        for( y=0;y<N;y++ ){
            if (!T[y] &&  slack[y] == 0){
                if (yx[y] == -1){
                    x = slackX[y];
                    break;
                }
                else{
                    T[y] = true;
                    if (!S[yx[y]]){
                        q[wr++] = yx[y];
                        Add_To_Tree(yx[y], slackX[y]);
                    }
                }
            }
        }
        if (y < N) break;
    }
    if (y < N){
        mxMatch++;
        for (int cx = x, cy = y, ty; cx != -2; cx = prev[cx], cy = ty){
            ty = xy[cx];
            yx[cy] = cx;
            xy[cx] = cy;
        }
        Augment();
    }
}

int Hungarian(){
    int ret = 0;
    mxMatch = 0;
    ms(xy,-1);
    ms(yx,-1);
    initLabels();
    Augment();
    rep(x,N) ret += cost[x][xy[x]];
    return ret;
}

int main() {
    int test = II ;
    For(cs,test){
        N = II ;
        rep(i,N) rep(j,N) cost[i][j] = II ;
        int Ans = Hungarian();
        printf("Case %d: %d\n",cs,Ans);
    }
}
