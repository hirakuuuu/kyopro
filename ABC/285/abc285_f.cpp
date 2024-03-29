#include <bits/stdc++.h>
using namespace std;
#define rep(i, a, n) for(int i = a; i < n; i++)
#define ll long long
#define pii pair<int, int>
#define pll pair<ll, ll>
const int MOD = 1000000007;
const int mod = 998244353;

template<class t,class u> void chmax(t&a,u b){if(a<b)a=b;}
template<class t,class u> void chmin(t&a,u b){if(b<a)a=b;}

// 問題
// https://atcoder.jp/contests/abc285/tasks/abc285_f

struct SegmentTree {
    private:
        int n;
        vector<int> node;
    
    public:
        SegmentTree(vector<int> a){
            // 配列のサイズを取得
            int sz = a.size();
            // nはszを超える最小の2のべき乗
            n = 1;
            while(n < sz) n *= 2;
            // ノードの個数は2n-1
            node.resize(2*n-1, 0);

            // 再下段にaの値を格納
            rep(i, 0, sz) node[i+n-1] = a[i];
            // 親を更新
            for(int j = n-2; j >= 0; j--) node[j] = node[2*j+1]+node[2*j+2];
        }

        // 更新処理
        void update(int x, int val){
            // 再下段の指定した位置の値を更新
            x += n-1;
            node[x] += val;
            // 親の値を更新しながら上る
            while(x > 0){
                x = (x-1)/2;
                node[x] += val;
            }
        }

        // 取得処理
        int get_num(int a, int b, int k=0, int l=0, int r=-1){
            if(r < 0) r = n;
            if(r <= a or b <= l) return 0;
            if(a <= l and r <= b) return node[k];

            int v1 = get_num(a, b, 2*k+1, l, (l+r)/2);
            int v2 = get_num(a, b, 2*k+2, (l+r)/2, r);
            return v1+v2;
        }
};

int main(){
    int n; cin >> n;
    string s; cin >> s;
    vector<int> a(n);
    vector<SegmentTree> cnt(26, SegmentTree(a));
    rep(i, 0, n){
        cnt[s[i]-'a'].update(i, 1);
    }

    int q; cin >> q;
    vector<int> c(26);
    while(q--){
        int t; cin >> t;
        if(t == 1){
            int x; cin >> x; x--;
            char C; cin >> C;
            cnt[s[x]-'a'].update(x, -1);
            s[x] = C;
            cnt[C-'a'].update(x, 1);
        }else{
            int l, r; cin >> l >> r; 
            l--;
            rep(i, 0, 26){
                c[i] = cnt[i].get_num(l, r);
            }
            bool f = true;
            // 個数のチェック
            int M = -1, m = -1;
            rep(i, 0, 26){
                if(c[i] > 0){
                    if(m == -1) m = i;
                    M = i;
                }
            }
            rep(i, 0, 26){
                if(m < i and i < M){
                    if(c[i] != cnt[i].get_num(0, n)){
                        f = false;
                    }
                }
            }
            // 昇順のチェック
            int tmp = l;
            rep(i, 0, 26){
                if(cnt[i].get_num(tmp, tmp+c[i]) != c[i]) f = false;
                tmp += c[i];
            }

            if(f) cout << "Yes" << endl;
            else cout << "No" << endl;

        }

    }
    return 0;
}