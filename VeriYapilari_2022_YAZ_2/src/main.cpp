
/* 
 * File:   main.cpp
 * Author: HAKAN KIRIK
 *
 * Created on August 18, 2022, 10:20 PM
 */

#include <cstdlib>
#include<iostream>
#include "Radix.hpp"
#include "ReadAndSort.hpp"
#include "Avl.hpp"
using namespace std;

/*
 * 
 */
int main(int argc, char** argv) {

    ReadAndSort *read = new ReadAndSort("Sayilar.txt");
    Queue** queues = read->sortFile();
    AVL *avl = new AVL();
    for (int index = 0; index < read->lineCount(); index++) {


        avl->Add(queues[index]);

    }
    std::cout << "preorder yazim sekli:" << std::endl;
    avl->preorder();
	delete read;
	delete avl;
	

    return 0;
}

