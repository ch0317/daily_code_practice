//给你链表的头节点 head ，每 k 个节点一组进行翻转，请你返回修改后的链表。
//
//k 是一个正整数，它的值小于或等于链表的长度。如果节点总数不是 k 的整数倍，那么请将最后剩余的节点保持原有顺序。
//
//你不能只是单纯的改变节点内部的值，而是需要实际进行节点交换。
//
//
//
//示例 1：
//输入：head = [1,2,3,4,5], k = 2
//输出：[2,1,4,3,5]
//
//
//输入：head = [1,2,3,4,5], k = 3
//输出：[3,2,1,4,5]
//
//进阶：你可以设计一个只用 O(1) 额外内存空间的算法解决此问题吗？


/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode() : val(0), next(nullptr) {}
 *     ListNode(int x) : val(x), next(nullptr) {}
 *     ListNode(int x, ListNode *next) : val(x), next(next) {}
 * };
 */
#include <iostream>
using namespace std;

struct ListNode {
  int val;
  ListNode* next;
  ListNode(int x) : val(x), next(nullptr) {}
};

class Solution {
public:
  ListNode* reverseKGroup(ListNode* head, int k) {
    if(k == 1 || head == nullptr)
      return head;

    ListNode *node = head;
    for(int i = 0; i < k; i++){
      if(!node) return head;
      node = node->next;
    }

    ListNode *prev = nullptr;
    ListNode *curr = head;
    ListNode *tempNode = head;

    for(int i = 0; i < k; i++){
      tempNode = curr->next;
      curr->next = prev;
      prev = curr;
      curr = tempNode;
    }

    head->next = reverseKGroup(tempNode, k);
    return prev;
  }
};



// 工具函数：创建链表
ListNode* createList(initializer_list<int> vals) {
  ListNode dummy(0);
  ListNode* tail = &dummy;
  for (int v : vals) {
    tail->next = new ListNode(v);
    tail = tail->next;
  }
  return dummy.next;
}

// 工具函数：打印链表
void printList(ListNode* head) {
  while (head) {
    cout << head->val;
    if (head->next) cout << " -> ";
    head = head->next;
  }
  cout << endl;
}

int main() {
  Solution sol;

  ListNode* head1 = createList({1, 2, 3, 4, 5});
  cout << "Original list 1: ";
  printList(head1);
  ListNode* result1 = sol.reverseKGroup(head1, 2);
  cout << "Reversed in groups of 2: ";
  printList(result1);

  ListNode* head2 = createList({1, 2, 3, 4, 5});
  cout << "Original list 2: ";
  printList(head2);
  ListNode* result2 = sol.reverseKGroup(head2, 3);
  cout << "Reversed in groups of 3: ";
  printList(result2);

  return 0;
}
