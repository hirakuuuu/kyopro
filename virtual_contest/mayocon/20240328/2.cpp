#include <bits/stdc++.h>
using namespace std;
#define rep(i, a, n) for(int i = a; i < n; i++)
#define rrep(i, a, n) for(int i = a; i >= n; i--)
#define inr(l, x, r) (l <= x && x < r)
#define ll long long
#define ld long double
#define pii pair<int, int>
#define pll pair<ll, ll>
// constexpr ll MOD = 1000000007;
constexpr ll MOD = 998244353;
constexpr int IINF = 1001001001;
constexpr ll INF = 1LL<<60;

template<class t,class u> void chmax(t&a,u b){if(a<b)a=b;}
template<class t,class u> void chmin(t&a,u b){if(b<a)a=b;}

int main(){
    string a, b; cin >> a >> b;
    if(a.size() != b.size()){
        if(a.size() > b.size()) cout << "GREATER" << endl;
        else cout << "LESS" << endl;
        return 0;
    }
    rep(i, 0, a.size()){
        if(a[i] != b[i]){
            if(a[i] > b[i]) cout << "GREATER" << endl;
            else cout << "LESS" << endl;
            return 0;
        }
    }
    cout << "EQUAL" << endl;
    return 0;
}