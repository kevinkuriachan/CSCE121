#ifndef __PLAYLIST__
#define __PLAYLIST__

#include <vector>
#include "PlaylistEntry.h"
using namespace std;

class Playlist {

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