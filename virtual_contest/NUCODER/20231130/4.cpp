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
// 

int main(){
    vector<string> s(3);
    rep(i, 0, 3) cin >> s[i];

    set<char> c;
    rep(i, 0, 3){
        for(auto ss: s[i]) c.insert(ss);
    }

    if(c.size() > 10){
        cout << "UNSOLVABLE" << endl;
        return 0;
    }

    int ii = 0;
    map<char, int> m;
    for(char cc: c){
        m[cc] = ii;
        ii++;
    }

    vector<ll> ind(10);
    iota(ind.begin(), ind.end(), 0);
    do{
        bool f = true;
        vector<ll> num(3);
        rep(i, 0, 3){
            for(auto ss: s[i]){
                num[i] *= 10;
                num[i] += ind[m[ss]];
            }
            if(num[i] <= 0) f = false;
            if(ind[m[s[i][0]]] == 0) f = false;
        }
        f &= (num[0]+num[1] == num[2]);
        if(f){
            rep(i, 0, 3) cout << num[i] << endl;
            return 0;
        }
    }while(next_permutation(ind.begin(), ind.end()));

    cout << "UNSOLVABLE" << endl;
    return 0;
}