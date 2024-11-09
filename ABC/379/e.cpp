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
    int n; cin >> n;
    string s; cin >> s;
    vector<ll> acc(n+1);
    rep(i, 1, n+1){
        acc[i] = acc[i-1]+(ll)(s[i-1]-'0')*i;
    }

    vector<int> ans;
    ll tmp = 0;
    int r = n;
    while(true){
        if(r > 0){
            tmp += acc[r];
            r--;
        }
        ans.push_back(tmp%10);
        tmp /= 10;
        if(tmp == 0 && r <= 0) break;
    }
    reverse(ans.begin(), ans.end());
    for(auto aa: ans){
        cout << aa;
    }
    cout << endl;
    
    return 0;
}