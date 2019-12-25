

/**
/*
// Employee info
class Employee {
public:
    // It's the unique ID of each node.
    // unique id of this employee
    int id;
    // the importance value of this employee
    int importance;
    // the id of direct subordinates
    vector<int> subordinates;
};
*/

class Solution {
public:
    int getImportance(vector<Employee*> employees, int id) {
        int res = 0;
        queue<int> q;
        q.push(id);
        
        while(!q.empty()) {
            int num = 0;
            while(num < employees.size() && employees[num]->id != q.front()) num++;
            res += employees[num]->importance;
            for(int i = 0; i < employees[num]->subordinates.size(); i++) q.push(employees[num]->subordinates[i]);
            q.pop();
        }
        return res;
    }
};