#include <bits/stdc++.h>
using namespace std;
#define rep(i, a, n) for(int i = a; i < n; i++)
#define rrep(i, a, n) for(int i = a; i >= n; i--)
#define ll long long
#define pii pair<int, int>
#define pll pair<ll, ll>
// constexpr ll MOD = 1000000007;
constexpr ll MOD = 998244353;
constexpr int IINF = 1001001001;
constexpr ll INF = 1LL<<60;

template<class t,class u> void chmax(t&a,u b){if(a<b)a=b;}
template<class t,class u> void chmin(t&a,u b){if(b<a)a=b;}

// 問題
// https://atcoder.jp/contests/abc139/tasks/abc139_f

/*
偏角ソートして、区間のベクトルの合計のなかで、距離が最大になるものを取ればよい
これは直感的な話だから、知ってた方が良い
*/

// 座標の構造体
struct Point{
  double x, y;
  Point(){
    x = 0.0;
    y = 0.0;
  }
  Point(double x_, double y_): x(x_), y(y_){
  }
  Point operator +(Point P){
    return Point(x + P.x, y + P.y);
  }
  Point operator -(Point P){
    return Point(x - P.x, y - P.y);
  }
  Point operator *(double k){
    return Point(x * k, y * k);
  }
  Point operator /(double k){
    return Point(x / k, y / k);
  }
};

// 偏角の計算
double argument(Point O, Point P){
    return atan2(P.y-O.y, P.x-O.y);
}

int main(){
    int n; cin >> n;
    vector<Point> v(n);
    rep(i, 0, n){
        double x, y; cin >> x >> y;
        v[i] = Point(x, y);
    }

    sort(v.begin(), v.end(), [](const Point a, const Point b){
        return argument(Point(), a) < argument(Point(), b);
    });

    double ans = 0.0;
    rep(i, 0, n){
        double cx = 0.0, cy = 0.0;
        rep(j, 0, n){
            cx += v[(i+j)%n].x;
            cy += v[(i+j)%n].y;
            chmax(ans, sqrt(cx*cx+cy*cy));
        }
    }

    printf("%.20f\n", ans);

    
    return 0;
}