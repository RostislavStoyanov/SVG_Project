#include "FigureCollection.h"


FigureCollection::FigureCollection()
{
	numberOfEntries = 0;
	maxEntries = 4;
	collection = new Figure *[maxEntries];
}


FigureCollection::~FigureCollection()
{
	for (unsigned int i = 0; i < numberOfEntries; ++i)
		delete collection[i];
	delete[] collection;
}

void FigureCollection::addEntry(Figure *figure)
{
	if (numberOfEntries == maxEntries)
	{
		Figure** temp = new Figure*[maxEntries*2];
		for (unsigned int i = 0; i < maxEntries; ++i)
		{
			temp[i] = collection[i];
		}
		temp[numberOfEntries] = figure;
		for (unsigned int i = 0; i < maxEntries; ++i)
			delete collection[i];
		delete[] collection;
		collection = temp;
		numberOfEntries++;
		maxEntries *= 2;
		return;
	}
	collection[numberOfEntries] = figure;
	numberOfEntries++;
}

void FigureCollection::printToConsole() const
{
	for (unsigned int i = 0; i < numberOfEntries; ++i)
	{
		std::cout << i << " ";
		int currType = collection[i]->getType();
		switch (currType)
		{
		case 1:
			std::cout << "rectangle ";
			break;
		case 2:
			std::cout << "circle ";
			break;
		case 3:
			std::cout << "line ";
			break;
		}
		collection[i]->print();
	}
}
