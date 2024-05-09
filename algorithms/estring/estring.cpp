

#include <iostream>
#include <regex>
#include <string>
#include <map>
// find duplicates in an string
// 1. brute force
// 2. sorting
// 3. hashing
void findDuplicatesHash(std::string str)
{
	for (int i = 0; i < str.length(); i++)
	{
		int count = 1;
		if (str[i] != -1)
		{
			for (int j = i + 1; j < str.length(); j++)
			{
				if (str[i] == str[j])
				{
					count++;
					str[j] = -1;
				}
			}
		}
		if (count > 1)
		{
			std::cout << str[i] << " is duplicate\n";
		}
	}
}
// 4. bitwise
void findDuplicatesBitwise(std::string str)
{
	int H = 0;
	for (int i = 0; i < str.length(); i++)
	{
		int x = 1;
		x = x << (str[i] - 97);
		if ((x & H) > 0)
		{
			std::cout << str[i] << " is duplicate\n";
		}
		else
		{
			H = x | H;
		}
	}
}

// 5. counting
void findDuplicatesCounting(std::string str)
{
	int H[26] = { 0 };
	for (int i = 0; i < str.length(); i++)
	{
		H[str[i] - 97]++;
	}
	for (int i = 0; i < 26; i++)
	{
		if (H[i] > 1)
		{
			std::cout << char(i + 97) << " Show up " << H[i] << " times \n";
		}
	}
}
// 6. regex : regular expression
// 7. trie
// 8. binary search tree
// 9. self balancing binary search tree
// 10. bloom filter


int main()
{
	findDuplicatesHash("finding");
	findDuplicatesBitwise("finding");
	findDuplicatesCounting("finding");
	return 0;
}


