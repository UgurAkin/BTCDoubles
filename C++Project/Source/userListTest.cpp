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
#include "Helpers.h"
#include "UserList.h"
#include "User.h"


int main(int argc, char const *argv[])
{	
	std::string arg0(argv[0]);
	Path::setBasePath(arg0);
	std::string fileName = "Users.csv";
	std::string fileURI = Path::makePathToFile(Path::FOLDER::CSVFILES, fileName);

	auto users = UserList::loadFromFile(fileURI);

	std::cout << "No order: " << std::endl;
	for(auto user : *users){
		std::cout << *user << std::endl;
	}
	std::cout << std::endl;

	std::cout << "Order by first name: " << std::endl;
	users->orderByAscending(User::PROPERTIES::FIRST);
	std::cout << *users << endl;

	std::cout << "Order by last name: " << std::endl;
	users->orderByAscending(User::PROPERTIES::LAST);
	std::cout << "NOTE: Saving file in ascending last name order" << endl;
	users->save(fileURI);
	std::cout << *users << endl;	

	std::cout << "Order by rank: " << std::endl;
	users->orderByAscending(User::PROPERTIES::RANK);
	for(auto user : *users){
		std::cout << *user << std::endl;
	}
	std::cout << std::endl;

	return 0;
}