// INFO450PIG.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#include <iostream>
#include <string>

using namespace std;


int translateToPigLatin(string tobeTranslated)					//create function
{
	char translatedString[50];
	int newstrIndex = 0;
	int cutoff;
	int oldstrIndex = 0;							//create variables

	if (tobeTranslated.length() >= 47)
	{
		cout << "Too Long." << endl;
		return -1;
	}									//check if length >47 and terminate if so
	if (tobeTranslated.length() <= 2)
	{
		cout << tobeTranslated << endl;
		return 0;
	}
	// check if length <= 2 and echo if so

	for (oldstrIndex = 0; oldstrIndex != tobeTranslated.length(); oldstrIndex++)
	{										//iterate through characters of the string


		if (tobeTranslated[oldstrIndex] == 'a' || tobeTranslated[oldstrIndex] == 'e' || tobeTranslated[oldstrIndex] == 'i' ||
			tobeTranslated[oldstrIndex] == 'o' || tobeTranslated[oldstrIndex] == 'u')
		{											// check if character is a vowel
			cutoff = oldstrIndex;
			for (oldstrIndex; oldstrIndex != tobeTranslated.length(); oldstrIndex++) {
				translatedString[newstrIndex] = tobeTranslated[oldstrIndex];
				newstrIndex++;
			}										//make that character the starting point of new word
			for (oldstrIndex = 0; oldstrIndex < cutoff; oldstrIndex++)
			{
				translatedString[newstrIndex] = tobeTranslated[oldstrIndex];
				newstrIndex++;
			}										//add letters from original character that were skipped
			break;
		}

	}

	translatedString[newstrIndex] = 'a';
	newstrIndex++;
	translatedString[newstrIndex] = 'y';								//add the pig latin "ay"

	for (oldstrIndex = 0; oldstrIndex != tobeTranslated.length() + 2; oldstrIndex++)
	{
		cout << translatedString[oldstrIndex];
	}											//print word plus the "ay"

	cout << endl;
	return 0;
}
												//simply "cout << translatedString" sometimes gave
												//rediculous output so complicated cout method needed



int main()
{
	bool program = true;
	string beforeString;
	int tooLong = 47;
	
	while (program == true)										//program loop
	{
		
		cout << "Please enter a word to translate into Pig Latin, or quit to end the program." << endl;
		getline(cin,beforeString);

	
		if (isdigit(beforeString[0]))
		{																				
			cout << "Please do not enter a number." << endl;
			continue;
		}
													// checks if first character is a number, restarts if so

		if (beforeString == "and" || beforeString == "but" || beforeString == "for" || beforeString == "nor"
			|| beforeString == "so" || beforeString == "yet" || beforeString == "or")
		{
			cout << beforeString << endl;
			continue;									//checks if input is an	article, echos if so
		}
		if (beforeString == "a" || beforeString == "an" || beforeString == "the")
		{
			cout << beforeString << endl; 
			continue;
		}											//checks if input is a conjunction, echos if so
		if (beforeString == "quit")
		{
			program = false
		}											//checks if users wants to quit
		else
		{
			translateToPigLatin(beforeString);						//run function on input
		}
	}
}






