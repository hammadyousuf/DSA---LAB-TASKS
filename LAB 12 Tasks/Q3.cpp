#include <iostream>
#include <vector>
#include <string>
using namespace std;

void buildBadCharTable(string pattern, vector<int> &badCharTable) {
    int m = pattern.length();
    const int CHAR_SIZE = 256;

    badCharTable.assign(CHAR_SIZE, -1);

    for (int i = 0; i < m; i++) {
        badCharTable[(unsigned char)pattern[i]] = i;
    }
}

void buildGoodSuffixTable(string pattern, vector<int> &goodSuffix) {
    int m = pattern.length();
    goodSuffix.assign(m + 1, 0);

    vector<int> border(m + 1, 0);

    int i = m, j = m + 1;
    border[i] = j;

    while (i > 0) {
        while (j <= m && pattern[i - 1] != pattern[j - 1]) {
            if (goodSuffix[j] == 0)
                goodSuffix[j] = j - i;
            j = border[j];
        }
        i--;
        j--;
        border[i] = j;
    }

    j = border[0];
    for (i = 0; i <= m; i++) {
        if (goodSuffix[i] == 0)
            goodSuffix[i] = j;
        if (i == j)
            j = border[j];
    }
}

vector<int> boyerMoore(string text, string pattern) {
    int n = text.length();
    int m = pattern.length();
    vector<int> result;

    if (m == 0 || m > n) return result;

    vector<int> badCharTable;
    vector<int> goodSuffix;

    buildBadCharTable(pattern, badCharTable);
    buildGoodSuffixTable(pattern, goodSuffix);

    int s = 0;
    while (s <= n - m) {
        int j = m - 1;

        while (j >= 0 && pattern[j] == text[s + j]) {
            j--;
        }

        if (j < 0) {
            
            result.push_back(s);
            s += goodSuffix[0];  
        }
        else {
            int badCharShift = j - badCharTable[(unsigned char)text[s + j]];
            int goodSuffixShift = goodSuffix[j + 1];
            s += max(1, max(badCharShift, goodSuffixShift));
        }
    }

    return result;
}

int main() {
    string DNA = "ACGTACGTGACG";
    string pattern = "ACG";

    vector<int> positions = boyerMoore(DNA, pattern);

    cout << "Pattern found at indices: [ ";
    for (int idx : positions) cout << idx << " ";
    cout << "]\n";

    return 0;
}
