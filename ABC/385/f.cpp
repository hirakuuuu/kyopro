#include <bits/stdc++.h>

// 多倍長整数
#include<boost/multiprecision/cpp_int.hpp>
using namespace boost::multiprecision;
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
    vector<cpp_int> x(n), h(n);
    rep(i, 0, n){
        cin >> x[i] >> h[i];
        x[i] *= (cpp_int)1e11;
        h[i] *= (cpp_int)1e11;
    }

    // (x1, y1), (x2, y2) を通る直線に対して，(p, q) が隠れるかどうか
    auto is_beyond = [&](cpp_int x1, cpp_int y1, cpp_int x2, cpp_int y2, cpp_int p, cpp_int q) -> bool {
        return x2*q-y2*p <= y1*(x2-p);
    };

    // 座標 0 から見えるかどうか
    bool flag = true;
    rep(i, 1, n){
        if(is_beyond(0, 0, x[i-1], h[i-1], x[i], h[i])){
            flag = false;
            break;
        }
    }
    if(flag){
        cout << -1 << endl;
        return 0;
    }

    // 二分探索
    cpp_int ok = (cpp_int)1e12+1, ng = 0;
    ok *= (cpp_int)1e11;
    while(ok-ng > 1){
        cpp_int mid = (ok+ng)/2;
        flag = true;
        rep(i, 1, n){
            if(is_beyond(0, mid, x[i-1], h[i-1], x[i], h[i])){
                flag = false;
                break;
            }
        }
        if(flag) ok = mid;
        else ng = mid;
    }
    string ans = to_string(ok);
    while(ans.size() < 12){
        string _ans = "0"+ans;
        swap(ans, _ans);
    }
    int m = ans.size();
    string l = ans.substr(0, m-11), r = ans.substr(m-11, 11);
    cout << l << "." << r << endl;


    return 0;
}