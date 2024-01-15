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
// https://atcoder.jp/contests/abc130/tasks/abc130_f

int main(){
    int n; cin >> n;
    string D = "RLUD";
    vector<double> mx(4, 1e18), my(4, 1e18);
    vector<double> Mx(4, -1e18), My(4, -1e18);
    rep(i, 0, n){
        int x, y;
        char d; cin >> x >> y >> d;
        rep(j, 0, 4){
            if(D[j] == d){
                chmin(mx[j], x);
                chmin(my[j], y);
                chmax(Mx[j], x);
                chmax(My[j], y);
            }
        }
    }

    // 初期状態
    double X = max({Mx[0], Mx[1], Mx[2], Mx[3]})-min({mx[0], mx[1], mx[2], mx[3]});
    double Y = max({My[0], My[1], My[2], My[3]})-min({my[0], my[1], my[2], my[3]});
    double ans = X*Y, t;

    // x
    if(Mx[0] != -1e18 && Mx[1] != -1e18){
        if(Mx[0] != -1e18 && Mx[1] != -1e18) t = min(Mx[1]-Mx[0], mx[1]-mx[0])/2.0;
        else if(Mx[0] != -1e18) t = max(max(Mx[2], Mx[3])-Mx[0], 0.0);
        else if(Mx[1] != -1e18) t = max(mx[1]-min(mx[2], mx[3]), 0.0);
        X = max({Mx[0]+t, Mx[1]-t, Mx[2], Mx[3]})-min({mx[0]+t, mx[1]-t, mx[2], mx[3]});
        Y = max({My[0], My[1], My[2]+t, My[3]-t})-min({my[0], my[1], my[2]+t, my[3]-t});
        chmin(ans, X*Y);
    }

    // rep(i, 0, 4) cout << Mx[i] << ' ' << mx[i] << ' ';
    // cout << endl;
    // rep(i, 0, 4) cout << My[i] << ' ' << my[i] << ' ';
    // cout << endl;

    if((Mx[0] < Mx[1] && mx[0] < mx[1]) && (My[2] >= My[3] || my[2] >= my[3])){
        if(Mx[0] != -1e18 && Mx[1] != -1e18) t = min(Mx[1]-Mx[0], mx[1]-mx[0])/2.0;
        else if(Mx[0] != -1e18) t = max(max(Mx[2], Mx[3])-Mx[0], 0.0);
        else if(Mx[1] != -1e18) t = max(mx[1]-min(mx[2], mx[3]), 0.0);
        X = max({Mx[0]+t, Mx[1]-t, Mx[2], Mx[3]})-min({mx[0]+t, mx[1]-t, mx[2], mx[3]});
        Y = max({My[0], My[1], My[2]+t, My[3]-t})-min({my[0], my[1], my[2]+t, my[3]-t});
        chmin(ans, X*Y);
    }else if((Mx[0] >= Mx[1] || mx[0] >= mx[1]) && (My[2] < My[3] && my[2] < my[3])){
        if(Mx[2] != -1e18 && Mx[3] != -1e18) t = min(My[3]-My[2], my[3]-my[2])/2.0;
        else if(Mx[2] != -1e18) t = max(max(My[0], My[1])-My[2], 0.0);
        else if(Mx[3] != -1e18) t = max(my[3]-min(my[0], my[1]), 0.0);
        X = max({Mx[0]+t, Mx[1]-t, Mx[2], Mx[3]})-min({mx[0]+t, mx[1]-t, mx[2], mx[3]});
        Y = max({My[0], My[1], My[2]+t, My[3]-t})-min({my[0], my[1], my[2]+t, my[3]-t});
        chmin(ans, X*Y);
    }else{
        if(Mx[0] != -1e18 && Mx[1] != -1e18) t = min(Mx[1]-Mx[0], mx[1]-mx[0])/2.0;
        else if(Mx[0] != -1e18) t = max(max(Mx[2], Mx[3])-Mx[0], 0.0);
        else if(Mx[1] != -1e18) t = max(mx[1]-min(mx[2], mx[3]), 0.0);

        X = max({Mx[0]+t, Mx[1]-t, Mx[2], Mx[3]})-min({mx[0]+t, mx[1]-t, mx[2], mx[3]});
        Y = max({My[0], My[1], My[2]+t, My[3]-t})-min({my[0], my[1], my[2]+t, my[3]-t});
        chmin(ans, X*Y);

        if(Mx[2] != -1e18 && Mx[3] != -1e18) t = min(My[3]-My[2], my[3]-my[2])/2.0;
        else if(Mx[2] != -1e18) t = max(max(My[0], My[1])-My[2], 0.0);
        else if(Mx[3] != -1e18) t = max(my[3]-min(my[0], my[1]), 0.0);

        X = max({Mx[0]+t, Mx[1]-t, Mx[2], Mx[3]})-min({mx[0]+t, mx[1]-t, mx[2], mx[3]});
        Y = max({My[0], My[1], My[2]+t, My[3]-t})-min({my[0], my[1], my[2]+t, my[3]-t});
        chmin(ans, X*Y);

    }
    printf("%.20f\n", ans);
    
    return 0;
}