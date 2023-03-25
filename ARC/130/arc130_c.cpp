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
// https://atcoder.jp/contests/arc130/tasks/arc130_c


/*
どこを足しても繰り上がりがない → そのまま出力
*/

int calc(string a, string b){
    int res = 0;
    int aa, bb, cc = 0;
    rep(i, 0, max(a.size(), b.size())){
        if(i >= a.size()) aa = 0;
        else aa = a[i]-'0';
        if(i >= b.size()) bb = 0;
        else bb = b[i]-'0';
        res += (aa+bb+cc)%10;
        if(aa+bb+cc >= 10) cc = 1;
        else cc = 0;
    }
    return res+cc;
}



int main(){
    string a, b; cin >> a >> b;
    vector<int> cnt_a(10), cnt_b(10);
    for(const auto &aa: a) cnt_a[aa-'0']++;
    for(const auto &bb: b) cnt_b[bb-'0']++;

    ll ans = 1LL<<60;
    string ans_a, ans_b;

    rep(a0, 1, 10){
        string tmp_a, tmp_b;
        vector<int> cnt_a_ = cnt_a, cnt_b_ = cnt_b;
        rep(b0, 10-a0, 10){
            if(cnt_a_[a0] and cnt_b_[b0]){
                tmp_a += '0'+a0;
                tmp_b += '0'+b0;
                cnt_a_[a0]--;
                cnt_b_[b0]--;
                break;
            }
        }

        rep(aa, 1, 10){
            rep(bb, 9-aa, 10){
                while(cnt_a_[aa] and cnt_b_[bb]){
                    tmp_a += '0'+aa;
                    tmp_b += '0'+bb;
                    cnt_a_[aa]--;
                    cnt_b_[bb]--;
                }
            }
        }

        rrep(x, 9, 1){
            while(cnt_a_[x]){
                tmp_a += '0'+x;
                cnt_a_[x]--;
            }
            while(cnt_b_[x]){
                tmp_b += '0'+x;
                cnt_b_[x]--;
            }
        }

        ll tmp = calc(tmp_a, tmp_b);

        if(ans > tmp){
            swap(ans_a, tmp_a);
            swap(ans_b, tmp_b);
            swap(ans, tmp);
        }
    }
    reverse(ans_a.begin(), ans_a.end());
    reverse(ans_b.begin(), ans_b.end());
    cout << ans_a << endl;
    cout << ans_b << endl;


    
    return 0;
}