//! Store contacts in linked list in alphabetic order.


#include <iostream>
#include <stdio.h>
#include <string.h>

using namespace std;

class Node {

    public:
    char* contactName;
    unsigned long phoneNumber;
    Node *next;
};

class LinkedList {

    public:
        Node *head;
        Node * insert( char *name, unsigned long number ) {
            Node *newNode = new Node;
            newNode->contactName = name;
            newNode->phoneNumber = number;
            newNode->next = NULL;
            if ( head == NULL ) {
                head = newNode;
                return head;
            }
            Node *current = head;
            Node *previous = NULL;
            while ( current != NULL ) {
                if ( strcmp( name, current->contactName ) < 0 ) {
                    if ( previous == NULL ) {
                        newNode->next = head;
                        head = newNode;
                        return head;
                    }
                    newNode->next = current;
                    previous->next = newNode;
                    return head;
                }
                previous = current;
                current = current->next;
            }
            previous->next = newNode;
            return head;
        }
        void display() {
            cout << "Contact List" << endl;
            cout << "============" << endl;
            Node *current = head;
            while ( current != NULL ) {
                cout << current->contactName << " " << current->phoneNumber << endl;
                current = current->next;
            }
        }
};

int main() {

    LinkedList *contactsList = new LinkedList();

    cout << "How much contacts to insert: " << endl;
    int contactsCount;
    cin >> contactsCount;
    
    for( int i=0; i<contactsCount; i++ ) {
        cout << "Enter contact name: " << endl;
        char *name = new char[100];
        cin >> name;
        cout << "Enter contact phone number: " << endl;
        unsigned long number;
        cin >> number;
        contactsList->insert( name, number );
    }

    contactsList->display();

    return 0;
}