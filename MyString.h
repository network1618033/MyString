/**************************************************************************************************
*
*  Auteur :				Jonathan ZOGONA
*  Date :				27 Novembre 2019
*  Version :			Version 1.0.0
*
*  Description :		MyString avec Surchage des op�rateurs
*
***********************************************************************************************************/


#pragma once

#include<iostream>

class MyString
{
private :
	char* buf;
	int len;

	// Opérateurs de comparaison
	friend bool operator==(const MyString&, const MyString&);	
	friend bool operator==(const char*, const MyString&);
	friend bool operator==(const MyString&, const char*);

	friend bool operator!=(const MyString&, const MyString&);
	friend bool operator!=(const char*, const MyString&);
	friend bool operator!=(const MyString&, const char*);

	friend bool operator>(const MyString&, const MyString&);
	friend bool operator>(const char*, const MyString&);
	friend bool operator>(const MyString&, const char*);

	friend bool operator<(const MyString&, const MyString&);
	friend bool operator<(const char*, const MyString&);
	friend bool operator<(const MyString&, const char*);
	
	friend bool operator>=(const MyString&, const MyString&);
	friend bool operator>=(const char*, const MyString&);
	friend bool operator>=(const MyString&, const char*);


	friend bool operator<=(const MyString&, const MyString&);
	friend bool operator<=(const char*, const MyString&);
	friend bool operator<=(const MyString&, const char*);
	
	// Op�rateurs de flux
	friend std::ostream& operator<<(std::ostream&, const MyString&);
	friend std::istream& operator>>(std::istream&, MyString&);

	friend bool operator!(const MyString&);

public :
	// Constructeurs et destructeur
	MyString();
	MyString(const char*);
	
	MyString(int, const char = ' ');

	MyString(const MyString&);
	~MyString();

	// Getteurs
	int getLength() const;
	char getChar(int) const;
	const char* getBuffer() const;

	// Setteurs
	void setBuffer(const char*);
	
	// Méthodes usuelles
	void afficher() const;
	void append(const char*);

	// Opérateur d'assignation
	MyString& operator=(const MyString&);
	MyString& operator=(const char*);
	
	// Opérateurs de concat�nation
	MyString& operator+=(const MyString&);
	MyString& operator+=(const char*);

	// Opérateurs de casting
	operator const char*() const;

	// Opérateur d'indexation
	char& operator[](int);
	const char& operator[](int) const;

	// Opérateur d'appel de fonction
	MyString operator()(int, int = 0) const;
};


// Op�rateurs de concaténation
MyString operator+(const MyString&, const MyString&);
MyString operator+(const MyString&, const char*);
MyString operator+(const char* ,const MyString&);