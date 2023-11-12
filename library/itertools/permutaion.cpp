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

template <class T>
vector<vector<T>> permutation(vector<T> &arr, int r) {
    if ((int)arr.size() < r) {
        printf("combination ERROR: r is larger than arr.size()\n");
        exit(1);
    }

    vector<T> pattern;
    vector<vector<T>> result_comb;
    dfs_combination(arr, 0, r, pattern, result_comb);

    vector<vector<T>> result;

    for(auto res: result_comb){
        do{
            result.push_back(res);
        }while(next_permutation(res.begin(), res.end()));
    }
    sort(result.begin(), result.end());
    return result;
}


int main(){
    vector<int> a(10);
    iota(a.begin(), a.end(), 0);
    vector<vector<int>> out=permutation(a, 3);
    for(auto o: out){
        for(auto oo: o){
            cout << oo << ' ';
        }
        cout << endl;
    }
    
    return 0;
}