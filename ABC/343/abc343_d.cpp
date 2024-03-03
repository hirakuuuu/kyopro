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
// https://atcoder.jp/contests/abc343/tasks/abc343_d

int main(){
    ll n, t; cin >> n >> t;
    map<ll, ll> cnt;
    cnt[0] = n;
    set<ll> s;
    vector<ll> score(n);
    s.insert(0);
    while(t--){
        ll a, b; cin >> a >> b;
        a--;
        cnt[score[a]]--;
        if(cnt[score[a]] == 0) s.erase(s.find(score[a]));
        score[a] += b;
        cnt[score[a]]++;
        if(cnt[score[a]] == 1) s.insert(score[a]);
        cout << s.size() << endl;
    }
    
    return 0;
}