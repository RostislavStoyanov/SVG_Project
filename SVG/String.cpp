#include "String.h"


String::String() :currentSize(0),
					maxSize(16),
					data(nullptr){
    try {
        data = new char[maxSize];
		data[0] = '\0';
    }
    catch (std::bad_alloc &) {
        std::cerr << "Not enough memory" << std::endl;
        throw;
    }
}

String::~String() {
    delete[] data;
}

size_t String::length() const {
    return currentSize;
}

size_t String::max_size() const
{
	return maxSize;
}

String::String(char ch) :currentSize(0),
						maxSize(16),
						data(nullptr)
{
	try {
		data = new char[maxSize];
		data[0] = ch;
		data[1] = '\0';
	}
	catch (std::bad_alloc &) {
		std::cerr << "Not enough memory" << std::endl;
		throw;
	}
}

String::String(const String &other) :currentSize(0),
									maxSize(other.maxSize),
									data(nullptr){
    getData(other.data, maxSize);
}

String::String(const char *other) : currentSize(0),
									maxSize(strlen(other) * 2),
									data(nullptr) {
    getData(other, maxSize);
}

void String::getData(const char *dataSource, size_t maxSize) {
    currentSize = strlen(dataSource);
    try {
        char *newData = new char[maxSize];
			strcpy(newData, dataSource);
			delete[] data;
			data = newData;
    }
    catch (std::bad_alloc &) {
        std::cerr << "Not enough memory" << std::endl;
        throw;
    }
}

String String::operator=(const String &other) {
    if (this != &other) {
        maxSize = other.maxSize+1;
        getData(other.data, maxSize);
    }
    return *this;
}

String String::operator=(const char *other) {
    if (this->data != other) {
        maxSize = strlen(other) *2;
        getData(other, maxSize);
    }
    return *this;
}

void String::addChar(const char newChar) {
    if (maxSize == currentSize+1) {
		maxSize *= 2;
		char* temp = new char[maxSize];
		strcpy_s(temp, currentSize+1, data);
		delete[] data;
		data = temp;
    }
	data[currentSize++] = newChar;
	data[currentSize] = 0;
}

void String::getLine(std::istream & is, const char delim)
{
	if (data[0] != 0)
	{
		delete[] data;
		try {
			data = new char[maxSize];
			data[0] = '\0';
		}
		catch (std::bad_alloc &) {
			std::cerr << "Not enough memory" << std::endl;
			throw;
		}
	}
	char temp;
	while (!is.eof())
	{
		is.get(temp);
		if (temp == delim)
			break;
		else
			addChar(temp);
	}
	return;
}

size_t String::find(const char * text)
{
	size_t currPos=String::npos;
	bool found = false;
	for (size_t i = 0; i < currentSize; i++)
	{
        if (data[i] == text[0])
		{
			if (strlen(text) == 1)
				return i;
			for (size_t j = i+1; j < i+ strlen(text); j++)
			{
                if (data[j] == text[j - i])
					found = true;
				else
				{
					found = false;
					break;
				}
			}
			if (found == true)
			{
				currPos = i;
				break;
			}
			else
				continue;
		}
	}
	return currPos;
}


char * String::toChar() const
{
	char* text= new char[currentSize+1];
	strcpy(text, data);
	return text;
}

String String::substr(size_t pos, size_t len)
{
	String newStr;
	for (size_t i = 0; i < len; i++)
	{
		newStr.addChar(data[pos + i]);
	}
	return newStr;
}

String String::substrDelim(size_t pos, char delim)
{
	String newStr;
	char currentSymbol;
	for (size_t i = pos; i < currentSize; i++)
	{
		currentSymbol = data[i];
		if (currentSymbol == delim)
			break;
		else newStr.addChar(currentSymbol);
	}
	return newStr;
}

String & String::operator+=(const String &other)
{
	for (size_t i = 0; i < other.currentSize; i++)
	{
		addChar(other.data[i]);
	}
	return *this;
}

String & String::operator+=(const char *other)
{
	for (size_t i = 0; i < strlen(other); i++)
	{
		addChar(other[i]);
	}
	return *this;
}

String & String::operator+=(const char ch)
{
	addChar(ch);
	return *this;
}


char & String::operator[](size_t pos)
{
	return data[pos];
}

const char & String::operator[](size_t pos) const
{
	return data[pos];
}

bool String::operator==(const String &other)
{
	if (other.currentSize != currentSize)
		return false;
	for (size_t i = 0; i < currentSize; i++)
	{
		if (other.data[i] != data[i])
			return false;
	}
	return true;
}

bool String::operator==(const char *other)
{
	if(currentSize != strlen(other))
		return false;
	for (size_t i = 0; i < currentSize; i++)
	{
		if (data[i] != other[i])
			return false;
	}
	return true;
}

double String::stod() const
{
	char* temp = toChar();
	double toRet=atof(temp);
	delete[] temp;
	return toRet;
}

unsigned int String::stou() const
{
	unsigned int toRet = 0;
	char* tempArr = toChar();
	sscanf(tempArr, "%u", &toRet);
	delete[] tempArr;
	return toRet;
}

int String::stoi() const
{
	int toRet = 0;
	char* tempArr = toChar();
	sscanf(tempArr, "%i", &toRet);
	delete[] tempArr;
	return toRet;
}

void String::clear()
{
	if (data = nullptr) return;
	delete[] data;
	currentSize = 0;
	maxSize = 16;
	try {
		data = new char[maxSize];
		data[0] = '\0';
	}
	catch (std::bad_alloc &) {
		std::cerr << "Not enough memory" << std::endl;
		throw;
	}
}

std::istream & operator>>(std::istream &is, String &str)
{
	char temp;
	if (str.currentSize != 0)
		str.clear();
	while (is)
	{
		is.get(temp);
		if (temp == '\n' || temp == ' ' || temp == '\t')
		{
			if (str.currentSize == 0) continue;
			else 
				break;
		}
		str.addChar(temp);
	}
	str.data[str.currentSize + 1] = 0;
	return is;
}

std::ostream & operator<<(std::ostream & os, const String & str)
{
	for (size_t i = 0; i < str.currentSize; i++)
	{
		os << str.data[i];
	}
	return os;
}

String operator+(const String &lhs, const String &rhs)
{
	String toRet(lhs);
	toRet += rhs;
	return toRet;
}

String operator+(String &&lhs, String &&rhs)
{
	String toRet(lhs);
	toRet += rhs;
	return toRet;
}

String operator+(String && lhs, const String &rhs)
{
	String toRet(lhs);
	toRet += rhs;
	return toRet;
}

String operator+(const String &lhs, String &&rhs)
{
	String toRet(lhs);
	toRet += rhs;
	return toRet;
}

String operator+(const String &lhs, const char *rhs)
{
	String toRet(lhs);
	toRet += rhs;
	return toRet;
}

String operator+(String &&lhs, const char *rhs)
{
	String toRet(lhs);
	toRet += rhs;
	return toRet;
}

String operator+(const char *lhs, const String &rhs)
{
	String toRet(lhs);
	toRet += rhs;
	return toRet;
}

String operator+(const char *lhs, String &&rhs)
{
	String toRet(lhs);
	toRet += rhs;
	return toRet;
}

String operator+(const String &lhs, char rhs)
{
	String toRet(lhs);
	toRet += rhs;
	return toRet;
}

String operator+(String &&lhs, char rhs)
{
	String toRet(lhs);
	toRet += rhs;
	return toRet;
}

String operator+(char lhs, const String &rhs)
{
	String toRet(lhs);
	toRet += rhs;
	return toRet;
}
