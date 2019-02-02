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

#ifndef __HELPERS_H_
#define __HELPERS_H_

#include <vector>
#include <string>

namespace StringExtensions
{
    std::vector<std::string> split(char, const std::string &);
}

namespace FileRW
{
    std::string getBasePath(const std::string& );
    std::vector<std::string> readLinesInFile(const std::string &);
    bool writeToFile(const std::string &, const std::string &);
    bool writeLinesToFile(const std::string &, const std::vector<std::string> &);
}

namespace Linq
{
    template <typename T>
    std::vector<T> take(const std::vector<T> & container, int amt){
        if(amt > container.size()){
            return container;
        }

        auto result = container;
        result.erase(result.begin() + amt, result.end());
        return result;
    }

    template <typename T> 
    std::vector<T> skip(const std::vector<T> & container, int by){
        if(by == 0){
            return container;
        }
        
        std::vector<T> result;
        if(by > container.size()){
            return result;
        }

        result = container;
        result.erase(result.begin(), result.begin()+by);
        return result;
    }
}

namespace RandomExtensions {
    template <typename T>
    std::vector<T> randomShuffle(const std::vector<T>& collection){
        srand(time(0));

        auto result(collection);
        auto len = result.size();
        for(int i = 0; i < len; i++)
        {
            int rnd = rand() % len;
            std::swap(result[i], result[rnd]);
        }
        
        return result;
    }

    int randomInt(int min, int max);
}

#endif //__HELPERS_H_