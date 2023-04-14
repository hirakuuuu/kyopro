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

// 問題
// https://atcoder.jp/contests/abc296/tasks/abc296_f

class BIT {
public:
    ll n; // データの長さ
    vector<ll> a; // データの格納先

    BIT(ll n_): n(n_), a(n_+1, 0){} // コンストラクタ

    // a[i]をxに加算する
    void add(ll pos, ll x){
        pos++; // 1インデックスにしてる
        while(pos <= n){
            a[pos] += x;
            pos += pos&(-pos);
        }
    }

    // [0, i]を求める
    ll sum_sub(ll pos){
        pos++;
        ll res = 0;
        while(0 < pos){
            res += a[pos];
            pos -= pos&(-pos);
        }
        return res;
    }

    // [l, r]の和
    ll sum(ll l, ll r){
        return sum_sub(r)-sum_sub(l-1);
    }

    // a[0]+a[1]+...+a[i] >= x となる最小のiを求める（任意のkでa[k]>=0が必要）
    ll lower_bound(ll x){
        if(x <= 0){
            return 0;
        }else{
            ll i = 0, len = 1;

            //最大としてありうる区間の長さを取得する
            //n以下の最小の二乗のべき(BITで管理する数列の区間で最大のもの)を求める
            while(len < n) len *= 2;

            //区間の長さは調べるごとに半分になる
            while(0 < len){
                //その区間を採用する場合
                if(i+len < n and a[i+len] < x){
                    x -= a[i+len];
                    i += len;
                }
            }
            return i;
        }
    }

};

int main(){
    int n; cin >> n;
    vector<int> a(n), b(n);
    rep(i, 0, n) cin >> a[i];
    rep(i, 0, n) cin >> b[i];

    // ソートして一致しないならNo
    vector<int> a_ = a, b_ = b;
    sort(a_.begin(), a_.end());
    sort(b_.begin(), b_.end());
    if(a_ != b_){
        cout << "No" << endl;
        return 0;
    }

    a_.erase(unique(a_.begin(), a_.end()), a_.end());
    if(a_.size() == n){
        int ta = 0, tb = 0;
        BIT bit_a(n+1), bit_b(n+1);
        rep(i, 0, n){
            ta += bit_a.sum(a[i], n);
            bit_a.add(a[i], 1);
            tb += bit_b.sum(b[i], n);
            bit_b.add(b[i], 1);
        }
        // cout << ta << ' ' << tb << endl;

        if((ta+tb)%2) cout << "No" << endl;
        else cout << "Yes" << endl;

    }else{
        cout << "Yes" << endl;
    }

    
    return 0;
}