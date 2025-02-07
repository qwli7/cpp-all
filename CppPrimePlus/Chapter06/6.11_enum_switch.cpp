#include <iostream>

enum {red, orange, yellow, green, blue, violet, indigo};

int main() {
    using namespace std;

    cout << "Enter color code(0-6): ";
    int code;
    cin >> code;
    while(code >= red && code <= indigo){
        //使用枚举量作为 label
        switch(code){
            case red:
                cout << "red code" << endl;
                break;
            case orange:
                cout << "orange code" << endl;
                break;
            case yellow:
                cout << "yellow code" << endl;
                break;
            case green:
                cout << "green code" << endl;
                break;
            case blue:
                cout << "blue code" << endl;
                break;
            case violet:
                cout << "violet code" << endl;
                break;
            case indigo:
                cout << "indigo code" << endl;
                break;
        } 
        cout << "Enter color code(0-6): ";
        cin >> code;
    }
    cout << "Bye \n";
    return 0;
}