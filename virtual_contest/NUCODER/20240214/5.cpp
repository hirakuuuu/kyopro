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
    int n, m; cin >> n >> m;
    stack<int> stc;
    stc.push(1);
    vector<bool> seen(n+1);
    seen[1] = true;

    while(!stc.empty()){
        int k; cin >> k;
        int nxt = -1;
        rep(i, 0, k){
            int v; cin >> v;
            if(nxt == -1 && !seen[v]) nxt = v;
        }
        if(nxt == -1){
            stc.pop();
            nxt = stc.top();
        }else{
            stc.push(nxt);
            seen[nxt] = true;
        }
        cout << nxt << endl;
        if(nxt == n) break;
    }

    string ok; cin >> ok;
    return 0;
}