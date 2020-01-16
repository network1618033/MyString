/**************************************************************************************************
*
*  Auteur :				Jonathan ZOGONA
*  Date :				27 Novembre 2019
*  Version :			Version 1.0.0
*
*  Description :		MyString avec Surchage des op�rateurs
*
***********************************************************************************************************/

#include "MyString.h"

#include<iostream>

#include<string.h>


using namespace std;

// Constructeurs et destructeur

MyString::MyString() : buf(NULL), len(0) {}

MyString::MyString(const char* pBuf )
{
	int taille = strlen(pBuf);
	
	try
	{
		this->buf = new char[taille + 1];
	}
	catch (bad_alloc ex)
	{
		cout << "Erreur d'allocation : " << endl;
		cout << ex.what() << endl;
		exit(EXIT_FAILURE);
	}

	strcpy_s(this->buf, taille + 1, pBuf);
	this->len = taille;
}

MyString::MyString(int nbr, const char car)
{
	try
	{
		this->buf = new char[nbr + 1];
	}
	catch (bad_alloc ex)
	{
		cout << "Erreur d'allocation : " << endl;
		cout << ex.what() << endl;
		exit(EXIT_FAILURE);
	}

	for (int i = 0; i < this->len; i++)
		this->buf[i] = car;

	this->buf[nbr] = '\0';
	this->len = nbr;
	
}

MyString::MyString(const MyString& pMyString)
{
	this->buf = NULL;
	this->setBuffer(pMyString.buf);
}

MyString::~MyString()
{
	delete[] buf;
}

// Getteurs
int MyString::getLength() const
{
	return this->len;
}

char MyString::getChar(int index) const
{
	if (index >= 0 && index < this->len)
		return this->buf[index];
	else
		return NULL;
}

const char* MyString::getBuffer() const
{
	return this->buf;
}


// Setteurs
void MyString::setBuffer(const char* pBuf)
{	
	char* newBuf = NULL;
	
	try
	{
		newBuf = new char[strlen(pBuf) + 1];
	}
	catch (bad_alloc ex)
	{
		cout << "Erreur d'allocation : " << endl;
		cout << ex.what() << endl;
		exit(EXIT_FAILURE);
	}

	strcpy_s(newBuf, strlen(pBuf) + 1, pBuf);

	delete[] this->buf;

	this->len = strlen(pBuf);	
	this->buf = newBuf;
}

// Methodes usuelles
void MyString::afficher() const
{
	cout << this->buf;
}


void MyString::append(const char* pBuf)
{
	int taille = 0;
	char* newBuf = NULL;

	
	taille = strlen(pBuf) + this->len + 1;

	try
	{
		newBuf = new char[taille];
	}
	catch (bad_alloc ex)
	{
		cout << "Erreur d'allocation : " << endl;
		cout << ex.what() << endl;
		exit(EXIT_FAILURE);
	}

	strcpy_s(newBuf, this->len + 1, this->buf);
	strcat_s(newBuf, taille, pBuf);

	delete[] this->buf;
	this->buf = NULL;

	this->buf = newBuf;
	this->len = taille;
}

// Operateurs de comparaison
	// Egalit�
bool operator==(const MyString& left, const MyString& right)
{
	return !strcmp(left.buf, right.buf);
}

bool operator==(const char* leftStr, const MyString& right)
{
	return !strcmp(leftStr, right.buf);
}

bool operator==(const MyString& left, const char* rightStr)
{
	return !strcmp(left.buf, rightStr);
}


	// Diff�rence
bool operator!=(const MyString& left, const MyString& right)
{
	return !(left == right);
}

bool operator!=(const char* leftStr, const MyString& right)
{
	return strcmp(leftStr, right.buf);;
}

bool operator!=(const MyString& left, const char* rightStr)
{
	return strcmp(left.buf, rightStr);;
}


	// Sup�riorit� >
bool operator>(const MyString& left, const MyString& right)
{
	return (strcmp(left.buf, right.buf) > 0);
}

bool operator>(const char* leftStr, const MyString& right)
{
	return (strcmp(leftStr, right.buf) > 0);
}

bool operator>(const MyString& left, const char* rightStr)
{
	return (strcmp(left.buf, rightStr) > 0);
}


	// Sup�riorit� >=
bool operator>=(const MyString& left, const MyString& right)
{
	return !(left < right);
}

bool operator>=(const char* leftStr, const MyString& right)
{
	return !(strcmp(leftStr, right.buf) < 0);
}

bool operator>=(const MyString& left, const char* rightStr)
{
	return !(strcmp(left.buf , rightStr) < 0);
}

	// Inf�riorit� <
bool operator<(const MyString& left, const MyString& right)
{
	return (strcmp(left.buf, right.buf) < 0);
}

bool operator<(const char* leftStr, const MyString& right)
{
	return (strcmp(leftStr, right.buf) < 0);
}

bool operator<(const MyString& left, const char* rightStr)
{
	return (strcmp(left.buf, rightStr) < 0);
}

	// Inf�riorit� <=
bool operator<=(const MyString& left, const MyString& right)
{
	return !(left > right);
}

bool operator<=(const char* leftStr, const MyString& right)
{
	return !(strcmp(leftStr, right.buf) < 0);
}


bool operator<=(const MyString& left, const char* rightStr)
{
	return !(strcmp(left.buf, rightStr) < 0);
}

// Op�rateur d'assignation
MyString& MyString::operator=(const MyString& right)
{
	this->setBuffer(right.buf);
	
	return *this;
}

MyString& MyString::operator=(const char* right)
{
	this->setBuffer(right);

	return *this;
}

// Op�rateurs de concat�nation
MyString& MyString::operator+=(const MyString& right)
{
	this->append(right.buf);

	return *this;
}

MyString& MyString::operator+=(const char* rightStr)
{
	this->append(rightStr);

	return *this;
}

MyString operator+(const MyString& left, const MyString& right)
{
	MyString result(left);

	result += right;

	return result;
}

MyString operator+(const MyString& left, const char* rightStr)
{
	MyString result(left);

	result += rightStr;

	return result;
}

MyString operator+(const char* leftStr, const MyString& right)
{
	MyString result(leftStr);

	result += right;

	return result;
}


// Op�rateurs de flux
ostream& operator<<(ostream& stream, const MyString& right)
{
	stream << right.buf;
	return stream;
}

istream& operator>>(istream& stream, MyString& right)
{
	stream.getline(right.buf, 1000);
	right.len = strlen(right.buf);

	return stream;
}


// Op�rateur de casting
MyString::operator const char* () const
{
	return (const char*) (this->buf);
}


// Op�rateur d'indexation
char& MyString::operator[](int index)
{	
	if (index >= 0 && index < this->len)
		return this->buf[index];
}


const char& MyString::operator[](int index) const
{
	if (index >= 0 && index < this->len)
		return this->buf[index];
	else
		return NULL;
}


bool operator!(const MyString& right)
{
	return !right.buf;
}

// Op�rateur d'appel de fonction
MyString MyString::operator()(int index, int length) const
{
	MyString nMyString;

	if (index < this->len)
	{
		char* chaine = NULL;
		(length != 0 && (length + index) < this->len) ? 
			length = length : length = this->len - index;
		
		try
		{
			chaine = new char[length + 1];
		}
		catch (bad_alloc ex)
		{
			cout << "Erreur d'allocation : " << endl;
			cout << ex.what() << endl;
			exit(EXIT_FAILURE);
		}

		for (int i = index; i < index + length; i++)
		{
			chaine[i - index] = this->buf[i];
		}
		chaine[length] = '\0';

		nMyString.setBuffer(chaine);
	}
	else
	{
		nMyString = "Index OutOfRange";
	}

	return nMyString;
}

