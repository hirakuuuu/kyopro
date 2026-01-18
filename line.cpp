#include <iostream>
#include <string>
#include <sstream>
#include <iomanip>
#include <map>
#include <chrono>
using namespace std;

// 二つの時刻 (YYYY-MM-DDThh:mm) の経過時間（分）を取得
long long get_elapsed_minutes(string time1, string time2){
  istringstream ss1(time1);
  istringstream ss2(time2);
  tm t1 = {};
  tm t2 = {};
  ss1 >> get_time(&t1, "%Y-%m-%dT%H:%M");
  ss2 >> get_time(&t2, "%Y-%m-%dT%H:%M");

  if(ss1.fail() || ss2.fail()){
    cerr << "Error: Failed to parse time string" << endl;
    return 0;
  }

  auto tp1 = chrono::system_clock::from_time_t(mktime(&t1));
  auto tp2 = chrono::system_clock::from_time_t(mktime(&t2));
  auto duration = tp2 - tp1;
  return chrono::duration_cast<std::chrono::minutes>(duration).count();
}

// ある時刻 (YYYY-MM-DDThh:mm) と同じ月の最初の時刻を取得
string get_first_day_of_month(string time) {
    istringstream ss(time);
    tm t1 = {};
    ss >> get_time(&t1, "%Y-%m-%dT%H:%M");

    if (ss.fail()) {
        cerr << "Error: Failed to parse time string." << std::endl;
        return ""; // エラーを示す空文字列を返す
    }

    tm next_month = t1;
    next_month.tm_mday = 1;
    next_month.tm_hour = 0;
    next_month.tm_min = 0;
    next_month.tm_sec = 0;
    mktime(&next_month); // tm_year, tm_mon の範囲を正規化
    stringstream output_ss;
    output_ss << put_time(&next_month, "%Y-%m-%dT%H:%M");
    return output_ss.str();
}

// ある時刻 (YYYY-MM-DDThh:mm) の次の月の最初の時刻を取得
string get_first_day_of_next_month(string time) {
    istringstream ss(time);
    tm t1 = {};
    ss >> get_time(&t1, "%Y-%m-%dT%H:%M");

    if (ss.fail()) {
        cerr << "Error: Failed to parse time string." << std::endl;
        return ""; // エラーを示す空文字列を返す
    }

    tm next_month = t1;
    next_month.tm_mon++;
    next_month.tm_mday = 1;
    next_month.tm_hour = 0;
    next_month.tm_min = 0;
    next_month.tm_sec = 0;

    // 年と月を調整
    if (next_month.tm_mon > 11) {
        next_month.tm_mon = 0;
        next_month.tm_year++;
    }

    mktime(&next_month); // tm_year, tm_mon の範囲を正規化
    stringstream output_ss;
    output_ss << put_time(&next_month, "%Y-%m-%dT%H:%M");
    return output_ss.str();
}

struct Data{
  string name; // データの名前
  long long size;    // データサイズ（整数, KB）
  Data(string _name="", long long _size=0): name(_name), size(_size) {}
};


struct Storage {
private:
  string _storage_name;   // ストレージの名前
  int _storage_type;      // ストレージのタイプ (A: 0, B: 1)
  long long _store_coef;  // 保存時課金係数
  long long _update_coef; // 更新時課金係数
  bool _can_use_for_free; // 無料プランで使えるかどうか

  long long _total_stored = 0;     // 現在使用している総容量 (KB)
  long long _max_stored = 0;       // 現在の月における最大容量 (KB) 
  long long _total_updated = 0;    // 現在の月における更新量 (KB)
  long long _total_used = 0;       // 今後変化がなかったとき，月末における使用時間（分）* 容量 (KB)
  long long _minutes_of_month = 0; // その月の合計時間（分）

  map<string, Data> _data;  // ファイルの情報

  // タイプAについて，指定した最大容量における保存料金を計算
  // 無料プランにおいて，操作を行っても料金がかからないかの判定に使用
  long long _calc_fee_store_A(long long max_stored){
    return ((max_stored+999)/1000+_store_coef-1)/_store_coef;
  }

  // タイプAについて，指定した更新量における更新料金を計算
  // 無料プランにおいて，操作を行っても料金がかからないかの判定に使用
  long long _calc_fee_update_A(long long total_updated){
    return ((total_updated+999)/1000+_update_coef-1)/_update_coef;
  }

  // タイプAについて，指定した最大容量，更新量における合計料金を計算
  // 無料プランにおいて，操作を行っても料金がかからないかの判定に使用
  long long _calc_fee_A(long long max_stored, long long total_updated){
    long long f_store = _calc_fee_store_A(max_stored);
    long long f_update = _calc_fee_update_A(total_updated);
    return f_store+f_update;
  }


public: 
  Storage(string storage_name="", int storage_type=0, long long store_coef=1, long long update_coef=1, bool can_use_for_free=true):
    _storage_name(storage_name), _storage_type(storage_type), _store_coef(store_coef), _update_coef(update_coef), _can_use_for_free(can_use_for_free) {}

  // 現在の最大容量における保存料金を計算
  long long calc_fee_store(){
    if(_storage_type == 0){ // タイプ A
      long long max_stored_MB = (_max_stored+999)/1000;
      return (max_stored_MB+_store_coef-1)/_store_coef;
    }else{ // タイプ B
      long long average_store_per_minutes = (_total_used+_minutes_of_month-1)/_minutes_of_month;
      long long average_store_per_minutes_MB = (average_store_per_minutes+999)/1000;
      return (average_store_per_minutes_MB+_store_coef-1)/_store_coef;
    }
  }

  // 現在の更新量における更新料金を計算
  long long calc_fee_update(){
    long long total_updated_MB = (_total_updated+999)/1000;
    return (total_updated_MB+_update_coef-1)/_update_coef;
  }

  // 現在の合計料金を計算
  long long calc_fee(){
    long long f_store = calc_fee_store();
    long long f_update = calc_fee_update();
    return f_store+f_update;
  }


  pair<bool, string> upload_file(string request_time, string month_first_time, string next_month_first_time, bool free_plan, string filename, long long filesize, long long now_fee){
    
    if(free_plan && !_can_use_for_free){ // 利用者が無料プランでストレージが使えない場合
      return {false, "UPLOAD: this storage location is not available on the free plan"};
    }

    if(_data.count(filename)){ // 同名のファイルが既に存在する場合
      return {false, "UPLOAD: file already exists"};
    }
    // cout << _calc_fee_store(max(_max_stored, _total_stored+filesize)) << " " << calc_fee_update(_total_updated+filesize) << endl;

    if(free_plan && _storage_type == 0 && now_fee+_calc_fee_A(max(_max_stored, _total_stored+filesize), _total_updated+filesize) > 1000){ // 利用料金が 1000 円を超える場合
      return {false, "UPLOAD: free plan fee limit exceeded"};
    }

    _data[filename] = Data(filename, filesize);
    _total_stored += filesize;
    _max_stored = max(_max_stored, _total_stored);
    _total_updated += filesize;

    _total_used += filesize*get_elapsed_minutes(request_time, next_month_first_time);

    return {true, "UPLOAD: Successfully uploaded!"};
  }

  pair<bool, string> delete_file(string request_time, string month_first_time, string next_month_first_time, bool free_plan, string filename, long long now_fee){
    
    if(free_plan && !_can_use_for_free){ // 利用者が無料プランでストレージが使えない場合
      return {false, "DELETE: this storage location is not available on the free plan"};
    }

    if(!_data.count(filename)){ // 同名のファイルが既に存在しない場合
      return {false, "DELETE: file does not exist"};
    }

    long long filesize = _data[filename].size;
    if(free_plan && _storage_type == 0 && now_fee+_calc_fee_A(max(_max_stored, _total_stored-filesize), _total_updated+filesize) > 1000){ // 利用料金が 1000 円を超える場合
      return {false, "DELETE: free plan fee limit exceeded"};
    }

    _total_stored -= filesize;
    _total_updated += filesize;

    // cout << get_elapsed_minutes(request_time, next_month_first_time) << endl;
    _total_used -= filesize*get_elapsed_minutes(request_time, next_month_first_time);


    return {true, "DELETE: Successfully deleted!"};
  }


  pair<bool, string> update_file(string request_time, string month_first_time, string next_month_first_time, bool free_plan, string filename, long long filesize, long long now_fee){
    
    if(free_plan && !_can_use_for_free){ // 利用者が無料プランでストレージが使えない場合
      return {false, "UPDATE: this storage location is not available on the free plan"};
    }

    if(!_data.count(filename)){ // 同名のファイルが既に存在しない場合
      return {false, "UPDATE: file does not exist"};
    }

    long long pre_filesize = _data[filename].size;
    if(free_plan && _storage_type == 0 && now_fee+_calc_fee_A(max(_max_stored, _total_stored-pre_filesize+filesize), _total_updated+pre_filesize+filesize) > 1000){ // 利用料金が 1000 円を超える場合
      return {false, "UPDATE: free plan fee limit exceeded"};
    }

    _data[filename].size = filesize;
    _total_stored -= pre_filesize;
    _total_stored += filesize;
    _max_stored = max(_max_stored, _total_stored);
    _total_updated += pre_filesize;
    _total_updated += filesize;

    _total_used -= pre_filesize*get_elapsed_minutes(request_time, next_month_first_time);
    _total_used += filesize*get_elapsed_minutes(request_time, next_month_first_time);

    return {true, "UPDATE: Successfully deleted!"};
  }

  // 現在の総保存容量 (KB) を返す
  // CALC で保存容量を表示するために使用
  long long total_stored(){
    return _total_stored;
  }
  
  // 現在の月の総時間を分で取得して格納
  // タイプ B の保存料金の計算で使用
  void set_minutes_of_month(long long elapsed_minutes){
    _minutes_of_month = elapsed_minutes;
    _total_used = elapsed_minutes*_total_stored;
  }


  // 更新量と最大容量をリセット
  // 月の初め（CALC が呼ばれたとき）に必ず行う
  void reset_per_month(){
    _total_updated = 0;
    _max_stored = _total_stored;
  }

};

struct StorageManager {
private:
  map<string, Storage> _storages;

  string _month_first_time = "";
  string _next_month_first_time = "";

  string fee_string(){
    long long store_fee = 0;
    long long update_fee = 0;
    long long total_fee = 0;
    for(auto& [name, storage]: _storages){
      store_fee += storage.calc_fee_store();
      update_fee += storage.calc_fee_update();
      total_fee += storage.calc_fee();
    }

    string res = to_string(store_fee)+' '+to_string(update_fee)+' '+to_string(max(0LL, total_fee-1000));
    return res;
  }

public:
  StorageManager(){}

  void add_storage(string name, Storage storage){
    if(_storages.count(name)) return;
    _storages[name] = storage;
  }

  void reset_per_month(){
    for(auto& [name, storage]: _storages){
      storage.reset_per_month();
    }
  }

  void set_month_first_time_and_elapesed_minutes(string request_time){
    _month_first_time = get_first_day_of_month(request_time);
    _next_month_first_time = get_first_day_of_next_month(request_time);
    // cout << _month_first_time << ' ' << _next_month_first_time << endl;
    long long elapsed_minutes = get_elapsed_minutes(_month_first_time, _next_month_first_time);
    for(auto& [name, storage]: _storages){
      // cout << elapsed_minutes << endl;
      storage.set_minutes_of_month(elapsed_minutes);
    }
  }

  string upload_file(string requesttime, string storagename, bool free_plan, string filename, long long filesize){
    if(_month_first_time == ""){
      set_month_first_time_and_elapesed_minutes(requesttime);
    }

    long long now_fee = 0;
    for(auto& [name, storage]: _storages){
      if(name == storagename) continue;
      now_fee += storage.calc_fee();
    }
    auto [status, message] = _storages[storagename].upload_file(requesttime, _month_first_time, _next_month_first_time, free_plan, filename, filesize, now_fee);
    if(!status){
      return message;
    }
    return "UPLOAD: "+fee_string();
  }

  string delete_file(string requesttime, string storagename, bool free_plan, string filename){
    if(_month_first_time == ""){
      set_month_first_time_and_elapesed_minutes(requesttime);
    }

    long long now_fee = 0;
    for(auto& [name, storage]: _storages){
      if(name == storagename) continue;
      now_fee += storage.calc_fee();
    }
    auto [status, message] = _storages[storagename].delete_file(requesttime, _month_first_time, _next_month_first_time, free_plan, filename, now_fee);
    if(!status){
      return message;
    }
    return "DELETE: "+fee_string();
  }

  string update_file(string requesttime, string storagename, bool free_plan, string filename, long long filesize){
    if(_month_first_time == ""){
      set_month_first_time_and_elapesed_minutes(requesttime);
    }

    long long now_fee = 0;
    for(auto& [name, storage]: _storages){
      if(name == storagename) continue;
      now_fee += storage.calc_fee();
    }
    auto [status, message] = _storages[storagename].update_file(requesttime, _month_first_time, _next_month_first_time, free_plan, filename, filesize, now_fee);
    if(!status){
      return message;
    }
    return "UPDATE: "+fee_string();
  }

  string calc(){
    string res = "CALC: ";
    res += '[';
    for(auto& [name, storage]: _storages){
      res += to_string(storage.total_stored())+' ';
    }
    res.pop_back(); // 最後の空白を消す
    res += "] ";

    res += fee_string();
    return res;
  }


};


int main(int argc, char *argv[]) {

  // 各ストレージを定義
  // 係数は逆数にして整数で保存（少数による演算を避けるため）
  Storage storage_A1("storage_A1", 100, 2000, true);
  Storage storage_A2("storage_A2", 1000, 100, true);
  Storage storage_B1("storage_B1", 100, 1000, false, 1);
  Storage storage_B2("storage_B2", 10000, 2, false, 1);

  StorageManager manager;
  manager.add_storage("storage_A1", storage_A1);
  manager.add_storage("storage_A2", storage_A2);
  manager.add_storage("storage_B1", storage_B1);
  manager.add_storage("storage_B2", storage_B2);

  // 利用者のステータス（無料プラン or 有料プラン）
  bool free_plan = true;

  while (!cin.eof()) {
    string request_time;
    cin >> request_time;
    
    string request_method; 
    cin >> request_method;

    string message;

    if(request_method =="UPLOAD"){
      string storagename;
      cin >> storagename;
      string filename; 
      cin >> filename;
      long long filesize;
      cin >> filesize;

      message = manager.upload_file(request_time, storagename, free_plan, filename, filesize);

    }else if(request_method == "DELETE"){
      string storagename;
      cin >> storagename;
      string filename; 
      cin >> filename;

      message = manager.delete_file(request_time, storagename, free_plan, filename);

    }else if(request_method == "UPDATE"){
      string storagename;
      cin >> storagename;
      string filename; 
      cin >> filename;
      long long filesize;
      cin >> filesize;

      message = manager.update_file(request_time, storagename, free_plan, filename, filesize);

    }else if(request_method == "CALC"){
      message = manager.calc();
      manager.reset_per_month();
      manager.set_month_first_time_and_elapesed_minutes(request_time);
    }else if(request_method == "UPGRADE"){
      // 基本実装
      if(!free_plan){
        message = "UPGRADE: user is already on the paid plan";
      }else{
        free_plan = false;
        message = "UPGRADE: accepted";
      }
    }
      cout << message << endl;

  }
  return 0;
}