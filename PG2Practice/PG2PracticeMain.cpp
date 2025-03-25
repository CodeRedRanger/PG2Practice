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
				//Create Add suspect function 
				suspect.AddSuspect(file); 

				//std::string name;
				//std::string sex;
				//std::string height;
				//std::string	hairColor;
				//std::string eyeColor;
				//std::cout << "\nWhat is your character's name? ";
				//getline(std::cin, name);
				////Check map if name exists
				//
				//std::map<std::string, Suspect> suspects2 = suspect.GetSuspectMap(); 
				//std::map<std::string, Suspect>::iterator isFound = suspects2.find(name);

				//if (isFound != suspects2.end())
				//{
				//	std::cout << "\nThat suspect name already exists!\n" << std::endl;
				//}

				//else
				//{
				//	Suspect sus; 
				//	//Add to map if name doesn't exist
				//	//auto isInserted = suspects.insert(std::make_pair(name, std::vector<std::string>{"", "", "", ""}));
				//	//suspects[name] = { "","","",""};
				//	auto isInserted = suspects2.insert(std::make_pair(name, sus));
				//	
				//	sus.SetName(name); 
				//	suspects2[name] = sus;
				//	suspect.SetSuspectMap(suspects2); 

				//	//Add getline below. Can randomly generate height, hair and eye color; need enum of each trait
				//	std::string sexStr;
				//	std::string sex; 
				//	
				//	std::cout << "\nWhat is your character's sex? (Type 1 for male, 2 for female.) ";
				//	getline(std::cin, sexStr); 
				//	
				//	if (sexStr == "1" || sexStr == "2")
				//	{
				//		sexStr == "1" ? sex = "Male" : sex = "Female";

				//		//suspects[name] = { sex, "", "", "" }; 
				//		sus.SetSex(sex); 

				//		//std::cout << "What is your character's height? ";
				//		height = sus.GetHEIGHTS().at(rand() % sus.GetHEIGHTS().size());
				//		//suspects[name] = { sex, height, "", "" };
				//		sus.SetHeight(height);
				//		
				//		//std::cout << "What is your character's hair color? ";
				//		hairColor = sus.GetHAIRCOLORS().at(rand() % sus.GetHAIRCOLORS().size());
				//		//suspects[name] = { sex, height, hairColor, "" };
				//		sus.SetHairColor(hairColor);
				//		
				//		//std::cout << "What is your character's eye color? ";
				//		eyeColor = sus.GetEYECOLORS().at(rand() % sus.GetEYECOLORS().size());
				//		//suspects[name] = { sex, height, hairColor, eyeColor };
				//		sus.SetEyeColor(eyeColor);
				//		
				//		suspects2[name] = sus;
				//		suspect.SetSuspectMap(suspects2); 

				//		std::cout << "\n" << name << " has been added to the suspect list!\n" << std::endl; 

				//		for (std::map<std::string, Suspect>::iterator iter3 = suspects2.begin();
				//			iter3 != suspects2.end(); ++iter3)
				//		{
				//			if (sus.GetName() != iter3->second.GetName() && sus.GetSex() == iter3->second.GetSex()
				//				&& sus.GetHeight() == iter3->second.GetHeight()
				//				&& sus.GetHairColor() == iter3->second.GetHairColor()
				//				&& sus.GetEyeColor() == iter3->second.GetEyeColor())
				//			{
				//				std::cout << "\n" << iter3->second.GetName() << " has all the same characteristics as " <<
				//					name << "!\n"; 
				//				std::cout << "It is recommended that you remove one of these characters from the suspect list.\n"; 
				//				break; 
				//				//OR take out instead of recommending taking out; go back and regenerate characteristics again; 
				//				//use a while repeatSuspsect true around generated height, hair and eye color above
				//				//use an iterator inside while loop that increases by 1 and once it reaches 50,
				//				//calls break in case a unique character can't be formed,
				//				//gives error message to user (could not generate unique
				//				// suspect. All combinations of traits already exist.), and removes character from map.
				//			}
				//		}


				//		//output it to csv, using seralize function

				//		char delimiter = '*';
				//		std::ofstream outFile(file);

				//		for (std::map<std::string, Suspect>::iterator iter2 = suspects2.begin();
				//			iter2 != suspects2.end(); ++iter2)
				//		{
				//			iter2->second.Serialize(outFile, delimiter);
				//		}
				//		outFile.close();
				//	}

				//	else
				//	{
				//		std::cout << "\nInvalid input\n" << std::endl; 
				//		suspects2.erase(name); 
				//		suspect.SetSuspectMap(suspects2); 
				//	}

				//}
				break;
			}
			case 3:
				//Delete from map
				//output it to csv using serialize function
			{
				std::string name;
				std::cout << "\nWhat character would you like to remove from suspect list? ";
				getline(std::cin, name);
				//Check map if name exists
			
				std::map<std::string, Suspect> suspects2 = suspect.GetSuspectMap(); 

				std::map<std::string, Suspect>::iterator isFound = suspects2.find(name);

				if (isFound == suspects2.end())
				{
					std::cout << "\n" << name << " is not on the suspect list!\n" << std::endl;
				}

				else
				{

					suspects2.erase(name); 
					std::cout << "\n" << name << " has been removed from the suspect list!\n" << std::endl;
					suspect.SetSuspectMap(suspects2); 

				//output updated list to csv, using seralize function

					char delimiter = '*';
					std::ofstream outFile(file);

					for (std::map<std::string, Suspect>::iterator iter2 = suspects2.begin();
							iter2 != suspects2.end(); ++iter2)
						{
				
							iter2->second.Serialize(outFile, delimiter);
						}
						outFile.close();
				}

			
				break;
			}
			
			case 4:
			{
				//Delete map
				std::map<std::string, Suspect> suspects2; 
				suspect.SetSuspectMap(suspects2); 


				Suspect sus;

				//create 6 new suspects
				for (int i = 0; i < 6; ++i)
				{
					int randNameInt = rand() % 26; 
					std::string name = suspect.GetNAMES().at(randNameInt); 

					//int randSexInt = rand() % 2;
					std::string sex;  // = suspect.GetSEXES().at(randSexInt);

					if (randNameInt % 2 == 0)
					{
						sex = "Male";
					}

					else sex = "Female"; 

					int randHeightInt = rand() % 2;
					std::string height = suspect.GetHEIGHTS().at(randHeightInt);

					int randHairColorInt = rand() % 3;
					std::string hairColor = suspect.GetHAIRCOLORS().at(randHairColorInt);

					int randEyeColorInt = rand() % 3; 
					std::string eyeColor = suspect.GetEYECOLORS().at(randEyeColorInt);

					sus.SetName(name); 
					sus.SetSex(sex);
					sus.SetHeight(height);
					sus.SetHairColor(hairColor);
					sus.SetEyeColor(eyeColor); 

					//Go through current suspect map and make sure there is not another suspect
					//that has all the same characteristics as the suspect generated in this loop
					//even if the names are different
					bool allTraitsSame = false;

					for (std::map<std::string, Suspect>::iterator traitChecker = suspects2.begin();
						traitChecker != suspects2.end(); ++ traitChecker)
					{
						if (traitChecker->second.GetSex() == sus.GetSex() &&
							traitChecker->second.GetHeight() == sus.GetHeight() &&
							traitChecker->second.GetHairColor() == sus.GetHairColor() &&
							traitChecker->second.GetEyeColor() == sus.GetEyeColor())
						{
							allTraitsSame = true;
							break; 
						}
					}

					
					std::map<std::string, Suspect>::iterator isFound = suspects2.find(name); 

					//save suspect to map if names are different and all traits are not the same
					if (isFound == suspects2.end() && allTraitsSame == false)
					{

						suspects2[name] = sus;

						suspect.SetSuspectMap(suspects2);

						//output new map to csv using serialize function
						std::ofstream suspectFile(file);

						for (std::map<std::string, Suspect>::iterator serialIt = suspects2.begin();
								serialIt != suspects2.end(); ++serialIt)
						{
							serialIt->second.Serialize(suspectFile, traitDelimiter);
						}

						suspectFile.close();


					}
					else
					{
						//if name is duplicate of names in map or character has all the same traits as another
						//suspect in the map, then don't add suspect to map and remain at same point in for
						//loop that creates suspects so we still get 6 suspects in the end. 
						i--; 
					}

				}
				std::cout << "\nNew suspect list generated!\n" << std::endl; 
				break;
			}

			case 5:
			{
				//Select suspect key from map


				std::map<std::string, Suspect> suspects2 = suspect.GetSuspectMap(); 

				int randomNum = rand() % suspects2.size();

				std::map<std::string, Suspect>::iterator iterRand = suspects2.begin();

				std::advance(iterRand, randomNum);

				Suspect sus2 = iterRand->second;

				int numberOfGuesses = 1; 
				int numberOfClues = 0; 
				bool continuePlay = true; 
				int score = 10; 
				while (continuePlay)
				{
					std::cout << "Make a choice from the list below.\n";
					std::cout << "1. Guess who committed the crime!\n";
					std::cout << "2. Learn more about the suspect.\n";
					std::cout << "3. Print the suspect list.\n";
					std::cout << "4. Reveal the criminal!\n";

					std::string choiceStr;

					getline(std::cin, choiceStr);

					int choice = stoi(choiceStr);

					switch (choice)
					{
					case 1:
					{
						std::string suspectGuess;
						std::cout << "Who do you think committed the crime? "; 
						getline(std::cin, suspectGuess); 

						if (suspectGuess == sus2.GetName())
						{
							std::cout << "That's right!\n";
							std::cout << "The culprit is " << sus2.GetName() << "!\n";
							std::cout << "It took you " << numberOfGuesses; 
								
							if (numberOfGuesses == 1)
							{
								std::cout << " try to guess the culprit!\n";
							}

							else
							{
								std::cout << " tries to guess the culprit!\n";
							}

							std::cout << "Number of clues needed to guess culprit: " << numberOfClues << "\n"; 
							std::cout << "Total score [11 - (number of guesses + number of clues)] : " << std::max(score, 0) << "\n"
								<< std::endl; 

							continuePlay = false;
						}
						else
						{
							std::cout << "I'm sorry, that's wrong.\n";
							std::cout << "Total guesses so far: " << numberOfGuesses << "\n" << std::endl;
							numberOfGuesses++;
							score--; 
						}
						break;
					}
					case 2:
					{    

						std::cout << "What do you want to know about the suspect?\n";
						std::cout << "1. Sex\n";
						std::cout << "2. Height\n";
						std::cout << "3. Hair Color\n";
						std::cout << "4. Eye Color\n"; 

						std::string traitChoiceStr; 
						getline(std::cin, traitChoiceStr);

						int traitChoice = stoi(traitChoiceStr); 

						//If choose 2: What do you want to know? Sex, Height, Hair Color, Eye Color (1-4); based on choice;
						//print out value for that suspect key at that location in vector of values
						switch (traitChoice)
						{
						case 1:
						{
							std::cout << "The suspect's sex: " << sus2.GetSex() << "\n" << std::endl; 
							numberOfClues++; 
							score--; 
							break;
						}

						case 2:
						{
							std::cout << "The suspect's height: " << sus2.GetHeight() << "\n" << std::endl; 
							numberOfClues++;
							score--;
							break; 
						}

						case 3:
						{
							std::cout << "The suspect's hair color: " << sus2.GetHairColor() << "\n" << std::endl;
							numberOfClues++;
							score--;
							break;
						}

						case 4:
						{
							std::cout << "The suspect's eye color: " << sus2.GetEyeColor() << "\n" << std::endl;
							numberOfClues++;
							score--;
							break; 
						}

						default:
						{
							std::cout << "Invalid choice!\n" << std::endl; 
							break; 
						}

						}

						
						break;
					}
					case 3:
					{
						suspect.PrintSuspects(); 
						break;
					}
					case 4:
					{
						std::cout << "The culprit is " << sus2.GetName() << "!\n" << std::endl;
						continuePlay = false;
						break;
					}
					default:
					{
						std::cout << "Invalid choice!\n" << std::endl;
						break;
					}
					}
				}
				

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


