 // Brute Force 
 vector<int> findUnion(int arr1[], int arr2[], int n, int m)
    {
        //Your code here
        //return vector with correct order of elements
        vector<int > ans ; 
        set < int > st ; 
        for (int i = 0 ; i < n ; i++ )
        {
            st.insert(arr1[i]);
        }
        for (int i = 0 ; i < m ; i++ )
        {
            st.insert(arr2[i]);
        }
        
        for (auto it : st)
        {
            ans.push_back(it);
        }
        return ans ; 
    }


    // Not Using Set |||| Oprimal Approach 

     vector<int> findUnion(int arr1[], int arr2[], int n, int m)
    {
        //Your code here
        int i = 0 ; 
        int j = 0 ; 
        vector<int > uni ; 
        
        while ( i < n && j < m)
        {
            if (arr1[i] <= arr2[j])
            {
                if (uni.size() == 0 || uni.back() != arr1[i])
                {
                    uni.push_back(arr1[i]);
                }
                i++ ; 
            }
            if (arr1[i] >= arr2[j])
            {
                if (uni.size() == 0 || uni.back() != arr2[j])
                {
                    uni.push_back(arr2[j]);
                }
                j++ ; 
            }
        }
        while (i < n )
        {
            if (uni.size() == 0 || uni.back() != arr1[i])
                {
                    uni.push_back(arr1[i]);
                }
                i++ ; 
        }
        while (j < m )
        {
            if (uni.size() == 0 || uni.back() != arr2[j])
                {
                    uni.push_back(arr2[j]);
                }
                j++ ; 
        }
        return uni ; 
    }