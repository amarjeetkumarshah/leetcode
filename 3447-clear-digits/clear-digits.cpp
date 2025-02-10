class Solution {
public:
    string clearDigits(string s) {
        string res = ""; // Acts like a stack
        for (char c : s) {
            if (isdigit(c)) {
                if (!res.empty()) {
                    res.pop_back(); // Remove the last character
                }
            } else {
                res.push_back(c); // Add character to stack
            }
        }
        return res;
    }
};