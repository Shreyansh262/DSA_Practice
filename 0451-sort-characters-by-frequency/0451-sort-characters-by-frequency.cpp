class Solution {
public:
    string frequencySort(string s) {
        unordered_map<char, int> ss;
        for (int i = 0; i < s.size(); i++) {
            ss[s[i]]++;
        }
        vector<pair<int,char>> sortedss;
        for(auto &it : ss){
            sortedss.push_back({it.second,it.first});
        }
        sort(sortedss.begin(),sortedss.end(),[](const pair<int,char>& a, const pair<int,char>& b) {
                 return a.first > b.first;
             });
        string j;
        for(auto &x : sortedss){
            j.append(x.first,x.second);
        }
        return j;
    }
};