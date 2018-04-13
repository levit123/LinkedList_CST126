#include"song.h"

//CTORs and DTOR
song::song()
{
	m_name = "\0";
	m_artist = "\0";
	//cout << "Song default CTOR called" << endl;
}

song::song(string name, string artist)
{
	m_name = name;
	m_artist = artist;
	//cout << "Song CTOR called" << endl;
}

song::~song()
{
	//cout << "Song DTOR called" << endl;
}

//getter functions
string & song::GetName()
{
	return m_name;
}

string & song::GetArtist()
{
	return m_artist;
}

//setter functions
void song::SetName(string buffer)
{
	m_name = buffer;
}

void song::SetArtist(string buffer)
{
	m_artist = buffer;
}