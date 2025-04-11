//给你一个链表，删除链表的倒数第 n 个结点，并且返回链表的头结点。
//输入：head = [1,2,3,4,5], n = 2
//输出：[1,2,3,5]
//示例 2：
//
//输入：head = [1], n = 1
//输出：[]
//示例 3：
//
//输入：head = [1,2], n = 1
//输出：[1]
#include <iostream>
#include <vector>
using namespace std;

struct ListNode {
    int val;
    ListNode *next;
    ListNode() : val(0), next(nullptr) {}
    ListNode(int x) : val(x), next(nullptr) {}
    ListNode(int x, ListNode *next) : val(x), next(next) {}
};

// 打印链表
void printList(ListNode* head) {
  while (head) {
    cout << head->val;
    if (head->next) cout << " -> ";
    head = head->next;
  }
  cout << endl;
}

// 创建链表
ListNode* createList(const vector<int>& vals) {
  if (vals.empty()) return nullptr;
  ListNode* head = new ListNode(vals[0]);
  ListNode* current = head;
  for (size_t i = 1; i < vals.size(); ++i) {
    current->next = new ListNode(vals[i]);
    current = current->next;
  }
  return head;
}

class Solution {
public:
  ListNode* removeNthFromEnd(ListNode* head, int n) {
    ListNode *dummy_head = new ListNode();
    dummy_head->next = head;
    ListNode *fast = head;
    ListNode *slow = head;
    for(int i = 0; i < n; i++){
      fast = fast->next;
    }

    ListNode *pre = dummy_head;
    while(fast != nullptr){
      fast = fast->next;
      pre = slow;
      slow = slow->next;

    }

    pre->next = slow->next;

    return dummy_head->next;

  }
};

int main() {
  Solution sol;

  vector<vector<int>> test_cases = {
    {1},
    {1, 2},
    {1, 2, 3, 4, 5}
  };
  vector<int> ns = {1, 1, 2};

  for (size_t i = 0; i < test_cases.size(); ++i) {
    cout << "Original list: ";
    ListNode* head = createList(test_cases[i]);
    printList(head);
    cout << "Removing " << ns[i] << "th node from end...\n";
    head = sol.removeNthFromEnd(head, ns[i]);
    cout << "Updated list: ";
    printList(head);
    cout << "---------------------\n";
  }

  return 0;
}