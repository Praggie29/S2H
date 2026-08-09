class Solution {
public:
    int evalRPN(vector<string>& tokens) {
        stack <int> st;
        for ( string &ch : tokens ) {
            if ( ch == "+" ) {
                int first = st.top();
                st.pop();
                int second = st.top();
                st.pop();
                int sum = first + second;
                st.push(sum);
            }
            else if ( ch == "-" ) {
                int first = st.top();
                st.pop();
                int second = st.top();
                st.pop();
                int sum = second - first;
                st.push(sum);
            }
            else if ( ch == "*" ) {
                int first = st.top();
                st.pop();
                int second = st.top();
                st.pop();
                int sum = second * first;
                st.push(sum);
            }
            else if ( ch == "/" ) {
                int first = st.top();
                st.pop();
                int second = st.top();
                st.pop();
                int sum = second / first;
                st.push(sum);
            }
            else {
                int num = stoi(ch);
                st.push(num);
            }
        }
        return st.top();
    }
};