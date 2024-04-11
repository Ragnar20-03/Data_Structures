//  One Element Can be Picked Up many Tmies
class Solution {
    void subSequence(int index , int target , vector<int> & nums , vector<int> &arr , vector<vector<int>>&ans )
    {
        if (index >= nums.size() )
        {
            if (target == 0 )
            {
                ans.push_back(arr);
            }
            return ;
        }

       if (nums[index] <= target)
       {
            arr.push_back(nums[index]);
            subSequence(index , (target - nums[index]) , nums , arr , ans );
            arr.pop_back() ; 
       }

       subSequence(index + 1 , target , nums , arr , ans );

    } 
public:
    vector<vector<int>> combinationSum(vector<int>& candidates, int target) {
        vector<int> arr;
        vector<vector<int > > ans ; 
        subSequence(0 , target  , candidates , arr , ans);
        return ans ; 
    }
};