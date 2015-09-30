//checks the character Vowel or not
bool isVowel(char s){
    s = tolower(s);
    return (s == 'a' || s == 'e' || s == 'i' || s == 'o' || s == 'u' ) ;
}

//compute b^p
Long Pow(Long  b,Long  p){
    Long  ret = 1;
    while(p){
        if(p&1) ret *= b ;
        p >>= (1ll) , b *= b ;
    }
    return ret ;
}

//compute b^p%m
Long BigMod(Long  b,Long  p ,Long  m ){
     Long  ret = 1 ;
     while(p)  {
        if(p&1) ret = (ret * b ) % m ;
        p >>= (1ll) , b = (b*b)%m ;
     }
    return ret ;
}

//compute gcd of (a,b)
Long GCD(Long a , Long b){
    while(b) b ^=  a ^= b ^= a %= b ;
    return a;
}

//compute lcm of (a,b)
Long LCM(Long a , Long b) {
     return (a / GCD(a,b)*b);
}

//swap two variables
void SWAP(Long &a, Long &b){
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
Long toInt(string s){
    Long r = 0 ;
    istringstream sin(s); sin>>r;
    return r;
}

//convert Integer to String
string toString(Long number){
    stringstream ss;
    ss << number;
    return ss.str();
}

//convert Integer to hexadecimal
string Int2Hex(Long n){
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
Long Hex2Int(string s){ Long x ; std::stringstream ss; ss << std::hex << s; ss >> x; return x; }

//convert Integer to Binary
string i2b(Long a) {
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

int strMod(string Num , int md ){
     int rem = 0 , len = Num.size();
     for( int i = 0 ; i < len ; i++ ) rem = ( ( rem * 10 ) + ( Num[i]-'0') ) % md ;
     return ( rem == 0 ) ; // returns true if Num is divisible by md
}

void nextPalindrom(char str[], int size){
	int mid = ( size - 1 ) >> 1;
	int i = ((size & 1)==0) ? mid : mid - 1;
	int j = mid + 1;
	while( i >= 0 && str[i] == str[j] ) i--, j++;
	if( i < 0 || str[i] < str[j] ){
		i = mid;
		str[i] = str[i] + 1;
		while( i >= 0 && str[i] == ':' ){
			str[i--] = '0';
			str[i] = str[i] + 1;
		}
	}
	i = ( size % 2 == 0 ) ? mid : mid - 1;
	j = mid + 1;
	while( i >= 0 ) str[j++] = str[i--];
	if( str[0] == '0'){
		str[0] = str[size] = '1';
		str[size+1] = '\0';
	}
}
