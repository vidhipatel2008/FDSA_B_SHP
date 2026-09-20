#include <iostream>
using namespace std;
class Node
{
public:
    string song;
    Node *prev;
    Node *next;
    Node(string s)
    {
        song = s;
        prev = NULL;
        next = NULL;
    }
};
class Playlist
{
    Node *head;
public:
    Playlist()
    {
        head = NULL;
    }
    void addBeginning(string s)
    {
        Node *newNode = new Node(s);
        if (head == NULL)
        {
            head = newNode;
        }
        else
        {
            newNode->next = head;
            head->prev = newNode;
            head = newNode;
        }
    }
    void addEnd(string s)
    {
        Node *newNode = new Node(s);
        if (head == NULL)
        {
            head = newNode;
        }
        else
        {
            Node *temp = head;
            while (temp->next != NULL)
            {
                temp = temp->next;
            }
            temp->next = newNode;
            newNode->prev = temp;
        }
    }
    void insertAfter(string findSong, string newSong)
    {
        Node *temp = head;
        while (temp != NULL && temp->song != findSong)
        {
            temp = temp->next;
        }
        if (temp == NULL)
        {
            cout << "Song not found!" << endl;
            return;
        }
        Node *newNode = new Node(newSong);
        newNode->next = temp->next;
        newNode->prev = temp;
        if (temp->next != NULL)
        {
            temp->next->prev = newNode;
        }
        temp->next = newNode;
    }
    void removeFirst()
    {
        if (head == NULL)
        {
            cout << "Playlist is empty!" << endl;
            return;
        }
        Node *temp = head;
        head = head->next;
        if (head != NULL)
        {
            head->prev = NULL;
        }
        delete temp;
    }
    int count()
    {
        int c = 0;
        Node *temp = head;
        while (temp != NULL)
        {
            c++;
            temp = temp->next;
        }
        return c;
    }
    void display()
    {
        Node *temp = head;
        cout << "Playlist: ";
        while (temp != NULL)
        {
            cout << temp->song << " ";
            temp = temp->next;
        }
        cout << endl;
    }
};
int main()
{
    Playlist p;
    p.addBeginning("Song A");
    p.display();
    p.addEnd("Song C");
    p.display();
    p.insertAfter("Song A", "Song B");
    p.display();
    cout << "Number of songs: " << p.count() << endl;
    p.removeFirst();
    p.display();
    cout << "Number of songs: " << p.count() << endl;
    return 0;
}
