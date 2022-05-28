#include<bits/stdc++.h>

using namespace std;

int main(){
    string input,
    q0 = "000",
    q1 = "001",
    q2 = "010",
    q3 = "011",
    q4 = "100",
    q5 = "101",
    q6 = "110",
    q7 = "111",
    cur = "000";

    cin >> input;

    for(char i:input){
        if(i == '0'){
            if(cur == q0 || cur == q4) cur = q0;
            else if(cur == q1 || cur == q5) cur = q2;
            else if(cur == q2 || cur == q6) cur = q4;
            else if(cur == q3 || cur == q7) cur = q6;
        }
        else{
            if(cur == q3 || cur == q7) cur = q7;
            else if(cur == q0 || cur == q4) cur = q1;
            else if(cur == q1 || cur == q5) cur = q3;
            else if(cur == q2 || cur == q6) cur = q5;
        }
    }

    if(cur == q5) cout << "Machine will accept this input.";
    else cout << "Machine will not accept this input";
    cout << endl;

}