/**
*  struct ListNode {
*        int val;
*        struct ListNode *next;
*        ListNode(int x) :
*              val(x), next(NULL) {
*        }
*  };
*/
/*
class Solution {
public:
    vector<int> printListFromTailToHead(ListNode* head) {
        vector<int> res;
        
        ListNode *pre_node,*next_node;
        
        pre_node = head;
        next_node = pre_node;
         if(head==NULL)
            return res;

        while(head->next){
        	next_node = head->next;
        	head->next = next_node->next;
        	next_node->next = pre_node;
        	pre_node = next_node;
        }
        while(pre_node){
        	res.push_back(pre_node->val);
        	pre_node = pre_node->next;
        }

        return res;
    }
};*/

//first time
/*
class Solution {
public:
    vector<int> printListFromTailToHead(ListNode* head) {
        vector<int> res;
        while(head){
        	res.push_back(head->val);
        	head = head->next;
        }

        reverse(res.begin(),res.end());
        return res;
    }
};
*/



class Solution {
public:
    vector<int> printListFromTailToHead(ListNode* head) {
        vector<int> res;
        
        if(!head) return res;

        ListNode *pre_node = nullptr;
        ListNode *sec_node = nullptr;

        while(head){
        	sec_node = head->next;
        	head->next = pre_node;
        	pre_node = head;
        	head = sec_node;
        }
        head = pre_node;
        while(head){
        	res.push_back(head->val);
        	head = head->next;
        }

        return res;

    }
};


class Solution {
public:
    vector<int> reversePrint(ListNode* head) {
    	ListNode *curr_node = head;
    	ListNode *pre_node = nullptr;
    	ListNode *next;

    	while(curr_node){
    		next = curr_node->next;
    		curr_node->next = pre_node;
    		pre_node = curr_node;
    		curr_node =  next;
    	}

    	vector<int> res;
    	while(pre_node){
    		res.push_back(pre_node->val);
    		pre_node = pre_node->next;
    	}

    	return res;
    }
};
