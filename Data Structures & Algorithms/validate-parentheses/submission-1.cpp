class Solution {
public:
    bool isValid(string s) {
        vector<char> open;
        for(int i=0;i<s.length();i++)
        {
            if(s[i]=='(' || s[i]=='{' || s[i]=='[')
            {
                open.push_back(s[i]);
            }
            else if(s[i]==')')
            {
                if(open.size()-1 != '(')
                {
                    return false;
                }
            }
            else if(s[i]=='}' || s[i]==']')
            {
                if(open.size()-1 != '{')
                {
                    return false;
                }
            }
            else if(s[i]==']')
            {
                if(open.size()-1 != '[')
                {
                    return false;
                }
            }
        }
    return true;
    }
};
