/*Solution 1
Descrption- 2 pointers:	1.1 sort the given array
						1.2 declare an empty array
						1.3 declare 2 pointers(left and right); one points towards the beginning and the other points towards the end
						1.4 declare a while loop where left starts from 0 and right starts from the end of the array (l<r)
						1.5 in the loop- take a sum of the values at left and right and check if it matches the target value
							1.5.1 if yes- push them into the empty array one by one
							1.5.2 else if- if sum is lesser than target; do left++
							1.5.3 else- if sum is greater than target; do right--
						1.6 print the final array*/
#include <vector>
using namespace std;

int nonConstructibleChange(vector<int> coins) 
{
	sort(coins.begin(),coins.end());
	int changecreated=0;
	for(int i=0;i<coins.size();i++)
	{
		if(coins[i]>changecreated+1)
		{
			return changecreated+1;
		}
		changecreated+=coins[i];
	}
  // Write your code here.
  return changecreated+1;
}
