/*
    Rezwan_4029
    AUST , CSE-25
*/
#include <bits/stdc++.h>
#define pb push_back
#define ms(a,v) memset(a,v,sizeof a)
#define II ({int a; scanf("%d", &a); a;})
#define LL  ({ll  a; scanf("%lld", &a); a;})
#define all(X) X.begin() , X.end()
using namespace std;
typedef long long ll ;
#define rep(i,n) for( __typeof(n)i = 0 ; i < n ; i++)
#define For(i,n) for( __typeof(n)i = 1 ; i <= n ; i++)
#define forstl(i,n) for(__typeof(n.begin())i = n.begin();i!=n.end();i++)
#define forab(i,a,b) for( __typeof(b) i = a ; i <= (b) ; i++ )
#define forba(i,b,a) for( __typeof(b) i = b ; i >= (a) ; i-- )


#define MAXN 2500010 // total size of patterns here 500 patterns  and max length of pattern is 5000 . so 500 * 5000 = 2500000
#define CHARSET  64 // lower(26) + upper(26) + digits(10) +  and -(dash) (1) = 63

int Value(char x){
    if( islower(x) ) return x - 'a' ;
    else if(isupper(x))return x - 'A' + 26 ;
    else if(isdigit(x))return x - '0' + 52 ;
    return 63 ;
}
struct AhoCorasick{
    vector<int> mark[MAXN];
    int end , failure[MAXN];
    int Trie[MAXN][CHARSET];
    void __init(){
        mark[0].clear();
        fill(Trie[0], Trie[0] + CHARSET, -1);
        end = 1;
    }
    void add(char *s, int t){
        int pos = 0 ;
        for(int i = 0 ; s[i] ; i++ ){
            int ch = Value(s[i]);
            if (Trie[pos][ch] == -1){
                mark[end].clear();
                fill(Trie[end], Trie[end] + CHARSET, -1);
                Trie[pos][ch] = end++;
            }
            pos = Trie[pos][ch];
        }
        mark[pos].pb(t);
    }
    void computeFailure()
    {
        queue<int> Q ;
        failure[0] = 0;
        rep(i,CHARSET){
            if (Trie[0][i] != -1){
                failure[ Trie[0][i] ] = 0;
                Q.push( Trie[0][i] );
            }
            else Trie[0][i] = 0;
        }
        while (!Q.empty()){
            int p = Q.front(); Q.pop();
            forstl(it , mark[ failure[p] ] ) mark[p].pb( *it );
            rep(i,CHARSET){
                if (Trie[p][i] != -1){
                    failure[ Trie[p][i] ] = Trie[ failure[p] ][i];
                    Q.push( Trie[p][i] );
                }
                else
                    Trie[p][i] = Trie[ failure[p] ][i];
            }
        }
    }
}solve;

char P[512][5012]; // 500 patterns and max Length of pattern is 5000
int Counts[5012]; // Count which pattern occurs how many times

void CountFreq(char *T){
    for(int i = 0 , pos = 0 ; T[i] ; i++ ) {
            int ch = Value(T[i]);
            pos = solve.Trie[ pos ][ ch ];
            if (pos == 0) continue;
            forstl(it , solve.mark[ pos ] )  Counts[ *it ]++;
    }
}

char T[50007]; // Maximum size of Text

int main(){
    //freopen("in.txt", "r", stdin);
    int noOfpatterns ;
    scanf("%d",&noOfpatterns);
    rep(i,noOfpatterns) scanf("%s",P[i]);
    int noOftexts ;
    scanf("%d",&noOftexts);
    solve.__init();
    rep(i,noOfpatterns) solve.add(P[i],i);
    solve.computeFailure();
    memset(Counts,0,sizeof Counts);
    while(noOftexts--){
        scanf("%s",T);
        CountFreq(T);
    }
    rep(i,noOfpatterns) printf("%d\n", Counts[i]);
}
/*
Sample Input 1
5
he
she
sher
his
hers
2
ushers
she-said-he-said-she-said-he-said-his

Sample Output 1
5
3
1
1
1


Sample Input 2
3
who
shawty
hawt
2
Get-it-shawty-Get-it-shawty
Whoa-W-W-Whoa-Shawtyyyyy

Sample Output 2
0
2
3
*/
