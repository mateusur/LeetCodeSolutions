#include <string>
#include <set>
#include <unordered_map>
#include <algorithm>

using std::string;
using std::set;
using std::multiset;
// This solution is not the fastes but it was in hash map and set 
// category, that's why I solved it this way.
bool closeStrings(string word1, string word2) {
    if(word1.size() != word2.size()){
        return false;
    }
    set<char> c_word1;
    set<char> c_word2;
    
    multiset<char> occ_word1;
    multiset<char> occ_word2;
    sort(word1.begin(),word1.end());
    sort(word2.begin(),word2.end());

    auto count = [](const std::string& word,set<char>& c_word,multiset<char>& occ_word){
        char current = word[0];
        int occ = 1;
        c_word.insert(current);
        for(int i = 1 ; i<word.size(); ++i){
        if(word[i] == current){
            occ++;
        }else {
            occ_word.insert(occ);
            current = word[i];
            occ = 1;
            c_word.insert(current);
        }
    }
    occ_word.insert(occ);
    };

    count(word1,c_word1,occ_word1);
    count(word2,c_word2,occ_word2);
    return c_word1==c_word2 && occ_word1==occ_word2;
}
int main(){
    closeStrings("caaqqqqqbbba","qabqqbbcqqcc");

    return 0 ;
}