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


vector<int> seen(200005);
vector<int> a;
void dfs(int pos){
    if(seen[pos]){
        vector<int> path = {pos};
        int tmp = a[pos];
        while(tmp != pos){
            path.push_back(tmp);
            tmp = a[tmp];
        }

        cout << path.size() << endl;
        for(auto p: path){
            cout << p+1 << ' ';
        }
        cout << endl;
        exit(0);
    }

    seen[pos] = true;
    dfs(a[pos]);
    seen[pos] = true;
}

int main(){
    int n; cin >> n;
    a.resize(n);
    rep(i, 0, n){
        cin >> a[i];
        a[i]--;
    }

    rep(i, 0, n){
        dfs(i);
    }

    return 0;
}