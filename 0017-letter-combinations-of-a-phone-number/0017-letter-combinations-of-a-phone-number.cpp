class Solution {
public:
    void X(int i, string digits,map<char,string>mpp, string& ds, vector<string>& ans) {
        if(i==digits.size()) {ans.push_back(ds);
        return;}
        for(auto c :mpp[digits[i]]){
            ds.push_back(c);
            X(i+1,digits,mpp,ds,ans);
            ds.pop_back();
        }
    }
    vector<string> letterCombinations(string digits) {
        map<char,string>mpp = {{'2',"abc"},{'3',"def"},{'4',"ghi"},{'5',"jkl"},{'6',"mno"},{'7',"pqrs"},{'8',"tuv"},{'9',"wxyz"}};
        string ds;
        vector<string>ans;
        X(0,digits,mpp,ds,ans);
        return ans;
    }
};