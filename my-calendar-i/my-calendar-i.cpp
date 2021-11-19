class MyCalendar {
public:
    map<int,int> events;
    MyCalendar() {
       
    }
    
    bool book(int start, int end) {
        if(events.empty()){
            events[start]=end;
            return true;
        }
        
        auto st=events.upper_bound(start);
        if (st != events.end() && end > st->first)
        return false;
    if (st != events.begin() && start < prev(st)->second)
        return false;
    events[start] = end;
        return true;
    }
};

/**
 * Your MyCalendar object will be instantiated and called as such:
 * MyCalendar* obj = new MyCalendar();
 * bool param_1 = obj->book(start,end);
 */