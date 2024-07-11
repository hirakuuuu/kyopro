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
    int cnt = 0, p1 = -1;

    map<tuple<int, int, int>, bool> memo;
    bool f = false;

    // p[i]+p[j] > p[k] かどうか
    auto queri = [&](int i, int j, int k) -> bool {

        if(memo.find({i, j, k}) != memo.end()) return memo[{i, j, k}];
        // if(memo.find({j, i, k}) != memo.end()) return memo[{j, i, k}];

        // if(f){
        //     if(memo.find({k, j, i}) != memo.end()) return memo[{i, j, k}] = !memo[{k, j, i}];
        // }

        cnt++;
        assert(cnt <= 25000);

        cout << "? " << i << ' ' << j << ' ' << k << endl;
        string res; cin >> res;
        assert(res == "Yes" || res == "No");
        return memo[{i, j, k}] = memo[{j, i, k}] = (res == "Yes");
    };

    // 1の位置を特定
    p1 = 1;
    rep(i, 2, n+1){
        if(queri(p1, p1, i)){
            p1 = i;
        }
    }

    vector<int> p = {1};
    auto binary_search = [&](int i) -> void {
        int l = -1, r = p.size();
        while(r-l > 1){
            int m = (l+r)/2;
            if(queri(p[m], p1, i)) r = m;
            else l = m;
        }
        p.insert(p.begin()+r, i);
    };

    rep(i, 2, n+1){
        binary_search(i);
    }
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