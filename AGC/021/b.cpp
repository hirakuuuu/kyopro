#include <bits/stdc++.h>
// #include <atcoder/all>
using namespace std;
// using namespace atcoder;
#define rep(i, a, n) for(int i = a; i < n; i++)
#define rrep(i, a, n) for(int i = a; i >= n; i--)
#define inr(l, x, r) (l <= x && x < r)
#define ll long long
#define ld long double

// using mint = modint1000000007;
// using mint = modint998244353;
constexpr int IINF = 1001001001;
constexpr ll INF = 9e18;

template<class t,class u> void chmax(t&a,u b){if(a<b)a=b;}
template<class t,class u> void chmin(t&a,u b){if(b<a)a=b;}

/*
x^2+y^2 <= 10^18 とかの領域は考えないで良い
多分凸包を求めて, 垂直二等分線で分断した後に面積比を取る
*/

// 座標の構造体
struct Point{
    long double x, y;
    Point(){
    }
    Point(long double x_, long double y_): x(x_), y(y_){
    }
    Point operator +(Point P){
        return Point(x + P.x, y + P.y);
    }
    Point operator -(Point P){
        return Point(x - P.x, y - P.y);
    }
    Point operator /(long double m){
        return Point(x/m, y/m);
    }
    bool operator<(Point P) {
        if (x < P.x) return true;
        if (x > P.x) return false;
        if (y < P.y) return true;
        return false;
    }
};

// 90度回転
Point rotate90(Point P){
  return Point(P.y, -P.x);
}

// 内積
ll dot(Point P, Point Q){
  return P.x * Q.x + P.y * Q.y;
}

// 外積
ll cross(Point P, Point Q){
  return P.x * Q.y - P.y * Q.x;
}

// 偏角の計算
long double argument(Point O, Point P){
    long double res = atan2(P.y-O.y, P.x-O.y);
    if(res < 0.0) res = 2.0*M_PI+res;
    return res;
}

/*
隣り合っているところの辺の中点を取って、偏角を前のやつと比べて、その差の角度の扇形の面積出良い
*/

int main(){
    int n; cin >> n;
    vector<Point> g(n);
    map<pair<long double, long double>, int> ind; 
    rep(i, 0, n){
        cin >> g[i].x >> g[i].y;
        ind[{g[i].x, g[i].y}] = i;
    }
    sort(g.begin(), g.end());

    // 凸包を求める
    // 上側凸包と下側凸包を同時に求める
    vector<Point> g1, g2, convex;
    g1.push_back(g[0]), g2.push_back(g[0]);
    g1.push_back(g[1]), g2.push_back(g[1]);
    rep(i, 2, n){
        // x座標が小さい順に p1, p2, p3 とする. p1p2, p3p2 の外積が負なら反時計回り
        // このとき、p2 は凸包に含まれない 
        while(g1.size() >= 2 && cross(g1[g1.size()-2]-g1[g1.size()-1], g[i]-g1[g1.size()-1]) <= 0){
            g1.pop_back();
        }
        // x座標が小さい順に p1, p2, p3 とする. p1p2, p3p2 の外積が正なら時計回り
        // このとき、p2 は凸包に含まれない 
        while(g2.size() >= 2 && cross(g2[g2.size()-2]-g2[g2.size()-1], g[i]-g2[g2.size()-1]) >= 0){
            g2.pop_back();
        }
        g1.push_back(g[i]);
        g2.push_back(g[i]);
    }
    // 上側から時計回りに追加
    rep(i, 0, g1.size()) convex.push_back(g1[i]);
    rrep(i, g2.size()-2, 1) convex.push_back(g2[i]);

    vector<long double> ans(n);
    int m = (int)convex.size();
    vector<long double> rad(n);
    rep(i, 0, m){
        int l = ind[{convex[(i+1)%m].x, convex[(i+1)%m].y}];
        Point m1 = convex[(i+1)%m]-convex[i];
        long double r1 = argument(Point(0, 0), m1);
        Point m2 = convex[(i+2)%m]-convex[(i+1)%m];
        long double r2 = argument(Point(0, 0), m2);
        if(r1 < r2) r1 += 2.0*M_PI;
        rad[l] = r1-r2;
        ans[l] = rad[l]/(2.0*M_PI);
    }
    rep(i, 0, n){
        cout << setprecision(20) << ans[i] << endl;
    }
    return 0;
}