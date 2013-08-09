struct point{
    #define Type double
    Type x,y;
    point() { x = y = 0;}
	point(Type x, Type y) : x(x), y(y) {}
	point (const point &p) { x = p.x, y = p.y; }

    point operator+(const point  k){ return point(x + k.x , y + k.y ); }
    point operator-(const point  k){ return point(x - k.x , y - k.y ); }
    point operator*(const double k){ return point(k * x , k * y ); }

    point translate(point v) { return ( point(x,y) + v ) ; }
    point rotate(point p,double angle){
        point v(x - p.x , y-p.y );
        double c = cos(angle) , s = sin(angle);
        return point(p.x + v.x*c - v.y*s , p.y + v.x*s + v.y*c );
    }

    #define sqr(x) ((x)*(x))
    Type sqrdis(const point &b) {
		return sqr(x - b.x) + sqr(y - b.y);
	}
	double dis(const point &b) { return sqrt(sqrdis(b));}

    bool operator <(const point &p) const {
                    return x < p.x || (x == p.x && y < p.y);
    } // sorting angle by x axis
    /*
    bool operator <(const point &p) const {
                 return y < p.y || (y == p.y && x < p.x);
    } // sorting angle by y axis
    */
    friend ostream& operator<<(ostream& out, const point& p) {
		return out << '(' << p.x << ',' << p.y << ')';
	}
};
