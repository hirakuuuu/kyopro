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
// https://atcoder.jp/contests/agc018/tasks/agc018_b

struct SegmentTree {
    private:
        int n;
        vector<int> node;
    
    public:
        SegmentTree(vector<int> a){
            // 配列のサイズを取得
            int sz = (int) a.size();
            // nはszを超える最小の2のべき乗
            n = 1;
            while(n < sz) n *= 2;
            // ノードの個数は2n-1
            node.resize(2*n-1, 0);

            // 再下段にaの値を格納
            rep(i, 0, sz) node[i+n-1] = a[i];
            // 親を更新
            for(int j = n-2; j >= 0; j--) node[j] = max(node[2*j+1], node[2*j+2]);
        }

        // 更新処理
        void update(int x, int val){
            // 再下段の指定した位置の値を更新
            x += n-1;
            node[x] += val;
            // 親の値を更新しながら上る
            while(x > 0){
                x = (x-1)/2;
                node[x] = max(node[2*x+1], node[2*x+2]);
            }
        }

        // 取得処理
        int get_num(int a, int b, int k=0, int l=0, int r=-1){
            if(r < 0) r = n;
            if(r <= a or b <= l) return 0;
            if(a <= l and r <= b) return node[k];

            int v1 = get_num(a, b, 2*k+1, l, (l+r)/2);
            int v2 = get_num(a, b, 2*k+2, (l+r)/2, r);
            return max(v1, v2);
        }
};


int main(){
    int n, m; cin >> n >> m;
    vector<vector<int>> a(n, vector<int>(m));
    rep(i, 0, n){
        rep(j, 0, m){
            cin >> a[i][j];
            a[i][j]--;
        }
    }

    vector<int> used(m), cnt(m);
    rep(i, 0, n){
        cnt[a[i][0]]++;
    }

    int ans = cnt[0], max_i = 0;
    rep(i, 0, m){
        if(ans < cnt[i]){
            ans = cnt[i];
            max_i = i;
        }
    }

    used[max_i] = true;

    rep(t, 1, m){
        fill(cnt.begin(), cnt.end(), 0);
        rep(i, 0, n){
            rep(j, 0, m){
                if(used[a[i][j]]) continue;
                cnt[a[i][j]]++;
                break;
            }
        }

        int tmp = cnt[0];
        max_i = 0;
        rep(i, 0, m){
            if(tmp < cnt[i]){
                tmp = cnt[i];
                max_i = i;
            }
        }

        chmin(ans, tmp);
        used[max_i] = true;
    }

    cout << ans << endl;
    return 0;
}