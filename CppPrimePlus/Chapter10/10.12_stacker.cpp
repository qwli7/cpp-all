#include <iostream>
#include "10.10_stack.h"
#include <cctype>

//定义栈先进
int main() {
    using namespace std;
    Stack st;

    // unsigned long po;
    Item po; //和第十行代码作用一样

    cout << "Please enter A to add a purchase order: \n"
    << "P to process a PO, or Q to quit. \n";

    char ch;
    while(cin >> ch && toupper(ch) != 'Q') {
        while(cin.get() != '\n') {
            continue;
        }
        if(!isalpha(ch)) {
            cout << "\a";
            continue;
        }

        switch(ch) {
            case 'A':
            case 'a':
                cout << "Enter a PO number to add: ";
                cin >> po;
                if(st.isFull()) {
                    cout << "stack already full\n";
                } else {
                    st.push(po);
                }
                break;
            case 'P':
            case 'p':
                if(st.isEmpty()) {
                    cout << "stack alreay empty\n";
                } else {
                    st.pop(po);
                    cout << "PO #" << po << " popped\n";
                }
                break;

        }
        cout << "Please enter A to add a purchase order, \n"
        << "P to process a PO, or Q to quit.\n";
    }

    cout << "Bye\n";
    return 0;
}