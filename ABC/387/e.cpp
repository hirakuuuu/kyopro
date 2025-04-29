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


// これが絶対入る？

// 10...16, 10...17
// 20...24, 20...25
// 30...32, 30...33
// 40...40, 40...41
// 50...48, 50...49
// 80...00, 80...01

int main(){

    string s; cin >> s;
    int m = (int)s.size();

    auto f = [&](int n) -> int {
        int res = 0;
        while(n){
            res += n%10;
            n /= 10;
        }
        return res;
    };

    if(m <= 5){
        // 全探索
        int n = stoi(s);
        rep(a, n, 2*n){
            if(a%f(a) == 0 && (a+1)%f(a+1) == 0){
                cout << a << endl;
                return 0;
            }
        }
        cout << -1 << endl;
        return 0;
    }

    // 6 桁以上ある場合
    if(s[0] == '1'){
        string s_ = "1";
        rep(_, 0, m-3) s_.push_back('0');
        s_.push_back('1');
        s_.push_back('6');
        if(s <= s_){
            cout << s_ << endl;
        }else{
            cout << "2";
            rep(_, 0, m-3) cout << "0";
            cout << "2";
            cout << "4";
            cout << endl;
        }
    }else if(s[0] == '2'){
        cout << "3";
        rep(_, 0, m-3) cout << "0";
        cout << "3";
        cout << "2";
        cout << endl;
    }else if(s[0] == '3'){
        cout << "4";
        rep(_, 0, m-3) cout << "0";
        cout << "4";
        cout << "0";
        cout << endl;
    }else if(s[0] == '4'){
        cout << "5";
        rep(_, 0, m-4) cout << "0";
        cout << "1";
        cout << "2";
        cout << "0";
        cout << endl;
    }else if(s[0] == '5'){
        cout << "8";
        rep(_, 0, m-3) cout << "0";
        cout << "0";
        cout << "0";
        cout << endl;
    }else{
        cout << "1";
        rep(_, 0, m-3) cout << "0";
        cout << "0";
        cout << "1";
        cout << "6";
        cout << endl;
    }

    
    return 0;
}