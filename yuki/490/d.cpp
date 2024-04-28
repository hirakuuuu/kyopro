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
constexpr ll INF = 9e18;

template<class t,class u> void chmax(t&a,u b){if(a<b)a=b;}
template<class t,class u> void chmin(t&a,u b){if(b<a)a=b;}

ll power(ll a, ll b, ll m=MOD){
    ll res = 1;
    while(b > 0){
        if(b%2 == 1) res = res*a%m;
        a = a*a%m;
        b /= 2;
    }
    return res;
}

// 0ならば素数, 0でないなら最小の素因数
vector<int> erat(3000005);
void init_e(){
    rep(i, 2, sqrt(3000005)+1){
        if(erat[i] == 0){
            for(ll j = i*i; j < 3000005; j += i){
                if(erat[j] == 0) erat[j] = i;
            }
        }
    }
}

int main(){
    int t; cin >> t;
    init_e();
    vector<int> p;
    rep(i, 2, 3000005){
        if(erat[i] == 0) p.push_back(i);
    }
    // cout << p.size() << endl;
    while(t--){
        int n; cin >> n;
        int prime = erat[n];
        if(prime == 0){
            cout << "P" << endl;
            continue;
        }

        // n以下の素数かつprimeをかけると nを超えるものを数えたい
        auto r = upper_bound(p.begin(), p.end(), n);
        auto l = upper_bound(p.begin(), p.end(), n/2);
        // cout << r-l << ' ' << n-2-(r-l) << endl;
        int cnt = n-2-(r-l);
        if(cnt%2 == 1) cout << "K" << endl;
        else cout << "P" << endl;
        



    }
    return 0;
}