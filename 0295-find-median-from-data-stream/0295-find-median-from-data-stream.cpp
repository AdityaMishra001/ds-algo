class MedianFinder {
public:
    priority_queue<int>left;
    priority_queue<int, vector<int>,greater<int>>right;
    MedianFinder() {
      //  left.clear(),right.clear();
    }
    
    void addNum(int num) {
        if(left.empty() || left.top()>=num){
            left.push(num);
        }else
        right.push(num);

        if(left.size()-1>right.size()){
            int temp=left.top();
            left.pop(),right.push(temp);
        }else if(right.size()>left.size()){           int temp=right.top();
            right.pop(),left.push(temp);
        }
    }
    
    double findMedian() {
        if(left.size()==right.size())
        return (left.top()+right.top())/2.0;
            return left.top();
    }
};

/**
 * Your MedianFinder object will be instantiated and called as such:
 * MedianFinder* obj = new MedianFinder();
 * obj->addNum(num);
 * double param_2 = obj->findMedian();
 */