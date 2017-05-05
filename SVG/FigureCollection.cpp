#include "FigureCollection.h"

void nulifyArrayF(char arr[], const int size)
{
	for (int i = 0; i<size; ++i)
	{
		arr[i] = 0;
	}
	return;
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
		collection[i]->print();
	}
}

void FigureCollection::createFromLine(char *line)
{
	int indexStart = 0, indexFigure = 0, figureType = -1;
	char figure[250] = { 0 };
	while (line[indexStart++] != ' ');
	for (unsigned int i = indexStart; line[i] != ' '; ++i)
	{
		figure[indexFigure++] = line[i];
	}
	if (!strcmp(figure, "rectangle")) figureType = 1;
	if (!strcmp(figure, "circle")) figureType = 2;
	if (!strcmp(figure, "line")) figureType = 3;
	int lineLen = strlen(line);
	int indexForContent = indexStart + indexFigure + 1;
	char* currFill = new char[lineLen - indexForContent];
	char* currStroke = new char[lineLen - indexForContent];
	int currStrokeWidth = 1, indexInTemp = 0;
	char temp[256] = { 0 };
	switch (figureType)
	{
	case 1:
	{
		nulifyArrayF(currFill, lineLen-indexForContent);
		nulifyArrayF(currFill, lineLen - indexForContent);
		double  currX, currY, currHeight, currWidth;
		//acquiring X
		for (int i = indexForContent; line[i] != ' '&&i <= lineLen; ++i)
		{
			temp[indexInTemp++] = line[i];
			indexForContent++;
		}
		currX = std::atof(temp);
		nulifyArrayF(temp, 256);
		indexInTemp = 0;
		indexForContent++;
		//acquiring Y
		for (int i = indexForContent; line[i] != ' '&&i <= lineLen; ++i)
		{
			temp[indexInTemp++] = line[i];
			indexForContent++;
		}
		currY = std::atof(temp);
		nulifyArrayF(temp, 256);
		indexInTemp = 0;
		indexForContent++;
		//acquiring width
		for (int i = indexForContent; line[i] != ' '&&i <= lineLen; ++i)
		{
			temp[indexInTemp++] = line[i];
			indexForContent++;
		}
		currWidth = std::atof(temp);
		nulifyArrayF(temp, 256);
		indexInTemp = 0;
		indexForContent++;
		//acquiring height
		for (int i = indexForContent; line[i] != ' '&&i <= lineLen; ++i)
		{
			temp[indexInTemp++] = line[i];
			indexForContent++;
		}
		indexForContent++;
		currHeight = std::atof(temp);
		nulifyArrayF(temp, 256);
		indexInTemp = 0; 
		//acquiring fill
		for (int i = indexForContent; line[i] != ' '&&i <= lineLen; ++i)
		{
			temp[indexInTemp++] = line[i];
			indexForContent++;
		}
		indexForContent++;
		strcpy_s(currFill, strlen(temp) + 1, temp);
		nulifyArrayF(temp, 256);
		indexInTemp = 0;
		//acquiring stroke
		for (int i = indexForContent; line[i] != ' '&&i <= lineLen; ++i)
		{
			temp[indexInTemp++] = line[i];
			indexForContent++;
		}
		indexForContent++;
		strcpy_s(currStroke, strlen(temp) + 1, temp);
		nulifyArrayF(temp, 256);
		indexInTemp = 0;
		//acquiring strokeWidth
		for (int i = indexForContent; line[i] != ' '&&i <= lineLen; ++i)
		{
			temp[indexInTemp++] = line[i];
			indexForContent++;
		}
		currStrokeWidth = std::atoi(temp);
		nulifyArrayF(temp, 256);
		indexInTemp = 0;
		Rectangle* rect = new Rectangle;
		rect->getInfo(currFill, currStroke, currStrokeWidth, currX, currY, currWidth, currHeight);
		this->addEntry(rect);
		break;
	}
	case 2:
	{
		nulifyArrayF(currFill, lineLen - indexForContent);
		nulifyArrayF(currFill, lineLen - indexForContent);
		double  currX, currY, currR;
		//acquiring X
		for (int i = indexForContent; line[i] != ' '&&i <= lineLen; ++i)
		{
			temp[indexInTemp++] = line[i];
			indexForContent++;
		}
		currX = std::atof(temp);
		nulifyArrayF(temp, 256);
		indexInTemp = 0;
		indexForContent++;
		//acquiring Y
		for (int i = indexForContent; line[i] != ' '&&i <= lineLen; ++i)
		{
			temp[indexInTemp++] = line[i];
			indexForContent++;
		}
		currY = std::atof(temp);
		nulifyArrayF(temp, 256);
		indexInTemp = 0;
		indexForContent++;
		//acquiring Radius
		for (int i = indexForContent; line[i] != ' '&&i <= lineLen; ++i)
		{
			temp[indexInTemp++] = line[i];
			indexForContent++;
		}
		currR = std::atof(temp);
		nulifyArrayF(temp, 256);
		indexInTemp = 0;
		indexForContent++;
		//acquiring fill
		for (int i = indexForContent; line[i] != ' '&&i <= lineLen; ++i)
		{
			temp[indexInTemp++] = line[i];
			indexForContent++;
		}
		indexForContent++;
		strcpy_s(currFill, strlen(temp) + 1, temp);
		nulifyArrayF(temp, 256);
		indexInTemp = 0;
		//acquiring stroke
		for (int i = indexForContent; line[i] != ' '&&i <= lineLen; ++i)
		{
			temp[indexInTemp++] = line[i];
			indexForContent++;
		}
		indexForContent++;
		strcpy_s(currStroke, strlen(temp) + 1, temp);
		nulifyArrayF(temp, 256);
		indexInTemp = 0;
		//acquiring strokeWidth
		for (int i = indexForContent; line[i] != ' '&&i <= lineLen; ++i)
		{
			temp[indexInTemp++] = line[i];
			indexForContent++;
		}
		currStrokeWidth = std::atoi(temp);
		nulifyArrayF(temp, 256);
		indexInTemp = 0;
		Circle* circ = new Circle;
		circ->getInfo(currFill, currStroke, currStrokeWidth, currX, currY, currR);
		this->addEntry(circ);
		break;
	}
	case 3:
	{
		nulifyArrayF(currFill, lineLen - indexForContent);
		nulifyArrayF(currFill, lineLen - indexForContent);
		double  currX1, currY1, currX2, currY2;
		//acquiring X1
		for (int i = indexForContent; line[i] != ' '&&i <= lineLen; ++i)
		{
			temp[indexInTemp++] = line[i];
			indexForContent++;
		}
		currX1 = std::atof(temp);
		nulifyArrayF(temp, 256);
		indexInTemp = 0;
		indexForContent++;
		//acquiring Y1
		for (int i = indexForContent; line[i] != ' '&&i <= lineLen; ++i)
		{
			temp[indexInTemp++] = line[i];
			indexForContent++;
		}
		currY1 = std::atof(temp);
		nulifyArrayF(temp, 256);
		indexInTemp = 0;
		indexForContent++;
		//acquiring X2
		for (int i = indexForContent; line[i] != ' '&&i <= lineLen; ++i)
		{
			temp[indexInTemp++] = line[i];
			indexForContent++;
		}
		currX2 = std::atof(temp);
		nulifyArrayF(temp, 256);
		indexInTemp = 0;
		indexForContent++;
		//acquiring Y2
		for (int i = indexForContent; line[i] != ' '&&i <= lineLen; ++i)
		{
			temp[indexInTemp++] = line[i];
			indexForContent++;
		}
		currY2 = std::atof(temp);
		nulifyArrayF(temp, 256);
		indexInTemp = 0;
		indexForContent++;
		//acquiring fill
		for (int i = indexForContent; line[i] != ' '&&i <= lineLen; ++i)
		{
			temp[indexInTemp++] = line[i];
			indexForContent++;
		}
		indexForContent++;
		strcpy_s(currFill, strlen(temp) + 1, temp);
		nulifyArrayF(temp, 256);
		indexInTemp = 0;
		//acquiring stroke
		for (int i = indexForContent; line[i] != ' '&&i <= lineLen; ++i)
		{
			temp[indexInTemp++] = line[i];
			indexForContent++;
		}
		indexForContent++;
		strcpy_s(currStroke, strlen(temp) + 1, temp);
		nulifyArrayF(temp, 256);
		indexInTemp = 0;
		//acquiring strokeWidth
		for (int i = indexForContent; line[i] != ' '&&i <= lineLen; ++i)
		{
			temp[indexInTemp++] = line[i];
			indexForContent++;
		}
		currStrokeWidth = std::atoi(temp);
		nulifyArrayF(temp, 256);
		indexInTemp = 0;
		Line* line = new Line;
		line->getInfo(currFill, currStroke, currStrokeWidth, currX1, currY1, currX2,currY2);
		this->addEntry(line);
		break;
	}
	default:
		std::cerr << "Invalid figure!" << std::endl;
		break;
	}
	delete[] currFill;
	delete[] currStroke;
}

void FigureCollection::deleteEntry(int id)
{
	if (id == -1)
	{
		for (int i = id; i < numberOfEntries; ++i)
			delete collection[i];
	}
	if (id > numberOfEntries)
	{
		std::cerr << "No entry at this id " << std::endl;
		return;
	}
	else
	{
		Figure* temp = collection[id];
		for (int i = id; i < numberOfEntries; ++i)
		{
			collection[i] = collection[i + 1];
		}
		delete temp;
		numberOfEntries--;
		std::cout << "Deleted entry at postition" << id << std::endl;
	}
	
}
