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

vector<int> factorial = {
    1,
    808258749,
    117153405,
    761699708,
    573994984,
    62402409,
    511621808,
    242726978,
    887890124,
    875880304
};

int main(){
    int n, k; cin >> n >> k;
    if(n < 998244353){
        mint a = factorial[n/100000000];
        rep(i, (n/100000000)*100000000+1, n+1) a *= i;
        mint b = factorial[(n-k)/100000000];
        rep(i, ((n-k)/100000000)*100000000+1, (n-k)+1) b *= i;
        mint c = factorial[k/100000000];
        rep(i, (k/100000000)*100000000+1, k+1) c *= i;
        cout << (a/(b*c)).val() << endl;
    }else{
        if(k > n-k) k = n-k;

        if(n-k+1 <= 998244353){
            cout << 0 << endl;
        }else{
            mint a = 1;
            rrep(i, n, n-k+1) a *= i;
            mint b = 1;
            rrep(i, k, 1) b *= i;
            cout << (a/b).val() << endl;
        }
    }

    return 0;
}