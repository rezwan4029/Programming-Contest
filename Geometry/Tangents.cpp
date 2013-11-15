struct tempLine{ double a,b,c ;};

void tangents( point c , double r1 , double r2 , vector<tempLine>&ans)
{
    double r = r2 - r1 ;
    double z = c.x * c.x + c.y * c.y ;
    double d = z - (r *r);
    if( d < -EPS ) return ;
    d = sqrt( abs(d) ) ;
    tempLine l;
	l.a = (c.x * r + c.y * d) / z;
	l.b = (c.y * r - c.x * d) / z;
	l.c = r1;
	ans.pb(l);
}

vector<line>tangents(circle a , circle b )
{
    vector< tempLine >ans;
    for( int i = -1 ; i <= 1 ; i +=2 )
        for( int j = -1 ; j <= 1 ; j +=2 )
            tangents(b.p - a.p,a.r*i,b.r*j,ans);
    int sz = ans.size();
    vector<line>ret;
    rep(i,sz)
    {
        ans[i].c -= ans[i].a * a.p.x + ans[i].b * a.p.y ;
        ret.pb( line(ans[i].a,ans[i].b,ans[i].c) );
    }
    return ret;
}
