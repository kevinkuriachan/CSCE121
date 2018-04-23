	cout << "--------------------------" << endl;
	cout << "      Ordering System     " << endl;
	cout << "--------------------------" << endl;
	cout << "Options: " << endl;
	cout << "\t'N' - Create new order" << endl;
	cout << "\t'S' - Show order queue" << endl;
	cout << "\t'F' - Complete first order" << endl;
	cout << "\t'P' - Show phone orders" << endl;
	cout << "\t'D' - Show delivery queue" << endl;
	cout << "\t'U' - Complete first delivery" << endl;
	cout << "\t'C' - Clear order queue" << endl;
	cout << "\t'Q' - Quit" << endl;

	
bool charInArray(char c, const char s[]) 
{ // assumes string is null terminated
	int i = 0;
	while (s[i] != '\0')
	{
		if (c == s[i++]) return true;
	}
	return false; 
}

char prompt(const char msg[], const char validChoices[])
{
	char input;
	if (validChoices[0] == '\0') return '\0';
	cout << msg << " ";
	while (true)
	{
		cout << "[";
		int i = 0;
		while (validChoices[i] != '\0')
		{
			cout << upcase(validChoices[i]);
			if (validChoices[i+1] != '\0') cout << "/";
			i++;
		}
		cout << "] ";
		cin >> input;
		if (charInArray(upcase(input), validChoices)) return upcase(input);
	}

}