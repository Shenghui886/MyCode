// P1928 外星密码
// Use stack DAT

#include <iostream>
using namespace std;

string decode(const string &s, int &n) {
    string result;
    int repeat = 0;
    for(; n < s.size(); n++) {
        if(isalpha(s[n]))
            result.push_back(s[n]);
        else if(s[n] == '[') {
            ++n;
            result += decode(s, n);
        }
        else if(s[n] == ']') {
            string temp = result;
            for(int j = 1; j < repeat; j++) {
                result += temp;
            }
            return result;
        } else if(isdigit(s[n])) {
            while(isdigit(s[n])) {
                repeat = repeat * 10 + (s[n] - '0');
                n++;
            }
            n--; // Adjust for the increment in the loop
        }
    }
    return result;
}

int main(int argc, char** argv) {

    string s;
    cin >> s;
    int n = 0;
    string result = decode(s, n);
    cout << result << endl;

    return 0;
}

