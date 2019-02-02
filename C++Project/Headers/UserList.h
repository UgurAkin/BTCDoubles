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


#ifndef __USER_LIST
#define __USER_LIST

#include <vector>
#include <memory>
#include "User.h"

class UserList : public vector<User*>
{	
	typedef vector<User*> base;
	static const char DELIM = ',';
		
	public:

	enum class WR_FORMAT {
		PLAIN,
		CSV
	};

	UserList();
	UserList(const std::vector<User*> &);

	void orderByAscending(User::PROPERTIES);
	void orderByDescending(User::PROPERTIES );
	bool save(const string&, const WR_FORMAT format = WR_FORMAT::CSV);

	static std::unique_ptr<UserList> loadFromFile(const std::string& );
	static bool writeToFile(const std::string&, const UserList&, const WR_FORMAT format = WR_FORMAT::CSV);
	
	std::string toString() const;
	std::string toCSV() const;
	friend ostream& operator<< (ostream&, const UserList& );
	

	//TODO: hide constructors to avoid raw pointers (?).
	static std::unique_ptr<UserList> make (const std::vector<std::string>& );
};



#endif //__USER_LIST
