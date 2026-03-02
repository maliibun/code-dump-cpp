#include <bits/stdc++.h>

using namespace std;

class Solution {
public:
    bool isAnagramAl(string s, string t) {
        //fast solution only a-z
        vector<int> freq(32);

        int sl = s.length();
        int tl = t.length();
        if(sl != tl)
            return false;

        for(int i = 0; i < sl; i++){
            freq[s[i] - 'a']++;
            freq[t[i] - 'a']--;
        }

        for(int i = 0; i < 32; i++)
            if(freq[i] != 0)
                return false;
        
        return true;
    }

    bool isAnagramUnicode(string s, string t) {
        //mapping unicode characters
        if(s.size() != t.size())
            return false;

        unordered_map<char,int> smap;
        unordered_map<char,int> tmap;

        for(int i = 0; i < s.size(); i++){
            smap[s[i]]++;
            tmap[t[i]]++;
        }

        for(int i = 0; i < smap.size(); i++)
            if(smap[i] != tmap[i])
                return false;
        
        return true;
    }
};