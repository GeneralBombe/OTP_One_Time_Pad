// One_Time_pad.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>
#include <string>
#include <vector>
#include <random>




int main()
{

	const char alphabet[52] = { 'A', 'B', 'C', 'D', 'E', 'F', 'G',
								'H', 'I', 'J', 'K', 'L', 'M', 'N',
								'O', 'P', 'Q', 'R', 'S', 'T', 'U',
								'V', 'W', 'X', 'Y', 'Z', 'a', 'b',
								'c', 'd', 'e', 'f', 'g', 'h', 'i',
								'j', 'k', 'l', 'm', 'n', 'o', 'p',
								'q', 'r', 's', 't', 'u', 'v', 'w',
								'x', 'y', 'z' };
	
	std::vector<char> inputKey;
	std::vector<int> inputNumber;

	
	/*
	char a = 'a';
	//convert the char to int
	int a_int = (int)a;
	*/
  
	char input[] = "GEHEIMTEXT";
	int inputLaenge = std::strlen(input);
	std::cout << "String lenght: " << inputLaenge << std::endl;

	std::vector<char> randomString;
	std::vector<int> randomStringNumber;
	
	std::vector<char> outputString;
	std::vector<int> outputInt;
	



	

	
	//usless code, weil char code 91-96 keine buchstaben sind ...


	
	/*
		int lowestNumber = 100;
		int highestNumber = 100;
		for (int i = 0; i < inputLaenge; i++) {

		//wenn das hier jemals wer liest, warum hab ich so lang dafür gebraucht zu raffen,
		//dass es im prinzip (rand() %58) + 65 ist und nicht rand() % 123 <-- ja 58 + 65 wirklich 123 :P 
		int charRandomNumber = rand() % 58 + 65;
		
		if (charRandomNumber < lowestNumber) {
			lowestNumber = charRandomNumber;
		}

		if (charRandomNumber > highestNumber) {
			highestNumber = charRandomNumber;
		}

		std::cout << (char)charRandomNumber;

	}
	*/



	

	//Zufälliger Buchstabe
	for (int i = 0; i < inputLaenge; i++) {
		int randomAuswahl = rand () % 2;

		
		//Großbuchstaben
		if (randomAuswahl == 0) {
			int randomNumber = rand() % 26 + 65;
			randomString.push_back(char(randomNumber));

		} //Kleinbuchstaben
		else {
			int randomNumber = rand() % 26 + 97;
			randomString.push_back(char(randomNumber));
		}
		
	}
	
	std::cout << "Random String Size: " <<  randomString.size() << std::endl;



	for (auto& celem : input) {
		inputKey.push_back(celem);
		inputNumber.push_back((int) celem);
	}
	
	for (auto & celem : randomString) {
		randomStringNumber.push_back((int) celem);
	}
	

	



	//Nummern Addieren der Vektoren

	for (int i = 0; i < inputLaenge; i++) {
		
		if (inputNumber[i] < 96) {
			inputNumber[i] = inputNumber[i] - 65;
		} else {
			inputNumber[i] = inputNumber[i] - 71;
		}
#
		if (randomStringNumber[i] < 96) {
			randomStringNumber[i] = randomStringNumber[i] - 65;
		}
		else {
			randomStringNumber[i] = randomStringNumber[i] - 71;
		}

		outputInt.push_back(inputNumber[i] + randomStringNumber[i]);
	}
	
	


	// % 52 um kein Overflow zu haben
	for (auto& elm : outputInt) {
		elm = elm % 52;
		//wieder von alphabet System in Char System

		if (elm < 26) {
			elm = elm + 65;
		}
		else {
			elm = elm + 71;
		}
		outputString.push_back(char(elm));
	}
	std::cout << "Input String: " << input << std::endl;
	std::cout << "Schluessel String: ";
	
	
	for(auto & elem : outputString) {
		std::cout << elem;
	}
	
}



// Run program: Ctrl + F5 or Debug > Start Without Debugging menu
// Debug program: F5 or Debug > Start Debugging menu

// Tips for Getting Started: 
//   1. Use the Solution Explorer window to add/manage files
//   2. Use the Team Explorer window to connect to source control
//   3. Use the Output window to see build output and other messages
//   4. Use the Error List window to view errors
//   5. Go to Project > Add New Item to create new code files, or Project > Add Existing Item to add existing code files to the project
//   6. In the future, to open this project again, go to File > Open > Project and select the .sln file
