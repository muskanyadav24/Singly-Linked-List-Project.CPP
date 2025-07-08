#include<iostream>
using namespace std;

class Node{
    public:
        int data;
        Node* next;

        Node(int d){  // object
            data = d;
            next = nullptr;
        }

};

class SinglyLL{

    private:
        Node* head;
        Node* tail;

    public:
        SinglyLL(){ // object 
            head = nullptr;
        }

        void push_back(int d){ // Append :- value ko end mins tail ke next me add karne ke liye.
            Node* newNode = new Node(d);
            tail->next = newNode; 
            tail = newNode; 
        }

        void push_front(int d){ // Insret_at_begnning :- value ko starting me add karne ke liye.
            Node* newNode = new Node(d);
            newNode->next = head; 
            head = newNode; 
        }

        void reverseList(){ // Node ko reverse karne ke liye
            Node* prev = nullptr;
            Node* current = head;
            Node* next = nullptr;

            while(current != nullptr){
                next = current->next;
                current->next = prev;
                prev = current;
                current = next;
            }

            head = prev;
        }

        void search(int key){ // Search value.
            Node* temp = head;
            while(temp != nullptr){
                if(temp->data == key){
                    cout << key << " Found in the list." << endl;
                    return;
                }
                temp = temp->next;
            }
            cout << key << " Not found in the list. " << endl;
        }

        void deleteValue(int key){ // Delete :- user jo value enter kare aagr oh value ho to use delete karne ke liye.
            Node* temp = head;
            Node* prev = nullptr;

            if(temp != nullptr && temp->data == key){
                head = temp->next;
                delete temp;
                cout << key << " delete from the list." << endl;
                return;
            }

            while(temp != nullptr && temp->data != key){
                prev = temp;
                temp = temp->next;
            }

            if(temp == nullptr){
                cout << key << " not found in the list. " << endl;
                return;
            }

            prev->next = temp->next;
            delete temp;
            cout << key << " delete from the list." << endl;
        }

        void display(){ // Display :- usre ne abhi tak kitni value enter ki he us ki info.. ke liye.
            Node* temp = head;
            if(temp == nullptr){
                cout << "List is empty." << endl;
                return;
            }
            while(temp){
                cout << temp->data << endl;
                temp = temp->next;
            }
        }

};

int main(){

    SinglyLL list;

    int choice,value;

    do{
        cout << endl << "------> Linked List Menu <------" << endl;
        cout << "Press 1 for Push_back value at end." << endl;
        cout << "Press 2 for Push_front value at start." << endl;
        cout << "Press 3 for Display list." << endl;
        cout << "Press 4 for Reverse list." << endl;
        cout << "Press 5 for Search a value." << endl;
        cout << "Press 6 for Delete a value." << endl;
        cout << "Press 0 for Exit." << endl;

        cout << "Enter your choice :- ";
        cin >> choice;

        switch(choice){
            case 1: 
                cout << "Enter the value of Push_back :- ";
                cin >> value;
                list.push_back(value);
                break;
            case 2: 
                cout << "Enter the value of Push_front :- ";
                cin >> value;
                list.push_front(value);
                break;
            case 3: 
                cout << "Display list." << endl;
                list.display();
                break;
            case 4:
                cout << "List reversed." << endl;
                list.reverseList();
                break;
            case 5:
                cout << "Enter Value to search :- ";
                cin >> value;
                list.search(value);
                break;
            case 6:
                cout << "Enter value to delete :- ";
                cin >> value;
                list.deleteValue(value);
                break;
            case 0:
                cout << "Thanks for using Singly Linked List." << endl;
                break;
            default:
                cout << "Invalid choice! Try again." << endl;
        }

    }while(choice != 0);

    // SinglyLL sl(10);
    // sl.push_back(20);
    // sl.push_back(30);
    // sl.push_back(40);
    // cout << "Push_back Initial List :- " << endl;
    // sl.display();

    // sl.push_front(90);
    // sl.push_front(80);
    // cout << "Push_front. " << endl;
    // sl.display();

    return 0;
}