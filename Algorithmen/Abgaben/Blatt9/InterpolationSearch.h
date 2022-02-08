#include<string>
#include<vector>

using namespace std;

/**
 * Applies interpolation search to find the id of item in list  
 *
 * @param item the string to be searched inside the list
 * @param list a vector of strings that may contain item
 * @param listLength length of the list
 * @return the id of item inside list if it is contained in list, -1 otherwise
 */
int interpolationSearch(string item, vector<string> list, int listLength);
/**
 * If a lexicographically precedes b which in turn lexicographically precedes c, approximate the value (b-a)/(c-a).
 * More precisely: if all of a,b,c differ at same index i first, return (b[i]-a[i])/(c[i]-a[i]), otherwise
 * return 0 if c[i] differs from a[i]=b[i] at some index i or 1 if a[i] differs from b[i]=c[i]  
 * Otherwise return -1
 *
 * @param a a string
 * @param b a string
 * @param c a string
 * @return approximation of (b-a)/(c-a) if a < b < c, otherwise -1
 */
double stringQuotient(string a, string b, string c);
