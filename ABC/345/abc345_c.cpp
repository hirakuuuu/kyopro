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
// https://atcoder.jp/contests/abc345/tasks/abc345_c

int main(){
    string s; cin >> s;
    ll n = s.size();
    vector<int> cnt(26);
    rep(i, 0, n) cnt[s[i]-'a']++;
    ll ans = 0;
    rep(i, 0, 26){
        if(cnt[i] >= 2){
            ans++;
            break;
        }
    }

    vector<ll> acc(26);
    rep(i, 0, n){
        ans += (ll)i-acc[s[i]-'a'];
        acc[s[i]-'a']++;
    }
    cout << ans << endl;

    
    return 0;
}