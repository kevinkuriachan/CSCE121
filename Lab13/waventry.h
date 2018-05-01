#ifndef __WAV_ENTRY_H__
#define __WAV_ENTRY_H__

#include "audioentry.h"
using namespace std;

class WavEntry: public AudioEntry {

	public:

    WavEntry(string s);
    virtual ~WavEntry();

    virtual void play();
        
};

#endif
