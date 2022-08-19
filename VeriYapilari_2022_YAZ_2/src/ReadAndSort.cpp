
#include "ReadAndSort.hpp"

ReadAndSort::ReadAndSort(std::string fileName) {
    this->fileName = fileName;


    int numlines = lineCount();
    this->lines = new Queue*[numlines];
    for (int i = 0; i < numlines; i++) {
        this->lines[i] = new Queue();
    }
}

int ReadAndSort::lineCount() {
    int counter = 0;
    std::ifstream file(this->fileName);
    std::string unused;
    while (std::getline(file, unused))
        ++counter;

    file.close();
    return counter;
}

void ReadAndSort::readLine() {
    std::string token;
    std::ifstream file(this->fileName);
    std::string str;
    int index = 0;
    while (std::getline(file, token)) {
        std::istringstream ss(token);

        while (std::getline(ss, str, ' ')) {
            this->lines[index]->enqueue(stoi(str));

        }
        index++;

    }
    file.close();
}

Queue** ReadAndSort::sortFile() {
    readLine();
    int count = lineCount();
    for (int index = 0; index < count; index++) {
        Radix sort(lines[index]);
        Queue *tmp = lines[index];
        lines[index] = sort.Sort();
        delete tmp;

    }
    return lines;
}
ReadAndSort::~ReadAndSort(){
	if(lines!=0){
		int count =lineCount();
		for (int i = 0; i < count; i++){
			if(lines[i]!=0) delete lines[i];
		}
		delete[] lines;
	}
	
}
