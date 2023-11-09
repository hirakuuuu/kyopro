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
// https://atcoder.jp/contests/abc059/tasks/arc072_a

ll f(vector<ll> &a){
    ll ans = 0, res = 0;
    ll sum = 0;
    // +-+-...
    rep(i, 0, a.size()){
        sum += a[i];
        if(i%2 == 0){
            if(sum <= 0){
                ans += -sum+1;
                sum = 1;
            }
        }else{
            if(sum >= 0){
                ans += sum+1;
                sum = -1;
            }
        }
    }
    res = ans;
    // -+-+...
    sum = 0, ans = 0;
    rep(i, 0, a.size()){
        sum += a[i];
        if(i%2 == 1){
            if(sum <= 0){
                ans += -sum+1;
                sum = 1;
            }
        }else{
            if(sum >= 0){
                ans += sum+1;
                sum = -1;
            }
        }
    }
    return min(res, ans);
}

int main(){
    int n; cin >> n;
    vector<ll> a(n);
    rep(i, 0, n) cin >> a[i];
    cout << f(a) << endl;

    
    return 0;
}