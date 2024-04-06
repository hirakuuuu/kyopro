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
    string s; cin >> s;
    // auto f = [&](auto self, int n, int k) -> string {
    //     if(n == 1 && k == 0) return "b";
    //     if(n == 2 && k == 0) return "a";
    //     if(n >= 3 && 0 <= k && k < 1<<(n-2) && k&1) return self(self, n-2, k/4)+self(self, n-1, k/2);
    //     return self(self, n-1, k/2)+self(self, n-2, k/4);
    // };
    // rep(i, 3, 24){
    //     rep(j, 0, 50) cout << '-';
    //     cout << endl;
    //     set<string> st;
    //     rep(j, 0, 1<<(i-2)){
    //         string tmp = f(f, i, j);
    //         // cout << "n=" << i << ", k=" << j << ", f(n, k)=" << tmp << endl;
    //         st.insert(tmp);
    //     }
    //     cout << i << ' ' << st.size() << endl;
    // }

    // 長さからnはわかる（フィボナッチ数列の第ｎ項）
    vector<int> fib = {0, 1, 1};
    while(fib.back() < 20000){
        int tmp = fib[fib.size()-1]+fib[fib.size()-2];
        fib.push_back(tmp);
    }
    int m = 0;
    while(fib[m] != (int)s.size()) m++;

    auto f = [&](auto self, int n, string t) -> int {
        if(n == 1){
            if(t == "b") return 0;
            return -1;
        }
        if(n == 2){
            if(t == "a") return 0;
            return -1;
        }

        int k1 = self(self, n-1, t.substr(0, fib[n-1])), k2 = self(self, n-2, t.substr(fib[n-1], fib[n-2]));
        if(k1 != -1 && k2 != -1 && (2*k1)/4 == k2) return 2*k1;
        
        k1 = self(self, n-2, t.substr(0, fib[n-2])), k2 = self(self, n-1, t.substr(fib[n-2], fib[n-1]));
        if(k1 != -1 && k2 != -1 && (2*k2)/4 == k1) return 2*k2+1;

        return -1;
    };

    if(s == "a"){
        cout << 2 << ' ' << 0 << endl;
    }else if(s == "b"){
        cout << 1 << ' ' << 0 << endl;
    }else{
        cout << m << ' ' << f(f, m, s) << endl;
    }


    return 0;
}