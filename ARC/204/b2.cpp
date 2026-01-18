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
    map<vector<int>, int> dist;
    dist[p] = 0;
    queue<vector<int>> que;
    que.push(p);
    while(!que.empty()){
        vector<int> q = que.front(); que.pop();
        int d = dist[q];
        rep(i, 0, n){
            rep(j, i+1, n){
                swap(q[i], q[j]);
                if(!dist.count(q)){
                    dist[q] = d+1;
                    que.push(q);
                }
                swap(q[i], q[j]);
            }
        }
    }
    do{
        rep(i, 0, n){
            cout << p[i] << ' ';
        }
        cout << ": " << dist[p] << ", ";

        int inv = 0;
        rep(i, 0, n){
            rep(j, 0, i){
                if(p[i] < p[j]) inv++;
            }
            cout << inv << ' ';
        }
        cout << endl;
    }while(next_permutation(p.begin(), p.end()));

    
    return 0;
}