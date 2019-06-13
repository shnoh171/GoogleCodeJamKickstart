#include <string>
using std::string;

string LookAndSay(int n) {
    string ret = "1";
    for (int i = 1; i < n; ++i) {
        string tmp;
        char prev = ret[0];
        int count = 1;
        for (int i = 1; i < ret.size(); ++i) {
            if (ret[i] == prev) {
                ++count;
            } else {
                tmp += std::to_string(count);
                tmp += prev;
                prev = ret[i];
                count = 1;
            }   
        }   
        tmp += std::to_string(count);
        tmp += prev;
        ret = tmp;
    }   
    return ret;
}
