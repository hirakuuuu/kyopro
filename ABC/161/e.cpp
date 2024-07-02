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
constexpr ll INF = 9e18;

template<class t,class u> void chmax(t&a,u b){if(a<b)a=b;}
template<class t,class u> void chmin(t&a,u b){if(b<a)a=b;}

int main(){
    int n, k, c; cin >> n >> k >> c;
    string s; cin >> s;
    int cnt = 0;
    rep(i, 0, n){
        if(s[i] == 'o') cnt++;
    }
    if(cnt == k){
        rep(i, 1, n+1){
            if(s[i-1] == 'o') cout << i << endl;
        }
        return 0;
    }

    vector<int> l(n+1), r(n+2);
    rep(i, 0, n){
        l[i+1] = l[i];
        if(s[i] =='o'){
            if(i <= c) chmax(l[i+1], 1);
            else chmax(l[i+1], l[i-c]+1);
        }
    }
    rrep(i, n, 1){
        r[i] = r[i+1];
        if(s[i-1] =='o'){
            if(i >= n-c) chmax(r[i], 1);
            else chmax(r[i], r[i+c+1]+1);
        }
    }

    multiset<int> tmp;
    vector<int> ans(n+1);
    rep(i, 1, n+1){
        chmax(ans[i], r[i+1]);
        chmax(ans[i], l[i-1]);
    }
    rep(i, 1, n+1){
        if(i <= n-c+1) tmp.insert(l[i-1]+r[i+c]);
        chmax(ans[i], *tmp.rbegin());
        if(c <= i) tmp.erase(tmp.find(l[i-c]+r[i+1]));
    }
    rep(i, 1, n+1){
        if(s[i-1] == 'o' && ans[i] < k){
            cout << i << endl; 
        }
    }

    return 0;
}