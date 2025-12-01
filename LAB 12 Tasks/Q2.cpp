#include<iostream>
#include<string>
#include<vector>
#define d 256
using namespace std;
vector<int> rabin_karp(string text, string pattern, int q){
    int n = text.length();
    int m = pattern.length();
    vector<int> matches;
    vector<int> collisions;
    if(m==0 || m > n){
        return matches;
    }
    int p = 0;
    int t = 0;
    int h = 1;
    for (int i = 0; i < m-1; i++)
    {
        h = (h*d) % q;
    }
    for (int i = 0; i < m; i++)
    {
        p = (p*d + pattern[i]) % q;
        t = (t*d + text[i]) % q;
    }
    for (int i = 0; i <= n - m; i++)
    {
        if(p==t){
        bool match = true;
        for (int j = 0; j < m; j++)
        {
            if(text[i+j]!=pattern[j]){
                match = false;
                break;
            }
        }
        if(match)
            matches.push_back(i);
        else
            collisions.push_back(i);
    }
        if(i < n - m){
            t = (d * (t - text[i] * h) + text[i + m]) % q;
            if(t < 0) t += q;
        }
    }
    if(!collisions.empty()){
        cout<<"False-positive hash collisions at indices: ";
        for (int c : collisions) cout<< c << " ";
        cout<<endl;
    }
    return matches;
}
int main(){
    string text = "Data structures and algorithms are fun. Algorithms make tasks easier.";
    string pattern = "Algorithms";

    int q = 101; 

    vector<int> result = rabin_karp(text, pattern, q);

    cout << "Pattern found at indices: ";
    for (int pos : result) cout << pos << " ";
    cout << endl;

    return 0;
}