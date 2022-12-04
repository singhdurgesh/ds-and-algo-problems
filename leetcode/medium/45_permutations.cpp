/*
Problem Name: 45. Permutations
Problem Link: https://leetcode.com/problems/permutations/
*/

class Solution {
public:
    vector<vector<int>> permute(vector<int>& nums) {
        return permute_v(nums, 0);
    }
    
    vector<vector<int> > permute_v(vector<int>& nums, int start){
        vector<vector<int> > ans;
        vector<int> temp2;
        if(start == nums.size()-1){
            temp2.push_back(nums[start]);
            ans.push_back(temp2);
            return ans;
        }

        vector<vector<int> > ans_n1, temp;
        ans_n1 = permute_v(nums, start+1);

        int curr = nums[start];

        for(int i=0; i<ans_n1.size(); i++){
            temp = insert_val(ans_n1[i], curr);
            for(vector<int> tt:temp){
                ans.push_back(tt);
            }
        }
        
        return ans;
    }
    
    vector<vector<int> > insert_val(vector<int> &nums, int val){
        vector<vector<int> > ans;
        int len = nums.size()+1;
        vector<int> temp(len);

        for(int i=0; i<nums.size()+1; i++){
            for(int j=0; j<i; j++){
                temp[j]=nums[j];
            }
            temp[i] = val;
            for(int j=i+1; j<nums.size()+1; j++){
                temp[j] = nums[j-1];
            }
            ans.push_back(temp);
        }
        return ans;
    }

    // method for Debugging
    void print_vector(vector<int> &v){
        for(int i=0 ;i<v.size(); i++){
            cout<<v[i]<<" ";
        }
        cout<<"\n";
    }

    // method for debugging
    void print_v(vector<vector<int>> &v){
        // cout<<v.size()<<" "<<v[0].size()<<endl;
        for(int i=0; i<v.size(); i++){
            for(int j=0; j<v[0].size(); j++){
                cout<<v[i][j]<<" ";
            }
            cout<<"\n";
        }
    }
};
