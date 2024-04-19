#include<iostream>
#include<vector> 
using namespace std ; 

int Count_SubSequence_Sum_Equal_to_k( int index , int sum , int  k  , vector<int>arr , vector<int>nums)
{
    if (index >= nums.size() )
    {
        if (sum == k )
        {
            for (auto it : arr)
            {
                cout<<it<<"\t";
            }
            cout<<"\n";
            return 1 ; 
        }
        return 0 ; 
    }

    sum += nums[index];
    arr.push_back(nums[index]);
    int takeCount = Count_SubSequence_Sum_Equal_to_k(index + 1, sum , k , arr , nums);

    arr.pop_back() ; 
    sum -= nums[index];
    int notTakeCount = Count_SubSequence_Sum_Equal_to_k(index + 1, sum , k , arr , nums);

    return takeCount + notTakeCount;

}

int main()
{

    vector<int> arr ; 
    vector<int>demo ; 

    arr.push_back(1);
    arr.push_back(2);
    arr.push_back(3);
    arr.push_back(4);
    arr.push_back(5);
    arr.push_back(6);

    cout<<"count is : "<<Count_SubSequence_Sum_Equal_to_k(0 , 0 , 10 , demo , arr);
    return  0 ; 
}