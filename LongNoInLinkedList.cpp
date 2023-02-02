//inserting very large numbers in linked list
#include <iostream>
using namespace std;

class node{
    public:
        int data;
        node *next;
} *sum2, *head1 = NULL, *head2 = NULL;;

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
    //cout << "Hello0" << endl;
    int carry=0, c;
    if(temp1->next != NULL && temp2->next != NULL){
        c = sum(temp1->next, temp2->next);
        if(temp1 != head1 && temp2 != head2){
            if(temp1->data + temp2->data + c > 9){
                carry = 1;
                insert(&sum2, (temp1->data + temp2->data + c)%10);
            }
            else{
                carry = 0;
                insert(&sum2, (temp1->data + temp2->data + c));
            }
        }
        else if (temp1 == head1 && temp2 != head2){}

        return carry;
    }
    else if (temp1->next == NULL && temp2->next != NULL){
        c = sum(temp1, temp2->next);
        if(temp1->data + temp2->data + c > 9){
            carry = 1;
            insert(&sum2, (temp1->data + temp2->data + c)%10);
        }
        else{
            carry = 0;
            insert(&sum2, (temp1->data + temp2->data + c));
        }
        return carry;
    }
    else if (temp1->next != NULL && temp2->next == NULL){
        //cout << "Hello3" << endl;
        c = sum(temp1->next, temp2);
        if(temp1->data + temp2->data + c > 9){
            carry = 1;
            insert(&sum2, (temp1->data + temp2->data + c)%10);
        }
        else{
            carry = 0;
            insert(&sum2, (temp1->data + temp2->data + c));
        }
        return carry;
    }
    else if (temp1->next == NULL && temp2->next == NULL){
        if(temp1->data + temp2->data > 9){
            carry = 1;
            insert(&sum2, (temp1->data + temp2->data)%10);
        }
        else{
            insert(&sum2, (temp1->data + temp2->data));
        }
        return carry;
    }
    else{
        return 0;
    }
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
    int c1 = sum(head1, head2);
    if(c1 == 1){
        insert(&sum2, 1);
    }
    //cout << "Hello";
    cout << endl;
    print(sum2);
    return 0;
}