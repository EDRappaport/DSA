/*
	Rappaport, Elliot D
	April 4, 2012
	DSA I, Project I
					*/
/*
	This program takes an input file with commands
	to manipulate Stacks and Queues, and returns an
	output file indicating what commands were done,
	what errors were encountered, and the popped
	values.
*/
					
#include <string>					
#include <fstream>
#include <iostream>
#include <list>
using namespace std;

template <typename D>
class SimpleList{
	class Node{
		friend class SimpleList<D>;
		D data;
		Node* next;
		Node (D dat, Node* nxt) :  data(dat), next(nxt){}
	};
	Node* head;
	Node* end;
	int count;
	string name;
	public:
	SimpleList(string nm) : head(0), end(0), count(0), name(nm){};
	int size(){
		return count;}
	bool empty(){
		return count == 0;}
	string print_name(){
		return name;}
	D& front(){
		return head->data;}
	D& tail(){
		return end->data;}
	void push_front(D dat);
	void push_back(D dat);
	virtual void push(D dat){};
	D pop();
};

template <typename D>
D SimpleList<D>::pop(){
	D popped = head->data;
    Node* old_head = head;
    if (this->size() == 1) {
        head = 0;
        end = 0;
    }
    else {
        head = head->next;
    }
    delete old_head;
    count--;
	return popped;
}

template <typename D>
void SimpleList<D>::push_front(D dat){
	Node* new_head = new Node(dat, head);
    if (this->empty()) {
        head = new_head;
        end = new_head;
    }
    else {
        head = new_head;
    }
    count ++;
}

template <typename D>
void SimpleList<D>::push_back(D dat){
	Node* new_end = new Node(dat, NULL);
	if (this->empty()){
		head = new_end;
	}
	else{
		end->next = new_end;
	}
	end = new_end;
	count ++;
}

template <typename D>
class Stack : public SimpleList<D>{
	public:
	void push(D dat){
		SimpleList<D>::push_front(dat);}
	Stack (string nm):SimpleList<D>::SimpleList(nm){}
};

template <typename D>
class Queue : public SimpleList<D>{
	public:
	void push(D dat){
		SimpleList<D>::push_back(dat);}
	Queue(string nm):SimpleList<D>::SimpleList(nm){}
};

int main(){

	//Declare lists of all Stacks & Queues
	list<SimpleList<int>*> listSLi;
	list<SimpleList<double>*> listSLd;
	list<SimpleList<string>*> listSLs;
	
	//Set input & output files
	string input;
	//string s;
	cout << "Enter name of input file:";
	cin >> input;
	ifstream in(input.c_str());		
	cout << "Enter name of output file:";
	string output;
	cin >> output;
	ofstream out(output.c_str());
		
	//run loop while there is what to read from input file	
	while(!in.eof()){
	string s;
	in >> s; //first word in command determines what to do
	if (s=="create"){
		in.get();//read and ignore blank space
		char type;
		type = in.get();//first char of name determines type of List
		string title;
		in >> title;
		title = type+title;
		string s_q;
		in >> s_q; //Stack or Queue?
		out << "PROCESSING COMMAND: " << s << " " << title << " " << s_q << "\n";
				
		if (type == 'i'){		
			//loop through list of all ints and check List titles
			list<SimpleList<int>*>::iterator it;
			bool exists = false;
			for ( it=listSLi.begin() ; it != listSLi.end(); it++ ){
				if ((*it)->print_name() == title){
					exists = true;
					out<<"ERROR: This name already exists!\n";
				}
			}
			if (!exists){ //create the List if it doesn't already exist
			if (s_q == "stack"){
				SimpleList<int>* pSLi;
				pSLi = new Stack<int>(title);
				listSLi.push_front(pSLi);}		
			else{
				SimpleList<int>* pSLi;
				pSLi = new Queue<int>(title);
				listSLi.push_front(pSLi);}
			}
		}
		
		if (type == 'd'){
			list<SimpleList<double>*>::iterator it;
			bool exists = false;
			for ( it=listSLd.begin() ; it != listSLd.end(); it++ ){
				if ((*it)->print_name() == title){
					exists = true;
					out<<"ERROR: This name already exists!\n";
				}
			}
			if (!exists){
			if (s_q == "stack"){
				SimpleList<double>* pSLi;
				pSLi = new Stack<double>(title);
				listSLd.push_front(pSLi);}
			else{
				SimpleList<double>* pSLi;
				pSLi = new Queue<double>(title);
				listSLd.push_front(pSLi);}
			}
		}
		if (type == 's'){
			list<SimpleList<string>*>::iterator it;
			bool exists = false;
			for ( it=listSLs.begin() ; it != listSLs.end(); it++ ){
				if ((*it)->print_name() == title){
					exists = true;
					out<<"ERROR: This name already exists!\n";
				}
			}
			if (!exists){
			if (s_q == "stack"){
				SimpleList<string>* pSLi;
				pSLi = new Stack<string>(title);
				listSLs.push_front(pSLi);}
			else{
				SimpleList<string>* pSLi;
				pSLi = new Queue<string>(title);
				listSLs.push_front(pSLi);}
			}
		}
	}
	
	if (s=="push"){
		in.get();//get and ignore space between command and title
		char type;
		type = in.get();
		string title;
		in >> title;
		title = type+title;
		
		if (type=='i'){
			int item;
			in >> item;
			out << "PROCESSING COMMAND: " << s << " " << title << " " << item << "\n";
			list<SimpleList<int>*>::iterator it;
			bool exists = false;
			for ( it=listSLi.begin() ; it != listSLi.end(); it++ ){
				if ((*it)->print_name() == title){
					(*it)->push(item);
					exists = true;
				}
			}
			if (!exists) out<<"ERROR: This name does not exist!\n";
		}
		
		if (type=='d'){
			double item;
			in >> item;
			out << "PROCESSING COMMAND: " << s << " " << title << " " << item << "\n";
			list<SimpleList<double>*>::iterator it;
			bool exists = false;
			for ( it=listSLd.begin() ; it != listSLd.end(); it++ ){
				if ((*it)->print_name() == title){
					(*it)->push(item);
					exists = true;
				}
			}
			if (!exists) out<<"ERROR: This name does not exist!\n";
		}
		
		if (type=='s'){
			string item;
			in >> item;
			out << "PROCESSING COMMAND: " << s << " " << title << " " << item << "\n";
			list<SimpleList<string>*>::iterator it;
			bool exists = false;
			for ( it=listSLs.begin() ; it != listSLs.end(); it++ ){
				if ((*it)->print_name() == title){
					(*it)->push(item);
					exists = true;
				}
			}
			if (!exists) out<<"ERROR: This name does not exist!\n";
		}
	}
	
	if (s=="pop"){
		in.get();
		char type;
		type = in.get();
		string title;
		in >> title;
		title = type+title;
		out << "PROCESSING COMMAND: " << s << " " << title << "\n";
		
		if (type == 'i'){
			list<SimpleList<int>*>::iterator it;
			bool exists = false;
			for ( it=listSLi.begin() ; it != listSLi.end(); it++ ){
				if ((*it)->print_name() == title){
					if ((*it)->empty()) out<<"ERROR: This list is empty!\n";
					if (!(*it)->empty()) out<<"Value popped: " << (*it)->pop() << "\n";
					exists = true;
				}
			}
			if (!exists) out<<"ERROR: This name does not exist!\n";			
		}

		if (type == 'd'){
			list<SimpleList<double>*>::iterator it;
			bool exists = false;
			for ( it=listSLd.begin() ; it != listSLd.end(); it++ ){
				if ((*it)->print_name() == title){
					if ((*it)->empty()) out<<"ERROR: This list is empty!\n";
					if (!(*it)->empty()) out << "Value popped: " << (*it)->pop() << "\n";
					exists = true;
				}
			}
			if (!exists) out<<"ERROR: This name does not exist!\n";			
		}

		if (type == 's'){
			list<SimpleList<string>*>::iterator it;
			bool exists = false;
			for ( it=listSLs.begin() ; it != listSLs.end(); it++ ){
				if ((*it)->print_name() == title){
					if ((*it)->empty()) out<<"ERROR: This list is empty!\n";
					if (!(*it)->empty()) out << "Value popped: " << (*it)->pop() << "\n";
					exists = true;
				}
			}
			if (!exists) out<<"ERROR: This name does not exist!\n";			
		}			
	}
	}//end while loop for file input
}//end main