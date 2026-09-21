#include <iostream>
using namespace std;
class Stack
{
    int arr[5];
    int top;
public:
    Stack()
    {
        top = -1;
    }
    void push(int x)
    {
        if (top == 4)
        {
            cout << "Stack is full!" << endl;
        }
        else
        {
            top++;
            arr[top] = x;
            cout << "Placed: " << x << endl;
        }
    }
    void pop()
    {
        if (top == -1)
        {
            cout << "Stack is empty!" << endl;
        }
        else
        {
            cout << "Taken: " << arr[top] << endl;
            top--;
        }
    }
    void displayTop()
    {
        if (top == -1)
            cout << "No tray on top" << endl;
        else
            cout << "Top tray: " << arr[top] << endl;
    }
};
int main()
{
    Stack s;
    s.push(10);
    s.displayTop();
    s.push(20);
    s.displayTop();
    s.push(30);
    s.displayTop();
    s.pop();
    s.displayTop();
    s.pop();
    s.displayTop();
    return 0;
}
