vector< pair<int,int> >primeDivisors;

void generate_divisors(int n)
{
    primeDivisors.clear();

    int cnt = 0 ;

    while(n % 2 == 0 ){
        n>>=1 , cnt++;
    }

    if(cnt) primeDivisors.push_back( make_pair(2,cnt) );

    int sq = sqrt(n) + 1 ;

    for( int i = 3 ; i <= sq ; i += 2 ){
        cnt = 0 ;
        while(n % i == 0 ) n /= i , cnt++ ;
        if(cnt) primeDivisors.push_back( make_pair(i,cnt) );
    }

    if(n > 1 ) primeDivisors.push_back( make_pair(n,1) ) ;
}
int main(){
    generate_divisors(100);
    forstl(it,primeDivisors) cout << it->first << " (" << it->second << ")"<< endl;
}
