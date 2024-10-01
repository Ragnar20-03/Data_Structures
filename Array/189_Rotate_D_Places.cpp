#include<iostream> 

using namespace std ; 

void RotateLeftByDPlaces (int arr [] , int n , int k) {
    int temp [n-k] ; 
    for (int i = 0 ; i < k ; i++ )
    {
        temp[i] = arr[i] ; 
    }

    cout<<"\n : Temp is : " ;
    for (int i = 0 ; i < k ; i++ )
    {
        cout<<temp[i]<< " : " ;
    }

    for (int i = k ; i < n ; i++  )
    {
        arr[i-k] = arr[i];
    }
    cout<<"\nArray after half shifting is : \n"  ; 
    for (int i = 0 ; i < n ; i++ )
    {
        cout << arr[i]<<" : " ;
    }
    int j = 0 ;
    for (int i = n- k ; i < n ; i++ )
    {
        arr[i] = temp[j] ; 
        j++;
    }
     cout<<"\nArray after Complete shifting is : \n"  ; 
    for (int i = 0 ; i < n ; i++ )
    {
        cout << arr[i]<<" : " ;
    }

}

int main () 
{
    int arr [] = { 1 , 2  ,3 ,4 ,5 , 6 , 7 };
    int n = 7 ; 
    int k = 3 ; 
    RotateLeftByDPlaces(arr , n  , k);
    return 0 ; 
}
