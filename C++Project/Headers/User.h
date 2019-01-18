/*
 * Created on Thu Jan 17 2019
 *
 * The MIT License (MIT)
 * Copyright (c) 2019 Ugur Akin
 *
 * Permission is hereby granted, free of charge, to any person obtaining a copy of this software
 * and associated documentation files (the "Software"), to deal in the Software without restriction,
 * including without limitation the rights to use, copy, modify, merge, publish, distribute, sublicense,
 * and/or sell copies of the Software, and to permit persons to whom the Software is furnished to do so,
 * subject to the following conditions:
 *
 * The above copyright notice and this permission notice shall be included in all copies or substantial
 * portions of the Software.
 *
 * THE SOFTWARE IS PROVIDED "AS IS", WITHOUT WARRANTY OF ANY KIND, EXPRESS OR IMPLIED, INCLUDING BUT NOT LIMITED
 * TO THE WARRANTIES OF MERCHANTABILITY, FITNESS FOR A PARTICULAR PURPOSE AND NONINFRINGEMENT. IN NO EVENT SHALL
 * THE AUTHORS OR COPYRIGHT HOLDERS BE LIABLE FOR ANY CLAIM, DAMAGES OR OTHER LIABILITY, WHETHER IN AN ACTION OF CONTRACT,
 * TORT OR OTHERWISE, ARISING FROM, OUT OF OR IN CONNECTION WITH THE SOFTWARE OR THE USE OR OTHER DEALINGS IN THE SOFTWARE.
 */

#ifndef __CLUB_USER
#define __CLUB_USER

#include <iostream>
using namespace std;

class User
{

	string firstName;
	string lastName;
	unsigned int rank;

  public:
	static const unsigned int AMT_PROPERTIES = 3;
	static const unsigned int UNRANKED = 0;
	enum struct PROPERTIES {
		FIRST = 1,
		LAST = 2,
		RANK = 0
	};

	User();
	User(string, string);
	User(string, string, int);

	string getFirstName() const;
	string getLastName() const;
	string getFullName() const;

	unsigned int getRank() const;
	void updateRank(unsigned int );

	User &operator=(const User&);

	//TODO: Add formatting to toString
	string toString() const;
	string toCSV() const;
	friend ostream &operator<<(ostream&, const User&);
};

#endif //__CLUB_USER