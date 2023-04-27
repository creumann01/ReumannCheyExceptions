//Chey Reumann
//CIS 1202.M01
//April 25, 2023

#include<iostream>
#include<string>
using namespace std;

class invalidCharacter
{

};
class invalidRange
{

};


char character(char, int);
bool validCharacter(char);

int main()
{
	char s, end, option;
	int os;
	do
	{
		cout << "Enter starting character: ";
		cin >> s;
		try
		{
			validCharacter(s);
		}
		catch (invalidCharacter)
		{
			cout << "Error: invalid character." << endl
				<< "Please enter a valid character: ";
			cin >> s;
		}
		cout << "Enter offset: ";
		cin >> os;
		try
		{
			end = character(s, os);

			cout << "Ending character is: " << end << endl;
		}
		catch (invalidRange)
		{
			cout << "ERROR: Target character is not in range!" << endl;
		}

		cout << "Would you like to go again? " << endl
			<< "Enter Y for yes and N for no: ";
		cin >> option;

	} while (option != 'N' && option != 'n');

}

char character(char start, int offset)
{
	char end;
	if (offset > 26)
	{
		throw invalidRange();
	}
	else
	end = start + offset;

	if (!isalpha(end))
	{
		throw invalidRange();
	}
	else
		return end;
}

bool validCharacter(char c)
{
	if (isalpha(c))
		return true;
	else
		throw invalidCharacter();
}

