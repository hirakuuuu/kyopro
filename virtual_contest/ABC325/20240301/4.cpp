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
    int n; cin >> n;
    vector<pair<ll, ll>> td(n);
    rep(i, 0, n){
        cin >> td[i].first >> td[i].second;
        td[i].second += td[i].first;
    }
    sort(td.begin(), td.end());
    priority_queue<ll, vector<ll>, greater<ll>> que;
    que.push(td[0].second);
    ll p = td[0].first;
    int ans = 0;
    rep(i, 1, n){
        if(td[i].first != td[i-1].first){
            while(!que.empty() && p < td[i].first){
                ll q = que.top(); que.pop();
                if(q >= p){
                    ans++;
                    p++;
                }
            }
            if(que.empty()) p = td[i].first;
        }
        que.push(td[i].second);
    }
    while(!que.empty()){
        ll q = que.top(); que.pop();
        if(q >= p){
            ans++;
            p++;
        }
    }
    cout << ans << endl;
    return 0;
}