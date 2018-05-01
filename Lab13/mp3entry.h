#ifndef __MP3_ENTRY_H__
#define __MP3_ENTRY_H__

#include "audioentry.h"
using namespace std;

class Mp3Entry: public AudioEntry {

	public:

    Mp3Entry(string s);
    virtual ~Mp3Entry();

    virtual void play();
        
};

#endif
