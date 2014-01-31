//** 0 based indexing */
int H[MX] ;
int Histogram() {
    stack<int>Stk;
    int Ans = 0 , pos = 0 , top , Area_With_Top ;
    while( pos < N ){
        if( Stk.empty() || H[ Stk.top() ] <= H[pos] ) Stk.push(pos++);
        else {
            top = Stk.top() ;
            Stk.pop();
            Area_With_Top = H[top] * ( Stk.empty() ? pos : pos - Stk.top() - 1 );
            Ans = max( Ans , Area_With_Top );
        }
    }
    while( !Stk.empty() ){
        top = Stk.top();
        Stk.pop();
        Area_With_Top = H[top] * ( Stk.empty() ? pos : pos - Stk.top() - 1 );
        Ans = max( Ans , Area_With_Top );
    }
    return Ans ;
}
