#include <bits/stdc++.h>
// #include <atcoder/all>
using namespace std;
// using namespace atcoder;
#define rep(i, a, n) for(int i = a; i < n; i++)
#define rrep(i, a, n) for(int i = a; i >= n; i--)
#define inr(l, x, r) (l <= x && x < r)
#define ll long long
#define ld long double

// using mint = modint1000000007;
// using mint = modint998244353;
constexpr int IINF = 1001001001;
constexpr ll INF = 1e18;

template<class t,class u> void chmax(t&a,u b){if(a<b)a=b;}
template<class t,class u> void chmin(t&a,u b){if(b<a)a=b;}

int main(){
    int T; cin >> T;
    while(T--){
        int n; cin >> n;
        vector<ll> s(n);
        vector<ll> t;
        rep(i, 0, n){
            cin >> s[i];
            if(inr(1, i, n-1)) t.push_back(s[i]);
        }
        sort(t.begin(), t.end());

        if(n == 2){
            if(s[1] <= s[0]*2){
                cout << 2 << endl;
            }else{
                cout << -1 << endl;
            }
            continue;
        }
        
        bool ok = true;
        ll ans = 2;
        ll tmp = s[0]*2;
        int pos = 0;
        while(tmp < s[n-1]){
            auto itr = upper_bound(t.begin()+pos, t.end(), tmp);
            if(itr-t.begin() == pos){
                ok = false;
                break;
            }
            pos = itr-t.begin();
            itr = prev(itr);
            tmp = (*itr)*2;
            ans++;
        }
        if(ok) cout << ans << endl;
        else cout << -1 << endl;
    }
    return 0;
}