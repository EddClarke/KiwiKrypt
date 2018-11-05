/*
 * Cipher.cpp
 *
 *  Created on: 16 Jan 2017
 *      Author: edwin
 */

#include "Vigenere.h"
#include "Conversion.h"
#include "LetterFrequency.h"
#include <fstream>
#include <iostream>
#include <string>

namespace Cipher
{
void dictionaryAttack(Cipher& c)
{
	float threshold = 35; //MAKE VARIABKE

	std::ifstream dictionary;

	dictionary.open("dictionary.txt");

	std::string line;
	while (std::getline(dictionary, line))
	{

		std::string result = c.decode(line);
		LetterFrequency lf = LetterFrequency(result);
		if (lf.difference_to_english() < threshold)
		{
			std::cout << ("[Found] " + result + " using " + line) << std::endl;
		}
	}
}

std::string Vigenere::decode(std::string key)
{
	std::string answer;
	for (int i = 0; i < text.length(); i++)
	{
		int numeric = Conversion::convert(text[i]);
		int keyval = Conversion::convert(key[i%key.length()]);
		numeric -= keyval;
		if (numeric < 0)
		{
			numeric += 26;
		}
		numeric %= 26;
		answer += Conversion::convert(numeric);
	}
	return answer;
}

std::string Vigenere::encode(std::string key)
{
	std::string answer;
	for (int i = 0; i < text.length(); i++)
	{
		int numeric = Conversion::convert(text[i]);
		int keyval = Conversion::convert(key[i % key.length()]);
		numeric += keyval;
		numeric %= 26;
		answer += Conversion::convert(numeric);
	}
	return answer;
}
void Vigenere::bruteForce()
{
	//dictionaryAttack(*this);
}
}
