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
// https://atcoder.jp/contests/abc343/tasks/abc343_e

int vol(int i, int j, int k, int ii, int jj, int kk){
    int a, b, c; 
    if(i <= ii) a = (i+7-ii);
    else a = (ii+7-i);
    if(j <= jj) b = (j+7-jj);
    else b = (jj+7-j);
    if(k <= kk) c = (k+7-kk);
    else c = (kk+7-k);
    return a*b*c;
}

int main(){
    vector<int> v(3);
    rep(i, 0, 3){
         cin >> v[i];
    }
    // 2個だけ重なる or 重ならない
    rep(i, 0, 8){
        rep(j, 0, 8){
            rep(k, 0, 8){
                vector<int> tmp(3);
                tmp[1] = (7-i)*(7-j)*(7-k);
                tmp[0] = 343*3-2*tmp[1];
                if(tmp == v){
                    cout << "Yes" << endl;
                    cout << "0 0 0 ";
                    cout << i << ' ' << j << ' ' << k << ' ';
                    cout << "14 14 14";
                    cout << endl;
                    return 0;
                }
            }
        }
    }
    // 3個重なる
    rep(i, 0, 7) rep(j, 0, 7) rep(k, 0, 7){
        rep(ii, -6, 7) rep(jj, -6, 7) rep(kk, -6, 7){
            vector<int> tmp(3);
            //if(min({7, ii+7, i+7}) < max({0, ii, i}) || min({7, jj+7, j+7}) < max({0, jj, j}) || min({7, kk+7, k+7}) < max({0, kk, k})) continue;
            tmp[2] = (min({7, ii+7, i+7})-max({0, ii, i}))*(min({7, jj+7, j+7})-max({0, jj, j}))* (min({7, kk+7, k+7})-max({0, kk, k}));
            tmp[1] += vol(0, 0, 0, i, j, k);
            tmp[1] += vol(0, 0, 0, ii, jj, kk);
            tmp[1] += vol(i, j, k, ii, jj, kk);
            tmp[1] -= 3*tmp[2];
            tmp[0] = 343*3-2*tmp[1]-3*tmp[2];
            if(tmp == v){
                cout << "Yes" << endl;
                cout << "0 0 0 ";
                cout << i << ' ' << j << ' ' << k << ' ';
                cout << ii << ' ' << jj << ' ' << kk;
                cout << endl;
                return 0;
            }
        }
    }
    cout << "No" << endl;
    return 0;
}