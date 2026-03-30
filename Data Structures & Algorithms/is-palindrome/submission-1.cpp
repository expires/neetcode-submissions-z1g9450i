class Solution {
public:
    bool isPalindrome(string s) {
        string lower_str = "";
        for(char c: s){
            lower_str += tolower(c);
        }

        int left = 0;
        int right = s.length() - 1;
        while(left < right){
            if(!isalnum(lower_str[left])){
                left++;
                continue;
            }

            if(!isalnum(lower_str[right])){
                right--;
                continue;
            }

            if(lower_str[left] != lower_str[right]){
                return false;
            }

            left++;
            right--;
        }

        return true;
    }
};
