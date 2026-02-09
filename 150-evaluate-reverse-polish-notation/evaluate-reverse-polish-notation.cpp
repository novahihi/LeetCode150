class Solution {
public:
    int evalRPN(vector<string>& tokens) {
    // check until meet a symbol, make a calculation of the last 2 tokens in the top and push the result in the stack
    stack <int> st;
    for (auto e: tokens) {
        if (e=="+") {
            int a = st.top();
            st.pop();
            int b = st.top();
            st.pop();
            st.push(a+b);
        }
        else if (e=="-") {
            int a = st.top();
            st.pop();
            int b = st.top();
            st.pop();
            st.push(b-a);
        }
        else if (e=="*") {
            int a = st.top();
            st.pop();
            int b = st.top();
            st.pop();
            st.push(a*b);
        }
        else if (e=="/") {
            int a = st.top();
            st.pop();
            int b = st.top();
            st.pop();
            st.push(b/a);
        }
        else st.push(stoi(e));
    }
    return st.top();
    }
};