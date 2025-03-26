//Additional functionality
//1. Add display high scores to menu and add high scores when user gets them; create high score csv file
//2. Create abstract class Person, with derived classes male and female
//each derived class overrides draw function of person class and draws face of character on screen
//face will be a circle with eyes and hair of the correct color; females with hair will have long hair, men short hair
//3. use friend keyword so that person class can use private variables in Suspect. 
//4. create vector of person unique pointers to all the people (male and females) on suspect list, with their associated traits for drawing


#include <iostream>
#include <memory>
#include <map> // for map
#include <vector>
#include <fstream> //for input stream
#include <string>
#include <sstream> //for stringstream
#include <algorithm> //for max()
#include "Suspect.h"
#include "HighScore.h"

int main()
{

	srand(time(0)); 

	std::string file = "Suspects.csv";
	char traitDelimiter = '*';
	std::string HSFile = "HighScores.csv";
	char scoreDelimiter = '['; 
	
	HighScore hs; 
	hs.LoadHighScores(HSFile, scoreDelimiter);

	Suspect suspect; 

	suspect.SetSuspectMap(suspect.LoadSuspects(file, traitDelimiter));

	std::cout << "Can you ..... Guess Who Did it??\n" << std::endl; 
	std::string name;
	std::cout << "What is your name? "; 
	getline(std::cin, name); 
	system("cls"); 


	bool gameOver = false; 
	while (gameOver == false)
	{
	std::cout << name << ", choose one of the following options.\n" << std::endl; 
	std::cout << "1. Print out suspect list.\n"; 
	std::cout << "2. Add suspect to list.\n";
	std::cout << "3. Remove a suspect from the list.\n"; 
	std::cout << "4. Generate new list of suspects.\n";
	std::cout << "5. Play \"Guess Who!?\"\n"; 
	std::cout << "6. See High Scores\n"; 
	std::cout << "7. Quit.\n"; 

	std::string choiceStr; 
	getline(std::cin, choiceStr); 
	int choice = stoi(choiceStr); 


		switch (choice)
		{
			case 1:
			{
				suspect.PrintSuspects(); 
						
			}
		
			break;
		
			case 2:
			{
				//Add suspect from map
				//output new suspect map to csv file using serialize function
				suspect.AddSuspect(file, traitDelimiter); 
				break;
			}
			case 3:
			{

				//Delete suspect from map
				//output new suspect map to csv file using serialize function

				suspect.RemoveSuspect(file, traitDelimiter); 
				break;
			}
			
			case 4:
			{
				//Delete map
				suspect.NewSuspectList(file, traitDelimiter);
				break;
			}

			case 5:
			{
				suspect.PlayGame(); 
				
				HighScore newScore;
				newScore.SetName(name);
				newScore.SetScore(suspect.GetScore());

				hs.AddHighScore(newScore, HSFile, scoreDelimiter);
				break;
			}

			case 6:
			{
				//Load high score list
				hs.PrintHighScores(); 
				break;
			}

			case 7:
				gameOver = true; 
				break; 

			default:
				break; 

		}

	}

	return 0; 
}


