#ifndef MEMORY_H
#define MEMORY_H

#include <fstream>
#include <string>

const int MAX_MEMORIES = 50;

struct Memory
{
    std::string text;
    int number;
};

void clearMemories();
void addMemory(const std::string& text, int number);
int memoryCount();
Memory getMemory(int index);
void saveMemories(std::ofstream& file);
void loadMemories(std::ifstream& file, int count);

#endif
