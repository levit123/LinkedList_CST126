#include"node.h"

//CTORs and DTORs
node::node()
{
	m_next = nullptr;
	//cout << "Node default CTOR called" << endl;
}

node::node(song data)
{
	m_data.SetArtist(data.GetArtist());
	m_data.SetName(data.GetName());
	//cout << "Node CTOR called" << endl;
}

node::~node()
{
	//cout << "Node DTOR called" << endl;
}

//Getters
song & node::GetSong()
{
	return m_data;
}

node * node::GetNext()
{
	return m_next;
}

//setters
void node::SetNext(node * nn)
{
	m_next = nn;
}

void node::SetSong(song data)
{
	m_data = data;
}