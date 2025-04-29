#include <bits/stdc++.h>
using namespace std;

#define ll long long



// ミラー・ラビン素数判定法
// p を奇素数とすると，任意の a∈[1..p) についてフェルマーの小定理より
//		a^(p-1) ≡ 1 (mod p)
// となる．これの平方根を考えていくと，
//		p-1 = 2^s d　（d : 奇数）
// と表せば，
//		a^d ≡ 1 (mod p) or ∃r=[0..s), a^(2^r d) ≡ -1 (mod p)
// と書き直せる．
// 
// この対偶を用いて判定することをランダムに選んだ a で繰り返す．
// n < 2^64 に範囲を限定するなら擬素数を生じない a を固定的に選べる．
// a = {2, 325, 9375, 28178, 450775, 9780504, 1795265022} と取ればよい.
// https://miller-rabin.appspot.com


// reference : https://nyaannyaan.github.io/library/prime/fast-factorize.hpp.html

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

// verify : https://judge.yosupo.jp/problem/primality_test
int main(){
    int q; cin >> q;
    while(q--){
        ll n; cin >> n;
        if(miller_rabin(n)) cout << "Yes" << endl;
        else cout << "No" << endl;
    }
    
    return 0;
}