
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
