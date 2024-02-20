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
    vector<int> a(n), b(n);
    vector<pair<int, int>> e(2*n+1, {-1, -1});
    rep(i, 0, n){
        cin >> a[i] >> b[i];
        if(a[i] != -1 && b[i] != -1 && a[i] >= b[i]){
            cout << "No" << endl;
            return 0;
        }
        if(a[i] != -1){
            if(e[a[i]].first != -1){
                cout << "No" << endl;
                return 0;
            }
            e[a[i]] = {0, i};
        }
        if(b[i] != -1){
            if(e[b[i]].first != -1){
                cout << "No" << endl;
                return 0;
            }
            e[b[i]] = {1, i};
        }
    }

    vector<bool> dp(2*n+1);
    dp[0] = true;
    rep(i, 0, 2*n+1){
        if(dp[i]){
            rep(j, i+2, 2*n+1){
                if((j-i)%2) continue;
                // [i+1, j] で達成可能か
                bool ok = true;
                rep(k, i+1, i+1+(j-i)/2){
                    if(e[k].first == 1 || e[k+(j-i)/2].first == 0) ok = false;
                    if(e[k].second != -1 && e[k+(j-i)/2].second != -1 && e[k].second != e[k+(j-i)/2].second) ok = false;
                }
                if(ok) dp[j] = true;
            }
        }
    }
    if(dp[2*n]) cout << "Yes" << endl;
    else cout << "No" << endl;


    
    return 0;
}