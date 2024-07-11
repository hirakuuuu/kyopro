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

/*
括弧列にできるかを考える上で、() が隣接しているところは除いても良い
そうすると　)))...)(((...( みたいな文字列になる
これは折れ線で考えると単なる V 字
実は、増加する部分に関しては、最小値が大きいものから取っていくのが最適
逆からも同じ議論ができる
それによって構成した括弧列は、合計がちょうど揃っていれば過去列になります。

*/


int main(){
    int n; cin >> n;
    vector<string> s(n);
    rep(i, 0, n){
        cin >> s[i];
        string t; t += s[i][0];
        rep(j, 1, s[i].size()){
            if(t.back() == '(' && s[i][j] == ')') t.pop_back();
            else t.push_back(s[i][j]);
        }
        s[i] = t;
    }

    vector<int> a(n), b(n);
    vector<pair<int, int>> f, l;
    rep(i, 0, n){
        rep(j, 0, s[i].size()){
            if(s[i][j] == '(') a[i]++;
            else b[i]++;
        }
        if(a[i]-b[i] >= 0) f.push_back({b[i], i});
        else l.push_back({a[i], i});
    }
    sort(f.begin(), f.end());
    sort(l.rbegin(), l.rend());

    string ans;
    for(auto [_, ind]: f) ans += s[ind];
    for(auto [_, ind]: l) ans += s[ind];

    int acc = 0;
    for(auto aa: ans){
        if(aa == '(') acc++;
        else acc--;
        if(acc < 0){
            cout << "No" << endl;
            return 0;
        }
    }

    if(acc == 0) cout << "Yes" << endl;
    else cout << "No" << endl;





    
    
    return 0;
}