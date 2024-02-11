#include<iostream>
using namespace std;
void traverseNeighbours_four_direction (int arr[4][4]  , int row , int col)
{
    int deltaRow [] = {-1 , 0 , 1 , 0  };
    int deltaCol [] = { 0 , 1 , 0 , -1 };

    for (int i = 0 ;i< 4 ; i++)
    {
        int newRow = row + deltaRow[i];
        int newCol  = col + deltaCol[i]; 

        if (newCol < 4 && newRow >= 0  && newCol >= 0 && newCol < 4 )
        {
            cout<<": "<<arr[newRow][newCol]<<endl;
        }
    }
}

void traverseNeighbours_eight_Direction(int arr[4][4] , int row , int col)
{
    for (int deltaRow = -1 ; deltaRow <= 1 ; deltaRow ++)
    {
        for (int deltaCol = -1 ; deltaCol <= 1 ; deltaCol++ )
        {
            int newRow = row + deltaRow ; 
            int newCol = col + deltaCol ; 
        }
    }
}
