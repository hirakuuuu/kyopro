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
constexpr ll INF = 1e18;

template<class t,class u> void chmax(t&a,u b){if(a<b)a=b;}
template<class t,class u> void chmin(t&a,u b){if(b<a)a=b;}

int main(){

    int n; cin >> n;
    if(n == 2) cout << "Second" << endl;
    else if(n == 3) cout << "First" << endl;
    else{
        if(n%2 == 0) cout << "First" << endl;
        else cout << "Second" << endl;
    }
    
    // map<int, bool> memo;
    // memo[0] = memo[1] = true;
    // auto f = [&](auto self, int n) -> bool {
    //     if(memo.count(n)) return memo[n];

    //     vector<int> y;
    //     for(int i = 1; i*i <= n; i++){
    //         if(n%i == 0){
    //             y.push_back(i);
    //             if(i != n/i) y.push_back(n/i);
    //         }
    //     }

    //     bool res = false;
    //     for(auto yy: y){
    //         if(!self(self, n-yy)){
    //             res = true;
    //             break;
    //         }
    //     }
    //     return memo[n] = res;
    // };

    // rep(i, 2, 101){
    //     cout << i << ": ";
    //     if(f(f, i)) cout << "First" << endl;
    //     else cout << "Second" << endl;
    // }
    return 0;
}