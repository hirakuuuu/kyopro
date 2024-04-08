#include <bits/stdc++.h>
using namespace std;
#define rep(i, a, n) for(int i = a; i < n; i++)
#define rrep(i, a, n) for(int i = a; i >= n; i--)
#define inr(l, x, r) (l <= x && x < r)
#define ll long long
#define ld long double
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
    string a, b; cin >> a >> b;
    int ans = 0;
    rep(i, 0, n/2){
        // a[i], a[n-1-i], b[i], b[n-1-i]
        vector<char> c = {a[i], a[n-i-1], b[i], b[n-i-1]};
        sort(c.begin(), c.end());
        set<char> s;
        rep(i, 0, 4) s.insert(c[i]);
        if(s.size() == 4){
            ans += 2;
        }else if(s.size() == 3){
            if(a[i] == a[n-i-1]) ans += 2;
            else ans += 1;
        }else if(s.size() == 2){
            bool f = false;
            rep(i, 1, 3){
                if(c[i-1] == c[i] & c[i] == c[i+1]) f = true;
            }
            if(f) ans += 1;
        }
    }
    if(n%2){
        if(a[n/2] != b[n/2]) ans++;
    }
    cout << ans << endl;
    
    return 0;
}