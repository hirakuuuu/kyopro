#include <bits/stdc++.h>
using namespace std;
#define rep(i, a, n) for(int i = a; i < n; i++)
#define ll long long
#define pii pair<int, int>
#define pll pair<ll, ll>
const int MOD = 1000000007;
const int mod = 998244353;

/*
max-ヒープ：完全二分木であり、各節点のキーがその親のキー以下であるもの
*/

const int MAX_K = 2000000001;
vector<int> Key(2000001);
int h;
void maxHeapify(int i){
    int l = 2*i;
    int r = 2*i+1;
    int largest = i;
    // 左の子、自分、右の子で値が最大のノードを選ぶ
    if(l <= h and Key[l] > Key[largest]) largest = l;
    if(r <= h and Key[r] > Key[largest]) largest = r;
    // iの子の方が値が大きい場合
    if(largest != i){
        swap(Key[i], Key[largest]);
        maxHeapify(largest);
    }
}

// 値を挿入した後、逆転しなくなるまで押し上げる
void heapIncreaseKey(int i, int key){
    if(key < Key[i]) return;
    Key[i] = key;
    while(i > 1 and Key[i/2] < Key[i]){
        swap(Key[i], Key[i/2]);
        i = i/2;
    }
}

// 挿入
void insert(int key){
    h++;
    Key[h] = (-1)*MAX_K;
    heapIncreaseKey(h, key);
}

// 最大の要素を取得
int heapExtractMax(){
    if(h < 1) return (-1)*MAX_K;
    int M = Key[1];
    Key[1] = Key[h];
    h--;
    maxHeapify(1);
    return M;
}

int main(){
    h = 0;
    vector<int> ans;
    while(true){
        string c; cin >> c;
        if(c == "end") break;
        if(c == "insert"){
            int k; cin >> k;
            insert(k);
        }else{
            ans.push_back(heapExtractMax());
        }
    }
    for(auto aa: ans){
        cout << aa << endl;
    }
}