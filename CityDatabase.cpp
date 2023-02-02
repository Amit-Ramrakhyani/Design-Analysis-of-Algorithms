#include <iostream>
using namespace std;

class node{
    public:
        string city;
        int x, y;
        node *next;

} *head = NULL;

void insertFront(node **head, string city, int x, int y){
    node *temp = new node();
    temp->city = city;
    temp->x = x;
    temp->y = y;
    temp->next = NULL;
    if(*head == NULL){
        *head = temp;
        return;
    }
    temp->next = *head;
    *head = temp;
}

void insertLast(node **head, string city, int x, int y){
    node *temp = new node();
    temp->city = city;
    temp->x = x;
    temp->y = y;
    temp->next = NULL;
    if(*head == NULL){
        *head = temp;
        return;
    }
    node *last = *head;
    while(last->next != NULL){
        last = last->next;
    }
    last->next = temp;
}

void Delete(string city){
    node *temp = head;
    if(temp != NULL && temp->city == city){
        head = temp->next;
        delete temp;
        return;
    }
    node *prev;
    while(temp != NULL && temp->city != city){
        prev = temp;
        temp = temp->next;
    }
    if(temp == NULL){
        cout << "City not found" << endl;
        return;
    }
    prev->next = temp->next;
    delete temp;
}

void Delete(int x, int y){
    node *temp = head;
    if(temp != NULL && temp->x == x && temp->y == y){
        head = temp->next;
        delete temp;
        return;
    }
    node *prev;
    while(temp != NULL && temp->x != x && temp->y != y){
        prev = temp;
        temp = temp->next;
    }
    if(temp == NULL){
        cout << "City not found" << endl;
        return;
    }
    prev->next = temp->next;
    delete temp;
}

void search(string city){
    node *temp = head;
    while(temp != NULL && temp->city != city){
        temp = temp->next;
    }
    if(temp == NULL){
        cout << "City not found" << endl;
        return;
    }
    cout << temp->city << " " << temp->x << " " << temp->y << endl;
}

void search(int x, int y){
    node *temp = head;
    while(temp != NULL && temp->x != x && temp->y != y){
        temp = temp->next;
    }
    if(temp == NULL){
        cout << "City not found" << endl;
        return;
    }
    cout << temp->city << " " << temp->x << " " << temp->y << endl;
}

void printInRange(int x, int y, int dist){
    node *temp = head;
    while(temp != NULL){
        int a = temp->x - x;
        int b = temp->y - y;
        if(a*a + b*b <= dist*dist){
            cout << temp->city << " " << temp->x << " " << temp->y << endl;
        }
        temp = temp->next;
    }
}

void print(node *head){
    while(head != NULL){
        cout << head->city << " " << head->x << " " << head->y << endl;
        head = head->next;
    }
}

int main(){
    insertFront(&head, "Delhi", 28, 77);
    insertFront(&head, "Mumbai", 19, 72);
    insertLast(&head, "Kolkata", 22, 88);
    insertFront(&head, "Chennai", 13, 80);
    insertLast(&head, "Bangalore", 15, 77);
    insertLast(&head, "Hyderabad", 17, 78);
    insertFront(&head, "Ahmedabad", 23, 72);
    insertLast(&head, "Pune", 18, 73);
    insertFront(&head, "Jaipur", 26, 75);
    print(head);
    cout << endl;
    Delete("Delhi");
    Delete(18, 73); 
    print(head);
    cout << endl;
    search("Mumbai");
    search(15, 77);
    cout << endl;
    printInRange(20, 80, 10);
    return 0;
}