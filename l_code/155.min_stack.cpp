//设计一个支持 push ，pop ，top 操作，并能在常数时间内检索到最小元素的栈。
//
//实现 MinStack 类:
//
//MinStack() 初始化堆栈对象。
//void push(int val) 将元素val推入堆栈。
//void pop() 删除堆栈顶部的元素。
//int top() 获取堆栈顶部的元素。
//int getMin() 获取堆栈中的最小元素。
//
//
//示例 1:
//
//输入：
//["MinStack","push","push","push","getMin","pop","top","getMin"]
//[[],[-2],[0],[-3],[],[],[],[]]
//
//输出：
//[null,null,null,null,-3,null,0,-2]
//
//解释：
//MinStack minStack = new MinStack();
//minStack.push(-2);
//minStack.push(0);
//minStack.push(-3);
//minStack.getMin();   --> 返回 -3.
//minStack.pop();
//minStack.top();      --> 返回 0.
//minStack.getMin();   --> 返回 -2.
//
//
//提示：
//
//-231 <= val <= 231 - 1
//pop、top 和 getMin 操作总是在 非空栈 上调用
//push, pop, top, and getMin最多被调用 3 * 104 次
#include <iostream>
#include <vector>
using namespace std;
class MinStack {
  vector<pair<int,int>> data_;
public:
  MinStack() {

  }

  void push(int val) {
    if(data_.empty()){
      data_.push_back({val,val});
    }else{
      int t = data_.back().second;
      if(val < t){
        data_.push_back({val,val});
      }else{
        data_.push_back({val,t});
      }
    }
  }

  void pop() {
    data_.pop_back();
  }

  int top() {
    return data_.back().first;
  }

  int getMin() {
    return data_.back().second;
  }
};


int main() {
  MinStack minStack;
  minStack.push(-2);
  minStack.push(0);
  minStack.push(-3);
  cout << "getMin(): " << minStack.getMin() << endl; // -3
  minStack.pop();
  cout << "top(): " << minStack.top() << endl;       // 0
  cout << "getMin(): " << minStack.getMin() << endl; // -2
  return 0;
}

/**
 * Your MinStack object will be instantiated and called as such:
 * MinStack* obj = new MinStack();
 * obj->push(val);
 * obj->pop();
 * int param_3 = obj->top();
 * int param_4 = obj->getMin();
 */
