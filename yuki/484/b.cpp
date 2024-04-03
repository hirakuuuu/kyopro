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

int main(){
    int n; cin >> n;
    vector<int> a(n);
    rep(i, 0, n) cin >> a[i];
    int acc = 0;
    rep(i, 0, n) acc ^= a[i];
    if(acc != 0){
        cout << "No" << endl;
        return 0;
    }
    set<int> s(a.begin(), a.end());
    if((2 < n && s.size() < n) || *s.begin() == 0){
        cout << "Yes" << endl;
        return 0;
    }
    vector<bool> dp(5005);
    dp[a[0]] = true;
    rep(i, 1, n){
        if(dp[0]){
            cout << "Yes" << endl;
            return 0;
        }
        vector<bool> dp_ = dp;
        rep(j, 0, 5005){
            if(dp_[j] && (j^a[i]) < 5005){
                dp[j^a[i]] = true;
            }
        }
        dp[a[i]] = true;
    }

    cout << "No" << endl;

    
    return 0;
}