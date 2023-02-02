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
    return 0;
}