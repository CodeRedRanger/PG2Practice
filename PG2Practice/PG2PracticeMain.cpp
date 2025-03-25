#include <iostream>
#include <memory>
#include <map> // for map
#include <vector>
#include <fstream> //for input stream
#include <string>
#include <sstream> //for stringstream
#include <algorithm> //for max()
#include "Suspect.h"

int main()
{

	srand(time(0)); 

	std::string file = "Suspects.csv";
	char traitDelimiter = '*';

	Suspect suspect; 

	std::map<std::string, Suspect> suspects2; 
	suspects2 = suspect.LoadSuspects(file, traitDelimiter);
	suspect.SetSuspectMap(suspects2); 

	bool gameOver = false; 

	while (gameOver == false)
	{
	std::cout << "Choose one of the following options.\n" << std::endl; 
	std::cout << "1. Print out suspect list.\n"; 
	std::cout << "2. Add suspect to list.\n";
	std::cout << "3. Remove a suspect from the list.\n"; 
	std::cout << "4. Generate new list of suspects.\n";
	std::cout << "5. Play \"Guess Who!?\"\n"; 
	std::cout << "6. Quit.\n"; 
	//Incorporate high score system for number of guesses, and add choice to view high scores.

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

				////Select suspect key from map

				//std::map<std::string, Suspect> suspects2 = suspect.GetSuspectMap(); 

				//int randomNum = rand() % suspects2.size();

				//std::map<std::string, Suspect>::iterator iterRand = suspects2.begin();

				//std::advance(iterRand, randomNum);

				//Suspect sus2 = iterRand->second;

				//int numberOfGuesses = 1; 
				//int numberOfClues = 0; 
				//bool continuePlay = true; 
				//int score = 10; 
				//while (continuePlay)
				//{
				//	std::cout << "Make a choice from the list below.\n";
				//	std::cout << "1. Guess who committed the crime!\n";
				//	std::cout << "2. Learn more about the suspect.\n";
				//	std::cout << "3. Print the suspect list.\n";
				//	std::cout << "4. Reveal the criminal!\n";

				//	std::string choiceStr;

				//	getline(std::cin, choiceStr);

				//	int choice = stoi(choiceStr);

				//	switch (choice)
				//	{
				//	case 1:
				//	{
				//		std::string suspectGuess;
				//		std::cout << "Who do you think committed the crime? "; 
				//		getline(std::cin, suspectGuess); 

				//		if (suspectGuess == sus2.GetName())
				//		{
				//			std::cout << "That's right!\n";
				//			std::cout << "The culprit is " << sus2.GetName() << "!\n";
				//			std::cout << "It took you " << numberOfGuesses; 
				//				
				//			if (numberOfGuesses == 1)
				//			{
				//				std::cout << " try to guess the culprit!\n";
				//			}

				//			else
				//			{
				//				std::cout << " tries to guess the culprit!\n";
				//			}

				//			std::cout << "Number of clues needed to guess culprit: " << numberOfClues << "\n"; 
				//			std::cout << "Total score [11 - (number of guesses + number of clues)] : " << std::max(score, 0) << "\n"
				//				<< std::endl; 

				//			continuePlay = false;
				//		}
				//		else
				//		{
				//			std::cout << "I'm sorry, that's wrong.\n";
				//			std::cout << "Total guesses so far: " << numberOfGuesses << "\n" << std::endl;
				//			numberOfGuesses++;
				//			score--; 
				//		}
				//		break;
				//	}
				//	case 2:
				//	{    

				//		std::cout << "What do you want to know about the suspect?\n";
				//		std::cout << "1. Sex\n";
				//		std::cout << "2. Height\n";
				//		std::cout << "3. Hair Color\n";
				//		std::cout << "4. Eye Color\n"; 

				//		std::string traitChoiceStr; 
				//		getline(std::cin, traitChoiceStr);

				//		int traitChoice = stoi(traitChoiceStr); 

				//		//If choose 2: What do you want to know? Sex, Height, Hair Color, Eye Color (1-4); based on choice;
				//		//print out value for that suspect key at that location in vector of values
				//		switch (traitChoice)
				//		{
				//		case 1:
				//		{
				//			std::cout << "The suspect's sex: " << sus2.GetSex() << "\n" << std::endl; 
				//			numberOfClues++; 
				//			score--; 
				//			break;
				//		}

				//		case 2:
				//		{
				//			std::cout << "The suspect's height: " << sus2.GetHeight() << "\n" << std::endl; 
				//			numberOfClues++;
				//			score--;
				//			break; 
				//		}

				//		case 3:
				//		{
				//			std::cout << "The suspect's hair color: " << sus2.GetHairColor() << "\n" << std::endl;
				//			numberOfClues++;
				//			score--;
				//			break;
				//		}

				//		case 4:
				//		{
				//			std::cout << "The suspect's eye color: " << sus2.GetEyeColor() << "\n" << std::endl;
				//			numberOfClues++;
				//			score--;
				//			break; 
				//		}

				//		default:
				//		{
				//			std::cout << "Invalid choice!\n" << std::endl; 
				//			break; 
				//		}

				//		}

				//		
				//		break;
				//	}
				//	case 3:
				//	{
				//		suspect.PrintSuspects(); 
				//		break;
				//	}
				//	case 4:
				//	{
				//		std::cout << "The culprit is " << sus2.GetName() << "!\n" << std::endl;
				//		continuePlay = false;
				//		break;
				//	}
				//	default:
				//	{
				//		std::cout << "Invalid choice!\n" << std::endl;
				//		break;
				//	}
				//	}
				//}
				//

				break;
			}

			case 6:
				gameOver = true; 
				break; 

			default:
				break; 

		}

	}

	return 0; 
}


