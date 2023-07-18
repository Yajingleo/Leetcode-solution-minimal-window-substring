class Solution {
public:
    string nextClosestTime(string time) {
        set<char> letters;
        for (char c: time) {
            if (c != ':') letters.insert(c);
        }
        set<string> Times;
        for (char c1: letters) {
            for (char c2: letters) {
                for (char c3: letters) {
                    for (char c4: letters) {
                        if (c1 <= '2' && (c2 <= '4' || c1 <= '1') && c3 <= '5') {
                            char s[] = {c1, c2, ':', c3, c4};
                            Times.insert(string(s, 5)); 
                        }
                    }
                }
            }
        }
        
        set<string>::iterator it = times.find(time);
        ++it;
        
        return (it == times.end()) ? *times.begin() : *it;
    }
};
