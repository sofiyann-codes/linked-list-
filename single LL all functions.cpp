#include<iostream>
using namespace std;

// with the help of these two classes we create linked list
class Node{       
	public:
		int data;   // Data store karega (jaise 1, 2, 3...)
		Node* next;  // Next node ka address rakhega
		
		Node(int val){
			data = val;  // Constructor: data mein value daalna
			next = NULL;  // Next pehle NULL, kyunki naye node ka aage koi nai hota
		}	
};

class List{
	Node* head; // Start of the list
	Node* tail; // End of the list
	
	public:
		List(){
			head = tail = NULL;	 // Initially list khaali hoti
		}
		
		void push_front(int val){ 		// TC: O(1)																// insert element at front
			Node* newnode = new Node(val); // new node creation
			
			if (head == NULL) {  // Agar list khaali hai
			head = tail = newnode; // Pehla node dono head aur tail ban gaya
			return;
			}
			else{
			newnode->next = head; // Naye node ka next purana head
			head = newnode;       // Head ko naye node pe shift kar diya
			}
		}
		
		void push_back(int val){ 		// TC: O(1)													       	// insert element at end
			Node* newnode = new Node(val);
			
			if(head == NULL){
				head = tail = newnode;
				return;
			}
			else{
				tail->next = newnode;
				tail =  newnode;
			}
		}
		
		void pop_front(){ 				// TC: O(1)																// pop element from front
			if(head == NULL){
				cout << "LL is empty\n";
				return;
			}
				Node* temp = head;
				head = head->next;
				temp->next = NULL;
				
				delete temp;
		}
		
		void pop_back(){ 		// TC: O(n)																		// pop element from end
			if( head == NULL){
				cout<<"LL is empty\n";
			}
			Node* temp = head;
			while(temp->next != tail){
				temp = temp->next;
			}
			temp->next = NULL;
			delete tail;
			tail = temp;
		}
		
		void insert(int val, int pos){ 	// TC: O(n)															// insert element at any specific position
			if(pos < 0){
				cout<<"invalid pos\n";        
			}
			if(pos ==0){
				push_front(val);
				return;
			}
			Node* temp = head;
			for(int i = 0;i < pos-1; i++){
				if(temp == NULL){
					cout<<"Invalid pos\n";
					return;
				}
				temp = temp->next;
			}
			Node* newnode = new Node(val);
			newnode->next = temp->next;
			temp->next = newnode;
		}
		
		int search(int key){  			// TC: O(n)															// search an element in linkedlist
			Node* temp = head;
			int idx = 0;
			
			while(temp != NULL){
				if(temp->data == key){
					return idx;           
				}
				temp = temp->next;
				idx++;
			}
			return -1;
	}
		
		void printLL(){  			// TC: O(n)																// function to print linkedlist
			Node* temp = head;
			
			while(temp != NULL){
				cout<< temp->data << "->";
				temp = temp->next;
			}
			cout<< "NULL" <<endl;
		}                   
};
int main(){
	List ll;
	
	ll.push_front(3);
	ll.push_front(2);
	ll.push_front(1);
	
	ll.printLL();
	cout<< ll.search(4) <<endl;

	return 0;
}