int Divisors(int n){
  int res = 1;
  for(int i = 2 ; i*i <= n ; i++){
    int cnt = 0;
    while(!(n%i)) n /= i ,  cnt++;
    if(cnt) res *= (cnt+1);
  }
  if(n > 1) res *= 2;
  return res;
}

set<int> Divisors(int  n)
{
    set<int>s;
    int  i,sq=sqrt(n)+1;
    for(i=1;i <= sq;i++)
    {
       if(n%i)continue;
       s.insert(i);
       s.insert(n/i);
    }
    return s;
}