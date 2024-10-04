#include <bits/stdc++.h>
#include <atcoder/all>
using namespace std;
using namespace atcoder;
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

/*
2つの数列のΣが出てきたら→畳み込みっぽい形
Tを反転すると添え字の和が揃うので、畳み込みに帰着できる
また、xor から 積の和の形にするのは容易
*/

int main(){
    string s, t; cin >> s >> t;
    reverse(t.begin(), t.end());
    int n = (int)s.size(), m = (int)t.size();
    vector<int> s1(n), s2(n), t1(m), t2(m);
    rep(i, 0, n){
        if(s[i] == '1') s1[i] = 1;
        else s2[i] = 1;
    }
    rep(i, 0, m){
        if(t[i] == '1') t1[i] = 1;
        else t2[i] = 1;
    }

    vector<int> c1 = convolution(s1, t2);
    vector<int> c2 = convolution(s2, t1);
    int ans = IINF;
    rep(i, 0, n-m+1){
        chmin(ans, c1[i+m-1]+c2[i+m-1]);
    }
    cout << ans << endl;



    return 0;
}