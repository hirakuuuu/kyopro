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

/*
エラトステネスの篩で N までの素数を O(NloglogN) 時間で列挙できる.
また, 自然数 n の素因数分解を O(logn) で実行できる
よって愚直に素因数分解するだけでも O(NlogN) であり, N <= 10^7 では十分高速
*/

// 0ならば素数, 0でないなら最小の素因数
vector<int> erat(1500005);
void init_e(){
    for(ll i = 2; i*i <= 1500005; i++){
        if(erat[i] == 0){
            for(ll j = i*i; j < 1500005; j += i){
                if(erat[j] == 0) erat[j] = i;
            }
        }
    }
}

int main(){
    init_e();
    vector<ll> primes;
    rep(i, 2, 1000005){
        if(erat[i] == 0){
            primes.push_back(i);
        }
    }

    ll mx = 1000000000000LL;
    vector<ll> nums;
    auto f = [&](auto self, int pos, int t, ll tmp) -> void {
        if(t == 2){
            nums.push_back(tmp);
            return;
        }

        rep(i, pos, (int)primes.size()){
            ll q = primes[i];
            ll cur = tmp;
            if(q*q > mx/cur) break;
            for(int k = 2; k <= 60; k += 2){
                cur *= q*q;
                self(self, i+1, t+1, cur);
                if(q*q > mx/cur) break;
            }
        }
    };
    f(f, 0, 0, 1);
    sort(nums.begin(), nums.end());
    nums.erase(unique(nums.begin(), nums.end()), nums.end());

    int q; cin >> q;
    while(q--){
        ll a; cin >> a;
        int pos = upper_bound(nums.begin(), nums.end(), a)-nums.begin();
        cout << nums[pos-1] << endl;
    }

    
    return 0;
}