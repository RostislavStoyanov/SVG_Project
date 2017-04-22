#include "FigureCollection.h"


FigureCollection::FigureCollection()
{
	for (unsigned int i = 0; i < numberOfEntries; ++i)
		collection[i] = NULL;
	collection = NULL;
	numberOfEntries = 0;
	maxEntries = 0;
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
		Figure** temp = new Figure*[maxEntries + 1];
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
		return;
	}
	collection[numberOfEntries] = figure;
	numberOfEntries++;
}

void FigureCollection::printToConsole() const
{
	for (unsigned int i = 0; i < numberOfEntries; ++i)
	{
		collection[i]->print();
	}
}
