//给你两个单链表的头节点 headA 和 headB ，请你找出并返回两个单链表相交的起始节点。如果两个链表不存在相交节点，返回 null 。
//
//题目数据 保证 整个链式结构中不存在环。
//
//注意，函数返回结果后，链表必须 保持其原始结构 。
//
//自定义评测：
//
//评测系统 的输入如下（你设计的程序 不适用 此输入）：
//
//intersectVal - 相交的起始节点的值。如果不存在相交节点，这一值为 0
//listA - 第一个链表
//listB - 第二个链表
//skipA - 在 listA 中（从头节点开始）跳到交叉节点的节点数
//skipB - 在 listB 中（从头节点开始）跳到交叉节点的节点数

/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */
#include <iostream>
#include <vector>
using namespace std;

// 单链表节点定义
struct ListNode {
    int val;
    ListNode *next;
    ListNode(int x) : val(x), next(nullptr) {}
};

class Solution {
public:
    ListNode *getIntersectionNode(ListNode *headA, ListNode *headB) {
        ListNode *pa = headA;
        ListNode *pb = headB;

        while(pa != pb){
          if(pa == NULL){
            pa = headB;
          }

          if(pb == NULL){
            pb = headA;
          }
          if (pa == pb){
                break;
          }
          pa = pa->next;
          pb = pb->next;
        }

        return pa;
    }
};


// 打印链表
void printList(ListNode *head) {
    while (head) {
        cout << head->val;
        if (head->next) cout << " -> ";
        head = head->next;
    }
    cout << endl;
}

// 创建两个相交链表的测试数据
// 返回 pair<listA头节点, listB头节点>
pair<ListNode*, ListNode*> createIntersectedLists(int intersectVal, int skipA, int skipB, const vector<int>& listA_vals, const vector<int>& listB_vals) {
    ListNode *headA = nullptr, *tailA = nullptr;
    ListNode *headB = nullptr, *tailB = nullptr;
    ListNode *intersection = nullptr;

    // 创建listA
    for (int i = 0; i < listA_vals.size(); i++) {
        ListNode *node = new ListNode(listA_vals[i]);
        if (!headA) headA = tailA = node;
        else tailA->next = node, tailA = node;
        if (i == skipA) intersection = node;  // 记录交叉节点
    }

    // 创建listB
    for (int i = 0; i < listB_vals.size(); i++) {
        ListNode *node = new ListNode(listB_vals[i]);
        if (!headB) headB = tailB = node;
        else tailB->next = node, tailB = node;
        if (i == skipB) tailB->next = intersection;  // 连接到listA的交叉节点
    }

    return {headA, headB};
}

int main() {
    Solution sol;

    // 示例测试用例：
    // listA: 4 -> 1 -> 8 -> 4 -> 5
    // listB: 5 -> 6 -> 1 -> 8 -> 4 -> 5
    // 交点节点值：8
    vector<int> listA_vals = {4, 1, 8, 4, 5};
    vector<int> listB_vals = {5, 6, 1};
    int intersectVal = 8;
    int skipA = 2;  // listA第2个节点(从0开始)开始交叉
    int skipB = 2;  // listB第2个节点开始交叉

    auto [headA, headB] = createIntersectedLists(intersectVal, skipA, skipB, listA_vals, listB_vals);

    cout << "List A: ";
    printList(headA);
    cout << "List B: ";
    printList(headB);

    ListNode* intersection = sol.getIntersectionNode(headA, headB);
    if (intersection) {
        cout << "Intersected at node with value: " << intersection->val << endl;
    } else {
        cout << "No intersection." << endl;
    }

    return 0;
}