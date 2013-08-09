ll  SumOfDivisors(ll  x){
    if(x == 1) return 0;
    ll  i,ans = 1,sq=sqrt(x);
    for(i = 2;i <= sq;i ++){
        if( x % i == 0)
            if(i*i == x) ans += i ;
            else ans+= i+x/i ;
    }
    return ans;
}