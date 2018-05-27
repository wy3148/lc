

//
//https://leetcode.com/problems/longest-word-in-dictionary-through-deleting/description/
//

class Solution {
public:
    
    bool formed(string s, string cur){
        
        //abpcplea
        //apple
        
        if (s.length() < cur.length()) return false;
        int pos = 0;
        for(int i = 0; i < cur.length();i++){
            bool found = false;
            for (int j = pos; j < s.length(); j++){
                if (cur[i] == s[j]){
                    pos = j + 1;
                    found = true;
                    break;
                }
            }
            if (!found) return false;
        }
        return true;
    }
    
    string small(string s1, string s2){
        for (int i = 0; i < s1.length(); i++){
            if (s1[i] < s2[i]){
                return s1;
            }else if (s1[i] == s2[i]){
                continue;
            }else{
                return s2;
            }
        }
        return s1;
    }
    
    string findLongestWord(string s, vector<string>& d) {
        string result;        
        for (auto cur : d){
            if (formed(s,cur)){
                if (cur.length() > result.length()){
                    result = cur;
                }else if (cur.length() == result.length()){
                    result = small(cur,result);    
                }
            }
        }
        return result;
    }
};
