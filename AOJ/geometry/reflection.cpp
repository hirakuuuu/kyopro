#include <bits/stdc++.h>
using namespace std;
#define rep(i, a, n) for(int i = a; i < n; i++)
#define ll long long
#define pii pair<int, int>
#define pll pair<ll, ll>
const int MOD = 1000000007;
const int mod = 998244353;

// ポイントクラス
#define EPS 1e-10
#define equals(a, b) (fabs((a) - (b)) < EPS)

struct Point {
    double x, y;

    Point(double x = 0, double y = 0): x(x), y(y) {}

    Point operator + (Point p) { return Point(x+p.x, y+p.y); }
    Point operator - (Point p) { return Point(x-p.x, y-p.y); }
    Point operator * (double a) { return Point(x*a, y*a); }
    Point operator / (double a) { return Point(x/a, y/a); }

    double abs() { return sqrt(norm()); }
    double norm() { return x*x + y*y; }

    bool operator < (const Point &p) const {
        return x != p.x ? x < p.x : y < p.y;
    }

    bool operator == (const Point &p) const {
        return fabs(x-p.x) < EPS && fabs(y-p.y) < EPS;
    }
};
typedef Point Vector;

// 線分
struct Segment {
    Point p1, p2;
};

// 直線
typedef Segment Line;

// 円
struct Circle {
    Point c;
    double r;
    Circle(Point c = Point(), double r = 0.0): c(c), r(r) {}
};

// 多角形
typedef vector<Point> Polygon;

// 内積
double dot(Vector a, Vector b){
    return a.x*b.x+a.y*b.y;
}
// 外積
double cross(Vector a, Vector b){
    return a.x*b.y-a.y*b.x;
}

// 射影
Point project(Segment s, Point p){
    Vector base = s.p2 - s.p1;
    double r = dot(p-s.p1, base)/base.norm();
    return s.p1+base*r;
}

// 反射
Point reflect(Segment s, Point p){
    return p+(project(s, p)-p)*2;
}


int main(){
    Vector p0, p1, p2;
    cin >> p0.x >> p0.y >> p1.x >> p1.y;
    Segment s;
    s.p1 = p0, s.p2 = p1;
    int q; cin >> q;
    vector<Point> ans;
    while(q--){
        Point p2;
        cin >> p2.x >> p2.y;
        ans.push_back(reflect(s, p2));
    }
    for(auto aa: ans){
        printf("%.10f %.10f\n", aa.x, aa.y);
    }

}