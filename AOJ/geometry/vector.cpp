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

// 内積
double dot(Vector a, Vector b){
    return a.x*b.x+a.y*b.y;
}
// 外積
double cross(Vector a, Vector b){
    return a.x*b.y-a.y*b.x;
}


int main(){
    int q; cin >> q;
    vector<int> ans;
    while(q--){
        Vector p0, p1, p2, p3, l1, l2;
        cin >> p0.x >> p0.y >> p1.x >> p1.y >> p2.x >> p2.y >> p3.x >> p3.y;
        l1 = p1-p0;
        l2 = p3-p2;
        if(cross(l1, l2) == 0) ans.push_back(2);
        else if(dot(l1, l2) == 0) ans.push_back(1);
        else ans.push_back(0);
    }
    for(auto aa: ans){
        cout << aa << endl;
    }
  
}