//设计一个基于时间的键值数据结构，该结构可以在不同时间戳存储对应同一个键的多个值，并针对特定时间戳检索键对应的值。
//
//实现 TimeMap 类：
//
//TimeMap() 初始化数据结构对象
//void set(String key, String value, int timestamp) 存储给定时间戳 timestamp 时的键 key 和值 value。
//String get(String key, int timestamp) 返回一个值，该值在之前调用了 set，其中 timestamp_prev <= timestamp 。如果有多个这样的值，它将返回与最大  timestamp_prev 关联的值。如果没有值，则返回空字符串（""）。
//
//示例 1：
//
//输入：
//["TimeMap", "set", "get", "get", "set", "get", "get"]
//[[], ["foo", "bar", 1], ["foo", 1], ["foo", 3], ["foo", "bar2", 4], ["foo", 4], ["foo", 5]]
//输出：
//[null, null, "bar", "bar", null, "bar2", "bar2"]
//
//解释：
//TimeMap timeMap = new TimeMap();
//timeMap.set("foo", "bar", 1);  // 存储键 "foo" 和值 "bar" ，时间戳 timestamp = 1
//timeMap.get("foo", 1);         // 返回 "bar"
//timeMap.get("foo", 3);         // 返回 "bar", 因为在时间戳 3 和时间戳 2 处没有对应 "foo" 的值，所以唯一的值位于时间戳 1 处（即 "bar"） 。
//timeMap.set("foo", "bar2", 4); // 存储键 "foo" 和值 "bar2" ，时间戳 timestamp = 4
//timeMap.get("foo", 4);         // 返回 "bar2"
//timeMap.get("foo", 5);         // 返回 "bar2"
//
//
//提示：
//
//1 <= key.length, value.length <= 100
//key 和 value 由小写英文字母和数字组成
//1 <= timestamp <= 107
//set 操作中的时间戳 timestamp 都是严格递增的
//最多调用 set 和 get 操作 2 * 105 次

#include <iostream>
#include <unordered_map>
#include <vector>
#include <string>
#include <algorithm>

using namespace std;

class TimeMap {
  unordered_map<string, vector<pair<int, string>>> mp_;
public:

  TimeMap() {}

  void set(string key, string value, int timestamp) {
    mp_[key].push_back({timestamp, value});
  }

  string get(string key, int timestamp) {
    if(mp_.count(key) == 0) return "";

    int left = 0;
    int right = mp_[key].size() - 1;
    string res = "";

    while(left <= right) {
      int md = left + (right - left) / 2;
      if(mp_[key][md].first <= timestamp){
        res = mp_[key][md].second;
        left = md + 1;
      }else{

        right = md - 1;
      }
    }

    return res;
  }

};

int main() {
  TimeMap timeMap;

  timeMap.set("foo", "bar", 1);
  cout << timeMap.get("foo", 1) << endl; // 输出: bar
  cout << timeMap.get("foo", 3) << endl; // 输出: bar

  timeMap.set("foo", "bar2", 4);
  cout << timeMap.get("foo", 4) << endl; // 输出: bar2
  cout << timeMap.get("foo", 5) << endl; // 输出: bar2

  cout << timeMap.get("foo", 0) << endl; // 输出: 空字符串

  return 0;
}


/**
 * Your TimeMap object will be instantiated and called as such:
 * TimeMap* obj = new TimeMap();
 * obj->set(key,value,timestamp);
 * string param_2 = obj->get(key,timestamp);
 */