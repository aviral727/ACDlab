#include<bits/stdc++.h>

using namespace std;

int main(){
    string input;
    cout << "Enter number: ";
    cin >> input;
    int state = 0;

    for(char i:input) {
        if(state == 0 && i == '1') state = 1;
        else if(state == 1 && i == '0') state = 2;
        else if(state == 1 && i == '1') state = 0;
        else if(state == 2 && i == '0') state = 1;
    }

    if(state == 0) cout << "Machine will accept this input.";
    else cout << "Machine will not accept this input";
    cout << endl;
}