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
    int k; cin >> k;
    vector<ll> lunlun;
    auto f = [&](auto self, ll tmp, int ord) -> void {
        lunlun.push_back(tmp);
        if(ord == 10) return;
        self(self, tmp*10+tmp%10, ord+1);
        if(tmp%10 != 0){
            self(self, tmp*10+tmp%10-1, ord+1);
        }
        if(tmp%10 != 9){
            self(self, tmp*10+tmp%10+1, ord+1);
        }
    };
    rep(i, 1, 10) f(f, i, 1);
    sort(lunlun.begin(), lunlun.end());
    cout << lunlun[k-1] << endl;
    return 0;
}