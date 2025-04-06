// https://leetcode.com/contest/weekly-contest-444/problems/implement-router/
// Implement Router


class Packet {
public:
    int source;
    int destination;
    int timestamp;
};

class Router {
    int limit;
    queue<Packet> q;
    set<string> st;
    map<int, deque<int>> mpp;

    string helper(int s, int d, int t) {
        return to_string(s) + "-" +  to_string(d) + "-" + to_string(t);
    }

public:
    Router(int memoryLimit) {
        limit = memoryLimit;
    }
    
    bool addPacket(int source, int destination, int timestamp) {
        string str = helper(source, destination, timestamp);
        if (st.find(str) != st.end()) return false;

        if (q.size() == limit) {
            Packet first = q.front();
            q.pop();
            string s = helper(first.source, first.destination, first.timestamp);
            st.erase(s);
            mpp[first.destination].pop_front();
        }

        st.insert(str);
        q.push({source, destination, timestamp});
        mpp[destination].push_back(timestamp);
        return true;
    }
    
    vector<int> forwardPacket() {
        if (q.empty()) return {};
        
        Packet first = q.front();
        q.pop();
        string s = helper(first.source, first.destination, first.timestamp);
        st.erase(s);
        mpp[first.destination].pop_front();
        
        return {first.source, first.destination, first.timestamp};
    }
    
    int getCount(int destination, int startTime, int endTime) {
        auto& ts = mpp[destination];
        auto start = lower_bound(ts.begin(), ts.end(), startTime);
        auto end = upper_bound(ts.begin(), ts.end(), endTime);
        int result = end - start;
        return result;
    }
};

/**
 * Your Router object will be instantiated and called as such:
 * Router* obj = new Router(memoryLimit);
 * bool param_1 = obj->addPacket(source,destination,timestamp);
 * vector<int> param_2 = obj->forwardPacket();
 * int param_3 = obj->getCount(destination,startTime,endTime);
 */