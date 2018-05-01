#include <iostream>
#include "mp3entry.h"
using namespace std;

Mp3Entry::Mp3Entry(string s) : AudioEntry(s)
{
#ifdef DEBUG
    cout << "Mp3Entry Constructor" << endl;
#endif

    // We would scan the file to determine
    // the actual play length, the artist,
    // etc.

    // Here as a poor man's surrogate we put a random length:
    play_length = 120.0 + (rand() % 60); 

    // We're just going to assume that all of these are music,
    // not podcasts, for example
    setMusic(true);
}


Mp3Entry::~Mp3Entry()
{
#ifdef DEBUG
    cout << "Mp3Entry Destructor" << endl;
#endif
 
}

void Mp3Entry::play()
{
#ifdef DEBUG
    cout << "Mp3Entry play" << endl;
#endif
    cout << "In practice, we'd call an external application player for .mp3 file..." << endl;

    // Fake some output to show the behavior
    if (isMusic())
        cout << "\t(" << get_name() << ")\ttra-la-la-lah! ..... " << get_play_length() << "s" << endl;
    else
        cout << "\t(" << get_name() << ")\tblah-blah-blah! ..... " << get_play_length() << "s" << endl;

}


