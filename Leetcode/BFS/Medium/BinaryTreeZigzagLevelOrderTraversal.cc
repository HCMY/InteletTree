class Solution {
public:
    vector<vector<int>> zigzagLevelOrder(TreeNode* root) {
      vector<vector<int>> res;
      vector<int> tmp_vec;
      queue<TreeNode*> my_queue;
      TreeNode* tmp_node;

      int level = 2;
      
      if(!root)
          return res;
       my_queue.push(root);
       my_queue.push(NULL);
        
        while(!my_queue.empty()){
            while(my_queue.front()!=NULL){
                tmp_node = my_queue.front();
                tmp_vec.push_back(tmp_node->val);
                
                if(tmp_node->left)
                  my_queue.push(tmp_node->left);
                if(tmp_node->right)
                  my_queue.push(tmp_node->right);

                my_queue.pop();
            }
            my_queue.pop();

            if(!my_queue.empty())
              my_queue.push(NULL);

            if(level%2==0)
              res.push_back(tmp_vec);
            else{
                reverse(tmp_vec.begin(),tmp_vec.end());
                res.push_back(tmp_vec);
            }
            
            tmp_vec.clear();
            level++;
        }

        return res;
    }
};