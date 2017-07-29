#include "FigureCollection.h"
namespace Figures
{
	void nulifyArrayF(char arr[], const size_t size)
	{
		for (int i = 0; i < size; ++i)
		{
			arr[i] = 0;
		}
		return;
	}

	void getFromPosition(char* arr, char* temp, int& index, int&indexInTemp, size_t lineLen)
	{
		for (int i = index; arr[i] != ' '&&i <= lineLen; ++i)
		{
			temp[indexInTemp++] = arr[i];
			index++;
		}
	}

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
			Figure** temp = new Figure*[maxEntries * 2];
			for (unsigned int i = 0; i < maxEntries; ++i)
			{
				temp[i] = collection[i];
			}
			temp[numberOfEntries] = figure;
			delete[] collection;
			collection = temp;
			numberOfEntries++;
			maxEntries *= 2;
			return;
		}
		collection[numberOfEntries++] = figure;
	}

	void FigureCollection::printToConsole() const
	{
		if (numberOfEntries == 0)
		{
			std::cerr << "No entires" << std::endl;
			return;
		}
		for (unsigned int i = 0; i < numberOfEntries; ++i)
		{
			std::cout << i << " ";
			collection[i]->print();
		}
	}

	unsigned int FigureCollection::currentEntry() const
	{
		return numberOfEntries;
	}

	void FigureCollection::deleteEntry(int id)
	{
		if (id == -1)
		{
			for (unsigned int i = 0; i < numberOfEntries; i++)
			{
				delete collection[i];
			}
			numberOfEntries = 0;
			return;
		}
		if (id > numberOfEntries || id < 0)
		{
			std::cerr << "No entry at this id " << std::endl;
			return;
		}
		else
		{
			Figure* temp = collection[id];
			for (unsigned int i = id; i < numberOfEntries; ++i)
			{
				collection[i] = collection[i + 1];
			}
			delete temp;
			numberOfEntries--;
			std::cout << "Deleted entry at postition" << id << std::endl;
		}

	}

	void FigureCollection::translate(const int addX, const int addY, int id)
	{
		if (id == -1)
		{
			for (unsigned int i = 0; i < numberOfEntries; i++)
			{
				collection[i]->translate(addX, addY);
			}
			std::cout << "Translated all figures" << std::endl;
		}
		else if (id<0 || id>maxEntries)
		{
			std::cerr << "No such entry" << std::endl;
			return;
		}
		else
		{
			collection[id]->translate(addX, addY);
			std::cout << "Translated figure at position: " << id << std::endl;
		}
	}

	void FigureCollection::exportToFile(std::ofstream &out) const
	{
		for (unsigned int i = 0; i < numberOfEntries; i++)
		{
			collection[i]->printToFile(out);
		}
	}

	void FigureCollection::withinRectangle(const double rectX, const double rectY, const double rectWidth, const double rectHeight) const
	{
		int count = 0;
		for (unsigned int i = 0; i < numberOfEntries; i++)
		{
			if (collection[i]->withinRectangle(rectX, rectY, rectWidth, rectHeight))
			{
				collection[i]->print();
				count++;
			}
		}
		if (count == 0) std::cout << "No figures inside the figure!" << std::endl;
		return;
	}

	void FigureCollection::withinCircle(const double circX, const double circY, const double circR) const
	{
		int count = 0;
		for (unsigned int i = 0; i < numberOfEntries; i++)
			if (collection[i]->withinCircle(circX, circY, circR))
			{
				collection[i]->print();
			}
		if (count == 0) std::cout << "No figures inside the figure!" << std::endl;
		return;
	}
}