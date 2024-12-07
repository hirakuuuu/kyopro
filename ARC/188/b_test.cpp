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

int main(){

    auto f = [&](int n, int k) -> bool{

        rep(start, 0, 2){
            vector<int> b(n);
            if(start == 0) b[0] = 1;
            else b[n/2] = 1;
            int c = 1;
            while(true){
                int rest = 0;
                if(c == 0){
                    rep(i, 0, n/2){
                        if(b[i] != b[n-1-i]){
                            if(b[i] == 0) b[i] = 1;
                            else b[n/2+i] = 1;
                            break;
                        }
                        rest++;
                    }
                }else{
                    rep(i, 0, n/2){
                        int tmp = (k+i)%n;
                        int e = (n-1-k-tmp+n)%n;
                        if(tmp == e) e = (tmp+n/2)%n;
                        if(b[tmp] != b[e]){
                            if(b[tmp] == 0) b[tmp] = 1;
                            else b[e] = 1;
                            break;
                        }
                        rest++;
                    }
                }
                if(rest == n/2) break;
                c = 1-c;
            }
            bool ok = true;
            cout << n << ' ' << k << ' ' << start << ' ';
            rep(i, 0, n){
                cout << b[i] << ' ';
            }
            cout << endl;
            rep(i, 0, n){
                if(b[i] == 0){
                    ok = false;
                    break;
                }
            }
            if(ok) return true;
        }
        return false;
    };

    for(int i = 2; i <= 10; i += 4){
        for(int k = 1; k < i; k++){
            cout << i << ' ' << k << ": ";
            if(f(i, k)) cout << "Yes" << endl;
            else cout << "No" << endl;
        }
    }
    
    return 0;
}