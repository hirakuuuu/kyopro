#include <bits/stdc++.h>
using namespace std;
#define rep(i, a, n) for(int i = a; i < n; i++)
#define rrep(i, a, n) for(int i = a; i >= n; i--)
#define ll long long
#define pii pair<int, int>
#define pll pair<ll, ll>
const int MOD_NUM = 1000000007;
const int mod_num = 998244353;
const int iinf = 1001001001;

template<class t,class u> void chmax(t&a,u b){if(a<b)a=b;}
template<class t,class u> void chmin(t&a,u b){if(b<a)a=b;}

/*
https://qiita.com/KyleKatarn/items/4e64249abfc151d8e82b
コンビネーション
配列の中から repeat 個の要素を取り出した集合を、昇順に並べた配列を出力.
計算量：O(n^repeat/repeat!)
*/


template <class T>
void dfs_combination(vector<T> &arr, int idx, int r, vector<T> &pattern, vector<vector<T>> &result){
    // r個に達したのでresultに格納
    if(r == 0){
        result.push_back(pattern);
        return;
    }

    // r個列挙できない場合はreturn
    if((idx+r) > (int)arr.size()) {
        return;
    }

    // idx番目の要素を選ぶ場合
    pattern.push_back(arr[idx]);
    dfs_combination(arr, idx+1, r-1, pattern, result);
    pattern.pop_back();

    // 選ばない場合
    dfs_combination(arr, idx+1, r, pattern, result);

}
template <class T>
vector<vector<T>> combination(vector<T> &arr, int r) {
    if ((int)arr.size() < r) {
        printf("combination ERROR: r is larger than arr.size()\n");
        exit(1);
    }

    vector<T> pattern;
    vector<vector<T>> result;
    dfs_combination(arr, 0, r, pattern, result);
    return result;
}

class UnionFind {
    vector<ll> parent, maxi, mini;
    inline ll root(ll n){
        return (parent[n] < 0? n:parent[n] = root(parent[n]));
    }
public:
    UnionFind(ll n_ = 1): parent(n_, -1), maxi(n_), mini(n_){
        iota(maxi.begin(), maxi.end(), 0);
        iota(mini.begin(), mini.end(), 0);
    }

    inline bool same(ll x, ll y){
        return root(x) == root(y);
    }

    inline void unite(ll x, ll y){
        ll rx = root(x);
        ll ry = root(y);
        if(rx == ry) return;
        if(parent[rx] > parent[ry]) swap(rx, ry);
        parent[rx] += parent[ry];
        parent[ry] = rx;
        maxi[x] = std::max(maxi[x],maxi[y]);
        mini[x] = std::min(mini[x],mini[y]);
    }

    inline ll min(ll x){
        return mini[root(x)];
    }

    inline ll max(int x){
        return mini[root(x)];
    }

    inline ll size(ll x){
        return (-parent[root(x)]);
    }

    inline ll operator[](ll x){
        return root(x);
    }

    inline void print(){
        rep(i, 0, (ll)parent.size()) cout << root(i) << " ";
        cout << endl;
    }

    void clear(){
        rep(i, 0, (ll)parent.size()){
            parent[i] = -1;
        }
        iota(maxi.begin(), maxi.end(), 0);
        iota(mini.begin(), mini.end(), 0);
    }
};

int main(){
    int n, m;
    ll k; cin >> n >> m >> k;
    vector<int> u(m), v(m);
    vector<ll> w(m);
    rep(i, 0, m){
        cin >> u[i] >> v[i] >> w[i];
        u[i]--;
        v[i]--;
    }
    vector<int> a(m);
    iota(a.begin(), a.end(), 0);
    vector<vector<int>> out = combination(a, n-1);

    ll ans = k;

    for(auto o: out){
        ll cost = 0;
        UnionFind uf(n);
        rep(i, 0, n-1){
            if(uf.same(u[o[i]], v[o[i]])){
                cost = -1;
                break;
            }
            uf.unite(u[o[i]], v[o[i]]);
            cost += w[o[i]];
        }
        if(cost >= 0){
            chmin(ans, cost%k);
        }
    }
    cout << ans << endl;
    
    return 0;
}