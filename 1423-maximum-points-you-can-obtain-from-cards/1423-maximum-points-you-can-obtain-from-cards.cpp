class Solution {
public:
    int maxScore(vector<int>& cardPoints, int k) {
        if(cardPoints.size()==1) return cardPoints[0];
        if(cardPoints.size()<=k) return arrsum(cardPoints);
        stack<int>card;
        int msum = 0,sum = 0;
        for(int i = 0;i<k;i++){
            card.push(cardPoints[i]);
            sum += cardPoints[i];
        }
        msum = sum;
        for(int i = 0;i<k;i++){
            int x = card.top();
            sum = sum - x + cardPoints[cardPoints.size()-i-1];
            card.pop();
            msum = max(sum,msum);
        }
        return msum;
    }
    int arrsum(vector<int>& cardPoints){
        int sum = 0;
        for(int i: cardPoints){
            sum += i;
        }
        return sum;
    }
};