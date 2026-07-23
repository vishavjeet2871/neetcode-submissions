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
    int find(vector<int> &inorder,int left,int right,int val){
        for(int i=left;i<=right;i++){
            if(inorder[i]==val){
                return i;
            }
        }
        return -1;
    }
    TreeNode* build(vector<int>&inorder,vector<int>&postorder,int &postidx,int left,int right){
        if(left>right || postidx<0){
            return NULL;
        }
        int val=postorder[postidx];
        int inidx=find(inorder,left,right,val);
        TreeNode* cur=new TreeNode(val);
        postidx--;
        cur->right=build(inorder,postorder,postidx,inidx+1,right);
        cur->left=build(inorder,postorder,postidx,left,inidx-1);

        return cur;

    }
    TreeNode* buildTree(vector<int>& inorder, vector<int>& postorder) {
        int postidx=inorder.size()-1;
        return build(inorder,postorder,postidx,0,inorder.size()-1);
    }
};