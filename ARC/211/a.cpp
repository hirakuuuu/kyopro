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

    int t; cin >> t;
    while(t--){
        vector<ll> a(10);
        ll sum_a = 0;
        vector<int> c;
        rep(i, 1, 10){
            cin >> a[i];
            if(a[i]) c.push_back(i);
            sum_a += a[i];
        }
        if(a[5] > (sum_a-a[5])){
            cout << a[5]-(sum_a-a[5])-1 << endl;
        }else if(c.size() == 1){
            cout << 0 << endl;
        }else if(c.size() == 2){
            if(c[0]+c[1] == 10){
                cout << 1 << endl;
            }else{
                cout << 0 << endl;
            }
        }else{
            cout << 0 << endl;
        }
    }
    
    return 0;
}