#include "InterpolationSearch.h"
#include <iostream>
#include <cmath>

int interpolationSearch(string item, vector<string> list, int listLength)
{
	//TODO: Hier vervollständigen
	int unten = 0;
	int oben = listLength - 1;
	while (oben > unten)
	{
		int next = floor(stringQuotient(list[unten], item, list[oben]) * (oben - unten)) + unten;
		cout << next;
		if (item == list[next])
		{
			return next;
		}
		else
		{

			listLength = oben - unten + 1;
			if (item.compare(list[next]) < 0)///////////////
			{	
				cout << "fall_1 ";
				cout << "\n";

				int i = 0;
				while (item.compare(list[next - i * sqrt(listLength)]) > 0)//////////////////list[next - (i+1) * sqrt(listLength) + 1].compare(item) >= 0 || 
				{
					i++;
				}
				cout << i;
				cout << "\n";
				oben = next - i * sqrt(listLength);
				unten = fmax(unten, next - (i + 1) * sqrt(listLength) + 1);

				cout << oben;
				cout << "\n";
				cout << unten;
				cout << "\n";
				cout << "\n";
			}
			else
			{
				cout << "fall_2 ";
				cout << "\n";

				int i = 0;
				while (list[next + i * sqrt(listLength)].compare(item) > 0 || item.compare(list[next + (i + 1) * sqrt(listLength) - 1]) > 0)//////////////////list[next + i * sqrt(listLength)].compare(item) >= 0 || 
				{
					i++;
				}
				cout << i;
				cout << "\n";

				oben = fmin(oben, next + (i + 1) * sqrt(listLength) - 1);
				unten = next + i * sqrt(listLength);

				cout << oben;
				cout << "\n";
				cout << unten;
				cout << "\n";
				cout << "\n";
			}
		}
	}

	if (oben == unten && item == list[oben])
	{
		return oben;
	}
	return -1;
}




double stringQuotient(string a, string b, string c)
{
	// Ensure that a < b < c
	if (a.compare(b) > 0 || b.compare(c) > 0)
	{
		return -1;
	}
	int i = 0;
	// Figure out maximum search length
	int maxLength = a.length();
	if (b.length() < maxLength)
	{
		maxLength = b.length();
	}
	if (c.length() < maxLength)
	{
		maxLength = c.length();
	}
	// While i smaller than shortest of a,b,c
	while (i < maxLength)
	{
		// if the strings begin to be different at i
		if (a.at(i) != c.at(i))
		{
			// if b is still the same as a return 0
			if (a.at(i) == b.at(i))
			{
				return 0;
			}
			else
			{
				// if b is still the same as c return 1
				if (b.at(i) == c.at(i))
				{
					return 1;
				}
				else
				{
					// otherwise return (b[i]-a[i])/(c[i]-a[i])
					double zaehler = b.at(i) - a.at(i);
					double nenner = c.at(i) - a.at(i);
					return zaehler / nenner;
				}
			}
		}
		i++;
	}
	// at least one string finished
	// figure out next character (if a string ended, give it value 31 which is one less than space)
	int aChar;
	int bChar;
	int cChar;
	if (maxLength == a.length())
	{
		aChar = 31;
	}
	else
	{
		aChar = a.at(maxLength);
	}
	if (maxLength == b.length())
	{
		bChar = 31;
	}
	else
	{
		bChar = b.at(maxLength);
	}
	if (maxLength == c.length())
	{
		cChar = 31;
	}
	else
	{
		cChar = c.at(maxLength);
	}
	// a[i] = b[i] -> return 0
	if (aChar == bChar)
	{
		return 0;
	}
	else
	{
		// b[i] = c[i] -> return 1
		if (bChar == cChar)
		{
			return 1;
		}
		else
		{
			// otherwise return (b[i]-a[i])/(c[i]-a[i])
			double zaehler = bChar - aChar;
			double nenner = cChar - aChar;
			return zaehler / nenner;
		}
	}
}
