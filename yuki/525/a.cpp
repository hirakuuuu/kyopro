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
    string x, y; cin >> x >> y;
    if(x.size() >= y.size() && x.size()-y.size() <= 1){
        string s;
        int px = 0, py = 0;
        while(s.size() < x.size()+y.size()){
            if(s.size()%2 == 0){
                s += x[px], px++;
            }else{
                s += y[py], py++;
            }
        }
        cout << s << endl;
    }else{
        cout << "?" << endl;
    }
    return 0;
}