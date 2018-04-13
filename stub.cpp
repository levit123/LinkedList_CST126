#define _CRTDBG_MAP_ALLOC
#define _CRT_SECURE_NO_WARNINGS

#include"list.h"
#include<crtdbg.h>

void ReadData(list &music);
string SearchByName(list &music);
string SearchByArtist(list &music);
void Add(list &music);
void BatchAdd(list &music);
void Remove(list &music);
void BatchRemove(list &music);
void SaveToFile(list &music);

int main()
{
	_CrtSetDbgFlag(_CRTDBG_ALLOC_MEM_DF | _CRTDBG_LEAK_CHECK_DF);

	list music;
	int choice = 0;

	ReadData(music);

	while (choice != 9)
	{
		cout << "\nMUSIC PLAYLIST MENU\n"
			<< "=====================\n"
			<< "1: Search By Song Name\n"
			<< "2: Search By Artist\n"
			<< "3: Add\n"
			<< "4: Batch Add (read and add songs from a text file)\n"
			<< "5: Remove\n"
			<< "6: Batch Remove (read from a text file, and remove the songs listed)\n"
			<< "7: Save To Text File\n"
			<< "8: Display List\n"
			<< "9: Exit\n\n"
			<< "Enter a number for your choice: ";
		cin >> choice;
		cout << endl;

		switch (choice)
		{
		case 1:
			SearchByName(music);
			break;
		case 2:
			SearchByArtist(music);
			break;
		case 3:
			Add(music);
			break;
		case 4:
			BatchAdd(music);
			break;
		case 5:
			Remove(music);
			break;
		case 6:
			BatchRemove(music);
			break;
		case 7:
			SaveToFile(music);
			break;
		case 8:
			music.display();
			break;
		case 9:
			cout << "\nShutting down program..." << endl;
			break;
		}
	}

	music.Purge();

	return 0;
}

//Reads data from file into the music list
void ReadData(list &music)
{
	string buffer;

	ifstream file;
	file.open("SongList.txt");

	while (!file.eof())
	{
		node * nn = new node;

		//reads name from file into buffer
		getline(file, buffer, '-');

		//sets song name using setter
		nn->GetSong().SetName(buffer);

		//reads artist from file into buffer
		getline(file, buffer);

		//sets song artist using setter
		nn->GetSong().SetArtist(buffer);
		
		//insert node (append)
		music.InsertOrdered(nn);
	}
	file.close();
}

//Program searches for a user-defined song by song name
string SearchByName(list &music)
{
	node * search = music.GetNode();
	string buffer = "", NameToReturn = "";
	int index = 0;

	cout << "Enter a song name to search for: ";
	cin.clear();
	cin.ignore();
	getline(cin, buffer);

	//converts the buffer to uppercase
	for (int i = 0; i < buffer.size(); i++)
	{
		char character = toupper(buffer[i]);
		buffer[i] = character;
	}

	for (; search != nullptr; search = search->GetNext())
	{
		//copies the song name to a string and converts it to uppercase for comparison purposes
		string TestName = search->GetSong().GetName();
		//converts the buffer to uppercase
		for (int i = 0; i < TestName.size(); i++)
		{
			char character = toupper(TestName[i]);
			TestName[i] = character;
		}

		//compares TestName (which contains the name of the song but in uppercase) to buffer to see if the song is found in the list
		if (TestName == buffer)
		{
			cout << "\nNODE WAS FOUND.\nSong Name: " << search->GetSong().GetName() << "\nArtist: " << search->GetSong().GetArtist() << "\n\n";
			NameToReturn = search->GetSong().GetName();
		}
	}

	return NameToReturn;
}

//Program searches for a user-defined song by artist
string SearchByArtist(list &music)
{
	node * search = music.GetNode();
	string buffer = "", ArtistToReturn;
	int index = 0;

	cout << "Enter an artist to search for: ";
	cin.clear();
	cin.ignore();
	getline(cin, buffer);

	//converts the buffer to uppercase
	for (int i = 0; i < buffer.size(); i++)
	{
		char character = toupper(buffer[i]);
		buffer[i] = character;
	}

	for (; search != nullptr; search = search->GetNext())
	{
		//copies the song artist to a string and converts it to uppercase for comparison purposes
		string TestArtist = search->GetSong().GetArtist();
		for (int i = 0; i < TestArtist.size(); i++)
		{
			char character = toupper(TestArtist[i]);
			TestArtist[i] = character;
		}

		//compares TestArtist (which contains the artist of the song but in uppercase) to buffer to see if the song is found in the list
		if (TestArtist == buffer)
		{
			cout << "\nNODE WAS FOUND.\nSong Name: " << search->GetSong().GetName() << "\nArtist: " << search->GetSong().GetArtist() << "\n\n";
			ArtistToReturn = search->GetSong().GetArtist();
		}
	}

	return ArtistToReturn;
}

//Adds a user-defined song to the list
void Add(list &music)
{
	node * nn = new node;
	string buffer;

	//user enters a song name and it saves it to the node
	cout << "Enter a song name: ";
	cin.clear();
	cin.ignore();
	getline(cin, buffer);
	nn->GetSong().SetName(buffer);

	//user enters an artist name and it saves it to the node
	cout << "Enter an artist name: ";
	cin.clear();
	getline(cin, buffer);
	nn->GetSong().SetArtist(buffer);

	music.InsertOrdered(nn);

	//delete[] nn;
}

//Adds multiple songs from the list based on a text file
void BatchAdd(list & music)
{
	string filename, buffer;

	cout << "Enter name of text file: ";
	cin.clear();
	cin.ignore();
	getline(cin, filename);
	
	ifstream FileAdd;
	FileAdd.open(filename);
	
	if (FileAdd.fail())
	{
		cout << "File not found (be sure to include the '.txt' at the end of the filename)" << endl;
	}
	else
	{
		while (!FileAdd.eof())
		{
			node * nn = new node;

			//reads name from file into buffer
			getline(FileAdd, buffer, '-');

			//sets song name using setter
			nn->GetSong().SetName(buffer);

			//reads artist from file into buffer
			getline(FileAdd, buffer);

			//sets song artist using setter
			nn->GetSong().SetArtist(buffer);

			//insert node (append)
			music.InsertOrdered(nn);
		}
	}
	FileAdd.close();
}

//Removes a specific song by name
void Remove(list & music)
{
	string name = SearchByName(music);

	music.DeleteNode(name);
}

//Removes multiple songs from the list based on a text file
void BatchRemove(list & music)
{
	string filename, buffer;

	//user enters name of text to file with song names to remove from list
	cout << "Enter name of text file: ";
	cin.clear();
	cin.ignore();
	getline(cin, filename);

	ifstream FileRemove;
	FileRemove.open(filename);

	if (FileRemove.fail())
	{
		cout << "File not found (be sure to include the '.txt' at the end of the filename)" << endl;
	}
	else
	{
		while (!FileRemove.eof())
		{
			//reads song name from file into buffer
			getline(FileRemove, buffer, '\n');

			//deletes the song from the list
			music.DeleteNode(buffer);
		}
	}
	FileRemove.close();
}

//Saves the list back to the text file
void SaveToFile(list & music)
{
	node * travel = music.GetNode();

	ofstream file;
	file.open("SongList.txt", ofstream::trunc);

	while (travel != nullptr)
	{
		//writes list to text file
		file << travel->GetSong().GetName();
		file << "-";
		file << travel->GetSong().GetArtist();
		if (travel->GetNext() != nullptr)
		{
			file << "\n";
		}

		//moves to the next node in the list
		travel = travel->GetNext();
	}
	file.close();
}