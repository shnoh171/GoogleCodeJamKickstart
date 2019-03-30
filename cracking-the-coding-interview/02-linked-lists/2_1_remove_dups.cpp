#include <iostream>
#include <string>
#include <unordered_set>
using namespace std;

struct node {
	char letter;
	node *next = NULL;
};

class LinkedList {
	private:
		node *head, *tail;
	public:
		LinkedList() { head = NULL; tail = NULL; }
		void InsertNode(char letter);
		void InsertSequence(string seq);
		void RemoveDuplicate();
		void PrintList();
};

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	LinkedList l;
	l.InsertSequence("FOLLOW UP");
	l.RemoveDuplicate();
	l.PrintList();

	return 0;
}

void LinkedList::InsertNode(char letter) {
	if (head == NULL) {
		head = new node;
		tail = head;
		head->letter = letter;
		return;
	}

	tail->next = new node;
	tail = tail->next;
	tail->letter = letter;
}

void LinkedList::InsertSequence(string seq) {
	for (auto it : seq) {
		InsertNode(it);
	}
}

void LinkedList::RemoveDuplicate() {
	if (head == NULL) return;

	unordered_set<char> ht;
	node *curr = head;
	node *prev;
	while (curr != NULL) {
		if (ht.find(curr->letter) == ht.end()) {
			ht.insert(curr->letter);
			prev = curr;
			curr = curr->next;
		} else {
			prev->next = curr->next;
			delete curr;
			curr = prev->next;
		}
	}
}

void LinkedList::PrintList() {
	node *temp = head;
	while (temp != NULL) {
		cout << temp->letter;
		temp = temp->next;
	}
	cout << "\n";
}