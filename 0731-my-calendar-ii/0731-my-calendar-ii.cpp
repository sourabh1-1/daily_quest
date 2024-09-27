class MyCalendarTwo {
public:
    map<int, int> Count;
    MyCalendarTwo() {
        
    }
    
    bool book(int start, int end) {
        Count[start]++;
        Count[end]--;
        int ongoingEvents=0;
        for(auto &[time, change]: Count){
            ongoingEvents+=change;
            if(ongoingEvents>=3){
                Count[start]--;
                Count[end]++;
                return false;
            }
        }
        return true;
    }
};

/**
 * Your MyCalendarTwo object will be instantiated and called as such:
 * MyCalendarTwo* obj = new MyCalendarTwo();
 * bool param_1 = obj->book(start,end);
 */