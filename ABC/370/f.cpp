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

int main(){
    int n, k; cin >> n >> k;
    vector<int> a(n);
    rep(i, 0, n){
        cin >> a[i];
    }

    // 切ったらだめな位置の個数を返す判定関数
    const int D = 20;
    auto judge = [&](int x) -> int {
        vector<vector<int>> to(D, vector<int>(n)); // ダブリング用のグラフ
        vector<vector<int>> cost(D, vector<int>(n)); // ピースの個数

        int tmp = 0, w = 0, sum = 0;
        rep(i, 0, n){
            while(sum < x){ // sum が x 未満である限り
                sum += a[tmp]; w++;
                tmp = (tmp+1)%n;
            }
            to[0][i] = tmp;
            cost[0][i] = w;
            sum -= a[i]; w--; // 円環の尺取りはこれでいい
        }

        // ダブリング
        rep(i, 0, D-1){
            rep(j, 0, n){
                to[i+1][j] = to[i][to[i][j]];
                cost[i+1][j] = min(cost[i][j]+cost[i][to[i][j]], n+1); // n+1 個以上になるとだめ
            }
        }

        int res = 0;
        rep(i, 0, n){
            int v = i, co = 0;
            rep(j, 0, D){
                if((k>>j)&1){
                    co += cost[j][v];
                    v = to[j][v];
                }
            }
            if(co > n) res++; 
        }
        return res;
    };

    ll ok = 0, ng = 0; // ng が 2e9 なので ll にしないとオーバーフローする
    rep(i, 0, n) ng += a[i]; // a の合計にしておくと、一周以上する辺を張らなくて済む
    while(ng-ok > 1){
        ll mid = (ok+ng)/2;
        if(judge(mid) == n) ng = mid;
        else ok = mid;
    } 
    cout << ok << ' ' << judge(ok) << endl;
    
    return 0;
}