 
class Solution {
public:
    vector<TreeNode*> delNodes(TreeNode* root, vector<int>& to_delete) {
       vector<TreeNode*> res;
       //unordered_set<int> to_del(to_delete.begin(), to_delete.end());
        
        if(!root)
        	return res;
        
        DFS(root,NULL,res,to_delete);

        return res;
    }

    void DFS(TreeNode *&root, TreeNode *parent, vector<TreeNode*> &res, const vector<int> to_delete){
    	if(!root) return;

    	TreeNode *&left = root->left;
    	TreeNode *&right = root->right;

    	if(!is_todelete(root,to_delete) && !parent)
    		res.push_back(root);
    	else if(is_todelete(root,to_delete))
    		root = nullptr;

    	DFS(left,root,res,to_delete);
    	DFS(right,root,res,to_delete);

    }

    bool is_todelete(const TreeNode *node, const vector<int> to_delete){
    	for(auto val:to_delete){
    		if(node->val==val)
    			return true;
    	}
    	return false;
    }
};