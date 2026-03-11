using namespace std;

struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode() : val(0), left(nullptr), right(nullptr) {}
    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
    TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
};

void swap(TreeNode* current) {
    if (!current) {
        return;
    }
    swap(current->left);
    swap(current->right);
    TreeNode* t;
    t->left = current->left;
    current->left = current->right;
    current->right = t->left;
}

class Solution {
public:
    TreeNode* invertTree(TreeNode* root) {
        swap(root);
        return root;
    }
};



