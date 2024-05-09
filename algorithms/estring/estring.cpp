

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

// check if a string is palindrome
// what is palindrome?
// A palindrome is a word, phrase, number, or other sequence of characters that reads the same forward and backward
// For example, "radar", "madam", "level", "rotor", "civic", "deified", "reviver", "racecar", "redder", "refer", and "repaper"
bool isPalindrome(std::string str)
{
	int i = 0;
	int j = str.length() - 1;
	while (i < j)
	{
		if (str[i] != str[j])
		{
			return false;
		}
		i++;
		j--;
	}
	return true;
}
// check if a string is anagram
// what is anagram?
// An anagram is a word or phrase formed by rearranging the letters of a different word or phrase, typically using all the original letters exactly once
// For example, "listen" and "silent", "evil" and "vile", "heart" and "earth", "bad credit" and "debit card"
bool isAnagram(std::string str1, std::string str2)
{
	if (str1.length() != str2.length())
	{
		return false;
	}
	std::map<char, int> m;
	for (int i = 0; i < str1.length(); i++)
	{
		m[str1[i]]++;
	}
	for (int i = 0; i < str2.length(); i++)
	{
		m[str2[i]]--;
		if (m[str2[i]] < 0)
		{
			return false;
		}
	}
	return true;
}

// check if a string is a rotation of another string
// what is rotation?
// A string is a rotation of another string if it is obtained by rotating the original string by some distance in either direction
// For example, "waterbottle" is a rotation of "erbottlewat"
bool isRotation(std::string str1, std::string str2)
{
	if (str1.length() != str2.length())
	{
		return false;
	}
	std::string str = str1 + str1;
	return str.find(str2) != std::string::npos;
}
// check if a string permutation of another string
// what is permutation?
// A permutation is an ordered arrangement of objects. 
// For example, 3124 is one possible permutation of the digits 1, 2, 3 and 4
// For example, "abc" and "bca", "123" and "321"
bool isPermutation(std::string str1, std::string str2)
{
	if (str1.length() != str2.length())
	{
		return false;
	}
	std::map<char, int> m;
	for (int i = 0; i < str1.length(); i++)
	{
		m[str1[i]]++;
	}
	for (int i = 0; i < str2.length(); i++)
	{
		m[str2[i]]--;
		if (m[str2[i]] < 0)
		{
			return false;
		}
	}
	return true;
}



int main()
{
	findDuplicatesHash("finding");
	findDuplicatesBitwise("finding");
	findDuplicatesCounting("finding");
	isPermutation("abccd", "baccd") ? std::cout << "Permutation\n" : std::cout << "Not Permutation\n";
	return 0;
}


