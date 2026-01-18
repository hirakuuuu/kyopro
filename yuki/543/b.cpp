#include <bits/stdc++.h>
// #include <atcoder/all>

// 多倍長整数
#include<boost/multiprecision/cpp_int.hpp>
using namespace boost::multiprecision;

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
    cpp_int n, b; cin >> n >> b;
    if(b == 1){
        cout << 0 << endl;
        return 0;
    }
    if(n == 0){
        cout << "NaN" << endl;
        return 0;
    }


    vector<int> seen((int)b, -1);
    cpp_int tmp = 0, i = 0;
    ll tmp_id = (ll)tmp;
    while(seen[tmp_id] == -1){
        seen[tmp_id] = (int)i;
        i++;
        tmp = (tmp+n)%b;
        tmp_id = (ll)tmp;
    }
    if(seen[1] == -1) cout << "NaN" << endl;
    else cout << seen[1] << endl;
    return 0;
}