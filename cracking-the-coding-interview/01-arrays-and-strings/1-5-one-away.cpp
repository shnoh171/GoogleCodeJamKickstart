#include <iostream>
#include <string>
using namespace std;

bool IsZeroOrOneWay(string word1, string word2) {
    if (word1.size() > word2.size()) swap(word1, word2);
    if (word1.size() == word2.size()) {
        int count = 0;
        for (int i = 0; i < word1.size(); ++i) {
            if (word1[i] != word2[i]) ++count;
        }
        if (count > 1) return false;
    } else if (word2.size() - word1.size() == 1) {
        int i = 0;
        int j = 0;
        while (i < word1.size() && j < word2.size()) {
            if (word1[i] != word2[j]) {
                ++j;
            }
            if (j > i + 1) return false;
            ++i;
            ++j;
        }
    } else {
        return false;
    }

    return true;
}

int main() {
    cout << IsZeroOrOneWay("pales", "pale") << endl;
    return 0;
}