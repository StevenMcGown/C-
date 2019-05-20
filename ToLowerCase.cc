class LowerCase {
public:
    string toLowerCase(string str) {
    for (int i = 0; i < str.length(); ++i) { // for each character in str to character array
        if (str[i]>=65 && str[i]<=90) { // dec of ASCII characters
          str[i] = char(int(str[i])+32); // 32 offset is lowercase 
        }
      }      
    return str;
    }
};
