const int SZ = 100010 ;
int n , arr[SZ] , dp[SZ];

int lis() {
    int mxLen = 1;
    dp[0] = arr[0];
    For(i,n-1){
        int curr = arr[i] , last = dp[ mxLen - 1 ] ;
        if ( last < curr ) {
            dp[ mxLen++ ] = curr;
        }
        else if( last > curr ) {
            int *pos = lower_bound(dp , dp + mxLen , curr) ;
            if( *pos > curr) *pos = curr;
        }
    }
    return mxLen ;
    // for solution print the dp upto mxLen
}

 // for longest decreasing subarruence, multiply elements by -1
