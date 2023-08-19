#include <bits/stdc++.h>
using namespace std;
#define rep(i, a, n) for(int i = a; i < n; i++)
#define rrep(i, a, n) for(int i = a; i >= n; i--)
#define ll long long
#define pii pair<int, int>
#define pll pair<ll, ll>
// constexpr ll MOD = 1000000007;
constexpr ll MOD = 998244353;
constexpr int IINF = 1001001001;
constexpr ll INF = 1LL<<60;

template<class t,class u> void chmax(t&a,u b){if(a<b)a=b;}
template<class t,class u> void chmin(t&a,u b){if(b<a)a=b;}

// 0ならば素数, 0でないなら最小の素因数
vector<ll> erat(1000010);
vector<ll> p;
void init_e(){
    for(ll i = 2; i <= 1000005; i++){
        if(erat[i] == 0){
            p.emplace_back(i);
            for(ll j = i*i; j <= 1000005; j += i){
                if(erat[j] == 0) erat[j] = i;
            }
        }
    }
}

int main(){
    ll n; cin >> n;
    init_e();
    int ans = 0;
    for(int i = 0; i < p.size() && p[i]*p[i] <= n; i++){
        for(int j = i+1; j < p.size() && p[i]*p[i]*p[j] <= n; j++){
            for(int k = j+1; k < p.size() && p[i]*p[i]*p[j] <= n/(p[k]*p[k]); k++){
                ans++;
            }
        }
    }
    cout << ans << endl;


    return 0;
}

// int main(){
//     ll n; cin >> n;
//     init_e();
//     vector<ll> p_2;
//     for(auto pp: p){
//         p_2.emplace_back(pp*pp);
//     }
//     int ans = 0;
//     for(int i = 0; p[i]*p[i]*p[i]*p[i]*p[i] <= n; i++){
//         for(int j = i+1; p[i]*p[i]*p[j]*p[j]*p[j] <= n; j++){
//             int cnt = lower_bound(p_2.begin(), p_2.end(), n/p[i]*p[i]*p)


//         }
//     }
//     cout << ans << endl;


//     return 0;
// }