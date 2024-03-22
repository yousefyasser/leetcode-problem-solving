class SmallestInfiniteSet {
public:
    int min;
    priority_queue<int, vector<int>, greater<int>> pq;
    map<int, int> freq;
    
    SmallestInfiniteSet() {
        min = 1;
    }
    
    int popSmallest() {
        if(pq.empty()) return min++;
        
        int val = pq.top();
        pq.pop();
        freq[val]--;
        
        return val;
    }
    
    void addBack(int num) {
        if(num < min && !freq[num]){
            pq.push(num);
            freq[num]++;
        }
    }
};

/**
 * Your SmallestInfiniteSet object will be instantiated and called as such:
 * SmallestInfiniteSet* obj = new SmallestInfiniteSet();
 * int param_1 = obj->popSmallest();
 * obj->addBack(num);
 */