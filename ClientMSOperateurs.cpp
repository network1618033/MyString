/**************************************************************************************************
*
*  Auteur :				Ghislain DUGUAY et Jonathan ZOGONA
*  Date :				27 Novembre 2019
*  Version :			Version 1.0.0
*
*  Description :		MyString avec Surchage des op�rateurs
*
***********************************************************************************************************/

#include <iostream>
#include "MyString.h"

using namespace std;


/**************** Programme principal *******************************/
int main(void)
{
	MyString str1("Ghislain");


	// #1: Vérification: MyString == char*
	if (str1 == "Ghislain")
		cout << "TRUE" << endl;
	else
		cout << "FALSE" << endl;

	// #2: Vérification: char* == MyString
	("Ghislain" == str1) ? cout << "TRUE" << endl : cout << "FALSE" << endl;

	// #3: Concatenation avec + entre deux objets.
	MyString str2(" Duguay");
	MyString str3 = str1 + str2;
	str3.afficher();

	// #4: Concatenation avec += entre un objet et une chaine.
	str3 += " - CCNB Bathurst";
	cout << endl;
	str3.afficher();

	// #5: Vérification: char* >= MyString
	cout << endl;
	("Ghislain" >= str3) ? cout << "TRUE" << endl : cout << "FALSE" << endl;

	// #6: Utilisation du << pour affichage.
	cout << endl << str3 << endl;

	// #7: Utilisation du >> pour initialiser la chaine.
	cout << "Saisir une chaine: ";
	cin >> str3;
	str3[0] = 'A';
	cout << "La nouvelle chaine est: " << str3 << endl;

	// #8: Utilisation des [] avec un index sur un objet MyString
	char monChar = str3[2];
	cout << "Le caractere isole est : " << monChar << endl;

	// #9: Utilisation de ! pour voir si la chaine est vide.
	MyString str4;
	cout << "Est-ce que la chaine est vide? : " << !str4 << endl;

	// #10 DEFI: Substring avec l'utilisation des ()
	MyString str5 = str3(3);
	cout << "La chaine isole est : " << str5 << endl;

	return 0;
}