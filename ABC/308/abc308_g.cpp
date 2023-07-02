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

// 問題
// https://atcoder.jp/contests/abc308/tasks/abc308_g

multiset<ll> X, XOR;

int main(){
    int Q; cin >> Q;
    while(Q--){
        int op; cin >> op;

        if(op == 1){
            ll x; cin >> x;
            auto itr = X.lower_bound(x);

            if(itr != X.begin() && itr != X.end()) XOR.erase(XOR.find(*prev(itr)^*itr));
            if(itr != X.begin()) XOR.insert(*prev(itr)^x);
            if(itr != X.end()) XOR.insert(x^*itr);

            X.insert(x);
        }else if(op == 2){
            int x; cin >> x;
            X.erase(X.find(x));
            auto itr = X.lower_bound(x);

            if(itr != X.begin() && itr != X.end()) XOR.insert(*prev(itr)^*itr);
            if(itr != X.begin()) XOR.erase(XOR.find(*prev(itr)^x));
            if(itr != X.end()) XOR.erase(XOR.find(x^*itr));

        }else{
            cout << *XOR.begin() << '\n';
        }
    }

    
    return 0;
}