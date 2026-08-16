class Solution {
public:
    string largestOddNumber(string num) {
        int len = num.length()-1;
        while(len>=0){
            int d = num[len] - '0';
            if(d%2 != 0){
                return num.substr(0,len+1);
                
            }
            len--;
        }
        return "";
    }
};