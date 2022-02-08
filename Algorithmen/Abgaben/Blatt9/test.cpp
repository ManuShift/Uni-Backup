int interpolationSearch(string item, vector<string> list, int listLength)
{
	int unten = 0;
	int oben = listLength - 1;
	while (oben > unten)
	{
		int next = floor(stringQuotient(list[unten], item, list[oben]) * (oben - unten)) + unten;
		if (item == list[next])
		{
			return next;
		}
		else
		{
			cout << "hallo";
			listLength = oben - unten + 1;
			if (item.compare(list[next]) < 0)///////////////
			{
				int i = 1;
				while (item.compare(list[next + (i - 1) * sqrt(listLength)]) > 0)//////////////////
				{
					i++;
				}
				oben = next - i * sqrt(listLength);
				unten = fmax(unten, next - (i + 1) * sqrt(listLength) + 1);
			}
			else
			{
				int i = 1;
				while (item.compare(list[next + i * sqrt(listLength) - 1]) > 0)//////////////////
				{
					i++;
				}
				oben = fmin(oben, next + (i + 1) * sqrt(listLength) - 1);
				unten = next + i * sqrt(listLength);
			}
		}
	}

	if (oben == unten && item == list[oben])
	{
		return oben;
	}
	return -1;
}
