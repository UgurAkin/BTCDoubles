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
#include <memory>

static const int SIM_MIN_AMT_USERS = 32;
static const int SIM_MAX_AMT_USERS = 50;

//WARNING: Decent spaghetthi ahead !

int main(int argc, char* argv[]){
    
    std::string arg0(argv[0]);
    std::string base = FileRW::getBasePath(arg0);
    std::string usersFileURI = base +  "/../../TextFiles/rndUsers.csv";

    auto allUsers = UserList::loadFromFile(usersFileURI);
    int amtUsers = RandomExtensions::randomInt(SIM_MIN_AMT_USERS, SIM_MAX_AMT_USERS);

    std::unique_ptr<UserList> competitors = std::make_unique<UserList> (RandomExtensions::randomShuffle(*allUsers));
    *competitors = Linq::take(*competitors, amtUsers);

    competitors->orderByAscending(User::PROPERTIES::RANK);

    int amtCourts = amtUsers / 4;
    int amtSpares = amtUsers % 4;
    std::vector<UserList*> courtsPlayers(amtCourts);
    for(int court = 0; court < amtCourts; court++){
        auto competitorsCopy = std::make_unique<UserList>(*competitors);
        int skipBy = court * 4;
        int take = 4;
        *competitorsCopy = Linq::skip(*competitorsCopy, skipBy);
        *competitorsCopy = Linq::take(*competitorsCopy, take);

        courtsPlayers[court] = new UserList(*competitorsCopy);
    }

    int amtCourtsA = amtCourts / 2;

    std::string courtAStr = "Group A 8:00-10:00 PM\n\n";
    for(int court = 0; court < amtCourtsA; court++){
        courtAStr += "Court " + to_string(court + 1) + "\n\n";
        courtAStr += courtsPlayers[court]->toString() + "\n";
    }
    courtAStr += "\n\n";

    std::string courtBStr = "Group B 6:00-8:00 PM\n\n";
    for(int court = amtCourtsA; court < amtCourts; court++){
        courtBStr += "Court " + to_string(court + 1) + "\n\n";
        courtBStr += courtsPlayers[court]->toString() + "\n";
    }
    courtBStr += "\n\n";

    int spareOffset = amtUsers - amtSpares;
    std::string sparesStr = "Spares\n\n";
    for(int spare = 0; spare < amtSpares; spare++){
        sparesStr += to_string(spare + 1) + ". " + (*competitors)[spareOffset + spare]->toString();
    }
    
    

    auto fileContentsToWrite = courtAStr + courtBStr + sparesStr;
    std::string outputFileURI = base + "/../../TextFiles/doubles_fixture_0.txt";
    FileRW::writeToFile(outputFileURI, fileContentsToWrite);
}