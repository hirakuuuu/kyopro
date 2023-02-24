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
デカルト積
配列の要素から重複を許してrepeat個取り出した配列を昇順に出力。
計算量：O(n^repeat)
*/

void print (vector<vector<ll>> a){
    for (auto b: a){
        for(auto c: b){
            cout << c << ' ';
        }
        cout << '\n';
    }
}

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
    vector<ll> a={0, 1};    
    itertools iter;
    vector<vector<ll>> out=iter.product(a,20);
  	cout << out.size() << endl;
    //print(out);

    return 0;
}