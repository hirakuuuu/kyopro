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
パーミュテーション
配列の要素の順列を、昇順に並べた配列を出力.
計算量：O(n*n!)
*/

void print (vector<vector<ll>> a){
    for (auto b: a){
        for(auto c: b){
            cout << c << ' ';
        }
        cout << endl;
    }
}

vector<vector<ll>> permutations(vector<ll> lis){
    vector<ll> range(lis.size()), tmp(lis.size());
    iota(range.begin(), range.end(), 0);
    vector<vector<ll>> ans;

    // next_permutationで[0, n)の順列を昇順に列挙
    do{
        for(ll i = 0; i < (ll)lis.size(); i++){
            tmp[range[i]] = lis[i];
        }
        ans.push_back(tmp);
    }while(next_permutation(range.begin(), range.end()));

    return ans;
}


int main(){
    vector<long long> a={1,3,6};
    vector<vector<long long>> out=permutations(a);
    print(out);
    
    return 0;
}