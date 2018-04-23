/*********************************************************************
    A file with helper routines to get user input
 *********************************************************************/

char prompt(const char msg[], const char valid_choices[]);

int prompt_for_int(const char msg[], const int min, const int max);
void prompt_for_pause();
