#include "FigureCollection.h"

void nulifyArrayF(char arr[], const size_t size)
{
	for (int i = 0; i<size; ++i)
	{
		arr[i] = 0;
	}
	return;
}

void getFromPosition(char* arr, char* temp, int& index,int&indexInTemp,size_t lineLen)
{
	for (int i =index; arr[i] != ' '&&i <= lineLen; ++i)
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
		Figure** temp = new Figure*[maxEntries*2];
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
	size_t lineLen = strlen(line);
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
		getFromPosition(line, temp, indexForContent, indexInTemp, lineLen);
		currX = std::atof(temp);
		nulifyArrayF(temp, 256);
		indexInTemp = 0;
		indexForContent++;
		//acquiring Y
		getFromPosition(line, temp, indexForContent, indexInTemp, lineLen);
		currY = std::atof(temp);
		nulifyArrayF(temp, 256);
		indexInTemp = 0;
		indexForContent++;
		//acquiring width
		getFromPosition(line, temp, indexForContent, indexInTemp, lineLen);
		currWidth = std::atof(temp);
		nulifyArrayF(temp, 256);
		indexInTemp = 0;
		indexForContent++;
		//acquiring height
		getFromPosition(line, temp, indexForContent, indexInTemp, lineLen);
		indexForContent++;
		currHeight = std::atof(temp);
		nulifyArrayF(temp, 256);
		indexInTemp = 0; 
		//acquiring fill
		getFromPosition(line, temp, indexForContent, indexInTemp, lineLen);
		indexForContent++;
		strcpy_s(currFill, strlen(temp) + 1, temp);
		nulifyArrayF(temp, 256);
		indexInTemp = 0;
		//acquiring stroke
		getFromPosition(line, temp, indexForContent, indexInTemp, lineLen);
		indexForContent++;
		strcpy_s(currStroke, strlen(temp) + 1, temp);
		nulifyArrayF(temp, 256);
		indexInTemp = 0;
		//acquiring strokeWidth
		getFromPosition(line, temp, indexForContent, indexInTemp, lineLen);
		currStrokeWidth = std::atoi(temp);
		nulifyArrayF(temp, 256);
		indexInTemp = 0;
		Rectangle* rect = new Rectangle;
		rect->getInfo(currFill, currStroke, currStrokeWidth, std::fabs(currX), std::fabs (currY), std::fabs(currWidth), std::fabs(currHeight));
		this->addEntry(rect);
		std::cout << "Successfully created rectangle id: " << numberOfEntries << std::endl;
		break;
	}
	case 2:
	{
		nulifyArrayF(currFill, lineLen - indexForContent);
		nulifyArrayF(currFill, lineLen - indexForContent);
		double  currX, currY, currR;
		//acquiring X
		getFromPosition(line, temp, indexForContent, indexInTemp, lineLen);
		currX = std::atof(temp);
		nulifyArrayF(temp, 256);
		indexInTemp = 0;
		indexForContent++;
		//acquiring Y
		getFromPosition(line, temp, indexForContent, indexInTemp, lineLen);
		currY = std::atof(temp);
		nulifyArrayF(temp, 256);
		indexInTemp = 0;
		indexForContent++;
		//acquiring Radius
		getFromPosition(line, temp, indexForContent, indexInTemp, lineLen);
		currR = std::atof(temp);
		nulifyArrayF(temp, 256);
		indexInTemp = 0;
		indexForContent++;
		//acquiring fill
		getFromPosition(line, temp, indexForContent, indexInTemp, lineLen);
		indexForContent++;
		strcpy_s(currFill, strlen(temp) + 1, temp);
		nulifyArrayF(temp, 256);
		indexInTemp = 0;
		//acquiring stroke
		getFromPosition(line, temp, indexForContent, indexInTemp, lineLen);
		indexForContent++;
		strcpy_s(currStroke, strlen(temp) + 1, temp);
		nulifyArrayF(temp, 256);
		indexInTemp = 0;
		//acquiring strokeWidth
		getFromPosition(line, temp, indexForContent, indexInTemp, lineLen);
		currStrokeWidth = std::atoi(temp);
		nulifyArrayF(temp, 256);
		indexInTemp = 0;
		Circle* circ = new Circle;
		circ->getInfo(currFill, currStroke, currStrokeWidth, std::fabs(currX), std::fabs(currY), std::fabs(currR));
		this->addEntry(circ);
		std::cout << "Successfully created circle id: " << numberOfEntries << std::endl;
		break;
	}
	case 3:
	{
		nulifyArrayF(currFill, lineLen - indexForContent);
		nulifyArrayF(currFill, lineLen - indexForContent);
		double  currX1, currY1, currX2, currY2;
		//acquiring X1
		getFromPosition(line, temp, indexForContent, indexInTemp, lineLen);
		currX1 = std::atof(temp);
		nulifyArrayF(temp, 256);
		indexInTemp = 0;
		indexForContent++;
		//acquiring Y1
		getFromPosition(line, temp, indexForContent, indexInTemp, lineLen);
		currY1 = std::atof(temp);
		nulifyArrayF(temp, 256);
		indexInTemp = 0;
		indexForContent++;
		//acquiring X2
		getFromPosition(line, temp, indexForContent, indexInTemp, lineLen);
		currX2 = std::atof(temp);
		nulifyArrayF(temp, 256);
		indexInTemp = 0;
		indexForContent++;
		//acquiring Y2
		getFromPosition(line, temp, indexForContent, indexInTemp, lineLen);
		currY2 = std::atof(temp);
		nulifyArrayF(temp, 256);
		indexInTemp = 0;
		indexForContent++;
		//acquiring fill
		getFromPosition(line, temp, indexForContent, indexInTemp, lineLen);
		indexForContent++;
		strcpy_s(currFill, strlen(temp) + 1, temp);
		nulifyArrayF(temp, 256);
		indexInTemp = 0;
		//acquiring stroke
		getFromPosition(line, temp, indexForContent, indexInTemp, lineLen);
		indexForContent++;
		strcpy_s(currStroke, strlen(temp) + 1, temp);
		nulifyArrayF(temp, 256);
		indexInTemp = 0;
		//acquiring strokeWidth
		getFromPosition(line, temp, indexForContent, indexInTemp, lineLen);
		currStrokeWidth = std::atoi(temp);
		nulifyArrayF(temp, 256);
		indexInTemp = 0;
		Line* line = new Line;
		line->getInfo(currFill, currStroke, currStrokeWidth, std::fabs(currX1), std::fabs(currY1), std::fabs(currX2),std::fabs(currY2));
		this->addEntry(line);
		std::cout << "Successfully created line id: " << numberOfEntries << std::endl;
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
		for (unsigned int i = 0; i < numberOfEntries; i++)
		{
			delete collection[i];
		}
		numberOfEntries = 0;
		return;
	}
	if (id > numberOfEntries||id < 0)
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
		if (collection[i]->withinCircle(circX,circY,circR))
		{
			collection[i]->print();
	}
	if (count == 0) std::cout << "No figures inside the figure!" << std::endl;
	return;
}
