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
// https://atcoder.jp/contests/abc325/tasks/abc325_d

int main(){
    int n; cin >> n;
    vector<ll> t(n), d(n);
    vector<pair<ll, ll>> e(n);
    rep(i, 0, n){
        cin >> t[i] >> d[i];
        e[i] = {t[i], t[i]+d[i]};
    }
    sort(e.begin(), e.end());

    int ind = 0, ans = 0;
    priority_queue<ll, vector<ll>, greater<ll>> que;
    for(ll i = 0; ; i++){
        if(que.empty()){
            if(ind == n) break;
            i = e[ind].first;
        }

        while(ind < n && i == e[ind].first){
            que.push(e[ind].second);
            ind++;
        }

        while(!que.empty() && que.top() < i) que.pop();
        if(!que.empty()){
            ans++;
            que.pop();
        }
    }

    cout << ans << endl;

    
    return 0;
}