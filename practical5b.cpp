#include <iostream>
using namespace std;
class Node
{
public:
    string name;
    Node *next;
    Node(string n)
    {
        name = n;
        next = NULL;
    }
};
class CircularList
{
    Node *head;
public:
    CircularList()
    {
        head = NULL;
    }
    void join(string name)
    {
        Node *newNode = new Node(name);
        if (head == NULL)
        {
            head = newNode;
            newNode->next = head;
        }
        else
        {
            Node *temp = head;
            while (temp->next != head)
            {
                temp = temp->next;
            }
            temp->next = newNode;
            newNode->next = head;
        }
    }
    void leave(string name)
    {
        if (head == NULL)
        {
            cout << "Circle is empty!" << endl;
            return;
        }
        Node *temp = head;
        Node *prev = NULL;
        do
        {
            if (temp->name == name)
            {
                break;
            }
            prev = temp;
            temp = temp->next;
        } while (temp != head);
        if (temp->name != name)
        {
            cout << "Student not found!" << endl;
            return;
        }
        if (temp == head)
        {
            if (head->next == head)
            {
                head = NULL;
            }
            else
            {
                Node *last = head;
                while (last->next != head)
                {
                    last = last->next;
                }
                head = head->next;
                last->next = head;
            }
        }
        else
        {
            prev->next = temp->next;
        }
        delete temp;
    }
    void display()
    {
        if (head == NULL)
        {
            cout << "Circle is empty!" << endl;
            return;
        }
        Node *temp = head;
        cout << "Circle: ";
        do
        {
            cout << temp->name << " ";
            temp = temp->next;
        } while (temp != head);

        cout << endl;
    }
};
int main()
{
    CircularList c;
    c.join("A");
    c.display();
    c.join("B");
    c.display();
    c.join("C");
    c.display();
    c.leave("B");
    c.display();
    c.leave("A");
    c.display();
    return 0;
}
