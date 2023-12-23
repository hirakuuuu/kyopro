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
// https://atcoder.jp/contests/abc192/tasks/abc192_d

int main(){
    string x; cin >> x;
    ll m; cin >> m;
    if(x.size() == 1){
        if((x[0]-'0') <= m) cout << 1 << endl;
        else cout << 0 << endl;
        return 0;
    }

    int d = 0;
    for(auto xx: x){
        chmax(d, (xx-'0'));
    }
    ll ok = d, ng = 2e18;
    while(ng-ok > 1){
        ll mid = (ok+ng)/2;
        // mid進数でｍを表す
        vector<ll> a;
        ll tmp = m;
        while(tmp){
            a.push_back(tmp%mid);
            tmp /= mid;
        }
        reverse(a.begin(), a.end());
        bool f = a.size() > x.size();
        if(a.size() == x.size()){
            bool g = true;
            rep(i, 0, a.size()){
                if((x[i]-'0') < a[i]){
                    g = true;
                    break;
                }
                if((x[i]-'0') > a[i]){
                    g = false;
                    break;
                }
            }
            f = g;
        }

        if(f) ok = mid;
        else ng = mid;
    }
    cout << ok-d << endl;

    
    return 0;
}