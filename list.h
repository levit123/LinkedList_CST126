#include"node.h"

class list
{
public:
	//CTOR and DTOR
	list();
	~list();

	//The functions for inserting and deleting nodes
	void prepend(node * nn);
	void append(node * nn);
	void InsertOrdered(node * nn);
	void DeleteNode(string title);
	void Purge();

	//Getter function
	node * GetNode();

	//Function for displaying nodes
	void display();
private:
	node * head;
};