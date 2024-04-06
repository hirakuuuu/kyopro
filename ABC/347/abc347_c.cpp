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
    ll n, a, b; cin >> n >> a >> b;
    vector<ll> d(n);
    rep(i, 0, n){
        cin >> d[i];
        d[i] %= (a+b);
    }
    sort(d.begin(), d.end());
    d.erase(unique(d.begin(), d.end()), d.end());
    int mx = 0;
    rep(i, 0, d.size()){
        chmax(mx, (2*(a+b)+d[(i+1)%d.size()]-d[i]-1)%(a+b));
    }
    if(a+b-mx <= a) cout << "Yes" << endl;
    else cout << "No" << endl;
    // if(s.size() >= 3){
    //     if(mx-mi+1 <= a) cout << "Yes" << endl;
    //     else cout << "No" << endl;
    // }else{
    //     if(min(mx-mi+1, (a+b+mi-mx)%(a+b)+1) <= a) cout << "Yes" << endl;
    //     else cout << "No" << endl;
    // }



    
    return 0;
}