#include<iostream> // Header file for input and output
using namespace std;

// Definition of a Node in doubly linked list
class Node{
public:
	int data;       // Stores the value of the node
	Node* next;     // Pointer to the next node
	Node* prev;     // Pointer to the previous node
	
	// Constructor to initialize the node with data and NULL pointers
	Node(int val){
		data = val;
		next = prev = NULL;
	}
};

// Definition of the Doubly Linked List
class DoublyList{
	Node* head;     // Points to the first node of the list
	Node* tail;     // Points to the last node of the list

public:
	// Constructor to initialize an empty list
	DoublyList(){
		head = tail = NULL;
	}
	
	void push_front(int val){           //  INSERT ELEMENT AT FRONT
		Node* newNode = new Node(val); // Create a new node with given value
		
		if(head == NULL){              // If list is empty, head and tail are the same
			head = tail = newNode;
		}
		else{
			newNode->next = head;      // Point new node's next to current head
			head->prev = newNode;      // Point current head's prev to new node
			head = newNode;            // Move head to new node
		}
	}
	
	void push_back(int val){		   //  INSERT ELEMENT AT END
		Node* newNode = new Node(val); // Create a new node
		
		if(head == NULL){              // If list is empty, new node is head and tail
			head = tail = newNode;
		}
		else{
			newNode->prev = tail;      // Link new node's prev to current tail
			tail->next = newNode;      // Link current tail's next to new node
			tail = newNode;            // Move tail to the new node
		}
	}
	
	void pop_front(){			  // POP ELEMENT FROM FRONT
		if(head == NULL){         // If list is empty, nothing to delete
			cout<< "DLL is empty\n";
			return;
		}
		
		Node* temp = head;        // Store the current head node
		head = head->next;	      // Update the head to next node
		
		if(head != NULL){         // If list had more than 1 node
			head->prev = NULL;    // Remove backward link from new head
		}
		
		temp->next = NULL;        // Remove forward link from old head
		delete temp;              // Free memory
	}
	
	void pop_back(){		// POP ELEMENT FROM BACK
		if(head == NULL){   // If list is empty, nothing to delete
			cout<<"DLL is empty\n";
			return;
		}
		
		Node* temp = tail;       // Store the current tail
		tail = tail->prev;       // Move tail to previous node
		
		if(tail != NULL){        // If more than one node exists
			tail->next = NULL;   // Remove forward link from new tail
		}
		
		temp->prev = NULL;       // Remove backward link from old tail
		delete temp;             // Free memory
	}
	
	void print(){					// FUNCTION TO PRINT LL ELEMENTS
		Node* temp = head;       // Start from the head of the list
		
		while(temp != NULL){     // Traverse till the end of list
			cout << temp->data << " <=> "; // Print current node data
			temp = temp->next;   // Move to next node
		}
		cout << "NULL\n";        // Indicate end of list
	}
};


int main(){
	DoublyList dll;              // Create an object of DoublyList
	
	dll.push_back(1);           // Insert 1 at end
	dll.push_back(2);           // Insert 2 at end
	dll.push_back(3);           // Insert 3 at end
	

	dll.print();                // Print the current list

	return 0;                   // End of program
}
