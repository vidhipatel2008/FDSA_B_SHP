#include <iostream>
#include <string>
using namespace std;

int main(){
    string l;
    cout << "Enter the line: ";
    getline(cin, l);

    int count = 0;
    int count1 = 0;
    int indx;
    for (int i = 0; i < l.length(); i++) {
        if (l[i] != ' ') {
            count1++;
        }
        else {
            if (count1 > count){
                count = count1;
                indx = i - count;
            }
            count1 = 0;
        }
    }
    if (count1 > count){
        count = count1;
        indx = l.length() - count;
    }

    for (int i = indx; i < indx + count; i++){
        cout << l[i];
    }
    cout << endl;
    cout << count << endl;
}
