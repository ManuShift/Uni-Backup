#include <iostream>
#include <fstream>
#include <vector>
#include <sstream>
#include <string>
#include <cstring>
#include "InterpolationSearch.h"

using namespace std;

/**
 * Loads the CSV file filename and reads the list of names and whether they are naughty or nice.
 *
 * @param filename path to input file
 * @param naughtyOrNiceNames referenced string vector to store the names listed in filename
 * @param naughtyOrNiceStatus referenced bool vector to store whether a child is nice (true) or naughty (false)
 * @return number of names listed in filename
 */
int loadNaughtyOrNiceList(string filename, vector<string>& naughtyOrNiceNames, vector<bool>& naughtyOrNiceStatus)
{
	// Open input file
	fstream naughtyOrNiceFile;
	naughtyOrNiceFile.open(filename, ios::in);
	// Variable to track number of lines
	int numberOfEntries = 0;
	if (naughtyOrNiceFile.is_open())
	{
		// read file line by line
		string entry;
		while (getline(naughtyOrNiceFile, entry))
		{
			// create a reader for the line
			istringstream entryStream(entry);
			std::string name;
			std::string naughtyOrNice;
			// read only up to tab (separates name from naughtyOrNice) to read the name
			getline(entryStream, name, '\t');
			// read naughty or nice
			entryStream >> naughtyOrNice;
			// store in vectors
			naughtyOrNiceNames.push_back(name);
			if (naughtyOrNice == "NAUGHTY")
			{
				naughtyOrNiceStatus.push_back(false);
			}
			else
			{
				naughtyOrNiceStatus.push_back(true);
			}
			// count the entry
			numberOfEntries++;
		}
		// close the file
		naughtyOrNiceFile.close();
	}
	return numberOfEntries;
}

/**
 * Saves the names in naughtyOrNiceNames and the information whether the corresponding child is
 * nice (true) or naughty(false) in naughtyOrNiceStatus to a CSV file at filename
 *
 * @param filename path to output file
 * @param naughtyOrNiceNames referenced string vector that stores the names to be listed in filename
 * @param naughtyOrNiceStatus referenced bool vector that stores whether a child is nice (true) or naughty (false)
 * @param listLength length of the list
 */
void saveNaughtyOrNiceList(string filename, vector<string>& naughtyOrNiceNames, vector<bool>& naughtyOrNiceStatus, int listLength)
{
	// Create and open output file
	fstream naughtyOrNiceFile;
	naughtyOrNiceFile.open(filename, ios::out);
	if (naughtyOrNiceFile.is_open())
	{
		// Write each entry to file
		for (int i = 0; i < listLength; i++)
		{
			naughtyOrNiceFile << naughtyOrNiceNames[i];
			if (naughtyOrNiceStatus[i])
			{
				naughtyOrNiceFile << "\tNICE\n";
			}
			else
			{
				naughtyOrNiceFile << "\tNAUGHTY\n";
			}
		}
		naughtyOrNiceFile.close();
	}
}

int main (int argc, char** argv)
{
	// create vectors for storing the list
	vector<string> naughtyOrNiceNames;
	vector<bool> naughtyOrNiceStatus;
	// input and output paths - might need adjustment
	string inFileName = "list.csv";
	string outFileName = "new_list.csv";
	// open the file
	int listLength = loadNaughtyOrNiceList(inFileName,naughtyOrNiceNames,naughtyOrNiceStatus);
	// child to search and status to set for this child
	string naughtyChild = "Benjamin Coban";
	bool newStatus = false;
	// if arguments are handed over, argument 1 is the name of the child and argument 2 is NAUGHTY or NICE
	if (argc > 3)
	{
		cout << "USAGE: " << argv[0] << " [OPT1: Name, default: Benjamin Coban] [OPT2: NAUGHTY or NICE, default: NAUGHTY]" << endl;
		return 2;
	}
	if (argc > 1)
	{
		naughtyChild = argv[1];
	}
	if (argc > 2)
	{
		if (strcmp(argv[2],"NICE") == 0)
		{
			newStatus = true;
		}
		else
		{
			if (strcmp(argv[2],"NAUGHTY") != 0)
			{
				cout << "USAGE: " << argv[0] << " [OPT1: Name, default: Benjamin Coban] [OPT2: NAUGHTY or NICE, default: NAUGHTY]" << endl;
				return 2;
			}
		}
	}
	// find the id of naughtyChild in the vectors
	int id = interpolationSearch(naughtyChild, naughtyOrNiceNames, listLength);
	// if the child is not part of the list, id = -1
	if (id < 0)
	{
		cout << naughtyChild << " steht nicht auf der Liste!" << endl;
		return 1;
	}
	// set new status and save
	naughtyOrNiceStatus[id] = newStatus;
	saveNaughtyOrNiceList(outFileName, naughtyOrNiceNames, naughtyOrNiceStatus, listLength);
	// tell the user we were successful
	cout << "Status von " << naughtyChild << " erfolgreich auf " << (newStatus ? "NICE" : "NAUGHTY") << " gesetzt!" << endl;
	// Uncomment the following block to test if all names are found correctly.
	/*for (int i =0; i < listLength; i++)
	{
		if (interpolationSearch(naughtyOrNiceNames[i],naughtyOrNiceNames,listLength) != i)
		{
			cout << "Error at " << i << ": Result is " << interpolationSearch(naughtyOrNiceNames[i],naughtyOrNiceNames,listLength) << endl;
			return -1;
		}
		else
		{
			cout << i << " done!" << endl;
		}
	}*/
	return 0;
}
