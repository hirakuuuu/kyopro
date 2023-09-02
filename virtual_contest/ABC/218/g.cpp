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

multiset<int> s, t;
vector<int> a(100005), dp(100005);
vector<vector<int>> g(100005);
// s.size() = t.size() || s.size() = t.size()+1
void eval(int u){
    if(s.size() == t.size()) s.insert(u);
    else t.insert(u);

    if(s.empty() || t.empty()) return;
    if(*s.rbegin() > *t.begin()){
        int tmp_s = *s.rbegin(), tmp_t = *t.begin();
        s.erase(s.find(tmp_s)); s.insert(tmp_t);
        t.erase(t.find(tmp_t)); t.insert(tmp_s);
    }
}

void erase(int u){
    if(s.find(u) != s.end()) s.erase(s.find(u));
    else t.erase(t.find(u));

    if(s.size() < t.size()){
        s.insert(*t.begin()); t.erase(t.begin());
    }else if(s.size() == t.size()+2){
        t.insert(*s.rbegin()); s.erase(s.find(*s.rbegin()));
    }
}

void dfs(int pos, int par, int d){
    eval(a[pos]);
    int ma = 0, mi = IINF;
    for(auto npos: g[pos]){
        if(npos == par) continue;
        dfs(npos, pos, d+1);
        chmax(ma, dp[npos]);
        chmin(mi, dp[npos]);
    }

    if(ma == 0){
        if(s.size() == t.size()) dp[pos] = (*s.rbegin()+*t.begin())/2;
        else dp[pos] = *s.rbegin();
    }else if(d&1) dp[pos] = ma;
    else dp[pos] = mi;

    erase(a[pos]);
}

int main(){
    int n; cin >> n;
    rep(i, 0, n) cin >> a[i];
    rep(i, 0, n-1){
        int u, v; cin >> u >> v;
        u--, v--;
        g[u].push_back(v);
        g[v].push_back(u);
    }

    dfs(0, -1, 1);
    cout << dp[0] << endl;

    
    return 0;
}