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
// 

int main(){
    int w, h, n; cin >> w >> h >> n;
    vector<int> ans(4);
    ans[1] = w;
    ans[3] = h;
    rep(i, 0, n){
        int x, y, a; cin >> x >> y >> a;
        a--;
        if(a == 0){
            chmax(ans[a], x);
        }else if(a == 1){
            chmin(ans[a], x);
        }else if(a == 2){
            chmax(ans[a], y);
        }else if(a == 3){
            chmin(ans[a], y);
        }
    }

    cout << max(0, ans[1]-ans[0])*max(0, ans[3]-ans[2]) << endl;
    
    return 0;
}