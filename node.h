#include"song.h"

class node
{
public:
	//CTOR and DTOR
	node();
	node(song data);
	~node();

	//Getters
	song & GetSong();
	node * GetNext();
	//Setters
	void SetNext(node * nn);
	void SetSong(song data);
private:
	song m_data;
	node *m_next;
};