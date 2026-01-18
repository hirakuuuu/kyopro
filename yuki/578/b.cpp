#include <bits/stdc++.h>
#include <atcoder/all>
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
    int t; cin >> t;
    while(t--){
        int n; cin >> n;
        string s; cin >> s;
        if(n == 1){
            cout << 'B' << endl;
            continue;
        }

        if(s.substr(0, 2) == "AA"){
            int l = 1, r = 2;
            while(r < n && s[r] == 'B') r++;
            rep(i, l, r) s[i] = 'A'+('B'-s[i]);
        }else if(s.substr(0, 2) == "AB"){
            int l = 2;
            while(l < n && s[l] == 'A') l++;
            int r = l;
            while(r < n && s[r] == 'B') r++;
            rep(i, l, r) s[i] = 'A'+('B'-s[i]);
        }else if(s.substr(0, 2) == "BA"){
            int l = 0, r = 2;
            while(r < n && s[r] == 'B') r++;
            rep(i, l, r) s[i] = 'A'+('B'-s[i]);
        }else{
            s[0] = 'A';
        }

        int l = 0;
        while(l < n && s[l] == 'B') l++;
        int r = l;
        while(r < n && s[r] == 'A') r++;
        rep(i, l, r) s[i] = 'B';
        cout << s << endl;
    }

    return 0;
}