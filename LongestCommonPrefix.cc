class LongestCommonPrefix {
public:
    string longestCommonPrefix(vector<string>& strs) {
        if (strs.size() == 0)
            return "";
        for (int i = 0; i < strs[0].length(); ++i) {
           char c = strs[0].at(i); // Iterate through each character in first string
           for (int j = 1; j < strs.size(); ++j) {
               /* If the last index of the first string is reached or 
                * the character at common index is not identical, return
                * the substring from 0 to the current index
                */
               if (i == strs[j].length() || strs[j].at(i) != c) 
                   return strs[0].substr(0, i);
           }
        }
        return strs[0];
    }
};
