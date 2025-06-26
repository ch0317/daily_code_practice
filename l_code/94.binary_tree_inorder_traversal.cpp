//给定一个二叉树的根节点 root ，返回 它的 中序 遍历 。
//
//
//
//示例 1：
//
//
//输入：root = [1,null,2,3]
//输出：[1,3,2]
//示例 2：
//
//输入：root = []
//输出：[]
//示例 3：
//
//输入：root = [1]
//输出：[1]
//
//
//提示：
//
//树中节点数目在范围 [0, 100] 内
//-100 <= Node.val <= 100
//
//
//进阶: 递归算法很简单，你可以通过迭代算法完成吗？

/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 * };
 */
#include <iostream>
#include <vector>
#include <stack>
using namespace std;

// 二叉树节点定义
struct TreeNode {
  int val;
  TreeNode *left;
  TreeNode *right;
  TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
};

// 解法类
class Solution {
public:
  vector<int> inorderTraversal(TreeNode* root) {
    stack<TreeNode *> st;
    TreeNode * curr = root;
    vector<int> result;

    while(curr != nullptr || !st.empty()){
      while(curr){
        st.push(curr);
        curr = curr->left;
      }

      curr = st.top();
      st.pop();
      result.push_back(curr->val);
      curr = curr->right;
    }

    return result;
  }
};


// 构建示例树：[1, null, 2, 3]
TreeNode* buildSampleTree() {
  TreeNode* node3 = new TreeNode(3);
  TreeNode* node2 = new TreeNode(2);
  node2->left = node3;
  TreeNode* root = new TreeNode(1);
  root->right = node2;
  return root;
}

void printVector(const vector<int>& vec) {
  for (int val : vec) {
    cout << val << " ";
  }
  cout << endl;
}

int main() {
  Solution sol;

  // 示例1
  TreeNode* root1 = buildSampleTree();
  vector<int> result1 = sol.inorderTraversal(root1);
  cout << "Output 1: ";
  printVector(result1); // 应该输出 [1, 3, 2]

  // 示例2
  TreeNode* root2 = nullptr;
  vector<int> result2 = sol.inorderTraversal(root2);
  cout << "Output 2: ";
  printVector(result2); // 应该输出 []

  // 示例3
  TreeNode* root3 = new TreeNode(1);
  vector<int> result3 = sol.inorderTraversal(root3);
  cout << "Output 3: ";
  printVector(result3); // 应该输出 [1]

  return 0;
}

