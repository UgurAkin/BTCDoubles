/*
 * Tuesday Competitive Doubles Project
 * 
 * Desc: Automation of managing, maintaining and displaying
 * 		 documents related to Tuesday Doubles at Burnaby Tennis Club
 * 
 * Author: Ugur Akin
 * Date: Wednesday, 17 January 2019
 * 
 */


#include <iostream>
#include <string>
#include <fstream>
#include "UserList.h"
#include "User.h"



int main(int argc, char const *argv[])
{	
	auto filePath = "TextFiles/Users.csv";

	auto users = UserList::loadFromFile(filePath);

	std::cout << "No order: " << std::endl;
	for(auto user : *users){
		std::cout << *user << std::endl;
	}
	std::cout << std::endl;

	std::cout << "Order by first name: " << std::endl;
	users->orderByAscending(User::PROPERTIES::FIRST);
	for(auto user : *users){
		std::cout << *user << std::endl;
	}
	std::cout << std::endl;

	std::cout << "Order by last name: " << std::endl;
	users->orderByAscending(User::PROPERTIES::LAST);
	for(auto user : *users){
		std::cout << *user << std::endl;
	}
	std::cout << std::endl;

	std::cout << "Order by rank: " << std::endl;
	users->orderByAscending(User::PROPERTIES::RANK);
	for(auto user : *users){
		std::cout << *user << std::endl;
	}
	std::cout << std::endl;

	delete users;
	return 0;
}