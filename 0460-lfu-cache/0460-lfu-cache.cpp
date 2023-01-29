class LFUCache {
    int capacity;
    int minFreq;
    unordered_map<int,pair<int,int>> keyVal;
    unordered_map<int,list<int>> freqList;
    unordered_map<int,list<int>::iterator> pos;
    
public:
    
    LFUCache(int capacity) {
        this->capacity = capacity;
        minFreq = 0;
    }
    
    int get(int key) {
        if(keyVal.find(key) == keyVal.end())
            return -1;
        
        // update the call count of that key
        
        // erase entry of key in old call count list
        freqList[keyVal[key].second].erase(pos[key]);

        // increase call count by 1
        keyVal[key].second++;

        // push entry of key in new call count list
        freqList[keyVal[key].second].push_back(key);

        // get the iterator of key in new call count list
        pos[key] = --freqList[keyVal[key].second].end();

        // updating the minimum frequency accordingly
        if(freqList[minFreq].empty())
            minFreq++;

        return keyVal[key].first;
    }
    
    void put(int key, int value) 
    {
        if(!capacity)
            return;
        
        if(keyVal.find(key) != keyVal.end()) 
        {
            // update the value for its key
            keyVal[key].first = value;
            
            // erase entry of key in old call count list
            freqList[keyVal[key].second].erase(pos[key]);
            
            // increase call count by 1
            keyVal[key].second++;
            
             // push entry of key in new call count list
            freqList[keyVal[key].second].push_back(key);
            
            // get the iterator of key in new call count list
            pos[key] = --freqList[keyVal[key].second].end();
            
            // updating the minimum frequency accordingly
            if(freqList[minFreq].empty())
                minFreq++;
            
            return;
        }
        
        if(keyVal.size() == capacity) 
        {
            // get the min freq key
            int delKey = freqList[minFreq].front();
            
            // delete the min frequency key from all three maps
            keyVal.erase(delKey);
            pos.erase(delKey);
            freqList[minFreq].pop_front();
        }
        
        keyVal[key] = {value,1};
        freqList[1].push_back(key);
        pos[key] = --freqList[1].end();
        minFreq = 1;
    }
};

/**
 * Your LFUCache object will be instantiated and called as such:
 * LFUCache* obj = new LFUCache(capacity);
 * int param_1 = obj->get(key);
 * obj->put(key,value);
 */