#include <iostream>
#include "audioentry.h"
using namespace std;

AudioEntry::AudioEntry(string s) : PlaylistEntry(s)
{
#ifdef DEBUG
    cout << "AudioEntry Constructor" << endl;
#endif
    play_length = 0.0;

    is_music = false;
}

AudioEntry::~AudioEntry()
{
#ifdef DEBUG
    cout << "AudioEntry Destructor" << endl;
#endif
}


bool AudioEntry::isMusic()
{
    return is_music;
}

void AudioEntry::setMusic(bool ism)
{
    is_music = ism;
}



