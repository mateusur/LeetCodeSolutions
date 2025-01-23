#include <string>
using namespace std;

bool vowel(const char& c){
    return c=='a' || c=='e' ||c=='i' ||c=='o' ||c=='u';
}
int maxVowels(string s, int k) {
    int l=0, r=0;
    
    int vowels = 0;
    for(; r<k;++r){
        if(vowel(s[r])){
            vowels++;
        }
         
    }
    if(vowels==k){
            return k;
    }
    int max_vowels =vowels;
    while (r<s.size())
    {
        if(vowel(s[r])){
            vowels++;
        } 

        if(vowel(s[l])){
            vowels--;
        }
        r++;
        l++;
        if(vowels==k){
            return k;
        }
        max_vowels = max(max_vowels,vowels);
    }
    
    return max_vowels;
}
int main(){
    maxVowels("abciiidef",3);
    maxVowels("aeiou",2);
    maxVowels("leetcode",3);


    return 0 ;
}