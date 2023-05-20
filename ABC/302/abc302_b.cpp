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
// https://atcoder.jp/contests/abc302/tasks/abc302_b

int main(){
    int h, w; cin >> h >> w;
    vector<string> s(h);
    rep(i, 0, h) cin >> s[i];

    // 横右向き
    rep(i, 0, h){
        rep(j, 0, w-4){
            string t;
            rep(k, 0, 5) t += s[i][j+k];
            if(t == "snuke"){
                rep(k, 0, 5){
                    cout << i+1 << ' ' << j+k+1 << endl;
                }
                return 0;
            }
        }
    }
    // 横左向き
    rep(i, 0, h){
        rep(j, 4, w){
            string t;
            rep(k, 0, 5) t += s[i][j-k];
            if(t == "snuke"){
                rep(k, 0, 5){
                    cout << i+1 << ' ' << j-k+1 << endl;
                }
                return 0;
            }
        }
    }

   
    // 縦下向き
    rep(i, 0, h-4){
        rep(j, 0, w){
            string t;
            rep(k, 0, 5) t += s[i+k][j];
            if(t == "snuke"){
                rep(k, 0, 5){
                    cout << i+k+1 << ' ' << j+1 << endl;
                }
                return 0;
            }
        }
    }
    // 縦下向き
    rep(i, 4, h){
        rep(j, 0, w){
            string t;
            rep(k, 0, 5) t += s[i-k][j];
            if(t == "snuke"){
                rep(k, 0, 5){
                    cout << i-k+1 << ' ' << j+1 << endl;
                }
                return 0;
            }
        }
    } 
    // 斜め右下
    rep(i, 0, h-4){
        rep(j, 0, w-4){
            string t;
            rep(k, 0, 5) t += s[i+k][j+k];
            if(t == "snuke"){
                rep(k, 0, 5){
                    cout << i+k+1 << ' ' << j+k+1 << endl;
                }
                return 0;
            }
        }
    }
    // 斜め左下
    rep(i, 0, h-4){
        rep(j, 4, w){
            string t;
            rep(k, 0, 5) t += s[i+k][j-k];
            if(t == "snuke"){
                rep(k, 0, 5){
                    cout << i+k+1 << ' ' << j-k+1 << endl;
                }
                return 0;
            }
        }
    }
    // 斜め右上
    rep(i, 4, h){
        rep(j, 0, w-4){
            string t;
            rep(k, 0, 5) t += s[i-k][j+k];
            if(t == "snuke"){
                rep(k, 0, 5){
                    cout << i-k+1 << ' ' << j+k+1 << endl;
                }
                return 0;
            }
        }
    }
    // 斜め左上
    rep(i, 4, h){
        rep(j, 4, w){
            string t;
            rep(k, 0, 5) t += s[i-k][j-k];
            if(t == "snuke"){
                rep(k, 0, 5){
                    cout << i-k+1 << ' ' << j-k+1 << endl;
                }
                return 0;
            }
        }
    }
    return 0;
}