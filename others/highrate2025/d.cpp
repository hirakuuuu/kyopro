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
    if(n%3 == 0){
        cout << "Second" << endl;
    }else{
        cout << "First" << endl;
        cout << n%3 << endl;
        n -= n%3;
    }

    while(true){
        int a; cin >> a;
        if(a == 0){
            break;
        }else if(a == -1){
            break;
        }else{
            n -= a;
        }
        if(n == 0){
            cout << 0 << endl;
            break;
        }else{
            cout << n%3 << endl;
            n -= n%3;
        }
    }


    return 0;
}