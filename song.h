#include<iostream>
#include<fstream>
#include<string>

using std::cout;
using std::cin;
using std::endl;
using std::string;
using std::ifstream;
using std::ofstream;

class song
{
public:
	//CTORs and DTOR
	song();
	song(string name, string artist);
	~song();
	//Getters
	string & GetArtist();
	string & GetName();
	//Setters
	void SetName(string buffer);
	void SetArtist(string buffer);
private:
	string m_name;
	string m_artist;
};