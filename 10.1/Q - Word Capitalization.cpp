/*Q - Word Capitalization
Capitalization is writing a word with its first letter as a capital letter. Your task is to capitalize the given word.
Note, that during capitalization all the letters except the first one remains unchanged.
Input
A single line contains a non-empty word. This word consists of lowercase and uppercase English letters. The length of the word will not exceed 103.
Output
Output the given word after capitalization.
Examples
Input
ApPLe
Output
ApPLe
Input
konjac
Output
Konjac
*/
#include<iostream>
#include<cstring>
using namespace std;
int main()
{
    string a;cin>>a;
    a[0]=a[0]>96?a[0]-32:a[0];
    cout<<a;
    cin.get();
    cin.get();
}