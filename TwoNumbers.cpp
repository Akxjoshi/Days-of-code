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

vector<int> twoNumberSum(vector<int> array, int targetSum) 
{
	sort(array.begin(),array.end()); //time complexity- O(nlogn), space complexity- O(1)
	vector<int> a;
	int left=0,right=array.size();
	while(left<right)
	{
		if(array[left]+array[right]==targetSum)
		{
			a.push_back(array[left]);
			a.push_back(array[right]);
		}
		else if(array[left]+array[right]<targetSum)
		{
			left++;
		}
		else if(array[left]+array[right]>targetSum)
		{
			right--;
		}
	}
  return a;
}
/*Solution 2
Descrption- hashing:    2.1 initalise an empty unordered set (this has lesser time complexity than ordered ones)
					    2.2 declare an empty array
						2.3 run a "for" loop within the given array
						2.4 instead of finding sum and comparing, we will take the first value in the array via the loop and 
							subtract it from the target value and check whether the subtracted value is present in the set
							2.4.1 if yes- return the value taken via the loop and the subtracted value
							2.4.2 if not- insert this into the set
						2.5 print the final array
QUESTIONS- why use a set in solution 2? It traverses through the empty set in the first time, and what if it misses the correct answer in that?*/
#include <vector>
using namespace std;

vector<int> twoNumberSum(vector<int> array, int targetSum) 
{
	unordered_set<int> a;
	vector<int> b;
	for(int i=0;i<array.size();i++)
	{
		int temp=targetSum-array[i];
		if(a.find(temp)!=a.end())
		{
			b.push_back(temp);
			b.push_back(array[i]);
			//return vector<int>{temp,array[i]};
		}
		else
		{
			a.insert(array[i]);
		}
	}
  return b;
}
/*Solution 3
Descrption- brute force:	3.1 declare an empty array
							3.2 run a for loop from the start to 1 less than the actual size of the array
							3.3 run another for loop within which starts from one step ahead from the outer for loop and ends at the actual size of the array
							3.4 now keep on checking if the sum of values at both indexes matches the target value
								3.4.1 if yes- push both values at respective indexes into the empty array
								3.4.2 if not- let the loop keep on running
							3.5 print the final array*/
#include <vector>
using namespace std;

vector<int> twoNumberSum(vector<int> array, int targetSum) 
{
	vector<int> a;
	for(int i=0;i<array.size()-1;i++)
	{
		for(int j=i+1;j<array.size();j++)
		{
			if(array[i]+array[j]==targetSum)
			{
				a.push_back(array[i]);
				a.push_back(array[j]);
			}
		}
	}
  return a;
}
