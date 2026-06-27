class Solution {
public:
    int calculate(string s) {
        stack<int> st;
        long long result = 0;
        long long number = 0;
        int sign = 1;

        for (int i = 0; i < s.size(); i++) {
            if (isdigit(s[i])) {
                number = number * 10 + (s[i] - '0');
            }
            else if (s[i] == '+') {
                result += number * sign;
                number = 0;
                sign = 1;
            }
            else if (s[i] == '-') {
                result += number * sign;
                number = 0;
                sign = -1;
            }
            else if (s[i] == '(') {
                st.push(result);
                st.push(sign);

                result = 0;
                sign = 1;
                number = 0;
            }
            else if (s[i] == ')') {
                result += number * sign;
                number = 0;

                int oldSign = st.top();
                st.pop();

                int oldResult = st.top();
                st.pop();

                result = oldResult + oldSign * result;
            }
        }

        result += number * sign;
        return result;
    }
};