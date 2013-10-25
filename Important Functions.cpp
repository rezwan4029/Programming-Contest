//checks the character Vowel or not
bool isVowel(char s){
    s = tolower(s);
    return (s == 'a' || s == 'e' || s == 'i' || s == 'o' || s == 'u' ) ;
}

//compute b^p
ll Pow(ll  b,ll  p){
    ll  ret = 1;
    while(p){
        if(p&1) ret *= b ;
        p >>= (1ll) , b *= b ;
    }
    return ret ;
}

//compute b^p%m
ll BigMod(ll  b,ll  p ,ll  m ){
     ll  ret = 1 ;
     while(p)  {
        if(p&1) ret = (ret * b ) % m ;
        p >>= (1ll) , b = (b*b)%m ;
     }
    return ret ;
}

//compute gcd of (a,b)
ll GCD(ll a , ll b){
    while(b) b ^=  a ^= b ^= a %= b ;
    return a;
}

//compute lcm of (a,b)
ll LCM(ll a , ll b) {
     return (a / GCD(a,b)*b);
}

//swap two variables
void SWAP(ll &a, ll &b){
    a ^= b ;
    b = a ^ b ;
    a ^= b;
}

//checks wether p occurs in t
bool isSubString(string t , string p ){
    int pl = p.length() , tl = t.length() ;
    rep(i,tl) if( t.substr(i,pl) == p ) return true ;
    return false ;
}

//convert String to Integer
ll toInt(string s){
    ll r = 0 ;
    istringstream sin(s); sin>>r;
    return r;
}

//convert Integer to String
string toString(ll number){
    stringstream ss;
    ss << number;
    return ss.str();
}

//convert Integer to hexadecimal
string Int2Hex(ll n){
    string hex ;
    while(n) {
        int mod = n % 16 ;
        if( mod == 10 ) hex += 'A';
        else if( mod == 11 ) hex += 'B';
        else if( mod == 12 ) hex += 'C';
        else if( mod == 13 ) hex += 'D';
        else if( mod == 14 ) hex += 'E';
        else if( mod == 15 ) hex += 'F';
        else hex += ( mod + '0');
        n /= 16;
    }
    reverse(all(hex));
    return hex;
}

//convert hexadecimal to Integer
ll Hex2Int(string s){ ll x ; std::stringstream ss; ss << std::hex << s; ss >> x; return x; }

//convert Integer to Binary
string i2b(ll a) {
    string s ;
    do { s += (a&1) + '0' ,  a >>= 1; }while(a);
    reverse(all(s));
    return s;
}

//splits String in space
vector<string>Split(string s ){
    vector<string>ret;
    istringstream ss(s) ;
    string token ;
    while(ss >> token) ret.pb( token ) ;
    return ret;
}

//check wether string is palindrome
bool isPalindrome(string s ){
    int len = s.length();
    rep(i,len/2)if(s[i] != s[len - i - 1 ] ) return false ;
    return true;
}
