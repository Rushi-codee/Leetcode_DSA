class Solution {
public:
    string reverseWords(string s) {
        int n = s.length();
        string ans = "";
        int i = n-1;

        while(i>=0){
             // Step 1: Skip trailing and intermediate spaces
            while(i>=0 && s[i] == ' '){
                i--;
            }
            // if we reach beginiing of the word stop 
            if(i<0){
                break;
            }

            //find the start of the current word 
            int j = i;
            while(j >=0 && s[j] != ' '){
                j--;
            }

            // add a space before the next word (if ans is not empty)
            if(!ans.empty()){
                ans+= " ";
            }

            // store the word 
            ans += s.substr(j+1,i-j);

            // move pointer for next word 

            i = j;

        }

        return ans;
    
    }
};