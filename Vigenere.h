/*
 * Vigenere.h
 *
 *  Created on: 26 Jan 2017
 *      Author: edwin
 */

#ifndef VIGENERE_H_
#define VIGENERE_H_

#include "Cipher.h"

namespace Cipher {

class Vigenere : public Cipher
{
public:
	Vigenere(std::string t) : Cipher(t){}

	std::string encode(std::string key);
	std::string decode(std::string key);

	void bruteForce();
};

#endif /* VIGENERE_H_ */
