/* Basic HTML validator. Ok, a really, really basic one. */
#include <iostream>
#include <fstream>
#include <string>
#include <assert.h>
#include "stack.h"

int main(int argc, char *argv[])
{
    stack_t *tag_stack = NULL; 

    if (argc != 2)
    {
        cerr << "Usage: " << argv[0] << " <input.html>" << endl;
        return 1;
    }


    tag_stack = create_stack();

    ifstream infile;

    // Open the file
    infile.open(argv[1], ios_base::in);
    
    if (!infile) {
        cerr << "Couldn't open '" << argv[1] << "', for reading." << endl;
        //exit(1);
        return 1;
    }

    bool document_valid = true;
    string error_msg;

    int line_count = 0;
    string line;
    size_t pos;

    // Read in the file
    while (getline(infile, line)) {
        //cout << "Line #" << line_count << " '" << line << "'" << endl;
        // Process line:
        line_count++;

        bool finished_line = false;
        size_t pos, last_pos = 0;

        while (!finished_line)
        {
            pos = line.find('<', last_pos);
            if (pos != string::npos) {
                // found opening, now find closing
                size_t pos2 = line.find('>', pos);
                if (pos2 != string::npos)
                {
                    string tag = line.substr(pos, pos2 - pos + 1);
                    
                    //cout << "Got tag '" << tag << "'" << endl;

                    if (tag[1] != '/') 
                    { // Opening tag
                        push_on_stack(tag_stack, tag);
                    }
                    else
                    { // Closing tag
                        if (is_empty_stack(tag_stack))
                        {
                            error_msg = "Line #"+to_string(line_count)+": closing tag '" + tag + "' without opening one";
                            document_valid = false; // No closing!
				break;
                        }
                        else
                        {
                            string top = pop_off_stack(tag_stack); 

                            //cout << "Popped tag '" << top << "'" << endl;
                            string l = top.substr(1,top.size()-2);
                            //cout << "Popped trimmed to '" << l << "'" << endl;
                            string r = tag.substr(2,tag.size()-3);
                            //cout << "Compare with '" << r << "'" << endl;

                            if (r != l)
                            {
                                error_msg = "Line #"+to_string(line_count)+": '" + top + "' doesn't make sense with '" + tag + "'";
                                document_valid = false; // No closing!
				break;
                            }

                        }
                    }


                    last_pos += pos2 + 1; // Move past this character
                }
                else
                {
                    last_pos += line.size();
                    error_msg = "Line #"+to_string(line_count)+": no closing >";
                    document_valid = false; // No closing!
		    break;
                }
            }
            else
            {
                // Check that there are no closing > without opening ones.
                pos = line.find('>', last_pos);

                if (pos != string::npos)
                {
                    finished_line = true;
                    error_msg = "Line #"+to_string(line_count)+": has closing > without opening <";
                    document_valid = false; // No closing!
		    break;
                }
                else
                    finished_line = true;
            }
        }

        if (!document_valid) break; // May as well quit now.


    }

    infile.close();


    // Are there any reminants on the stack?
    if ((document_valid) && (!is_empty_stack(tag_stack)))
    {
        error_msg = "Unclosed tags";

        while (!is_empty_stack(tag_stack))
            error_msg += " '" + pop_off_stack(tag_stack) + "'";

        error_msg += " remain on the stack";
        document_valid = false; // No closing!
    }

    if (document_valid)
    {
        cout << "File '" << argv[1] << "' passed my basic santity checks for valid HTML." << endl;
    }
    else
    {
        cout << "File '" << argv[1] << "' is not valid HTML." << endl;
        cout << error_msg << endl;
    }


    destroy_stack(tag_stack);

    return 0;
}

