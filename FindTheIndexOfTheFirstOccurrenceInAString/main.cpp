#include <iostream>
#include <string>

using namespace std;

int strStr(string haystack, string needle){
  string::iterator it_needle = needle.begin();
  string::iterator it_haystack = haystack.begin();
  string::iterator it_temp;
  int offset = 0;
  while (it_haystack!=haystack.end())
  {
    it_temp = it_haystack;
    while (*it_temp == *it_needle)
    {
      it_temp++;
      it_needle++;
      if(it_needle==needle.end()){
        return offset;
      }
    }
    it_needle = needle.begin();
    it_haystack++;
    offset++;
  }
  return -1;
  
}
int main() {
  cout << strStr("sadbutsad","sad") << endl;
  cout << strStr("leetcode","leeto") << endl;
}