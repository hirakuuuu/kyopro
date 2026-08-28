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

// 0ならば素数, 0でないなら最小の素因数
const int MAX_N = 10000005;
vector<int> min_prime(MAX_N+1);
void eratosthenes(){
    rep(i, 2LL, (ll)sqrt(MAX_N)+1){
        if(min_prime[i] == 0){
            for(ll j = i*i; j <= MAX_N; j += i){
                if(min_prime[j] == 0) min_prime[j] = i;
            }
        }
    }
}

// 素因数分解 O(log{x})
vector<pair<int, int>> prime_factorization(ll x){
    vector<pair<int, int>> res;
    while(min_prime[x] != 0){
        ll p = min_prime[x];
        res.push_back({p, 0});
        while(x%p == 0){
            x /= p;
            res.back().second++;
        }
    }
    if(x != 1) res.push_back({x, 1});
    return res;
};

int main(){
    eratosthenes();
    int t; cin >> t;
    unordered_map<int, pair<int, int>> mp;
    while(t--){
        int n; cin >> n;
        vector<ll> a(n);
        mp.clear();
        
        rep(i, 0, n){
            cin >> a[i];
            vector<pair<int, int>> pf = prime_factorization(a[i]);
            for(auto [p, e]: pf){
                if(!mp.count(p)){
                    mp[p] = {e, 0};
                }else if(mp[p].second < e){
                    mp[p].second = e;
                    if(mp[p].first < mp[p].second){
                        swap(mp[p].first, mp[p].second);
                    }
                }
            }
        }

        mint mul = 1;
        for(auto [key, val]: mp){
            // cout << key << ' ' << val.first << endl;
            mul *= mint(key).pow(val.first);
        }

        rep(i, 0, n){
            vector<pair<int, int>> pf = prime_factorization(a[i]);
            mint tmp = mul;
            for(auto [p, e]: pf){
                if(mp[p].first == e){
                    tmp /= mint(p).pow(mp[p].first-mp[p].second);
                }
            }
            cout << tmp.val() << ' ';
        }
        cout << endl;
    }
    
    return 0;
}