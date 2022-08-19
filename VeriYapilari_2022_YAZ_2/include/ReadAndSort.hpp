

/* 
 * File:   ReadAndSort.hpp
 * Author: HAKAN KIRIK
 *
 * Created on August 18, 2022, 11:02 PM
 */

#ifndef READANDSORT_HPP
#define READANDSORT_HPP

#include <string>
#include <fstream>
#include <iostream>
#include <sstream>
#include "Queue.hpp"
#include "Radix.hpp"

class ReadAndSort {
private:


    std::string fileName;
public:

    ReadAndSort(std::string);
    ~ReadAndSort();
    Queue** sortFile();
    int lineCount();
private:
    Queue **lines;
    void readLine();


};



#endif /* READANDSORT_HPP */

