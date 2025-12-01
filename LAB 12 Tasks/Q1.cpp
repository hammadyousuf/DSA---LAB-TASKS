#include<iostream>
#include<string>
using namespace std;
int bruteforce(string text , string pattern){
    int k = 0;
    int n = text.length();
    int m = pattern.length();
    for (int i = 0; i <= n-m; i++)
    {
        int j = 0;
        while (j<m && text[i+j] == pattern[j])
        {
            k++;
            j++;
        }
        if(j==m){
            cout<<"The pattern '"<<pattern<<"' is found at index "<<i<<endl;
        }
    }
    return k;
}
int main(){
    string text;
    cout<<"Enter the text: ";
    getline(cin,text);
    string pattern;
    cout<<"Enter the pattern to find from text: ";
    getline(cin,pattern);
   int k = bruteforce(text,pattern);
    cout<<"The number of comparisons made is "<<k<<endl;
}