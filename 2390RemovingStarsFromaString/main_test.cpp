#include <gtest/gtest.h>
#include <string>
#include <stack>
#include <algorithm>

using std::string;
string removeStars(string s) {
    std::stack<char> st;

    for(const char& c : s){
        if(c=='*'){
            st.pop();
        }else{
            st.push(c);
        }
    }
    string rev;
    while(!st.empty()){
        rev.push_back(st.top());
        st.pop();
    }
    std::reverse(rev.begin(), rev.end());
    return rev;
}

TEST(RemoveStarsSuite, RemoveStars) {
  EXPECT_EQ(removeStars("leet**cod*e"), "lecoe");
}
TEST(RemoveStarsSuite, RemoveStars2) {
  EXPECT_EQ(removeStars("erase*****"), "");
}