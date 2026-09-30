class Solution {
public:

    string encode(vector<string>& strs)
    {
        //Is it empty?
        if (strs.empty())
            return "";
        
        
        string enc;

        //4#This3#has4#some5#words2#in2#it
        for (const string& s : strs)
        {
            enc.append(to_string(s.size()));
            enc.push_back('#');
            enc.append(s);
        }

        return enc;


    }

    vector<string> decode(string s)
    {
        vector<string> dec;

        if (s.empty())
            return dec;

        int i = 0;
        while(i < s.size())
        {
            int j = i;
            while (s[j] != '#')
                j++;
            
            int length = stoi(s.substr(i, j-i));
            i = j + 1;
            j = i + length;
            dec.push_back(s.substr(i, length));
            i = j;
        }

        return dec;
    }
};
