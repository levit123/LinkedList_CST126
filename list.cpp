#include"list.h"

//CTOR and DTOR
list::list()
{
	head = nullptr;
	//cout << "List CTOR called" << endl;
}

list::~list()
{
	//cout << "List DTOR called" << endl;
}

//insert node at head of list
void list::prepend(node * nn)
{
	nn->SetNext(head);
	head = nn;
}

//insert node at end of list
void list::append(node * nn)
{
	if (head == nullptr)
	{
		head = nn;
	}
	else
	{
		node * travel = head;

		while (travel->GetNext() != nullptr)
		{
			//moves to the next node in the list
			travel = travel->GetNext();
		}

		travel->SetNext(nn);
	}
}

//Insert a node into the linked list at a specific point
void list::InsertOrdered(node * nn)
{
	node * travel = nullptr;
	node * trail = nullptr;

	//If list is empty or new nodes key is less than or equal to heads key (song name)
	if (head == nullptr || nn->GetSong().GetName() <= head->GetSong().GetName())
	{
		nn->SetNext(head);
		head = nn;
	}
	//otherwise...
	else
	{
		travel = head;
		trail = nullptr;

		while (travel != nullptr && travel->GetSong().GetName() < nn->GetSong().GetName())
		{
			trail = travel;
			//moves to the next node in the list
			travel = travel->GetNext();
		}

		trail->SetNext(nn);
		nn->SetNext(travel);
	}
}

//Deletes the node at a specific position
void list::DeleteNode(string title)
{
	node * travel = nullptr;
	node * trail = nullptr;

	//if list is empty...
	if (head == nullptr)
	{
		cout << "Error! List is empty\n" << endl;
	}
	//or if the song name of the head of the list is equal to the searched song name...
	else if (head->GetSong().GetName() == title)
	{
		trail = head;
		//moves to the next node in the list
		head = head->GetNext();
		delete trail;
	}
	//otherwise...
	else
	{
		travel = head;

		while (travel != nullptr && travel->GetSong().GetName() != title)
		{
			trail = travel;
			//moves to the next node in the list
			travel = travel->GetNext();
		}

		if (travel == nullptr)
		{
			cout << "Song title not found" << endl;
		}
		else
		{
			trail->SetNext(travel->GetNext());
			delete travel;
		}
	}
}

//Deletes every element of the linked list
void list::Purge()
{
	/*
	While head is not null
		trail = head
		head = head’s next pointer
		deallocate trail
	End Loop
	*/
	node * trail = nullptr;

	while (head != nullptr)
	{
		trail = head;
		//moves to the next node in the list
		head = head->GetNext();
		
		delete trail;
	}
}

//returns the head of the list
node * list::GetNode()
{
	return head;
}

//Displays all of the nodes in the list
void list::display()
{
	node * travel = head;

	while (travel != nullptr)
	{
		cout << "Song Title: " << travel->GetSong().GetName() << "\nSong Artist: " << travel->GetSong().GetArtist() << "\n" << endl;
		//moves to the next node in the list
		travel = travel->GetNext();
	}
}