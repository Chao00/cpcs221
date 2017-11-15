#include "linkedlist.h"
  // helper function for deep copy
  // Used by copy constructor and operator=
  // should create new Kebab objects
  void LinkedList::copyList(const LinkedList& ll){

  	Node* l = ll.front->next;
  	Node* n = new Node(ll.front->data);

  	front = n;
  	while(l){
  		n ->next = new Node(l->data);
  		l = l->next;
  		n = n->next;
  		n->next=NULL;
  	}
  	back = n;
  	length=ll.length;
  }
 // helper function for deep delete
  // Used by destructor and copy/assignment
  // Deallocates Nodes and the Kebabs inside
  void LinkedList::deleteList(){
  	Node* p = front;
  	Node* temp;
  	//Kebab* k;
  	while(p)
  	{
  		 temp = p;
  		temp->data=NULL;
  		p=p->next;
  		delete temp;
  		temp = NULL;
  	}
  	length=0;

  }
  // default constructor
 LinkedList:: LinkedList(){
 	length=0;
 	front=NULL;
 	back=NULL;
 }
   // copy constructor, performs deep copy of list elements
   LinkedList:: LinkedList(const LinkedList& ll){

   	copyList(ll);
   }
     // destructor
    LinkedList::  ~LinkedList(){
    	deleteList();
    }
    // MUTATORS

  // Inserts an item at the front of the list
  // POST:  List contains item at position 0
  // PARAM: item = item to be inserted
  void   LinkedList::insertFront(Kebab* item){
  	Node* p = new Node(item);
  	if(front==NULL){
  		front=p;
  		back=p;
  		length++;
  	}else{
  	p->next = front;
  	front = p;
  	length++;	
  	}
  	
  }
    // Inserts an item at the back of the list
  // POST:  List contains item at back
  // PARAM: item = item to be inserted
  void LinkedList::insertBack(Kebab* item){
  	Node* temp = new Node(item);
  	if(front==NULL){
  		front = temp;
  		back = temp;
  		length++;
  	}else{
  		back->next = temp;
  		back = temp;
  		length++;
  	}
  	
  }
    // Inserts an item in position p (0-indexed)
  // Returns false for invalid index
  // PRE:   0 <= p <= size
  // POST:  List contains item at position p
  // PARAM: item = item to be inserted, p = position where item will be inserted
  bool LinkedList::insertAt(Kebab* item, unsigned int p){
  	if(p>=0&&p<=size()){
  		if (p==0){
  		insertFront(item);
  		}
  		else if(p==size()){
  			insertBack(item);
  		}
  			else{
  			unsigned int count =1;
  			Node* n = new Node(item);
  			Node* c= front;
  			while(count!=p){
  				c = c->next;
  				count++;

  			}
  			n->next=c->next;
  			c->next=n;
  			length++;
  		}
  		
  	}
  	return false;
  }
    // Removes and returns an item from position p (0-indexed)
  // Return NULL if index is invalid
  // PRE:   0 <= p < size
  // POST:  Item is removed from list.
  //        Node is deallocated but Kebab should in memory
  //        Thus set data to NULL before deleting
  // PARAM: p = position from where item will be removed
  Kebab* LinkedList::removeAt(unsigned int p){
  	if(p>=0&&p<size()){
  		Node* temp = front;
  	                Node* prev;
  		if(p==0){
  		front = temp->next;
  	
  		Kebab* k = temp->data;
  		temp->data=NULL;
  		delete temp;
  		length--;
  		return k;
  		}
  		else if(p==size()-1){
  			while(temp->next!=NULL){
  				prev=temp;
  				temp=temp->next;
  			}
  			Kebab* k = temp->data;
  			prev->next=NULL;
  			back=prev;
  			temp->data = NULL;
  			delete temp;
  		 length--;
  		 return k;
  		}
  		else{
  			for (unsigned int i = 1; i !=p+1; i++)
  		{
  			prev = temp;
  			temp = temp->next;
  		}
  		prev->next = temp->next;
  		Kebab* k = temp->data;
  		temp->data = NULL;
  		delete temp;
  		length--;
  		return k;
  		}
  	}
  	return NULL;
  }
    // ACCESSORS

  // Returns size of list
  unsigned int LinkedList::size() const{
  	return length;
  }

  // Returns whether the list is empty
  bool LinkedList::isEmpty() const{
  	if (length==0)
  	{
  		return true;
  	}return false;
  }
    // Returns existence of a Kebab that has at least
  //   all the same ingredients as k, in any order
  //   i.e. the list has a Kebab whose ingredients
  //   are a super-multiset of k's ingredients
  bool LinkedList::contains(Kebab& k) const{
  	Node* temp = front;
  	for (unsigned int i = 0; i < size(); ++i)
  	{
  		if(temp->data->hasSameIngredients(k)){
  			return true;
  		}
  		temp = temp->next;
  	}
  	return false;
  }
    // Returns item at index (0-indexed)
  // Returns NULL if index is invalid
  //stub
  Kebab* LinkedList::elementAt(unsigned int p) const{
  	if(p>=0&&p<size()){
  	Node* temp = front;
  	//Node* prev;
  	if(p==0){
  		return front->data;
  	}if(p==size()-1){
  		return back->data;
  	}
  	else{
  		 for (unsigned int i = 1; i !=p+1; i++)
  		{
  			//prev = temp;
  			temp = temp->next;
  		}
  		return temp->data;
  	}

  	}
  	return NULL;
  }
    // OVERLOADED OPERATORS

  // overloaded assignment operator
  // must work in the following cases:
  // list2 = list1 -> general case
  // list2 = list2 -> should do nothing
  LinkedList&  LinkedList::operator=(const LinkedList& ll){
  	if(this!=&ll){
  		deleteList();
  		copyList(ll);
  		return *this;
  	}
  }
 
