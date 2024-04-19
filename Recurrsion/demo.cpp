#include<iostream>
#include<vector> 
using namespace std ; 


void print(int index , int sum , int k   , vector<int> nums  , vector<int> arr )
{
    if (index >=  nums.size() )
    {
        if (sum == k )
        {
            for (auto it : arr)
            {
                cout<<it<<"\t";
            }
            cout<<"\n";
        }
            return  ; 
    }

    sum += nums[index];
    arr.push_back(nums[index]);
    print(index + 1 , sum , k  , nums , arr);

    arr.pop_back() ; 
    sum -= nums[index];
    print(index + 1 , sum , k  , nums , arr);

}

int main() 
{
    vector<int> arr ;
        arr.push_back(1);
        arr.push_back(2);
        arr.push_back(3);
        arr.push_back(4);
        arr.push_back(5);

    vector <int> demo ; 
    print(0 , 0 , 6 ,   arr , demo );
    return  0 ; 
}