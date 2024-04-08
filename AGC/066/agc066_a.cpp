#include <bits/stdc++.h>
using namespace std;
#define rep(i, a, n) for(int i = a; i < n; i++)
#define rrep(i, a, n) for(int i = a; i >= n; i--)
#define inr(l, x, r) (l <= x && x < r)
#define ll long long
#define ld long double
#define pii pair<int, int>
#define pll pair<ll, ll>
// constexpr ll MOD = 1000000007;
constexpr ll MOD = 998244353;
constexpr int IINF = 1001001001;
constexpr ll INF = 1LL<<60;

template<class t,class u> void chmax(t&a,u b){if(a<b)a=b;}
template<class t,class u> void chmin(t&a,u b){if(b<a)a=b;}

int main(){
    int n, d; cin >> n >> d;
    vector<vector<int>> a_(n, vector<int>(n));
    rep(i, 0, n){
        rep(j, 0, n){
            cin >> a_[i][j];
        }
    }

    int sum = 0;
    rep(k, 0, 2*d){
        // i+jが奇数のマスは k, 偶数のマスは k+d (mod. 2d) にする
        // ある k については、コストが条件を満たすので、それを出力
        vector<vector<int>> a = a_;
        int cost = 0;
        rep(i, 0, n){
            rep(j, 0, n){
                if((i+j)%2){
                    int r = (4*d+k-a[i][j]%(2*d))%(2*d);
                    if(r < 2*d-r){
                        a[i][j] += r;
                        cost += r;
                    }else{
                        a[i][j] -= 2*d-r;
                        cost += 2*d-r;
                    }
                }else{
                    int r = (4*d+k+d-a[i][j]%(2*d))%(2*d);
                    if(r < 2*d-r){
                        a[i][j] += r;
                        cost += r;
                    }else{
                        a[i][j] -= 2*d-r;
                        cost += 2*d-r;
                    }
                }
            }
        }
        if(cost <= (d*n*n)/2){
            rep(i, 0, n){
                rep(j, 0, n){
                    cout << a[i][j] << ' ';
                }
                cout << endl;
            }
            return 0;
        }
    }


    return 0;
}