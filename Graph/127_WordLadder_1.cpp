/*
    Approach : 

        taket set data structure ;
        take queue of pair < string , step > ;
        push startword and erase it from set ; 
        while (q.empty() == false ) : 
            take word and step from queue ;
            if (word from queue matches the target word ) return step ; 
            take each character from that word and reaplace it with a - z char , if it matches push in queue and erase it from set ;          
            Continue   
        return 0 ; 
*/

class Solution {
public:
    int ladderLength(string beginWord, string endWord, vector<string>& wordList) {
        queue < pair < string , int > > q ; 
        unordered_set < string > st ( wordList.begin() , wordList.end());
        q.push({beginWord , 1});
        st.erase(beginWord);

        while (q.empty() == false )
        {
            string word = q.front().first ;
            int step = q.front().second ;
            q.pop() ; 

            if (word == endWord)
            {
                return step ; 
            }

            for (int i = 0 ; i < word.size() ; i++ )
            {
                char originalChar = word[i];
                for (char ch = 'a' ; ch <= 'z' ; ch ++ )
                {
                    word[i] = ch ; 
                    if (st.find(word) != st.end())
                    {
                        q.push({word , step + 1 });
                        st.erase(word);
                    }
                }
                word[i] = originalChar;
            }
        }
        return 0 ; 
    }
};