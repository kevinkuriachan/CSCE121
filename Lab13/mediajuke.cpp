#include <iostream>
#include <assert.h>
#include "promptuser.h"
#include "playlist.h"
using namespace std;

int main(int argc, char **argv)
{
    if (argc != 2) {
        cout << "Usage: " << endl << argv[0] << " <playlistfile>" << endl;
        return 1;
    }

    
    Playlist pl(argv[1]);

    cout << "Here is my playlist:" << endl;
    cout << pl << endl;
     
    cout << "Now we'll play:"  << endl;
    prompt_for_pause();

    pl.play_all();

    prompt_for_pause();

    cout << "Now we'll play in random order:"  << endl;
    prompt_for_pause();
    pl.play_all(true);
    prompt_for_pause();

    return 0;
}
