#include<iostream> 

using namespace std ;

void LeftRotate (int arr []  , int  n ) 
{
    int temp = arr [ 0 ] ; 

    for (int i = 0 ; i <  n - 1 ; i++ )
    {
        arr[i] = arr[i + 1 ];
    }
    arr[n-1 ] = temp ; 
}

void RightRotate ( int   arr[] , int n )
{
    int temp = arr [ n-1 ]; 
    for (int i = n - 1 ; i > 0 ; i-- )
    {
        arr[i] = arr[i - 1 ];
    }
    arr[0] = temp; 
}
int main () 
{

    int arr [] = { 0 , 1 , 2 , 3, 4 , 5 };
    int n = 6 ;
    LeftRotate(arr , 6 );
    LeftRotate(arr , 6 );
    LeftRotate(arr , 6 );
    for (int i =0 ; i < n ; i++ )
    {
        cout<<arr[i]<<" : ";
    }
    cout<<"\n Right Rotate : \n";
    RightRotate(arr , 6);
    RightRotate(arr , 6);
    RightRotate(arr , 6);
    for (int i =0 ; i < n ; i++ )
    {
        cout<<arr[i]<<" : ";
    }


    return 0; 
}