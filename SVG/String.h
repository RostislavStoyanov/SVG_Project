#pragma warning(disable:4996)
#ifndef STRING_STRING_H
#define STRING_STRING_H

#include<iostream>
#include<cstring>
#include<fstream>

class String {
private:
    char *data; //holds the text
    
	size_t maxSize; //maximum number of chars in data
    
	size_t currentSize; //current number of chars in data
	
	static const size_t npos = -1;
    
	void getData(const char *, size_t maxSize); //sets currentSize to the other char* size and
												// copies the content of the other char* to data
public:
    String(); //default constructor
    ~String(); //destructor

	String(char); //copy-consturctor(from char)
    String(const String &); //copy-constructor(from String)
    String(const char *);   //copy-constructor(from char*)

    String operator=(const String &); //operator= (from string)
    String operator=(const char *);  //operator=(from char*)

    size_t length() const; //currentSize getter

	size_t max_size() const; // returns maxSize

    void addChar(const char); //adds a char to the data array

	void getLine(std::istream&, const char delim = '\n'); // reads line till deliminator and stores it in this string object(all data previously stored is lost)

	size_t find(const char*); //searches for text in the string and if found returns the starting position , if not found returns -1;

	char* toChar() const; //returns a new allocated char pointer with the text inside (must be deleted afterwards)

	friend std::istream& operator>>(std::istream&,String&); //reads till space or enter(as normal >>)

	friend std::ostream& operator<<(std::ostream&, const String&); //prints the current object to ostream

	String substr(size_t pos = 0, size_t len= npos);

	String& operator+=(const String&); //concatenate string to the current string
	String& operator+=(const char*); //concatenates char array to current string
	String& operator+=(const char); //adds a char at the end of the current string object

	friend String operator+(const String&,const String&); //operator+ for 2 const string objects
	friend String operator+(String&&, String&&); //operator+ for 2 non-const string objects
	friend String operator+(String&&, const String&); //operator+ for 1 non-const and one const string object
	friend String operator+(const String&, String &&); //operator+ for 1 const and one non-const string object

	friend String operator+(const String&, const char*); //operator+ for const string object and const char*
	friend String operator+(String&&, const char*);		//operator+ for string object and const char*
	friend String operator+(const char*, const String&); //operator+ for const char* and const string object
	friend String operator+(const char*, String&&);	//operator+ for const char* and nonconst string object

	friend String operator+(const String&,char); //operator+ for char and string
	friend String operator+(String&&,char); 
	friend String operator+(char,const String&);
	friend String operator+(char,String&); 

	char& operator[] (size_t pos);				//Returns a reference to the char at position in the current string
	const char& operator[] (size_t pos) const;	//returns const char& if object is const-qualified
};


#endif //STRING_STRING_H
