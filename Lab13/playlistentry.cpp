#include <iostream>
#include "playlistentry.h"
using namespace std;


PlaylistEntry::PlaylistEntry(string s)
{
#ifdef DEBUG
    cout << "PlaylistEntry Constructor" << endl;
#endif
    
    play_length = 0.0;

    name = s; 
}

PlaylistEntry::~PlaylistEntry()
{
#ifdef DEBUG
    cout << "PlaylistEntry Destructor" << endl;
#endif
}

string PlaylistEntry::get_name()
{
    return name;
}

double PlaylistEntry::get_play_length()
{
    return play_length;
}

