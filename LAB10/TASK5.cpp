#include <iostream>
#include <fstream>

int main ()
{
	//declare strs to store search and replace words
	std::string search_word, replace_word;

	//open data file in (both) read and write modes
	std::fstream data("data.txt", std::ios::in | std::ios::out);

	//do while replace word is larger than search word
	do
	{
		std::cout << "search word: ";
		std::cin >> search_word;
		std::cout << "replacement: ";
		std::cin >> replace_word;
	} while (replace_word.length() > search_word.length());

	//store lengths to avoid repeated function calls
	size_t s_wordlen = search_word.length(), r_wordlen = replace_word.length();

	//fill the difference in word length with spaces (counted now, written later)
	std::string spaces;
	if (s_wordlen != r_wordlen)
	{
		for (int i = 0; i < s_wordlen - r_wordlen; i++)
		{
			spaces += " ";
		}
	}

	//declare vars for word &
	//found flag in case word not in file
	std::string word;
	bool found = false;

	//var to account for a dot (read as part of the word by >>)
	bool dot;
	while (data >> word)
	{
		dot = false;

		//if the current word has a dot at the end, remove it (for proper comparison)
		//flip dot flag
		if (word[word.length() - 1] == '.')
		{
			word.erase(word.length() - 1, 1);
			dot = true;
		}

		//flip found flag to avoid displaying err msg later
		if (word == search_word)
		{
			if (!found)
			{
				found = true;
			}

			//offset get ptr by word length for tellg()
			data.seekg(-search_word.length(), std::ios::cur);

			//offset by an additional -1 to account for '.'
			if (dot)
				data.seekg(-1, std::ios::cur);
				
			//position write/put ptr
			//write to file
			data.seekp(data.tellg());
			data << replace_word;

			//write '.' if dot flag
			if (dot)
				data << ".";

			//account for diff in search_word and replace_word with spaces
			data << spaces;
		}
	}

	//err if word not found
	if (!found)
		std::cerr << "NO SUCH WORD" << std::endl;
}
