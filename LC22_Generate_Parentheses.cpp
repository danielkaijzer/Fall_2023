#include <iostream>
#include <stack>
#include <vector>
#include <string>

/*
A parenthesis is valid if a closing bracket has a corresponding opening bracket in the stack.
*/

using namespace std;

void addParentheses(vector<string>&valid, int open, int close, string &s){

    // base case 
    if (open == 0 && close == 0){
        // add string to vector of valid parantheses strings
        valid.push_back(s);
        return;
    }

    if (open > 0){ // if we can still add open parenthesis
        s += "(";
        addParentheses(valid, open-1,close, s);
        s = s.substr(0, s.size()-1); // remove end parantheses
    }

    if (close > open){ // invalid
        s += ")";
        addParentheses(valid, open, close-1, s);
        s = s.substr(0, s.size()-1); // remove end parantheses
    }

}

vector<string> generateParenthesis(int n) {
    string s;

    vector<string> valid;
    addParentheses(valid,n,n, s);

    return valid;
}

int main(){
    vector<string> vs = generateParenthesis(3);

    cout << "Result: \n";

    for (auto s : vs){
        cout << s << endl;
    }

}