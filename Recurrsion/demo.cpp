#include<iostream>

using namespace std ; 


void print(int index  , vector<int> nums  , vector<int> arr )
{
    if (index >=  nums.size() )
    {
        for (int i = 0 ; i  < arr.size() ; i++ )
        {
            cout<<arr[i]<<"\t";
        }
        cout<<endl;
        return ; 
    }
    
    arr.push_back(nums[index]);
    print(index + 1 , nums , arr);

    arr.pop_back() ; 
    print(index + 1  , nums , arr);

}

int main() 
{
    vector<int> arr ;
        arr.push_back(1);
        arr.push_back(2);
        arr.push_back(3);
    vector <int> demo ; 
    print(0 ,  arr , demo );
    return  0 ; 
}