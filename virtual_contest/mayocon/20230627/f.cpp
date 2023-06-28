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



int main(){
    int n; cin >> n;
    vector<pll> w(n);
    rep(i, 0, n){
        cin >> w[i].first >> w[i].second;
    }
    sort(w.begin(), w.end(), [&](pll i, pll j) {
        return i.second*(j.first-1) < j.second*(i.first-1);
    });


    int ans = 0;
    pll last = {0LL, 0LL};
    rep(i, 0, n){
        if((w[i].second-1)*last.first >= last.second*w[i].first){
            ans++;
            last = {w[i].first-1, w[i].second};
        }
    }

    cout << ans << endl;


    rep(i, 0, n){

    }
    
    return 0;
}