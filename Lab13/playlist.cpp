#include <iostream> 
#include <fstream> 
#include <stdlib.h>  // For exit()
#include "playlist.h"
#include "mp3entry.h"
#include "waventry.h"
using namespace std;

Playlist::Playlist(string fname)
{
    ifstream infile;

    // Open the file
    infile.open(fname, ios_base::in);
    
    if (!infile) {
        cerr << "Couldn't open '" << fname << "', for reading." << endl;
        exit(1);
    }

    string line;

    // Read in the file
    while (getline(infile, line)) {
        // We go line-by-line
        // splitting on the first space.

        size_t pos = line.find(" ");   // find the first space
        string tag = line.substr(0,pos);
        string rest = line.substr(pos);

        rest.erase(0, rest.find_first_not_of(" ")); // gobble leading white space

        // Then we use the first part, before the space, to figure out
        // what sort of entry it is

        PlaylistEntry *new_entry = NULL; 

        if (tag == "MP3")
        {
            new_entry = new Mp3Entry(rest); // Make a new entry
                                        // via the information from the line
        }
        else if (tag == "WAV")
        {
            new_entry = new WavEntry(rest); // Make a new entry
                                        // via the information from the line
        }
        else
        {
            cout << "Unknown type [" << tag << "] -- ignoring '" << rest << "'" << endl; 
        }
 
        
        if (new_entry != NULL)
            the_entries.push_back(new_entry);
            
    } 

    infile.close();

}

ostream& operator<<(ostream& os, const Playlist& pl)
{
    if (pl.the_entries.size() > 0)
    {
        int c = 0;
        for (PlaylistEntry *e : pl.the_entries) {
            os << ++c << ".)  " <<  e->get_name() << endl;
        }   
    }
    else
    {
        os << "Playlist is empty";
    }

    return os;
}

Playlist::~Playlist()
{
#ifdef DEBUG
    cout << "Playlist Destructor" << endl;
#endif

    if (the_entries.size() > 0)
    {
        cout << "We need to delete " << the_entries.size() << " play list entries" << endl;
        for(PlaylistEntry *e : the_entries) {
            delete e;        
        }   
    }


}

void Playlist::play_all(bool shuffle)
{
    if (!shuffle)
    {
        for(PlaylistEntry *e : the_entries) {
            e->play();        
        }   
    }
    else
    {
        int n = the_entries.size();
        int shuffleme[n];
        for (int i = 0; i < n; i++)
            shuffleme[i] = i; // Set up a sequential list

        for (int i = 0; i < n*n; i++)
        { // Swap around some entries.
            int j = rand() % n;
            int k = rand() % n;
            int h = shuffleme[j];
            shuffleme[j] = shuffleme[k];
            shuffleme[k] = h;
        }

        /*
            Uncomment if you want to see the order in which it'll play:
        for (int i = 0; i < n; i++)
            cout << " " << shuffleme[i] << endl;
        */

        for (int i = 0; i < n; i++)
            the_entries[shuffleme[i]]->play(); // vectors are as convenient as 
                                               // arrays!

    }
}

