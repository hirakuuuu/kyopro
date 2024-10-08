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
    int q; cin >> q;
    vector<int> cnt(1000005);
    int kind = 0;
    while(q--){
        int t; cin >> t;
        if(t == 1){
            int x; cin >> x;
            if(cnt[x] == 0) kind++;
            cnt[x]++;
        }else if(t == 2){
            int x; cin >> x;
            if(cnt[x] == 1) kind--;
            cnt[x]--;
        }else{
            cout << kind << endl;
        }
    }
    
    return 0;
}