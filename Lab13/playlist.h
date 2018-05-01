#ifndef __PLAYLIST_H__
#define __PLAYLIST_H__

#include <vector>
#include "playlistentry.h"
using namespace std;

class Playlist 
    // : PlaylistEntry  
    // For recursive definition
{ 

	public:

    Playlist(string fname);
    virtual ~Playlist();

    void play_all(bool shuffle = false); 

    friend ostream& operator<<(ostream& os, const Playlist& pl); // This allows us to overload
                                                                 // the stream operator

	
    private:
        vector<PlaylistEntry *> the_entries;
};

#endif
