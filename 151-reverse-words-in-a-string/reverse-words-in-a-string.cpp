class Solution {
public:
    string reverseWords(string s) {
        stack<string> stack;
        string word;
        string ans;
        for(int i = 0; i<s.length(); i++){
            if(s[i] == ' '){
                if(!word.empty()){
                    stack.push(word);
                    word = "";
                }
            }else{
                word += s[i];
            }
        }
        if(!word.empty()){
            stack.push(word);
        }
        while(!stack.empty()){
            ans += stack.top();
            stack.pop();
            ans+= " ";
        }
        ans.pop_back();

        return ans;
    }
};