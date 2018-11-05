/*
 * Conversion.h
 *
 *  Created on: 16 Jan 2017
 *      Author: edwin
 */

#ifndef CONVERSION_H_
#define CONVERSION_H_

namespace Conversion
{
inline int convert(char c)
{
	int index = 0;
	for (char o : "abcdefghijklmnopqrstuvwxyz")
	{
		if (o == c)
		{
			return index;
		}
		index++;
	}
	return -1;
}
inline char convert(int i)
{
	return "abcdefghijklmnopqrstuvwxyz"[i];
}
}



#endif /* CONVERSION_H_ */
