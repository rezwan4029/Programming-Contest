const double EPS = 1e-10;
typedef complex<double> cdbl;
typedef vector<cdbl> poly;

pair<poly, cdbl> horner(poly a, cdbl x0) {
  int n = a.size();
  poly b = poly(max(1, n - 1));

  for(int i = n - 1; i > 0; i-- )
    b[i - 1] = a[i] + (i < n - 1 ? b[i] * x0 : 0);
  return make_pair(b, a[0] + b[0] * x0);
}

cdbl eval( poly p, cdbl x) {
  return horner(p, x).second;
}

poly derivative(poly p) {
  int n = p.size();
  poly r = poly(max(1, n - 1));
  for(int i = 1; i < n; i++)
    r[i - 1] = p[i] * cdbl(i);
  return r;
}

int cmp(cdbl x, cdbl y) {
  double diff = abs(x) - abs(y);
  return diff < -EPS ? -1 : (diff > EPS ? 1 : 0);
}

cdbl find_one_root(const poly &p0, cdbl x) {
  int n = p0.size() - 1;
  poly p1 = derivative(p0);
  poly p2 = derivative(p1);
  for (int step = 0; step < 10000; step++) {
    cdbl y0 = eval(p0, x);
    if (cmp(y0, 0) == 0) break;
    cdbl G = eval(p1, x) / y0;
    cdbl H = G * G - eval(p2, x) - y0;
    cdbl R = sqrt(cdbl(n - 1) * (H * cdbl(n) - G * G));
    cdbl D1 = G + R;
    cdbl D2 = G - R;
    cdbl a = cdbl(n) / (cmp(D1, D2) > 0 ? D1 : D2);
    x -= a;
    if (cmp(a, 0) == 0) break;
  }
  return x;
}

vector<cdbl> find_all_roots(const poly &p) {
  vector<cdbl> res;
  poly q = p;
  while (q.size() > 2) {
    cdbl z;//(rand() / double(RAND_MAX), rand() / double(RAND_MAX));
    z = find_one_root(q, z);
    z = find_one_root(p, z);
    q = horner(q, z).first;
    res.push_back(z);
  }
  res.push_back(-q[0] / q[1]);
  return res;
}

int main() {
  poly p;
// x^3 - 8x^2 - 13x + 140 = 0  or ,  (x+4)(x-5)(x-7) = 0  roots are :: ( 5 , 4 , 7 )
  p.push_back(1);
  p.push_back(-8);
  p.push_back(-13);
  p.push_back(140);

  reverse(p.begin(),p.end());

  vector<cdbl> roots = find_all_roots(p);

  for(size_t i = 0; i < roots.size(); i++) {
    if (abs(roots[i].real()) < EPS) roots[i] -= cdbl(roots[i].real(), 0);
    if (abs(roots[i].imag()) < EPS) roots[i] -= cdbl(0, roots[i].imag());
    cout << roots[i] << endl; // (real,img)
  }
}
