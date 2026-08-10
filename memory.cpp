#include "memory.h"

Memory memories[MAX_MEMORIES];
int totalMemories = 0;

void clearMemories()
{
    totalMemories = 0;
}

void addMemory(const std::string& text, int number)
{
    if (totalMemories < MAX_MEMORIES)
    {
        memories[totalMemories].text = text;
        memories[totalMemories].number = number;
        totalMemories++;
    }
}

int memoryCount()
{
    return totalMemories;
}

Memory getMemory(int index)
{
    return memories[index];
}

void saveMemories(std::ofstream& file)
{
    for (int i = 0; i < totalMemories; i++)
    {
        file << memories[i].number << "\n";
        file << memories[i].text << "\n";
    }
}

void loadMemories(std::ifstream& file, int count)
{
    totalMemories = 0;

    if (count > MAX_MEMORIES)
        count = MAX_MEMORIES;

    for (int i = 0; i < count; i++)
    {
        file >> memories[i].number;
        file.ignore();
        std::getline(file, memories[i].text);
        totalMemories++;
    }
}
