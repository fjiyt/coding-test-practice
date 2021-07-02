#include <iostream>
#include <string>
using namespace std;
 
int main() {
    string word;
    cin>>word;
    int listOfWord[26]={0,};
    int maxIdx=0, max;
 
    for(int i=0; i<word.size(); i++) {
        max=listOfWord[maxIdx];
        if(word[i]>90) {//아스키코드에서 대문자가 아니면
            word[i]=toupper(word[i]);
        }
 
        int NumberOfWord=word[i]-65; //아스키코드 사용
        listOfWord[NumberOfWord]+=1;
 
        if(listOfWord[NumberOfWord]>max) {
            maxIdx=NumberOfWord;
        }
    }
 
    for(int i=0; i<26; i++) {
        if(maxIdx!=i&&listOfWord[maxIdx]==listOfWord[i]) {
            cout<<"?"<<"\n";
            return 0;
        }
    }
 
    cout<<(char)(maxIdx+65)<<"\n";
 
    return 0;
}
