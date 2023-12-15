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


int main(){
    int q; cin >> q;
    multiset<int> X, XOR;

    while(q--){
        int t; cin >> t;
        if(t == 1){
            int x; cin >> x;
            if(X.size() > 0){
                int l, r;
                auto itr = X.lower_bound(x);
                if(itr == X.end()){
                    itr--;
                    l = *itr;
                    XOR.insert(l^x);
                }else if(itr == X.begin()){
                    r = *itr;
                    XOR.insert(r^x);
                }else{
                    r = *itr;
                    itr--;
                    l = *itr;
                    XOR.erase(XOR.find(l^r));
                    XOR.insert(l^x);
                    XOR.insert(r^x);
                }
            }
            X.insert(x);
        }else if(t == 2){
            int x; cin >> x;
            X.erase(X.find(x));
            if(X.size() > 0){
                int l, r;
                auto itr = X.lower_bound(x);
                if(itr == X.end()){
                    itr--;
                    l = *itr;
                    XOR.erase(XOR.find(l^x));
                }else if(itr == X.begin()){
                    r = *itr;
                    XOR.erase(XOR.find(r^x));
                }else{
                    r = *itr;
                    itr--;
                    l = *itr;
                    XOR.erase(XOR.find(l^x));
                    XOR.erase(XOR.find(r^x));
                    XOR.insert(l^r);
                }
            }
        }else if(t == 3){
            cout << *XOR.begin() << endl;
        }
    }
    
    return 0;
}