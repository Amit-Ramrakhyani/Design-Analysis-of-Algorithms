#include <iostream>
using namespace std;

class node{
    public:
        string city;
        int x, y;
        node *next;

} *headF = NULL, *headL = NULL;

void insertFront(string city, int x, int y){
    node *temp = new node();
    temp->city = city;
    temp->x = x;
    temp->y = y;
    temp->next = NULL;
    if(headF == NULL){
        headF = temp;
        headL = temp;
        return;
    }
    temp->next = headF;
    headF = temp;
}

void insertLast(string city, int x, int y){
    node *temp = new node();
    temp->city = city;
    temp->x = x;
    temp->y = y;
    temp->next = NULL;
    if(headF == NULL){
        headF = temp;
        headL = temp;
        return;
    }
    headL->next = temp;
    headL = temp;
}

void Delete(string city){
    node *temp = headF;
    if(temp != NULL && temp->city == city){
        headF = temp->next;
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
    node *temp = headF;
    if(temp != NULL && temp->x == x && temp->y == y){
        headF = temp->next;
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
    node *temp = headF;
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
    node *temp = headF;
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
    node *temp = headF;
    while(temp != NULL){
        int a = temp->x - x;
        int b = temp->y - y;
        if(a*a + b*b <= dist*dist){
            cout << temp->city << " " << temp->x << " " << temp->y << endl;
        }
        temp = temp->next;
    }
}

void print(){
    node *temp = headF;
    while(temp != NULL){
        cout << temp->city << " " << temp->x << " " << temp->y << endl;
        temp = temp->next;
    }
}

int main(){
    insertFront("Delhi", 28, 77);
    insertFront("Mumbai", 19, 72);
    insertLast("Kolkata", 22, 88);
    insertFront("Chennai", 13, 80);
    insertLast("Bangalore", 15, 77);
    insertLast("Hyderabad", 17, 78);
    insertFront("Ahmedabad", 23, 72);
    insertLast("Pune", 18, 73);
    insertFront("Jaipur", 26, 75);
    print();
    cout << endl;
    Delete("Delhi");
    Delete(18, 73); 
    print();
    cout << endl;
    search("Mumbai");
    search(15, 77);
    cout << endl;
    printInRange(20, 80, 10);
    return 0;
}