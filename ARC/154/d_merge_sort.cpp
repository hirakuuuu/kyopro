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

    int n; cin >> n;
    int cnt = 0;

    // p[i]+p[j] > p[k] かどうか
    auto queri = [&](int i, int j, int k) -> bool {

        cnt++;
        assert(cnt <= 25000);

        cout << "? " << i << ' ' << j << ' ' << k << endl;
        string res; cin >> res;
        assert(res == "Yes" || res == "No");
        return res == "Yes";
    };

    // 1の位置を特定
    int p1 = 1;
    rep(i, 2, n+1){
        if(queri(p1, p1, i)){
            p1 = i;
        }
    }
    assert(inr(1, p1, n+1));

    // ソート
    // 標準のソートだと厳密に nlogn で抑えられない
    // stable_sort でマージソートが実装されているので、こちらだと厳密に nlogn が最大の比較回数となる.
    vector<int> p(n);
    iota(p.begin(), p.end(), 1);
    stable_sort(p.begin(), p.end(), [&](int a, int b){
        if(a == b) return false;
        if(a == p1) return true;
        if(b == p1) return false;
        return !queri(a, p1, b);
    });
    assert(p[0] == p1);
    vector<int> ans(n);
    rep(i, 0, n) ans[p[i]-1] = i+1;

    cout << '!';
    rep(i, 0, n){
        cout << ' ' << ans[i];
    }
    cout << endl;


    
    return 0;
}