class Solution {
public:
    vector<int> nextGreaterElements(vector<int>& nums) {
        stack<int> x;
        int n = nums.size();
        vector<int> sol(n,-1);
        for (int i = 2 * n - 1; i >= 0; i--) {
            if (x.empty()) {
                x.push(nums[i % n]);
                continue;
            }
            while (x.top() <= nums[i % n]) {
                x.pop();
                if (x.empty()) {
                    x.push(nums[i % n]);
                    break;
                }
            }
            if(x.top() > nums[i%n]){
                sol[i % n] = x.top();
                x.push(nums[i % n]);
            }
        }
        return sol;
    }
};