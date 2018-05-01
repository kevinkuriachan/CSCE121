#ifndef __PLAYLIST_ENTRY_H__
#define __PLAYLIST_ENTRY_H__

#include <string>
using namespace std;

class PlaylistEntry {

	public:

    PlaylistEntry(string s);
    virtual ~PlaylistEntry();
	
	virtual void play() = 0;

	virtual string get_name();
    double get_play_length();

    protected:
        double play_length; 
        string name;

};

#endif
