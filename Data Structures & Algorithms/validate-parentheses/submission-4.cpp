class Solution {
public:
    bool isValid(string s) {
        vector<char> open;

        for(int i = 0; i < s.length(); i++) {

            if(s[i] == '(' || s[i] == '{' || s[i] == '[') {
                open.push_back(s[i]);
            }
            else {
                if(open.empty()) return false;

                if(s[i] == ')' && open.back() != '(') return false;
                if(s[i] == '}' && open.back() != '{') return false;
                if(s[i] == ']' && open.back() != '[') return false;

                open.pop_back(); // remove matched opening
            }
        }

        return open.empty(); // all should be matched
    }
};