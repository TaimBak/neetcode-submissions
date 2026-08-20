class Solution {
public:
    bool isPalindrome(string s) {
        
        std::string str = "";

        for (char c : s)
            if (std::isalnum(c))
                str += tolower(c);

        std::string rev = "";
        int length = str.length() - 1;
        
        for (int i = length; i >= 0; i--)
            rev.push_back(str[i]);

        if (str == rev)
            return true;
        else return false;
    }
};
