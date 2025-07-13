#include<iostream> // Header file for input/output operations
using namespace std;

// Definition of a Node in Circular Linked List
class Node{
public:
	int data;       // Value of the node
	Node* next;     // Pointer to the next node
	
	// Constructor to initialize data and set next to NULL
	Node(int val){
		data = val;
		next = NULL;
	}
};

// Definition of the Circular Linked List class
class CircularList{
	Node* head;     // Pointer to the first node
	Node* tail;     // Pointer to the last node
	
public:
	// Constructor to initialize an empty list
	CircularList(){
		head = tail = NULL;
	}
	
	void insertAtHead(int val){  				// 	INSERT ELEMENT AT BEGINNING OR HEAD
		Node* newNode = new Node(val);         // Create a new node with the given value
		
		if(tail == NULL){                      // If list is empty
			head = tail =  newNode;            // New node becomes head and tail
			tail->next = head;                 // Link tail to head (circular)
		}
		else{
			newNode->next = head;              // New node points to current head
			head = newNode;                    // Move head to new node
			tail->next = head;                 // Update tail's next to new head
		}
	}
	
	void insertAtTail(int val){					// 	INSERT ELEMENT AT TAIL OR END
		Node* newNode = new Node(val);         // Create new node
		
		if(tail == NULL){                      // If list is empty
			head = tail =  newNode;            // New node is head and tail
			tail->next = head;                 // Circular link
		}
		else{
			newNode->next = head;              // New node points to head
			tail->next = newNode;              // Tail points to new node
			tail = newNode;                    // Move tail to new node
		}
	}
	
	void deleteAtHead(){						// DELETE AT HEAD OR BEGINNING 	
		if(head == NULL) return;              // Empty list case
		
		else if(head == tail){                // Only one node case
			delete head;
			head = tail = NULL;
		}
		else{                                 // More than one node
			Node* temp = head;                // Store current head
			head = head->next;                // Move head to next node
			tail->next = head;                // Tail's next points to new head
			
			temp->next = NULL;                // Break old head's next pointer
			delete temp;                      // Free memory
		}
	}
	
	void deleteAtTail(){					// DELETE AT TAIL OR END
		if(head == NULL) return;           // Empty list
		
		else if(head == tail){             // Only one node
			delete head;
			head = tail = NULL;
		}
		else{
			Node* temp = tail;             // Store current tail
			
			Node* prev = head;             // Start from head to find node before tail
			while(prev->next != tail){
				prev = prev->next;
			}
			
			tail = prev;                   // Move tail to previous node
			tail->next = head;             // Maintain circular link
			
			temp->next = NULL;             // Break old tail's link
			delete temp;                   // Free memory
		}
	}
	
	void print(){						// FUNCTION TO PRINT ALL LL VALUES
		if(head == NULL) return;         // If list is empty, do nothing
		
		cout << head->data << "->";      // Print head node's data
		Node* temp = head->next;         // Start from next of head
		
		while(temp != head){             // Traverse till we come back to head
			cout << temp->data << "->";  // Print current node data
			temp = temp->next;           // Move to next node
		}
		
		cout << temp->data << endl;      // Print last node again (which is same as head in CLL)
	}
};

int main(){
	CircularList cll;                   // Create object of CircularList
	
	cll.insertAtTail(1);               // Insert 1 at end
	cll.insertAtTail(2);               // Insert 2 at end
	cll.insertAtTail(3);               // Insert 3 at end
	
	cll.print();                       // Print the list
	
	return 0;                          // End of program
}
