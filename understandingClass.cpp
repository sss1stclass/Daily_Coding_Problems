#include<bits/stdc++.h>
using namespace std;
class callName {
public:
    string Name;
    int age;
    string subject;
    int number;

    callName(string name1,  int age1, string sub, int num){
        Name=name1;
        age=age1;
        subject=sub;
        number=num;
    }
    void recallName(){
        cout<< "Name:"<<Name<<" Age:"<<age;
    }
};

bool removeOuterParentheses(string ch) {
stack<char>st;
    for (int i =0;i<ch.length();i++) {
        if (ch[i] == '(' || ch[i] == '[' || ch[i] == '{') {
            st.push(ch[i]);
        } else {
            if (st.empty()) return false;
            char top = st.top();
            st.pop();
            if ((ch[i] == ')' && top != '(') || (ch[i] == ']' && top != '[') || (ch[i] == '}' && top != '{')) {
                return false;
            }
        }
    }

    return st.empty();
}

int main(){
    callName n1("sohil", 24, "cpp", 100);
//    n1.recallName();
    string s = "(()())()[])";
    cout<<removeOuterParentheses(s);

    return 0;
}