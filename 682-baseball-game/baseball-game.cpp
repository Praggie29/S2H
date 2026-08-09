class Solution {
public:
    int calPoints(vector<string>& operations) {
        stack<int> st;
        for (int i = 0; i < operations.size(); i++) {
            if (operations[i] == "+") {
                int first = st.top();
                st.pop();
                int second = st.top();
                st.pop();
                int sum = first + second;
                st.push(second);
                st.push(first);
                st.push(sum);
            } else if (operations[i] == "D") {
                int first = st.top();
                int doubleValue = 2 * first;
                st.push(doubleValue);
            } else if (operations[i] == "C") {
                st.pop();
            } else {
                int num = stoi(operations[i]);
                st.push(num);
            }
        }

        int sumOfAllPointsInTheStack = 0;
        while (!st.empty()) {
            int topVal = st.top();
            sumOfAllPointsInTheStack += topVal;
            st.pop();
        }

        return sumOfAllPointsInTheStack;
    }
};