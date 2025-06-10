//给你一个链表数组，每个链表都已经按升序排列。
//
//请你将所有链表合并到一个升序链表中，返回合并后的链表。
//
//
//
//示例 1：
//
//输入：lists = [[1,4,5],[1,3,4],[2,6]]
//输出：[1,1,2,3,4,4,5,6]
//解释：链表数组如下：
//[
//  1->4->5,
//  1->3->4,
//  2->6
//]
//将它们合并到一个有序链表中得到。
//1->1->2->3->4->4->5->6
//示例 2：
//
//输入：lists = []
//输出：[]
//示例 3：
//
//输入：lists = [[]]
//输出：[]
//
//
//提示：
//
//k == lists.length
//0 <= k <= 10^4
//0 <= lists[i].length <= 500
//-10^4 <= lists[i][j] <= 10^4
//lists[i] 按 升序 排列
//lists[i].length 的总和不超过 10^4

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
#include <vector>
#include <queue> // For priority_queue
#include <algorithm> // For std::reverse (optional, if building lists from vector in reverse)

// Definition for singly-linked list.
struct ListNode {
    int val;
    ListNode *next;
    ListNode() : val(0), next(nullptr) {}
    ListNode(int x) : val(x), next(nullptr) {}
    ListNode(int x, ListNode *next) : val(x), next(next) {}
};

struct CompareNode {
    bool operator()(ListNode* a, ListNode* b){
        return a->val > b->val;
    }
};

class Solution {
public:
    ListNode* mergeKLists(std::vector<ListNode*>& lists) {
        //auto CompareNode = [](ListNode *a, ListNode *b){ return a->val > b->val; };
        std::priority_queue<ListNode*, std::vector<ListNode*>, CompareNode> min_heap;

        ListNode* dummy_head = new ListNode(0);
        ListNode *curr = dummy_head;
        for(auto l : lists){
            if (l)
                min_heap.push(l);
        }

        while(!min_heap.empty()){
            ListNode *min_node = min_heap.top();
            min_heap.pop();

            curr->next = min_node;
            curr = min_node;

            if(min_node->next){
              min_heap.push(min_node->next);
            }
        }

        return dummy_head->next;
    }
};

// Helper function to create a linked list from a vector
ListNode* createList(const std::vector<int>& nums) {
    if (nums.empty()) {
        return nullptr;
    }
    ListNode* head = new ListNode(nums[0]);
    ListNode* current = head;
    for (size_t i = 1; i < nums.size(); ++i) {
        current->next = new ListNode(nums[i]);
        current = current->next;
    }
    return head;
}

// Helper function to print a linked list
void printList(ListNode* head) {
    ListNode* current = head;
    while (current) {
        std::cout << current->val;
        if (current->next) {
            std::cout << " -> ";
        }
        current = current->next;
    }
    std::cout << std::endl;
}

// Helper function to free memory used by a linked list
void deleteList(ListNode* head) {
    ListNode* current = head;
    while (current) {
        ListNode* next = current->next;
        delete current;
        current = next;
    }
}

int main() {
    Solution sol;

    // Example 1:
    std::cout << "Example 1:" << std::endl;
    std::vector<ListNode*> lists1;
    lists1.push_back(createList({1, 4, 5}));
    lists1.push_back(createList({1, 3, 4}));
    lists1.push_back(createList({2, 6}));
    std::cout << "Input:" << std::endl;
    for (ListNode* l : lists1) {
        printList(l);
    }
    ListNode* result1 = sol.mergeKLists(lists1);
    std::cout << "Output: ";
    printList(result1);
    // Expected: 1 -> 1 -> 2 -> 3 -> 4 -> 4 -> 5 -> 6
    deleteList(result1); // Free memory
    for (ListNode* l : lists1) { // Also free input lists memory
        deleteList(l);
    }

    std::cout << std::endl;

    // Example 2:
    std::cout << "Example 2:" << std::endl;
    std::vector<ListNode*> lists2; // Empty list of lists
    std::cout << "Input: []" << std::endl;
    ListNode* result2 = sol.mergeKLists(lists2);
    std::cout << "Output: ";
    printList(result2);
    // Expected: (empty line)
    deleteList(result2);

    std::cout << std::endl;

    // Example 3:
    std::cout << "Example 3:" << std::endl;
    std::vector<ListNode*> lists3;
    lists3.push_back(createList({})); // List containing an empty list
    std::cout << "Input: [[]]" << std::endl;
    ListNode* result3 = sol.mergeKLists(lists3);
    std::cout << "Output: ";
    printList(result3);
    // Expected: (empty line)
    deleteList(result3);
    for (ListNode* l : lists3) {
        deleteList(l);
    }

    std::cout << std::endl;

    // Custom Test Case: Some empty lists, some single-node lists, some longer lists
    std::cout << "Custom Test Case:" << std::endl;
    std::vector<ListNode*> lists_custom;
    lists_custom.push_back(createList({}));
    lists_custom.push_back(createList({10}));
    lists_custom.push_back(createList({-5, 0, 5}));
    lists_custom.push_back(createList({20, 25}));
    lists_custom.push_back(createList({}));
    lists_custom.push_back(createList({1}));
    std::cout << "Input:" << std::endl;
    for (ListNode* l : lists_custom) {
        printList(l);
    }
    ListNode* result_custom = sol.mergeKLists(lists_custom);
    std::cout << "Output: ";
    printList(result_custom);
    // Expected: -5 -> 0 -> 1 -> 5 -> 10 -> 20 -> 25
    deleteList(result_custom);
    for (ListNode* l : lists_custom) {
        deleteList(l);
    }

    return 0;
}