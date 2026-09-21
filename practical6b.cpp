#include <iostream>
using namespace std;
class Node
{
public:
    string page;
    Node *next;
    Node(string p)
    {
        page = p;
        next = NULL;
    }
};
class Browser
{
    Node *top;
public:
    Browser()
    {
        top = NULL;
    }
    void visit(string page)
    {
        Node *newNode = new Node(page);
        newNode->next = top;
        top = newNode;
        cout << "Visited: " << page << endl;
    }
    void back()
    {
        if (top == NULL)
        {
            cout << "No history left!" << endl;
        }
        else
        {
            Node *temp = top;
            cout << "Back from: " << temp->page << endl;
            top = top->next;
            delete temp;
        }
    }
    void currentPage()
    {
        if (top == NULL)
        {
            cout << "No page open" << endl;
        }
        else
        {
            cout << "Current page: " << top->page << endl;
        }
    }
};
int main()
{
    Browser b;
    b.visit("Google");
    b.currentPage();
    b.visit("YouTube");
    b.currentPage();
    b.visit("Wikipedia");
    b.currentPage();
    b.back();
    b.currentPage();
    b.back();
    b.currentPage();
    b.back();
    b.currentPage();
    b.back();
    return 0;
}
