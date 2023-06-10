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
// https://atcoder.jp/contests/abc305/tasks/abc305_f

int main(){
    int n, m; cin >> n >> m;
    vector<bool> seen(n+1);
    seen[1] = true;
    stack<int> stc;
    stc.push(1);
    while(true){
        int k; cin >> k;
        vector<int> v(k);
        int next = 0;
        rep(i, 0, k){
            cin >> v[i];
            if(!seen[v[i]]&& !next) next = v[i];
        }

        if(next){
            seen[next] = true;
            stc.push(next);
        }else{
            stc.pop();
            next = stc.top();
        }

        if(next == n){
            cout << n << endl;
            string OK; cin >> OK;
            return 0;
        }else{
            cout << next << endl;
        }
    }
    
    return 0;
}