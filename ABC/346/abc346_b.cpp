#include <bits/stdc++.h>
using namespace std;
#define rep(i, a, n) for(int i = a; i < n; i++)
#define rrep(i, a, n) for(int i = a; i >= n; i--)
#define ll long long
#define pii pair<int, int>
#define pll pair<ll, ll>
// constexpr ll MOD = 1000000007;
constexpr ll MOD = 998244353;
constexpr int IINF = 1001001001;
constexpr ll INF = 1LL<<60;

template<class t,class u> void chmax(t&a,u b){if(a<b)a=b;}
template<class t,class u> void chmin(t&a,u b){if(b<a)a=b;}

// 問題
// https://atcoder.jp/contests/abc346/tasks/abc346_b

int main(){
    int w, b; cin >> w >> b;
    string s = "wbwbwwbwbwbw";
    string t;
    rep(i, 0, 100){
        t += s;
    }
    rep(i, 0, t.size()-w-b+1){
        string ss = t.substr(i, w+b);
        int cnt_w = 0, cnt_b = 0;
        for(auto sss: ss){
            if(sss == 'w') cnt_w++;
            if(sss == 'b') cnt_b++;
        }
        if(w == cnt_w && b == cnt_b){
            cout << "Yes" << endl;
            return 0;
        }
    }
    cout << "No" << endl;

    return 0;
}