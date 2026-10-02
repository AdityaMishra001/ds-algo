

class AllOne {
public:
    unordered_map<string,int>keyCount;
    unordered_map<int, unordered_set<string>>countKeys;
    set<int>ct;
    AllOne() {
        
    }
    
    void inc(string key) {
        int oldCount= keyCount[key]++;
        if(oldCount>0){
            countKeys[oldCount].erase(key);
            if(countKeys[oldCount].empty()){
                ct.erase(oldCount);
            }
        }
        
        countKeys[oldCount+1].insert(key);
        ct.insert(oldCount+1);
    }
    
    void dec(string key) {
        int oldCount=keyCount[key];
        if(oldCount==0)return;

        countKeys[oldCount].erase(key);
        if(countKeys[oldCount].empty()){
            ct.erase(oldCount);
        }

        if(oldCount==1){
            keyCount.erase(key);
        }else{
            keyCount[key]--;
            countKeys[oldCount-1].insert(key);
            ct.insert(oldCount-1);
        }
    }
    
    string getMaxKey() {
        if(ct.empty())return "";
        int targetCount= *ct.rbegin();
        if(countKeys[targetCount].size()==0)return "";
        return *countKeys[targetCount].begin();
    }
    
    string getMinKey() {
        if(ct.empty())return "";
        int targetCount= *ct.begin();
        if(countKeys[targetCount].size()==0)return "";
        return *countKeys[targetCount].begin();
    }
};

/**
 * Your AllOne object will be instantiated and called as such:
 * AllOne* obj = new AllOne();
 * obj->inc(key);
 * obj->dec(key);
 * string param_3 = obj->getMaxKey();
 * string param_4 = obj->getMinKey();
 */