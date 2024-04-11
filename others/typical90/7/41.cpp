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

/*
凸包を求める
格子点の数はピックの定理を使う
考察要素は少ないので、コードにコメントを書く
*/

// 座標の構造体
struct Point{
    ll x, y;
    Point(){
    }
    Point(ll x_, ll y_): x(x_), y(y_){
    }
    Point operator +(Point P){
        return Point(x + P.x, y + P.y);
    }
    Point operator -(Point P){
        return Point(x - P.x, y - P.y);
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

int main(){
    int n; cin >> n;
    vector<Point> g(n);
    rep(i, 0, n) cin >> g[i].x >> g[i].y;
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

    // 辺上にある格子点の数を数える
    ll edge_point = convex.size();
    rep(i, 0, convex.size()){
        ll ax = abs(convex[i].x-convex[(i+1)%convex.size()].x);
        ll ay = abs(convex[i].y-convex[(i+1)%convex.size()].y);
        edge_point += gcd(ax, ay)-1; // 頂点以外の格子点の個数を足す
    }

    // 凸包の面積の2倍
    ll area = 0;
    rep(i, 1, convex.size()-1){
        area += abs(cross(convex[i]-convex[0], convex[i+1]-convex[0]));
    }

    cout << (area+edge_point+2)/2-n << endl;
    
    
    return 0;
}

