#ifndef __AUDIO_ENTRY_H__
#define __AUDIO_ENTRY_H__

#include "playlistentry.h"
using namespace std;

class AudioEntry : public PlaylistEntry {

	public:

    AudioEntry(string s);
    virtual ~AudioEntry();

    bool isMusic();
	
    protected:
        void setMusic(bool ism);

    private:
        bool is_music;
};

#endif
