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
#include "UserList.h"
#include "Helpers.h"
#include <iostream>
#include <string>
#include <fstream>
#include <vector>
static const unsigned int DEFAULT_LIST_SIZE = 75;

int main(int argc, char* argv[]){
    
    std::string arg0(argv[0]);
    Path::setBasePath(arg0);
    std::string inputFileName = "RandomNames.txt";
    std::string outputFileName = "rndUsers.csv";
    std::string inputFileURI = Path::makePathToFile(Path::FOLDER::TEXTFILES, inputFileName);
    std::string outputFileURI = Path::makePathToFile(Path::FOLDER::CSVFILES, outputFileName);

    auto allNames = FileRW::readLinesInFile(inputFileURI);
    int listSize = DEFAULT_LIST_SIZE;
    if(argc >= 2){
        try{
            listSize = std::atoi(argv[1]);
        }
        catch(std::exception& e){
            throw std::invalid_argument("Invalid argument, expected size of the user list!");
        }
    }
    
    std::vector<std::string> randomNames = RandomExtensions::randomShuffle <std::string> (allNames);
    randomNames.erase(randomNames.begin() + listSize, randomNames.end());
    auto ul = UserList::make(randomNames);
    ul->orderByAscending(User::PROPERTIES::RANK);
    ul->save(outputFileURI);

}