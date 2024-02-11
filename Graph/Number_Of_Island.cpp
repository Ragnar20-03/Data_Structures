#include<iostream>
#include<vector>
#include<queue>

using namespace std  ; 

void Bfs(int startRow , int startCol , int visited[4][4] , int arr[4][4])
{
    queue<pair<int, int> >  q ; 
    q.push(make_pair(startRow , startCol));
    visited[startRow][startCol] = 1;  

    while (q.empty() == false)
    {
        int row = q.front().first ; 
        int col = q.front().second;
    q.pop();
        for (int deltaRow = -1 ; deltaRow <= 1 ; deltaRow ++)
        {
            for (int deltaCol = -1 ; deltaCol <= 1; deltaCol ++)
            {
                int nRow = row + deltaRow ; 
                int nCol = col + deltaCol ; 

                if (nRow < 4 && nCol < 4 && nRow >= 0 && nCol >= 0 && visited[nRow][nCol] != 1 && arr[nRow][nCol] == 1 )
                {
                    q.push(make_pair(nRow , nCol));
                    visited[nRow][nCol] = 1; 
                }
            }
        }
    }
}

int main()
{
    int arr[4][4] =   {
        {0, 0, 1, 1},
        {1, 0, 0, 0},
        {1, 0, 0, 0},
        {1, 0, 1, 1}
    };

    int iCnt = 0 ; 
    int visited[4][4] = {
        {0, 0, 0, 0},
        {0, 0, 0, 0},
        {0, 0, 0, 0},
        {0, 0, 0, 0}
    };
 
    for (int i = 0 ; i< 4 ; i++)
    {
        for (int j = 0 ; j < 4 ; j++)
        {
            cout<<"hii\n";
            if (arr[i][j] == 1 && visited[i][j] != 1)
            {
                cout<<"inside \n";
                iCnt ++; 
                Bfs(i , j , visited , arr);
            }
        }
    }

    return 0 ;
}