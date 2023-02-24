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

void print (vector<vector<ll>> a){
    for (auto b: a){
        for(auto c: b){
            cout << c << ' ';
        }
        cout << endl;
    }
}

vector<vector<ll>> combinations(vector<ll> lis, ll repeat){
    ll cnt = 0;
    deque<set<ll>> d;
    set<ll> s, tmp;
    d.push_back(s);

    while(cnt < repeat){
        deque<set<ll>> d2;
        for(auto itr = d.begin(); itr != d.end(); itr++){
            // cnt番目の要素となり得るのは、[cnt, n+cnt-repeat+1).
            for(auto it = lis.begin()+cnt; it != lis.begin()+lis.size()+cnt-repeat+1; it++){
                tmp = *itr;
                tmp.insert(*it);
                // cnt+1個の要素をもつ集合になったならば追加
                if((ll)tmp.size() == cnt+1){
                    d2.push_back(tmp);
                }
            }
        }
        d = d2;
        cnt++;
    }

    // 重複を削除
    sort(d.begin(), d.end());
    d.erase(unique(d.begin(), d.end()), d.end());

    // vectorに変換
    vector<vector<ll>> ans;
    for(auto item: d){
        vector<ll> ite(item.begin(), item.end());
        ans.push_back(ite);
    }

    return ans;
}

int main(){
    vector<long long> a={1,3,6};
    vector<vector<long long>> out=combinations(a,2);
    print(out);
    
    return 0;
}