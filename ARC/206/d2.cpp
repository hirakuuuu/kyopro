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
    
    int n; cin >> n;
    vector<int> p(n);
    iota(p.begin(), p.end(), 1);
    do{
        vector<int> lis(n, IINF), lds(n, IINF);
        rep(i, 0, n){
            int pi = lower_bound(lis.begin(), lis.end(), p[i])-lis.begin();
            lis[pi] = p[i];
            int pd = lower_bound(lds.begin(), lds.end(), -p[i])-lds.begin();
            lds[pd] = -p[i];
        }
        int len_lis = 0, len_lds = 0;
        rep(i, 0, n){
            if(lis[i] != IINF) len_lis++;
            if(lds[i] != IINF) len_lds++;
        }

        set<int> si, sd;
        rep(i, 0, 1<<n){
            if(__popcount(i) == len_lis){
                vector<int> q;
                rep(j, 0, n){
                    if((i>>j)&1) q.push_back(p[j]);
                }
                vector<int> r = q;
                sort(r.begin(), r.end());
                if(q == r){
                    for(auto qq: q) si.insert(qq);
                }
            }
            if(__popcount(i) == len_lds){
                vector<int> q;
                rep(j, 0, n){
                    if((i>>j)&1) q.push_back(p[j]);
                }
                vector<int> r = q;
                sort(r.rbegin(), r.rend());
                if(q == r){
                    for(auto qq: q) sd.insert(qq);
                }
            }
        }

        set<int> sid;
        for(auto ss: sd){
            if(si.count(ss)) sid.insert(ss);
        }
        // if(sid.size() != 0) continue;
        if(p[0] != 3) continue;

        rep(i, 0, n){
            cout << p[i] << ' ';
        }
        cout << ": " << sid.size() << endl;
    }while(next_permutation(p.begin(), p.end()));
    return 0;
}