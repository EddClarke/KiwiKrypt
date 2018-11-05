/*
 * Cipher.h
 *
 *  Created on: 16 Jan 2017
 *      Author: edwin
 */

#include <string>
namespace Cipher
{
class Cipher
{
public:
	std::string text;

	Cipher (std::string t) {this->text = t;}

	virtual std::string encode(std::string key){return "";}
	virtual std::string decode(std::string key){return "";}

	virtual void bruteForce();
};

}
