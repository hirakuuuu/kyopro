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
// https://atcoder.jp/contests/abc326/tasks/abc326_d

class itertools{
public:
    vector<vector<ll>> ary;
    vector<ll> lis;
    vector<ll> tmp;

    void repeating(vector<ll> nums, vector<ll> lis, ll repeat){
        if((ll)lis.size() == repeat){
            ary.push_back(lis);
        }else{
            tmp = lis;
            for (auto item: nums){
                tmp.push_back(item);
                repeating(nums, tmp, repeat);
                tmp=lis;
            }
        }
    }

    vector<vector<ll>> product(vector<ll> nums, ll repeat){
        repeating(nums, lis, repeat);
        return ary;
    };
};

int main(){
    int n; cin >> n;
    string r, c; cin >> r >> c;
    string abc = "ABC";

    itertools iter;
    vector<ll> m(n);
    iota(m.begin(), m.end(), 0);
    vector<vector<ll>> out_=iter.product(m, 3);
    vector<vector<ll>> out;

    for(auto oo: out_){
        set<ll> out_s;
        for(auto ooo: oo) out_s.insert(ooo);
        vector<ll> oo_ = oo;
        sort(oo_.begin(), oo_.end());
        if(out_s.size() == 3 && oo == oo_) out.push_back(oo);
    }
    int total = out.size();
    rep(i, 0, pow(total, n)){
        vector<int> a(n);
        int tmp = i;
        rep(j, 0, n){
            a[j] = tmp%total;
            tmp /= total;
        }
        rep(bit, 0, (1<<n)){
            vector<vector<char>> s(n, vector<char>(n, '.'));
            rep(j, 0, n){
                rep(k, 0, n){
                    if(k == out[a[j]][0]){
                        s[j][k] = r[j];
                    }else if(k == out[a[j]][1]){
                        if((bit&(1<<j)) > 0) s[j][k] = abc[((r[j]-'A')+1)%3];
                        else s[j][k] = abc[((r[j]-'A')+2)%3];
                    }else if(k == out[a[j]][2]){
                        if((bit&(1<<j)) > 0) s[j][k] = abc[((r[j]-'A')+2)%3];
                        else s[j][k] = abc[((r[j]-'A')+1)%3];
                    }
                }
            }
            bool f = true;
            rep(k, 0, n){
                int cnt = 0;
                vector<int> mask(3);
                rep(j, 0, n){
                    if(s[j][k] == '.') continue;
                    if(cnt == 0){
                        if(s[j][k] != c[k]) f = false;
                        cnt++;
                    }
                    mask[s[j][k]-'A']++;
                }
                rep(j, 0, 3){
                    if(mask[j] == 1) continue;
                    f = false;
                }
            }

            if(f){
                cout << "Yes" << endl;
                rep(k, 0, n){
                    rep(l, 0, n){
                        cout << s[k][l];
                    }
                    cout << endl;
                }
                return 0;
            }
        }
    }
    
    cout << "No" << endl;

    
    return 0;
}