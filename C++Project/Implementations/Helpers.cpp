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

#include "Helpers.h"
#include "Exceptions.h"
#include <vector>
#include <iostream>
#include <string>
#include <random>
#include <algorithm>
#include <fstream>
#include <exception>

//TODO: Reorganize this file into multiple files defining each namespace
//		separately.

std::vector<std::string> 
StringExtensions::split(
	char delim,
	const std::string &str )
{
	std::vector<std::string> tokens;
	size_t prev = 0, pos = 0;
	do
	{
		pos = str.find(delim, prev);
		if (pos == std::string::npos)
			pos = str.length();
		std::string token = str.substr(prev, pos - prev);
		if (!token.empty())
			tokens.push_back(token);
		prev = pos + 1;
	} while (pos < str.length() && prev < str.length());
	return tokens;
}


std::vector<std::string> 
FileRW::readLinesInFile(
	const std::string& fileURI )
{
	std::ifstream ifs;
	ifs.open(fileURI, std::fstream::in);
	try
	{
		if (ifs.is_open())
		{
			std::vector<std::string> result = std::vector<std::string>();
			std::string line = "";
			int lineIndex = 0;
			while (std::getline(ifs, line))
			{

				result.push_back(line);
				lineIndex++;
			}
			ifs.close();
			return result;
		}
		else
		{
			throw ReadFileException("Failed to locate file, file URI: " + fileURI);
		}
	}
	catch (ReadFileException &e)
	{
		std::cout << e.what();
	}
	catch (std::exception &e)
	{
		std::cout << e.what();
	}
	ifs.close();
}

bool FileRW::writeToFile(
	const std::string& fileURI, 
	const std::string& text )
{
	std::ofstream ofs;
	ofs.open(fileURI, std::ofstream::out | std::ofstream::trunc);
	try
	{
		if (ofs.is_open())
		{			
			ofs << text;
			ofs.close();
			return true;
		}
		else
		{
			throw ReadFileException("Failed to locate file, file URI: " + fileURI);
		}
		
	}
	catch (ReadFileException &e)
	{
		std::cout << e.what();
	}
	catch (std::exception &e)
	{
		std::cout << e.what();
	}
	
	ofs.close();
	return false;
}

bool FileRW::writeLinesToFile(
	const std::string& fileURI,
	const std::vector<std::string>& lines)
{
	std::string concatted = "";
	for(auto line : lines){
		concatted += line + "\n";
	}
	return FileRW::writeToFile(fileURI, concatted);
}
