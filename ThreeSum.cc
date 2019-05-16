class ThreeSum {
public:
    vector<vector<int>> threeSum(vector<int>& nums) {
        int x = 0;
        vector<vector<int>> nested_vector;
        vector<int> target_indices;
        sort(nums.begin(), nums.end());
        for (int i = 0; i < nums.size()-2; ++i) { 
           for (int j = i + 1; j < nums.size()-1; ++j) { 
             for (int k = j + 1; k < nums.size(); ++k) {
               if (nums[i] + nums[j] + nums[k] == 0) {                         
                   target_indices.push_back(nums[i]);
                   target_indices.push_back(nums[j]);
                   target_indices.push_back(nums[k]);
                   nested_vector.push_back(target_indices);
                   return nested_vector;
               }
             }
           } 
        }
        return nested_vector;
    }
};
