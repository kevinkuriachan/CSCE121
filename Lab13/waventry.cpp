#include <iostream>
#include "waventry.h"
using namespace std;

WavEntry::WavEntry(string s) : AudioEntry(s)
{
#ifdef DEBUG
    cout << "WavEntry Constructor" << endl;
#endif

    play_length = 12.0; // Short wav file

    // Let's assume this is a media sound, like a beep
    setMusic(false);
}


WavEntry::~WavEntry()
{
#ifdef DEBUG
    cout << "WavEntry Destructor" << endl;
#endif
 
}

void WavEntry::play()
{
#ifdef DEBUG
    cout << "WavEntry play" << endl;
#endif
    cout << "Calling an external application player for .wav file..." << endl;
    cout << "\t\t(" << get_name() << ") \ablah-blah-blah! ..... " << get_play_length() << "s" << endl;
}


