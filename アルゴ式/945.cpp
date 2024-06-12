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

/*
ヒストグラムの最大長方形
- 一番右を固定すると、見るべきヒストグラムは階段上になる
- このとき, stack に適切に {左端、高さ} を載せておくことで、O(N) で計算可能
- 今見ている長方形 {i, a[i]} について, stack の先頭の高さが a[i] 以上の間取り出す
- {l, h(>= a[i])} について, (i-l)*h が極大な長方形の1つである
- 見終わったら、{min(l), a[i]} を stack に追加
- 最後に高さ 0 の右端を追加するのを忘れずに
*/



int main(){
    int n; cin >> n;
    vector<int> a(n+1);
    rep(i, 0, n) cin >> a[i];

    auto max_area_histogram = [&](vector<int> a) -> int {
        stack<pair<int, int>> dot;
        int ans = 0;
        // (x座標, 高さ)
        rep(i, 0, n+1){
            int nx = i;
            while(!dot.empty() && dot.top().second >= a[i]){
                auto [cx, cy] = dot.top(); dot.pop();
                chmax(ans, (i-cx)*cy);
                nx = cx;
            }
            dot.push({nx, a[i]});
        }
        return ans;
    };  

    cout << max_area_histogram(a) << endl;
    
    return 0;
}