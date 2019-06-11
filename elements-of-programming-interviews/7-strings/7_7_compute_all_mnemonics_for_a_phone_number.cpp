#include <string>
#include <vector>
using std::string;
using std::vector;

const string keypad[10] = { "0", "1", "ABC", "DEF", "GHI", "JKL", "MNO", "PQRS", "TUV", "WXYZ" };

void _PhoneMnemonic(vector<string>& sequences, const string& sequence, const string& phone_number, int index) {
    if (index == phone_number.size()) {
        sequences.push_back(sequence);
        return;
    }   
        
    int digit = phone_number[index] - '0';
    for (auto c : keypad[digit]) {
        _PhoneMnemonic(sequences, sequence + c, phone_number, index + 1); 
    }   
}

vector<string> PhoneMnemonic(const string& phone_number) {
    vector<string> ret;
    ret.reserve(phone_number.size());
    _PhoneMnemonic(ret, "", phone_number, 0); 
    return ret;
}

/* Solution */
void PhoneMnemonicHelper(const string &, int, string *, vector<string> *);

vector<string> PhoneMnemonic(const string &phone_number) {
    vector<string> mnemonics;
    PhoneMnemonicHelper(phone_number, 0,
                        make_unique<string>(size(phone_number), 0).get(),
                        &mnemonics);
    return mnemonics;
}

const int kNumTelDigits = 10;

// The mapping from digit to corresponding characters.
const array<string, kNumTelDigits> kMapping = {
    {"0", "1", "ABC", "DEF", "GHI", "JKL", "MNO", "PQRS", "TUV", "WXYZ"}};

void PhoneMnemonicHelper(const string &phone_number, int digit,
                         string *partial_mnemonic, vector<string> *mnemonics) {
    if (digit == size(phone_number)) {
        // All digits are processed, so add partial_mnemonic to mnemonics.
        // (We add a copy since subsequent calls modify partial_mnemonic.)
        mnemonics->emplace_back(*partial_mnemonic);
    } else {
        // Try all possible characters for this digit.
        for (char c : kMapping[phone_number[digit] - '0']) {
            (*partial_mnemonic)[digit] = c;
            PhoneMnemonicHelper(phone_number, digit + 1, partial_mnemonic, mnemonics);
        }
    }
}
