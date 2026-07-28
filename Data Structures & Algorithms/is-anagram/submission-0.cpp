class Solution {
public:
    bool isAnagram(string s, string t) {
        int count[26]={};
        for(char a:s)
        {
            count[a-'a']++;
        }
        for(char a:t)
        {
            count[a-'a']--;
        }
        for(int n=0;n<26;n++)
        {
            if(count[n]!=0)
            {
                return false;
            }
        }
        return true;
    }
};
