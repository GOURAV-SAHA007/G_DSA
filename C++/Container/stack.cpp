#include<bits/stdc++.h>
using namespace std;

int main(){
    stack<int>st;
    st.push(8);
    st.push(9);
    st.push(4);
    st.emplace(2);

    cout << st.top() << endl;
    st.pop();
    cout << st.top() << endl;
    cout << st.size() << endl;
    cout << st.empty();
    

}