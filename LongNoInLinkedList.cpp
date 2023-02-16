//inserting very large numbers in linked list
#include <iostream>
using namespace std;

class node{
    public:
        int data;
        node *next;
} *sum2 = NULL, *head1 = NULL, *head2 = NULL;;

void insert(node **head, int data){
    node *temp = new node();
    temp->data = data;
    temp->next = *head;
    *head = temp;
}

void print(node *head){
    while(head != NULL){
        cout << (head->data);
        head = head->next;
    }
}

int sum(node *temp1, node *temp2){
    if(temp1 == NULL && temp2 == NULL){
        return 0;
    }
    int c = sum(temp1->next, temp2->next);
    int s = temp1->data + temp2->data + c;
    insert(&sum2, s%10);
    return s/10;
};

int main(){
    int n1, n2;

    cout << "Enter a number: ";
    cin >> n1;
    while(n1 != 0){
        insert(&head1, n1%10);
        n1 = n1/10;
    }
    cout << "Enter a number: ";
    cin >> n2;
    while(n2 != 0){
        insert(&head2, n2%10);
        n2 = n2/10;
    }
    print(head1);
    cout << endl;
    print(head2);
    cout << endl;
    print(sum2);
    return 0;
}