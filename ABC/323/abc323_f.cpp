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
// https://atcoder.jp/contests/abc323/tasks/abc323_f

int main(){
    vector<ll> x(3), y(3);
    rep(i, 0, 3) cin >> x[i] >> y[i];

    vector<ll> ans(2);
    if(y[0] == y[1] && ((x[2] <= x[1] && x[0] <= x[1]) || (x[1] <= x[0] && x[1] <= x[2]))){
        rep(i, 0, 2) ans[i]++;
        if(y[0] < y[2]) y[0]--;
        else y[0]++;
    }else if(x[0] == x[1] && ((y[2] <= y[1] && y[0] <= y[1]) || (y[1] <= y[0] && y[1] <= y[2]))){
        rep(i, 0, 2) ans[i]++;
        if(x[0] < x[2]) x[0]--;
        else x[0]++;
    }

    // 縦をそろえて、横をそろえる
    ll cx = x[0], cy = y[0];
    if(y[2] != y[1]){
        if(y[2]-y[1] > 0){
            ans[0] += abs(cx-x[1])+abs(cy-y[1]+1);
            ans[0] += abs(y[2]-y[1]);
            cx = x[1], cy = y[2]-1;
        }else{
            ans[0] += abs(cx-x[1])+abs(cy-y[1]-1);
            ans[0] += abs(y[2]-y[1]);
            cx = x[1], cy = y[2]+1;
        }
    }

    if(x[2] != x[1]){
        if(x[2]-x[1] > 0) ans[0] += abs(cx-x[1]+1)+abs(cy-y[2]);
        else ans[0] += abs(cx-x[1]-1)+abs(cy-y[2]);
        ans[0] += abs(x[2]-x[1]);
    }


    // 横をそろえて、縦をそろえる
    cx = x[0], cy = y[0];
    if(x[2] != x[1]){
        if(x[2]-x[1] > 0){
            ans[1] += abs(cx-x[1]+1)+abs(cy-y[1]);
            ans[1] += abs(x[2]-x[1]);
            cx = x[2]-1, cy = y[1];
        }else{
            ans[1] += abs(cx-x[1]-1)+abs(cy-y[1]);
            ans[1] += abs(x[2]-x[1]);
            cx = x[2]+1, cy = y[1];
        }
    }
    if(y[2] != y[1]){
        if(y[2]-y[1] > 0) ans[1] += abs(cx-x[2])+abs(cy-y[1]+1);
        else ans[1] += abs(cx-x[2])+abs(cy-y[1]-1);
        ans[1] += abs(y[2]-y[1]);
    }

    cout << min(ans[0], ans[1]) << endl;



    
    return 0;
}