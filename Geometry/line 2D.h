struct line
{
    point a , b ;
    line(point _a , point _b )
    {
        a = _a , b = _b ;
    }
    line() {}
    bool operator==(line v)
    {
        return (a==v.a) && (b==v.b);
    }
    // ** ভুমির সাথে  থিটা কোণে  নতুন রেখা উৎপন্ন  করে এবং থিটা রেডিয়ান  এ হতে হবে .
    line(point p,double theta)
    {
        a = p;
        if ( EQ( theta - pi/2.00 ) == 0 ) b = a + point(0,1);
        else b= a + point( 1 , tan( theta ) );
    }
    //ax+by+c=0 ,a,b,c দেয়া আছে তার জন্য রেখার দুইটা বিন্দু তৈরি করে
    line(double _a,double _b,double _c)
    {
        if ( EQ( _a ) == 0)
        {
            a = point(0,-_c/_b);
            b = point(1,-_c/_b);
        }
        else if (EQ(_b)==0)
        {
            a = point(-_c/_a,0);
            b = point(-_c/_a,1);
        }
        else
        {
            a = point(0,-_c/_b);
            b = point(1,(-_c-_a)/_b);
        }
    }
    //দুইটা বিন্দুর  মধ্যবর্তী দূরূত্ব
    double length()
    {
        return a.dis(b);
    }
    //ভুমির সাথে কত ডিগ্রী কোনে রেখাটি  অবস্থিত
    // return করতেছে রেডিয়ানে  //   angle 0 <= angle < pi
    double angle()
    {
        double k = atan2(b.y-a.y,b.x-a.x);
        if (EQ(k) < 0)k += pi;
        if (EQ(k-pi) == 0)k -= pi;
        return k;
    }
    // একটি বিন্দু থেকে লাইন এর লম্বদূরত্ব
    double dispointtoline(point p)
    {
        return fabs((p-a).cross((b-a)))/length();
    }

    // dont know the usage :p
    point lineprog(point p)
    {
        double d = (b - a).x * (b - a).x + (b - a).y * (b - a).y ;
        return a + ((b-a)*((b-a).dot((p-a))/d) );
    }
    //প্রতিবিম্ব বিন্দু /  Shadow point
    point symmetrypoint(point p)
    {
        point q = lineprog(p);
        return point(2 * q.x - p.x , 2 * q.y - p.y );
    }
    void input()
    {
        a.input() ;
        b.input();
    }
};
