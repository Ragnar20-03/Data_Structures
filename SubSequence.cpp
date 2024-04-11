#include<iostream>
 #include<vector>

 using namespace std ;

void SubSequenceEqualToK(int index , int k , int &sum , 
    vector<int > & nums , vector<int > &arr , vector<vector<int> > & ans)
{
        if (index >= nums.size() )
        {
                if (k == sum)
                {
                    ans.push_back(arr);
                }
                return ; 
                
        }

        sum += nums[index];
        arr.push_back(nums[index]);
        SubSequenceEqualToK(index + 1, k ,sum  , nums , arr  , ans);

        sum -= nums[index];
        arr.pop_back();
        SubSequenceEqualToK(index + 1, k ,sum  , nums , arr  , ans);

}


 int main()
 {
    vector<int > nums ; 
    nums.push_back(1);
    nums.push_back(2);
    nums.push_back(1);
    nums.push_back(0);
    nums.push_back(4);
    int sum = 0 ; 
    vector<vector<int > > ans ; 
    vector<int>arr ;
    SubSequenceEqualToK(0 , 6 , sum , nums  , arr, ans );

    for (auto it : ans)
    {
        cout<<"[";
        for (auto itX : it)
        {
            cout<<itX<<" ";
        }
        cout<<"]\n";
    }
    return  0 ; 
 }