#include <iostream>
#include <string>
#include <vector>
#include <algorithm>

using namespace std;
string longestCommonPrefix(vector<string>& strs){
  string anwser;
  sort(strs.begin(),strs.end());
  for(int i=0; i<strs.at(0).size();++i){
    char c = strs.at(0).at(i);
    for(auto s = strs.begin();s !=strs.end();++s){
      if((*s).at(i)!=c){
        return anwser;
      }
    }
    anwser+=c;
  }
  return anwser;
}
int main() {
  vector<string> s1 = {"flower","flow","flight"};
  vector<string> s2 = {"dog","racecar","car"};

  cout << longestCommonPrefix(s1) << endl;
  cout << longestCommonPrefix(s2) << endl;
}