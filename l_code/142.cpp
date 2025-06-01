// 给定一个链表的头节点  head ，返回链表开始入环的第一个节点。 如果链表无环，则返回 null。
// 如果链表中有某个节点，可以通过连续跟踪 next 指针再次到达，则链表中存在环。
// 为了表示给定链表中的环，评测系统内部使用整数 pos 来表示链表尾连接到链表中的位置（索引从 0 开始）。
// 如果 pos 是 -1，则在该链表中没有环。注意：pos 不作为参数进行传递，仅仅是为了标识链表的实际情况。
// 不允许修改 链表。
// 输入：head = [3,2,0,-4], pos = 1
// 输出：返回索引为 1 的链表节点
// 解释：链表中有一个环，其尾部连接到第二个节点
//
// 输入：head = [1,2], pos = 0
// 输出：返回索引为 0 的链表节点
// 解释：链表中有一个环，其尾部连接到第一个节点。
//
// 输入：head = [1], pos = -1
// 输出：返回 null
// 解释：链表中没有环。

/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */
#include <iostream>
#include <unordered_map>
#include <vector>
using namespace std;

// 定义链表节点
struct ListNode {
    int val;
    ListNode *next;
    ListNode(int x) : val(x), next(NULL) {}
};

class Solution {
public:
    ListNode *detectCycle(ListNode *head) {
        if(head == nullptr || head->next == nullptr)
          return nullptr;
        ListNode *slow = head;
        ListNode *fast = head;
        while(fast != nullptr && fast->next != nullptr){
            slow = slow->next;
            fast = fast->next->next;
          if(fast == slow){
            fast = head;
            while(fast != slow){
              fast = fast->next;
              slow = slow->next;
            }
            return fast;
          }

        }

        return nullptr;
    }
};

// 辅助函数：创建带环链表
ListNode* createLinkedListWithCycle(vector<int> vals, int pos) {
    if (vals.empty()) return nullptr;
    ListNode* head = new ListNode(vals[0]);
    ListNode* curr = head;
    ListNode* cycleEntry = nullptr;
    if (pos == 0) cycleEntry = head;
    for (int i = 1; i < vals.size(); i++) {
        curr->next = new ListNode(vals[i]);
        curr = curr->next;
        if (i == pos) cycleEntry = curr;
    }
    if (pos != -1) curr->next = cycleEntry;
    return head;
}

// 测试函数
void test(vector<int> vals, int pos, int expectedIndex) {
    ListNode* head = createLinkedListWithCycle(vals, pos);
    Solution sol;
    ListNode* result = sol.detectCycle(head);

    if (result) {
        cout << "入环节点值: " << result->val << endl;
        // 确认返回的是第 expectedIndex 个节点
        ListNode* temp = head;
        int index = 0;
        while (temp && temp != result) {
            temp = temp->next;
            index++;
        }
        cout << "实际索引: " << index << (index == expectedIndex ? " ✅" : " ❌") << endl;
    } else {
        cout << "无环" << (expectedIndex == -1 ? " ✅" : " ❌") << endl;
    }
}

int main() {
    test({3,2,0,-4}, 1, 1);
    test({1,2}, 0, 0);
    test({1}, -1, -1);
    return 0;
}

