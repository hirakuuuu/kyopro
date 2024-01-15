#include <bits/stdc++.h>
using namespace std;
#define rep(i, a, n) for(ll i = a; i < n; i++)
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
// https://atcoder.jp/contests/abc116/tasks/abc116_d

int main(){
    ll n, k; cin >> n >> k;
    vector<vector<ll>> sushi(n);
    rep(i, 0, n){
        ll t, d; cin >> t >> d;
        t--;
        sushi[t].push_back(d);
    }
    
    vector<ll> m, M;
    rep(i, 0, n){
        if(sushi[i].empty()) continue;
        sort(sushi[i].begin(), sushi[i].end());
        rep(j, 0, sushi[i].size()){
            if(j == sushi[i].size()-1) M.push_back(sushi[i][j]);
            else m.push_back(sushi[i][j]);
        }
    }

    sort(M.rbegin(), M.rend());
    sort(m.rbegin(), m.rend());
    ll tmp = 0, cnt = 0;
    rep(i, 0, min(k, (ll)m.size())){
        tmp += m[i];
        cnt++;
    }
    ll s = 0;
    while(cnt < k){
        tmp += M[s];
        s++;
        cnt++;
    }
    ll ans = tmp+s*s;
    rep(i, s, min(k, (ll)M.size())){
        tmp -= m[min(k, (ll)m.size())-i+s-1];
        tmp += M[i];
        //cout << m[min(k, (ll)m.size())-i+s-1] << ' ' << M[i] << ' ' << tmp << endl;
        chmax(ans, tmp+(i+1)*(i+1));
    }
    cout << ans << endl;



    return 0;
}