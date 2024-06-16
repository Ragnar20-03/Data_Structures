#include <bits/stdc++.h> 
// Brute Force
vector<int> findArrayIntersection(vector<int> &a, int n, vector<int> &b, int m)
{
	// Write your code here.
	vector<int > intersection ; 
	int visited [ m ] = { 0 } ; 
	for ( int i = 0 ; i < n ; i++  )
	{
		for (int j = 0  ; j < m ; j++ )
		{
			if (a[i] == b[j] && visited [ j ] == 0 )
			{
				intersection.push_back(a[i]);
				visited[j] = 1; 
				break;
			}
			if (a[i] < b [ j ])
			{
				break ; 
			}
		}
	}
	return intersection ; 
}


// Ptimal Approach 
// tow pointers 
// if same then push 
// if a[i] < b[j] then element not found , break ;
// if a[i] > b[j] then element of second is not found in first array , break ; 

vector<int> findArrayIntersection(vector<int> &a, int n, vector<int> &b, int m)
{
	// Write your code here.
	vector<int > intersection ; 
	int i = 0 ; 
	int j = 0 ; 
	while ( i < n && j < m )
	{

		if (a[i] == b[j])
		{
			intersection.push_back(a[i]);
			i++ ;
			j++ ; 
		}
		else if ( a[i] > b[j])
		{
			j ++ ; 
		}
		else if (a[i] < b[j])
		{
			i++ ; 
		}
	}