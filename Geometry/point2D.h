struct point {
    double x,y;
    point(){
        x = y = 0;
    }
    point(double x, double y) : x(x), y(y) {}
    void input(){
        scanf("%lf %lf",&x,&y);
    }
    point (const point &p) {
        x = p.x, y = p.y;
    }
    void translate(double tx, double ty) {
        x += tx;
        y += ty;
    }
    point translate(point t) {
        x += t.x;
        y += t.y;
    }
    point operator+(point k){
        return point(x + k.x , y + k.y );
    }
    point operator-(point k){
        return point(x - k.x , y - k.y );
    }
    point operator*(double k) {
        return point(k * x , k * y );
    }
    point operator/(double k) {
        return point(x / k , y/k );
    }
    point rotleft(){
        return point(-y,x);
    }
    point rotright(){
        return point(y,-x);
    }
    point rotate(point p,double angle) {
        point v(x - p.x , y-p.y );
        double c = cos(angle) , s = sin(angle);
        return point(p.x + v.x*c - v.y*s , p.y + v.x*s + v.y*c );
    }
    #define sqr(x) ((x)*(x))
    double sqrdis(const point &b)const {
        return sqr(x - b.x) + sqr(y - b.y);
    }
    double dis(const point &b)const {
        return sqrt(sqrdis(b));
    }
    bool operator ==(const point &p)const {
        return ((x==p.x) && (y==p.y));
    }
    bool collinear(const point &p1, const point &p2)const  {
        return (p1.y - y) * (p2.x - x) == (p2.y - y) * (p1.x - x);
    }

    inline double cross(const point &i)const
    {
        return x*i.y-y*i.x;
    }
    inline double dot(const point &i)const
    {
        return x*i.x+y*i.y;
    }
    bool in_box(const point &a, const point &b) const { // rectangle : a = leftDown , b = rightTop
        double lox = min(a.x, b.x), hix = max(a.x, b.x);
        double loy = min(a.y, b.y), hiy = max(a.y, b.y);
        return x >= lox && x <= hix && y >= loy && y <= hiy; // remove = (eq) if strictly in box need
    }

    bool operator <(const point &p) const {
        return x < p.x || (x == p.x && y < p.y);
    } // sorting angle by x axis
    /*
    bool operator <(const point &p) const {
                 return y < p.y || (y == p.y && x < p.x);
    } // sorting angle by y axis
    */
    friend ostream& operator<<(ostream& out, const point& p) {
        return out << '(' << p.x << ',' << p.y << ')' << endl;
    }
};
