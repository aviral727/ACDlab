#include<bits/stdc++.h>

using namespace std;

int main(){
    string input;
    cout << "Enter number: ";
    cin >> input;
    int state = 0;

    for(char i:input) {
        if(i == '0' || i == '2' || i == '4' || i == '6' || i == '8') state = 0;
        else state = 1;
    }

    if(state == 0) cout << "Machine will accept this input.";
    else cout << "Machine will not accept this input";
    cout << endl;
}