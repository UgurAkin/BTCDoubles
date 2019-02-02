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

#include "UserList.h"
#include "Helpers.h"
#include "Exceptions.h"
#include <algorithm>
#include <fstream>
#include <string>


UserList::UserList() : base() {};

UserList::UserList(const std::vector<User*> &vec) : base(vec) {};


void UserList::orderByAscending(User::PROPERTIES orderProperty)
{
	bool (*comparisonFunction)(const User* , const User* );

	switch (orderProperty)
	{
	default:
	case User::PROPERTIES::FIRST:
		comparisonFunction = [](const User* a, const User* b) {
			return a->getFirstName() < b->getFirstName();
		};
		break;
	case User::PROPERTIES::LAST:
		comparisonFunction = [](const User* a, const User* b) {
			return a->getLastName() < b->getLastName();
		};
		break;
	case User::PROPERTIES::RANK:
		comparisonFunction = [](const User* a, const User* b) {
			return a->getRank() < b->getRank();
		};
		break;
	}

	std::sort(this->begin(), this->end(), comparisonFunction);
}

void UserList::orderByDescending(User::PROPERTIES orderProperty)
{
	bool (*comparisonFunction)(const User* , const User* );

	switch (orderProperty)
	{
	default:
	case User::PROPERTIES::FIRST:
		comparisonFunction = [](const User* a, const User* b) {
			return a->getFirstName() > b->getFirstName();
		};
		break;
	case User::PROPERTIES::LAST:
		comparisonFunction = [](const User* a, const User* b) {
			return a->getLastName() > b->getLastName();
		};
		break;
	case User::PROPERTIES::RANK:
		comparisonFunction = [](const User* a, const User* b) {
			return a->getRank() > b->getRank();
		};
		break;
	}

	std::sort(this->begin(), this->end(), comparisonFunction);
}

bool UserList::save(
	const std::string& fileURI, 
	const UserList::WR_FORMAT format) 
{
	return UserList::writeToFile(fileURI, *this, format);
}

std::unique_ptr<UserList> UserList::loadFromFile(const string &fileURI)
{
	auto fileContents = FileRW::readLinesInFile(fileURI);
	
	if(fileContents.empty()){
		return std::make_unique<UserList>();
	}

	auto result = std::make_unique<UserList>();
	for(int lineIndex = 0; lineIndex < fileContents.size(); lineIndex++)
	{
		auto line = fileContents[lineIndex];
		auto tokens = StringExtensions::split(DELIM, line);
		if (tokens.size() != User::AMT_PROPERTIES)
		{
			throw ReadFileException("Corrupted line in file, at line " + std::to_string(lineIndex));
		}

		auto rankIndex = static_cast<int>(User::PROPERTIES::RANK);
		auto firstIndex = static_cast<int>(User::PROPERTIES::FIRST);
		auto lastIndex = static_cast<int>(User::PROPERTIES::LAST);

		unsigned int rank = std::stoi(tokens[rankIndex]);
		string first = tokens[firstIndex];
		string last = tokens[lastIndex];

		User *newUser = new User(first, last, rank);
		result->push_back(newUser);
	}
	return result;
}

bool UserList::writeToFile(
	const std::string &fileURI, 
	const UserList &users, 
	const  UserList::WR_FORMAT format)
{

	string str = "";
	switch (format)
	{	
		case UserList::WR_FORMAT::PLAIN:
			str = users.toString();
			break;
		default:
		case UserList::WR_FORMAT::CSV:
			str = users.toCSV();
			break;
	}
	return FileRW::writeToFile(fileURI, str);	
}

std::string UserList::toString() const {
	std::string result = "";
	for(User* user : *this){
		result += user->toString() + "\n";
	}
	return result;
}

std::string UserList::toCSV() const {
	std::string result = "";
	for(User* user : *this){
		result += user->toCSV() + "\n";
	}
	return result;
}

ostream& operator<< (ostream& os, const UserList& users){
	return os << users.toString();
}

std::unique_ptr<UserList> UserList::make(const std::vector<std::string> &names){
	auto result = std::make_unique<UserList>();
	for(size_t i = 0; i < names.size(); i++)
	{
		auto fullName = StringExtensions::split(' ', names[i]);
		auto firstName = fullName[0];
		auto lastName = fullName[1];
		auto rank = i+1;
		User* user = new User(firstName, lastName, rank);
		result->push_back(user);
	}
	
	return result;
}