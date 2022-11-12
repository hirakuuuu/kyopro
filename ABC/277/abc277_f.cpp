#include <bits/stdc++.h>
using namespace std;
#define rep(i, a, n) for(int i = a; i < n; i++)
#define ll long long
#define pii pair<int, int>
#define pll pair<ll, ll>
const int MOD = 1000000007;
const int mod = 998244353;

// 問題
// https://atcoder.jp/contests/abc277/tasks/abc277_f

vector<vector<int>> a;


int main(){
    int h, w; cin >> h >> w;
    a.resize(h);
    rep(i, 0, h){
        a[i].resize(w);
        rep(j, 0, w){
            cin >> a[i][j];
        }
    }

    vector<int> col(w);
    iota(col.begin(), col.end(), 0);
    sort(col.begin(), col.end(), [](int& i, int& j){return a[0][i] < a[0][j];});

    rep(i, 1, h){
        rep(j, 0, w-1){
            if(a[i][col[j]] != 0 and a[i][col[j+1]] != 0 and a[i][col[j]] > a[i][col[j+1]]){
                if(a[i-1][col[j]] == 0 or a[i-1][col[j+1]] == 0 or a[i-1][col[j]] == a[i-1][col[j+1]]){
                    swap(col[j], col[j+1]);
                }else{
                    cout << "No" << endl;
                    return 0;
                }
            }
        }
    }

    vector<pii> lr(h);
    rep(i, 0, h){
        rep(j, 0, w){
            if(a[i][col[j]] != 0){
                if(lr[i].first == 0) lr[i].first = a[i][col[j]];
                lr[i].second = a[i][col[j]];
            }
        }
    }

    sort(lr.begin(), lr.end());

    int tmp = lr[0].second;
    rep(i, 1, h){
        if(tmp <= lr[i].first){
            tmp = lr[i].second;
        }else{
            cout << "No" << endl;
            return 0;
        }
    }

    cout << "Yes" << endl;


    
    return 0;
}