#include <gtest/gtest.h>
#include <vector>
#include <stack>
#include <algorithm>

using std::vector;
vector<int> asteroidCollision(vector<int>& asteroids) {
        std::stack<int> st;
        st.push(asteroids[0]);
        int last;
        int current;
        for(int i = 1; i < asteroids.size(); ++i){
            if(st.empty()){
                st.push(asteroids[i]);
                ++i;
                if(i==asteroids.size()){
                    break;
                }
            }
            last = st.top();
            current = asteroids[i];
            if(current < 0 && last>0){
                while(abs(current) >last && last>0 ){
                    st.pop();
                    if(st.empty()){
                        break;
                    }
                    last = st.top();
                }
                if(abs(current) == last){
                    st.pop();
                } else if(last<0 || st.empty()){
                    st.push(current);
                }
            }   else {
                st.push(current);
            }
        }
        vector<int> anwser;
        while (!st.empty())
        {
            anwser.push_back(st.top());
            st.pop();
        }
         std::reverse(anwser.begin(),anwser.end());
        return anwser;
}

TEST(asteroidCollisionSuite, asteroidCollision) {
    vector<vector<int>> inputs{{5,10,-5},{8,-8},{10,2,-5},{-10,-8,8,12,8},{-10,-8,8,-8},{5,10,-5,-10},{-2,-2,1,-2},{1,-2,-2,-2}};
    vector<vector<int>> corrects{{5,10},{},{10},{-10,-8,8,12,8},{-10,-8},{5},{-2,-2,-2},{-2,-2,-2}};
    for(int i =0;i<inputs.size();++i){
        EXPECT_EQ(asteroidCollision(inputs[i]), corrects[i]);
    }
}