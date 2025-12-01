#include <iostream>
#include <vector>
#include <string>
using namespace std;

vector<int> buildLPS(string pattern) {
    int m = pattern.length();
    vector<int> lps(m, 0);

    int len = 0;  
    int i = 1;

    while (i < m) {
        if (pattern[i] == pattern[len]) {
            len++;
            lps[i] = len;
            i++;
        }
        else {
            if (len != 0) {
                len = lps[len - 1];
            }
            else {
                lps[i] = 0;
                i++;
            }
        }
    }
    return lps;
}

vector<int> KMP(string text, string pattern) {
    int n = text.length();
    int m = pattern.length();
    vector<int> positions;

    if (m == 0 || m > n) return positions;

    vector<int> lps = buildLPS(pattern);

    cout << "LPS Array: ";
    for (int x : lps) cout << x << " ";
    cout << endl;

    int i = 0, j = 0;

    while (i < n) {
        if (text[i] == pattern[j]) {
            i++; j++;
        }

        if (j == m) {
            positions.push_back(i - j);
            j = lps[j - 1];   
        }
        else if (i < n && text[i] != pattern[j]) {
            if (j != 0)
                j = lps[j - 1];
            else
                i++;
        }
    }
    return positions;
}
int main() {
    string text = "ababababc";
    string pattern = "abab";

    vector<int> result = KMP(text, pattern);

    cout << "Pattern found at indices: ";
    for (int pos : result) cout << pos << " ";
    cout << endl;

    return 0;
}
