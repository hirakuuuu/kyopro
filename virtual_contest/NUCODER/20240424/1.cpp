#include <bits/stdc++.h>
#include <atcoder/all>
using namespace std;
using namespace atcoder;
#define rep(i, a, n) for(int i = a; i < n; i++)
#define rrep(i, a, n) for(int i = a; i >= n; i--)
#define inr(l, x, r) (l <= x && x < r)
#define ll long long
#define ld long double

using mint = modint1000000007;
constexpr int IINF = 1001001001;
constexpr ll INF = 9e18;

template<class t,class u> void chmax(t&a,u b){if(a<b)a=b;}
template<class t,class u> void chmin(t&a,u b){if(b<a)a=b;}

int main(){
    int n; cin >> n;
    vector<int> a(n);
    rep(i, 0, n){
        cin >> a[i];
        a[i]--;
    }
    queue<int> que;
    que.push(0);
    vector<int> seen(n, -1);
    seen[0] = 0;
    while(!que.empty()){
        int q = que.front(); que.pop();
        if(seen[a[q]] != -1) continue;
        seen[a[q]] = seen[q]+1;
        que.push(a[q]);
    }
    cout << seen[1] << endl;

    
    return 0;
}