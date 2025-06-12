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
class Solution {
public:
    TreeNode* sortedArrayToBST(vector<int>& nums) {
        return makeBST(0 , nums.size() - 1 , nums);
    }

    TreeNode* makeBST(int l , int r , vector<int>&nums){
        if(l > r)return nullptr;


        int m = l + (r - l)/2;
        TreeNode* root = new TreeNode(nums[m]);

        root -> left = makeBST(l , m - 1 , nums);
        root -> right = makeBST(m + 1 , r , nums);

        return root;
    }
};