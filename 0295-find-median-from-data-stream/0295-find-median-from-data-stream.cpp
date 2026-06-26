class MedianFinder {
public:
    priority_queue <int,vector<int>,greater<int>> minrightstore;
    priority_queue <int> maxleftstore;
    MedianFinder(){}
    void addNum(int num) {
        maxleftstore.push(num);
        minrightstore.push(maxleftstore.top());
        maxleftstore.pop();
        if(maxleftstore.size()<minrightstore.size()){
            maxleftstore.push(minrightstore.top());
            minrightstore.pop() ;
        }
    }

    double findMedian() {
        if(maxleftstore.size()>minrightstore.size()) return maxleftstore.top();
        else return (maxleftstore.top()+minrightstore.top())/2.0;
    }
};

/**
 * Your MedianFinder object will be instantiated and called as such:
 * MedianFinder* obj = new MedianFinder();
 * obj->addNum(num);
 * double param_2 = obj->findMedian();
 */