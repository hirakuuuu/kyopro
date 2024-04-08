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
    string X; cin >> X;
    vector<int> x;
    rep(i, 0, X.size()){
        x.push_back(X[i]-'0');
    }
    ll m; cin >> m;
    int d = -1;
    rep(i, 0, x.size()){
        if(d < x[i]){
            d = x[i];
        }
    }
    if(X.size() == 1){
        if(x[0] > m) cout << 0 << endl;
        else cout << 1 << endl;
        return 0;
    }
    ll ok = d, ng = m+1;
    while(ng-ok > 1){
        ll mid = (ok+ng)/2;
        ll tmp = m;
        vector<ll> base_mid;
        while(tmp){
            base_mid.push_back(tmp%mid);
            tmp /= mid;
        }
        reverse(base_mid.begin(), base_mid.end());
        if(base_mid.size() < x.size()){
            ng = mid;
        }else if(base_mid.size() > x.size()){
            ok = mid;
        }else{
            int sz = (int)base_mid.size();
            bool f = true;
            rep(i, 0, sz){
                if(x[i] == base_mid[i]) continue;
                if(x[i] > base_mid[i]) f = false;
                break;
            }
            if(f) ok = mid;
            else ng = mid;
        }
    }
    cout << max(0LL, ok-(d+1)+1) << endl;
    
    return 0;
}