#include <bits/stdc++.h>
using namespace std;

class ListNode {
    public:
        int data;
        ListNode* next;
};

ListNode* insertData(int data) {
	ListNode* newNode = new ListNode();
	newNode->data = data;
	newNode->next = NULL;
	return newNode;
}

void push(ListNode** head_ref, int new_data) {
	ListNode* newNode = insertData(new_data);
	newNode->next = (*head_ref);
	(*head_ref) = newNode;
}

ListNode* addTwoLists(ListNode* list1, ListNode* list2) {
	ListNode* res = NULL;
	ListNode *temp, *prev = NULL;
	int carry = 0, sum;

	while (list1 != NULL || list2 != NULL) {
		sum = carry + (list1 ? list1->data : 0) + (list2 ? list2->data : 0);
		carry = (sum >= 10) ? 1 : 0;
		sum = sum % 10;
		temp = insertData(sum);
		if (res == NULL)
			res = temp;
		else
			prev->next = temp;
	
		prev = temp;

		if (list1)
			list1 = list1->next;
		if (list2)
			list2 = list2->next;
	}
	if (carry > 0)
		temp->next = insertData(carry);
	return res;
}

ListNode* reverse(ListNode* head) {
	if (head == NULL || head->next == NULL)
		return head;
	ListNode* rest = reverse(head->next);
	head->next->next = head;
	head->next = NULL;
	return rest;
}

void printList(ListNode* node) {
	while (node != NULL) {
		cout << node->data;
		node = node->next;
	}
	cout << endl;
}

int main(void) {
	ListNode* res = NULL;
	ListNode* list1 = NULL;
	ListNode* list2 = NULL;

	push(&list1, 2);
	push(&list1, 6);
	push(&list1, 3);
	push(&list1, 8);
	push(&list1, 1);
	cout << "List 1: ";
	printList(list1);

	push(&list2, 3);
	push(&list2, 9);
    push(&list2, 5);
    push(&list2, 7);
    push(&list2, 4);
	cout << "List 2: ";
	printList(list2);

	list1 = reverse(list1);
	list2 = reverse(list2);
	res = addTwoLists(list1, list2);

	res = reverse(res);
	cout << "Sum of List 1 and List 2: ";
	printList(res);
	return 0;
}