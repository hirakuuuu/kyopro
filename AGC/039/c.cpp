#include <bits/stdc++.h>
#include <atcoder/all>
using namespace std;
using namespace atcoder;
#define rep(i, a, n) for(int i = a; i < n; i++)
#define rrep(i, a, n) for(int i = a; i >= n; i--)
#define inr(l, x, r) (l <= x && x < r)
#define ll long long
#define ld long double

// using mint = modint1000000007;
using mint = modint998244353;
constexpr int IINF = 1001001001;
constexpr ll INF = 1e18;

template<class t,class u> void chmax(t&a,u b){if(a<b)a=b;}
template<class t,class u> void chmin(t&a,u b){if(b<a)a=b;}

/*
- 0^k1^k...0^k に操作して得られる列の場合 2k 回の操作が必要
- 周期 k をもつという表現が適切
- このように表せない場合は必ず 2n 回の操作が必要
- n/k は奇数でないといけない
- これを満たす k を全探索し，x 以下であるものの数を数える
- 0^k1^k...0^k だけではなく，上位 k 桁を決めたときにそれを反転したものをくっつけていく感じで作れるやつが 2k になる．
- 上位 k 桁が一致するときだけ分けると，適当に処理できそう
- 重複を排除するために調和級数的な感じで倍数になるところを引いておく
- 最上位桁から1が並ぶ個数だけ考えればいける
*/

int main(){


    // auto next = [&](vector<int> x) -> vector<int> {
    //     int n = (int)x.size();
    //     vector<int> res;
    //     res.push_back(1-x[n-1]);
    //     rep(i, 0, n-1){
    //         res.push_back(x[i]);
    //     }
    //     return res;
    // };

    // rep(n, 12, 13){
    //     cout << "#################### n = " << n << " ####################" << endl;
    //     rep(k, 0, 1<<n){
    //         vector<int> x(n);
    //         rep(i, 0, n){
    //             if((k>>i)&1) x[n-1-i] = 1;
    //         }



    //         int cnt = 0;
    //         map<vector<int>, bool> seen;
    //         while(!seen[x]){
    //             seen[x] = true;
    //             x = next(x);
    //             cnt++;
    //         }
    //         if(cnt != 2*n){
    //             rep(i, 0, n) cout << x[i];
    //             cout << ": ";
    //             cout << cnt << endl;
    //         }

    //     }
    // }

    int n; cin >> n;
    string x; cin >> x;

    vector<int> y;
    for(int i = 1; i*i <= n; i++){
        if(n%i == 0){
            if((n/i)%2 == 1) y.push_back(i);
            if(n/i != i){
                if(i%2 == 1) y.push_back(n/i);
            }
        }
    }
    sort(y.begin(), y.end());
    y.erase(unique(y.begin(), y.end()), y.end());

    mint mx = 0;
    rep(i, 0, n){
        mx *= 2;
        mx += (x[i]-'0');
    }
    mint ans = (mx+1)*(2*n);
    vector<mint> pre(n+1);
    for(auto k: y){
        // cout << k << ' ' << ans.val() << ' ' << pre[k].val()  << endl;
        
        string p = x.substr(0, k);
        mint tmp = 0;
        rep(i, 0, k){
            tmp *= 2;
            tmp += (x[i]-'0');
        }
        // p が繰り返し単位となる場合が入るかどうかを判定
        string now = p;
        bool f = 1;
        while(now.size() < n){
            if(f){
                rep(i, 0, k) now.push_back('1'-(p[i]-'0'));
            }else{
                rep(i, 0, k) now.push_back(p[i]);
            }
            f = 1-f;
        }
        // cout << now << ' ' << x << endl; 
        if(now <= x) tmp += 1;
        tmp -= pre[k];
        ans -= tmp*2*n;
        ans += tmp*2*k;

        for(int i = k*2; i <= n; i += k) pre[i] += tmp;
        

 
    }

    cout << ans.val() << endl;



    return 0;
}