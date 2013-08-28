//ax + by = gcd(a,b) 
// returns d the gcd of(a,b)

ll Ex_gcd(ll a,ll b,ll &x,ll &y)
{
    if (b){
        ll ret = Ex_gcd(b , a%b , x , y) , tmp = x ;
        x = y;
        y = tmp - (a/b)* y ;
        return ret;
    }
    else{
        x = 1 , y = 0;
        return a;
    }
}
