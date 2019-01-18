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


#include "User.h"
#include <string>
using namespace std;

User::User() : User("","") {};

User::User(string first, string last) : User(first, last, UNRANKED) {};

User::User(string first, string last, int rank){
	this->firstName = first;
	this->lastName = last;
	this->rank = rank;
}

string User::getFirstName() const{
	return this->firstName;
}

string User::getLastName() const {
	return this->lastName;
}

string User::getFullName() const {
	return this->firstName + " " + this->lastName;
}

unsigned int User::getRank() const {
	return this->rank;
}

void User::updateRank(unsigned int newRank){
	this->rank = newRank;
}

User& User::operator=(const User& other){
	this->firstName = other.firstName;
	this->lastName = other.lastName;
}

string User::toString() const{
	return std::to_string(this->rank) + ", " + getFullName();
}

string User::toCSV() const {
	return std::to_string(this->rank) + "," + this->firstName + "," + this->lastName;
}

ostream& operator<<(ostream& os, const User& user) {
	return os << user.toString();
}