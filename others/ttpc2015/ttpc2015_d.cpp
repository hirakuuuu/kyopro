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

// 64 bit で mod を取る
ll mod_pow(ll a, ll b, ll m){
    ll res = 1;
    a %= m;
    while(b > 0){
        if(b&1) res = __uint128_t(res)*a%m;
        a = __uint128_t(a)*a%m;
        b >>= 1;
    }
    return res;
}

// num が素数なら true，そうでなければ false （計算量 O(log{num}^3)）
bool miller_rabin(ll num){
    const vector<ll> A = {2, 325, 9375, 28178, 450775, 9780504, 1795265022};

    // これらは例外的に判定が必要（なぜかは分からん）
	if (num == 2 || num == 3 || num == 5 || num == 13 || num == 19 || num == 73 || num == 193
		|| num == 407521 || num == 299210837) return true;
    // 1 か 2 以外の偶数は素数でない
    if(num == 1 || !(num&1)) return false;
    
    // num-1 = 2^s d (d は奇数) を満たす s, d を求める
    ll s = 0, d = num-1;
    while(!(d&1)){
        s = s+1, d >>= 1;
    }

    // 各 a について，条件をチェックする
    for(auto a: A){
        ll powa = mod_pow(a, d, num);
        if(powa == 1 || powa == num-1) continue;
        
        bool may_prime = false;
        for(int i = 0; i < s-1; i++){
            powa = __uint128_t(powa)*powa%num;
            if(powa == 1) return false;
            if(powa == num-1){
                may_prime = true;
                break;
            }
        }
        if(!may_prime) return false;
    }

    return true;
}


int main(){
    string s; cin >> s;
    set<char> t;
    rep(i, 0, s.size()){
        t.insert(s[i]);
    }
    if(t.size() > 5){
        cout << -1 << endl;
        return 0;
    }

    vector<char> cs;
    for(auto tt: t) cs.push_back(tt);
    vector<bool> used(10);
    map<char, int> mp;
    auto f = [&](auto self, int pos) -> void {
        if(pos == cs.size()){
            ll num = 0;
            rep(i, 0, s.size()){
                num *= 10;
                num += mp[s[i]];
            }
            // cout << num << endl;
            if(miller_rabin(num)){
                cout << num << endl;
                exit(0);
            }
            return;
        }

        for(int k = 1; k < 10; k += 2){
            if(used[k]) continue;
            used[k] = true;
            mp[cs[pos]] = k;
            self(self, pos+1);
            used[k] = false;
        }
    };

    f(f, 0);
    cout << -1 << endl;
    
    return 0;
}