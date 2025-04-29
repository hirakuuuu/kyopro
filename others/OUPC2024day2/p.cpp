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
    vector<int> a(n);
    rep(i, 0, n){
        string s; cin >> s;
        if(s == "1"){
            a[i] = 0;
        }else if(s == "-1"){
            a[i] = 1;
        }else if(s == "i"){
            a[i] = 2;
        }else{
            a[i] = 3;
        }
    }

    // Ci
    auto mult_i = [&](int C) -> int {
        if(C == 0) return 2;
        if(C == 1) return 3;
        if(C == 2) return 1;
        return 0;
    };
    // A^B*C
    auto calc = [&](int A, int B, int C) -> int {
        int D = 0;
        if(A == 1){
            if(B%2 == 1) D = 1;
        }else if(A == 2){
            if(B%4 == 1) D = 2;
            if(B%4 == 2) D = 1;
            if(B%4 == 3) D = 3;
        }else if(A == 3){
            if(B%4 == 1) D = 3;
            if(B%4 == 2) D = 1;
            if(B%4 == 3) D = 2;
        }

        if(D == 0) return C;
        if(D == 1) return (C^1);
        if(D == 2) return mult_i(C);

        return (mult_i(C)^1);
    };
    int tmp = 0;
    rep(i, 0, n){
        int b; cin >> b;
        tmp = calc(a[i], b, tmp);
    }

    if(tmp == 0) cout << 1 << endl;
    if(tmp == 1) cout << -1 << endl;
    if(tmp == 2) cout << "i" << endl;
    if(tmp == 3) cout << "-i" << endl;
    
    
    return 0;
}