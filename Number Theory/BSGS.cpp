/*
  Shnak's Baby-Step-giant-Step Algorithm
  a^x = b (mod m)
  return the power x where a , b , m given
*/

#define mod 100000007

ll solve (ll a, ll b, ll m)
{
	ll n = (ll) sqrt (m + .0) + 1 , an = 1 , curr ;
	rep(i,n) an = (an * a) % m;
	map<ll,ll> vals;
	curr = an ;
	For(i,n){
		if ( !vals.count(curr) ) vals[ curr ] = i;
		curr = (curr * an) % m;
	}
    ll ans = mod ;
    curr = b ;
	rep(i,n+1){
		if ( vals.count(curr) ) {
			 ans = min( ans , vals[ curr ] * n - i ); // finding the minimum solution
			//if (ans < m) return ans; // return any solution
		}
		curr = (curr * a) % m;
	}
	return ans ;
	//return -1; // if no solution cant be found
}
