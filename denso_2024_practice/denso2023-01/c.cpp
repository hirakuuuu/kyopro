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
    int n, m, x, y; cin >> n >> m >> x >> y;
    vector<int> in_a(n);
    rep(i, 0, m){
        int a; cin >> a; a--;
        in_a[a]++;
    }

    string s; cin >> s;
    int cnt = 0, cnt_a = 0;
    rep(i, 0, n){
        if(s[i] == 'o'){
            cnt++;
            if(in_a[i]) cnt_a++;
        }
    }

    if(cnt >= x && m-cnt_a <= y) cout << "Yes" << endl;
    else cout << "No" << endl;
    return 0;
}