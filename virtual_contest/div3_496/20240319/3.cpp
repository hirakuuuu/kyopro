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
// div3_496

int main(){
    int n; cin >> n;
    vector<ll> a(n);
    rep(i, 0, n) cin >> a[i];
    map<int, int> cnt;
    rep(i, 0, n) cnt[a[i]]++;
    sort(a.begin(), a.end());
    int ans = 0;
    rep(i, 0, n){
        bool ok = false;
        rep(j, 0, 33){
            if((1LL<<j) <= a[i]) continue;
            auto itr = lower_bound(a.begin(), a.end(), (1LL<<j)-a[i]);
            if(itr == a.end()) continue;
            if(*itr == (1LL<<j)-a[i]){
                if(*itr == a[i]){
                    if(cnt[a[i]] >= 2) ok = true;
                }else{
                    ok = true;
                }
            }
        }
        if(!ok) ans++;
    }
    cout << ans << endl;
    
    return 0;
}