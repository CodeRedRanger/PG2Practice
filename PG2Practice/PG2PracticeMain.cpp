//Purpose of project
//Guess Who

//Menu:
//1. Load map of suspects  check
//2. Change map of suspects: Create  your own character...
//3. Play Who did it! ... Someone spotted a ... "Bald man in a black shirt with big ears! Who was it??
//Map is a name string key and a vector of traits that are string, bool or int
//Traits: Tall or short; bald, short hair, long hair; skin: light, medium, dark; ears: big or small; eyes: blue, brown, green
//Nose big, medium, small; Glasses yes or no; male or female
//Character class
//Create a vector of unique pointers to maps -> creates random character sets


//Displays all the character names
//Pick a character
//Pick a question
//Guess who did it
//1. Male/female
//2. Tall/short ...
//Answer: This person is a male; this person is short

#include <iostream>
#include <memory>
#include <map> // for map
#include <vector>
#include <fstream> //for input stream
#include <string>
#include <sstream> //for stringstream
#include "Suspect.h"

int main()
{
	srand(time(0)); 
	
	//take this out
	std::map <std::string, std::vector<std::string>> suspects; 
	
	std::map <std::string, std::vector<Suspect>> suspects2

	std::string file = "Suspects.csv"; 


	std::ifstream suspectFile(file);
	std::string suspect; 
	char traitDelimiter = '*'; 
	
	//take this out
	//std::vector<std::string> susTraitVec;

	//vector of suspects
	std::vector<Suspect> suspectVec; 

	while (std::getline(suspectFile, suspect))
	{
	
		//std::stringstream susTraits(suspect); 
		//std::string trait; 
		

		//while (std::getline(susTraits, trait, traitDelimiter))
		//{
		//create suspect
		Suspect nextSus(suspect, traitDelimiter); 
		suspectVec.push_back(nextSus); 

		//create vector of suspects, and then feed into map instead of vector traits
		//susTraitVec.push_back(trait); 
		//}
	}

	suspectFile.close();

	//for (std::vector<std::string>::iterator it = susTraitVec.begin(); it != susTraitVec.end(); it += 5) 
	for (std::vector<Suspect>::iterator it = suspectVec.begin(); it != suspectVec.end(); ++it)
	{

		suspects[it->GetName()] = {(it->GetSex()), (it->GetHeight()), (it->GetHairColor()), (it->GetEyeColor())};


	}

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

	std::string choiceStr; 
	getline(std::cin, choiceStr); 
	int choice = stoi(choiceStr); 


		switch (choice)
		{
			case 1:
			{
				//could just print from vector of suspects, but since I created map, will do below

				std::map<std::string, std::vector<std::string>>::iterator iter = suspects.begin();
				//change this iterator to string/Suspect ***********
				std::map < std::string, std::vector<Suspect>::iterator iterA = suspects2.begin(); 

				std::string suspectName = iter->first;
				std::vector<std::string> traits = iter->second;

				std::cout << "-----SUSPECTS-----\n" << std::endl;

				while (iter != suspects.end())
				{
					suspectName = iter->first;
					traits = iter->second;

					std::cout << "Suspect name: " << suspectName << std::endl;

					for (int i = 0; i < iter->second.size(); ++i)
					{
						switch (i)
						{
						case 0:
							std::cout << "Sex: " << iter->second.at(i) << std::endl;
							break;

						case 1:
							std::cout << "Height: " << iter->second.at(i) << std::endl;
							break;

						case 2:
							std::cout << "Hair Color: " << iter->second.at(i) << std::endl;
							break;

						case 3:
							std::cout << "Eye Color: " << iter->second.at(i) << "\n" << std::endl;
							break;

						default:
							break;
						}
					}
					++iter;
				}
			}
			//end of outer case 1
			break;
		
			case 2:
			{
				std::string name;
				std::string sex;
				std::string height;
				std::string	hairColor;
				std::string eyeColor;
				std::cout << "What is your character's name? ";
				getline(std::cin, name);
				//Check map if name exists
				std::map<std::string, std::vector<std::string>>::iterator isFound = suspects.find(name);

				if (isFound != suspects.end())
				{
					std::cout << "That suspect name already exists!\n" << std::endl;
				}

				else
				{
					Suspect sus; 

					//Add to map if name doesn't exist
					auto isInserted = suspects.insert(std::make_pair(name, std::vector<std::string>{"", "", "", ""}));
					//suspects[name] = { "","","",""};

					//Add getline below. Can randomly generate height, hair and eye color; need enum of each trait
					std::string sexStr;
					std::string sex; 
					
					std::cout << "What is your character's sex? (Type 1 for male, 2 for female.) ";
					getline(std::cin, sexStr); 
					
					if (sexStr == "1" || sexStr == "2")
					{
						sexStr == "1" ? sex = "Male" : sex = "Female";


						suspects[name] = { sex, "", "", "" };
						//std::cout << "What is your character's height? ";
						height = sus.HEIGHTS.at(rand() % sus.HEIGHTS.size());
						suspects[name] = { sex, height, "", "" };
						//std::cout << "What is your character's hair color? ";
						hairColor = sus.HAIRCOLOR.at(rand() % sus.HAIRCOLOR.size());
						suspects[name] = { sex, height, hairColor, "" };
						//std::cout << "What is your character's eye color? ";
						eyeColor = sus.EYECOLOR.at(rand() % sus.EYECOLOR.size());
						suspects[name] = { sex, height, hairColor, eyeColor };


						//output it to csv, using seralize function

						char delimiter = '*';
						std::ofstream outFile(file);

						for (std::map<std::string, std::vector<std::string>>::iterator iter2 = suspects.begin();
							iter2 != suspects.end(); ++iter2)
						{
							sus.SetName(iter2->first);
							sus.SetSex(iter2->second.at(0));
							sus.SetHeight(iter2->second.at(1));
							sus.SetHairColor(iter2->second.at(2));
							sus.SetEyeColor(iter2->second.at(3));
							sus.Serialize(outFile, delimiter);
						}
						outFile.close();
					}

					else
					{
						std::cout << "\nInvalid input\n" << std::endl; 
						suspects.erase(name); 
					}

				}
				break;
			}
			case 3:
				//Delete from map
				//output it to csv using serialize function
				break; 
			
			case 4:
				//Delete map
				//Create enum of names, sex, height, hair color, eye color
				//Go through loop of 6; generate random choice from each enum
				//Add those to the map as key string and value vector of strings
				//output it to csv using serialize function
				break; 

			case 5:
				//Select suspect key from map
				//Choose 1 (1. Guess who did it? 2. Learn more about suspect? 3. Tell me who did it. 4. Print Suspect list)
				//If choose 1. -> Who did it? List of suspects 1-6, and choose. If correct: You guessed right! and back to main menu
				//if choose wrong. Sorry that's wrong, and back to prior menu (1-3)
				//If choose 2: What do you want to know? Sex, Height, Hair Color, Eye Color (1-4); based on choice;
				//print out value for that suspect key at that location in vector of values
				//3. Print out key name
				//4. Print suspect list as above (can create deseralize function)

				break;

			case 6:
				gameOver = true; 
				break; 

			default:
				break; 

		}

	}

	return 0; 
}


