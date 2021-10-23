Question:-

Given a string s containing just the characters '(', ')', '{', '}', '[' and ']', determine if the input string is valid.

An input string is valid if:

Open brackets must be closed by the same type of brackets.
Open brackets must be closed in the correct order.
 

Example 1:

Input: s = "()"
Output: true
Example 2:

Input: s = "()[]{}"
Output: true
Example 3:

Input: s = "(]"
Output: false
Example 4:

Input: s = "([)]"
Output: false
Example 5:

Input: s = "{[]}"
Output: true
 

Constraints:

1 <= s.length <= 104
s consists of parentheses only '()[]{}'.
  
  
  
  
  
  Code:-
    
 class Solution {
public:
    bool isValid(string s) {
        stack<char> st;

        for(int i=0;i<s.size();i++){
            if(s[i]=='(' ||  s[i]=='{' || s[i]=='['){         // if character at i'th index is an opening bracket, push it in stack st.
                st.push(s[i]);
            }
            else if(!st.empty()){
                char a=st.top();
                st.pop();
                if(s[i]==')' && a=='('){}                   // check if correct corresponding parentheses are present.
                else if(s[i]=='}' && a=='{'){}            
                else if(s[i]==']' && a=='['){}
                else return false;
            }
            else
                return false;
        }
        if(!st.empty()){
            return false;        // after the loop ends, if the stack is not empty, that means parentheses are not valid.
        }
        return true;
    }
};   
