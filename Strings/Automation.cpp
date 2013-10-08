
#define MAX_SIZE 1000010
int f[MAX_SIZE][26];

void Compute_Transition_Fnc(string P)
{
    int m = P.size();
    forab(q,0,m){
        string Pq = P.substr(0,q);
        forab(c,'a','z'){
            int K = min( m , q+1 );
            string aux = Pq + c;
            while(1){
                bool check = true;
                rep(i,K) if( aux [q-i] != P [K-1-i] ) check=false;
                if(check) break;
                K--;
            }
            f[ q ][ c - 'a' ] = K;
        }
    }
}

void Finite_Automata_Matcher(string T,int m){
    int n = T.size() , q = 0 ;
        rep(i,n){
            q = f[q][ T[i]-'a' ];
            if(q == m ) cout<<"Pattern occurs with shift "<< i+1-m <<endl;
    }
}

int main(){
    string P,T;
    cout<<"Text :"; cin >> T ; cout << endl;
    cout<<"Pattern : "; cin>>P ; cout << endl;
    Compute_Transition_Fnc(P); //assuming that the alphabet letters are lowercase
    Finite_Automata_Matcher(T,P.size());
}
