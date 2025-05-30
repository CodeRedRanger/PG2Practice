#include <iostream> //for cout
#include <memory> //for smart pointers
#include <map> // for map
#include <vector>
#include <fstream> //for input/output file streams
#include <string> //for strings and getline
#include <sstream> //for stringstream
#include <algorithm> //for max()
#include "Suspect.h"
#include "HighScore.h"
#include "Male.h"
#include "Female.h"

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
	int choice; 

	try
	{
		choice = stoi(choiceStr);
	}
	catch (...)
	{
		choice = 0; 
	}

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

				system("pause"); 
				system("cls"); 

				//Drawing suspect begin
				if (suspect.GetSex() == "Male")
				{
					std::unique_ptr<Person> pMale = std::make_unique<Male>(suspect.GetEyeColor(), suspect.GetHairColor());
					pMale->Draw(); 
				}
				else
				{
					std::unique_ptr<Person> pFemale = std::make_unique<Female>(suspect.GetEyeColor(), suspect.GetHairColor());
					pFemale->Draw(); 
				}

				Console::SetCursorPosition(58, 26);  
				std::cout << suspect.GetName();

				Console::SetCursorPosition(1, 1);
				system("pause"); 
				system("cls"); 
				//Drawing suspect end

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
			{
				gameOver = true;
				break;
			}

			default:
			{
				std::cout << "Invalid choice!\n" << std::endl;
				break;
			}
		}

	}

	return 0; 
}


