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
// https://atcoder.jp/contests/abc313/tasks/abc313_d

int hakidashi(vector<vector<int>> &d){
    int h = d.size();
    int w = d[0].size();
    int pos = 0;

    rep(i, 0, w){
        bool found = false;
        rep(j, pos, h){
            if(d[j][i] == 1){
                if(j != pos) swap(d[pos], d[j]);
                found = true;
                break;
            }
        }

        if(found){
            rep(j, 0, h){
                if(j != pos and d[j][i] == 1){
                    rep(k, i, w){
                        d[j][k] ^= d[pos][k];
                    }
                }
            }
            pos++;
        }
    }

    return pos;
}

int main(){
    int n, k; cin >> n >> k;
    int tmp = 0;
    vector<int> a(n), p(n);
    rep(i, 0, k+1){
        cout << '?';
        rep(j, i+1, i+k+1){
            cout << ' ' << (j%(k+1))+1;
        }
        cout << endl;
        cin >> p[i];
        tmp ^= p[i];
    }
    int tmp_ = 0;
    rep(i, 0, k+1){
        a[i] = tmp^p[i];
        if(i < k-1) tmp_ ^= a[i];
    }

    rep(i, 0, n-(k+1)){
        cout << '?' << ' ' << i+(k+1)+1;
        rep(j, 1, k){
            cout << ' ' << j;
        }
        cout << endl;
        cin >> p[i+(k+1)];
        a[i+(k+1)] = p[i+(k+1)]^tmp_;
    }
    
    cout << '!';
    rep(i, 0, n){
        cout << ' ' << a[i];
    }
    cout << endl;
    
    return 0;
}