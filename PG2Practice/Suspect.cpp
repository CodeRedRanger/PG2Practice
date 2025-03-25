#include "Suspect.h"

std::map<std::string, Suspect> Suspect::LoadSuspects(std::string file, char traitDelimiter)
{

	std::ifstream suspectFile(file);
	std::string suspectNew;

	//vector of suspects
	std::vector<Suspect> suspectVec;

	while (std::getline(suspectFile, suspectNew))
	{

		//create suspect
		Suspect nextSus(suspectNew, traitDelimiter);
		suspectVec.push_back(nextSus);

	}

	suspectFile.close();

	std::map<std::string, Suspect> suspects;

	for (std::vector<Suspect>::iterator it = suspectVec.begin(); it != suspectVec.end(); ++it)
	{

		suspects[it->GetName()] = *it;

	}


	return suspects; 

}

void Suspect::PrintSuspects()
{

	std::map<std::string, Suspect> suspects2 = GetSuspectMap(); 

	std::map <std::string, Suspect>::iterator iter = suspects2.begin();

	std::string suspectName = iter->first;

	Suspect traits = iter->second;

	std::cout << "\n-----SUSPECTS-----\n" << std::endl;

	while (iter != suspects2.end())
	{
		suspectName = iter->first;
		traits = iter->second;

		std::cout << "Suspect name: " << suspectName << std::endl;

		for (int i = 0; i < suspects2.size(); ++i)
		{
			switch (i)
			{
			case 0:
				std::cout << "Sex: " << iter->second.GetSex() << std::endl;
				break;

			case 1:
				std::cout << "Height: " << iter->second.GetHeight() << std::endl;
				break;

			case 2:
				std::cout << "Hair Color: " << iter->second.GetHairColor() << std::endl;
				break;

			case 3:
				std::cout << "Eye Color: " << iter->second.GetEyeColor() << "\n" << std::endl;
				break;

			default:
				break;
			}
		}
		++iter;
	}


}

void Suspect::AddSuspect(const std::string& file, const char traitDelimiter)
{
	std::string name;
	std::string sex;
	std::string height;
	std::string	hairColor;
	std::string eyeColor;
	std::cout << "\nWhat is your character's name? ";
	getline(std::cin, name);
	//Check map if name exists

	std::map<std::string, Suspect> suspects2 = this->GetSuspectMap();
	std::map<std::string, Suspect>::iterator isFound = suspects2.find(name);

	if (isFound != suspects2.end())
	{
		std::cout << "\nThat suspect name already exists!\n" << std::endl;
	}

	else
	{
		Suspect sus;
		//Add to map if name doesn't exist
		//auto isInserted = suspects.insert(std::make_pair(name, std::vector<std::string>{"", "", "", ""}));
		//suspects[name] = { "","","",""};
		auto isInserted = suspects2.insert(std::make_pair(name, sus));

		sus.SetName(name);
		suspects2[name] = sus;
		this->SetSuspectMap(suspects2);

		//Add getline below. Can randomly generate height, hair and eye color
		std::string sexStr;
		std::string sex;

		std::cout << "\nWhat is your character's sex? (Type 1 for male, 2 for female.) ";
		getline(std::cin, sexStr);

		if (sexStr == "1" || sexStr == "2")
		{
			sexStr == "1" ? sex = "Male" : sex = "Female";

			sus.SetSex(sex);

			height = sus.GetHEIGHTS().at(rand() % sus.GetHEIGHTS().size());
			sus.SetHeight(height);

			hairColor = sus.GetHAIRCOLORS().at(rand() % sus.GetHAIRCOLORS().size());
			sus.SetHairColor(hairColor);

			eyeColor = sus.GetEYECOLORS().at(rand() % sus.GetEYECOLORS().size());
			sus.SetEyeColor(eyeColor);

			suspects2[name] = sus;
			this->SetSuspectMap(suspects2);

			std::cout << "\n" << name << " has been added to the suspect list!\n" << std::endl;

			//Warns player if new suspect has all of the same traits as another suspect (this will make game harder)
			for (std::map<std::string, Suspect>::iterator iter3 = suspects2.begin();
				iter3 != suspects2.end(); ++iter3)
			{
				if (sus.GetName() != iter3->second.GetName() && sus.GetSex() == iter3->second.GetSex()
					&& sus.GetHeight() == iter3->second.GetHeight()
					&& sus.GetHairColor() == iter3->second.GetHairColor()
					&& sus.GetEyeColor() == iter3->second.GetEyeColor())
				{
					std::cout << iter3->second.GetName() << " has all the same characteristics as " <<
						name << "!\n";
					std::cout << "It is recommended that you remove one of these characters from the suspect list.\n" << std::endl;
					break;
					//OR take out instead of recommending taking out; go back and regenerate characteristics again; 
					//use a while repeatSuspsect true around generated height, hair and eye color above
					//use an iterator inside while loop that increases by 1 and once it reaches 50,
					//calls break in case a unique character can't be formed,
					//gives error message to user (could not generate unique
					// suspect. All combinations of traits already exist.), and removes character from map.
				}
			}


			//output it to csv, using seralize function
			std::ofstream outFile(file);

			for (std::map<std::string, Suspect>::iterator iter2 = suspects2.begin();
				iter2 != suspects2.end(); ++iter2)
			{
				iter2->second.Serialize(outFile, traitDelimiter);
			}
			outFile.close();
		}

		else
		{
			std::cout << "\nInvalid input\n" << std::endl;
			suspects2.erase(name);
			this->SetSuspectMap(suspects2);
		}

	}


}

void Suspect::RemoveSuspect(const std::string& file, const char traitDelimiter)
{
	std::string name;
	std::cout << "\nWhat character would you like to remove from suspect list? ";
	getline(std::cin, name);

	//Check map if name exists
	std::map<std::string, Suspect> suspects2 = this->GetSuspectMap();

	std::map<std::string, Suspect>::iterator isFound = suspects2.find(name);

	if (isFound == suspects2.end())
	{
		std::cout << "\n" << name << " is not on the suspect list!\n" << std::endl;
	}

	else
	{

		suspects2.erase(name);
		std::cout << "\n" << name << " has been removed from the suspect list!\n" << std::endl;
		this->SetSuspectMap(suspects2);

		//output updated list to csv, using seralize function

		//char delimiter = '*';
		std::ofstream outFile(file);

		for (std::map<std::string, Suspect>::iterator iter2 = suspects2.begin();
			iter2 != suspects2.end(); ++iter2)
		{

			iter2->second.Serialize(outFile, traitDelimiter);
		}
		outFile.close();
	}
}

void Suspect::NewSuspectList(const std::string& file, const char traitDelimiter)
{

	//Delete map
	std::map<std::string, Suspect> suspects2;
	this->SetSuspectMap(suspects2);

	Suspect sus;

	//create 6 new suspects
	for (int i = 0; i < 6; ++i)
	{
		int randNameInt = rand() % 26;
		std::string name = this->GetNAMES().at(randNameInt);

		std::string sex;  

		//In NAMES vector of strings, all even names are male, odd names are female
		if (randNameInt % 2 == 0)
		{
			sex = "Male";
		}

		else sex = "Female";

		int randHeightInt = rand() % 2;
		std::string height = this->GetHEIGHTS().at(randHeightInt);

		int randHairColorInt = rand() % 3;
		std::string hairColor = this->GetHAIRCOLORS().at(randHairColorInt);

		int randEyeColorInt = rand() % 3;
		std::string eyeColor = this->GetEYECOLORS().at(randEyeColorInt);

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
			traitChecker != suspects2.end(); ++traitChecker)
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

		}
		else
		{
			//if name is duplicate of names in map or character has all the same traits as another
			//suspect in the map, then don't add suspect to map and remain at same point in for
			//loop that creates suspects so we still get 6 suspects in the end. 
			i--;
		}

	}

	this->SetSuspectMap(suspects2);

	//output new map to csv using serialize function
	std::ofstream suspectFile(file);

	for (std::map<std::string, Suspect>::iterator serialIt = suspects2.begin();
		serialIt != suspects2.end(); ++serialIt)
	{
		serialIt->second.Serialize(suspectFile, traitDelimiter);
	}

	suspectFile.close();


	std::cout << "\nNew suspect list generated!\n" << std::endl;

}

void Suspect::PlayGame()
{
	//Select suspect key from map
	std::map<std::string, Suspect> suspects2 = this->GetSuspectMap();

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
				std::cout << "\nWho do you think committed the crime? ";
				getline(std::cin, suspectGuess);

				if (suspectGuess == sus2.GetName())
				{
					std::cout << "\nThat's right!\n";
					std::cout << "The culprit is " << sus2.GetName() << "!\n";
					std::cout << "\nIt took you " << numberOfGuesses;

					if (numberOfGuesses == 1)
					{
						std::cout << " try to guess the culprit!\n";
					}

					else
					{
						std::cout << " tries to guess the culprit!\n";
					}

					std::cout << "Number of clues needed to guess culprit: " << numberOfClues << "\n";
					std::cout << "\nTotal score [11 - (number of guesses + number of clues)] : " << std::max(score, 0) << "\n"
						<< std::endl;

					continuePlay = false;
				}
				else
				{
					std::cout << "\nI'm sorry, that's wrong.\n";
					std::cout << "Total guesses so far: " << numberOfGuesses << "\n" << std::endl;
					numberOfGuesses++;
					score--;
				}
				break;
			}
			case 2:
			{

				std::cout << "\nWhat do you want to know about the suspect?\n";
				std::cout << "1. Sex\n";
				std::cout << "2. Height\n";
				std::cout << "3. Hair Color\n";
				std::cout << "4. Eye Color\n";

				std::string traitChoiceStr;
				getline(std::cin, traitChoiceStr);

				int traitChoice = stoi(traitChoiceStr);

				switch (traitChoice)
				{
					case 1:
					{
						std::cout << "\nThe suspect's sex: " << sus2.GetSex() << "\n" << std::endl;
						numberOfClues++;
						score--;
						break;
					}

					case 2:
					{
						std::cout << "\nThe suspect's height: " << sus2.GetHeight() << "\n" << std::endl;
						numberOfClues++;
						score--;
						break;
					}

					case 3:
					{
						std::cout << "\nThe suspect's hair color: " << sus2.GetHairColor() << "\n" << std::endl;
						numberOfClues++;
						score--;
						break;
					}

					case 4:
					{
						std::cout << "\nThe suspect's eye color: " << sus2.GetEyeColor() << "\n" << std::endl;
						numberOfClues++;
						score--;
					break;
					}

					default:
					{
						std::cout << "\nInvalid choice!\n" << std::endl;
						break;
					}

				}

				break;
			}
			case 3:
			{
				this->PrintSuspects();
				break;
			}
			case 4:
			{
				std::cout << "\nThe culprit is " << sus2.GetName() << "!\n" << std::endl;
				continuePlay = false;
				break;
			}
			default:
			{
				std::cout << "\nInvalid choice!\n" << std::endl;
				break;
			}
		}
	}

}


void Suspect::Serialize(std::ofstream& outFile, char delimiter)
{
   outFile << m_name << delimiter << m_sex << delimiter << m_height << delimiter << m_hairColor << delimiter << m_eyeColor << "\n";
     
}

void Suspect::Deserialize(std::string csvData, char delimiter)
{
	//std::map <std::string, std::vector<std::string>> suspects;


	//std::ifstream suspectFile(file);
	//std::string suspect;
	
	//pass this to this function
	//char traitDelimiter = '*';
	
	//std::vector<std::string> susTraitVec;

	//while (std::getline(suspectFile, suspect))
	//{

		std::stringstream susTraits(csvData);
		std::string trait;


		for (int i = 0; i < 5; ++i)
		{
			std::getline(susTraits, trait, delimiter); 
			if (i == 0) this->SetName(trait);
			if (i == 1) this->SetSex(trait);
			if (i == 2) this->SetHeight(trait);
			if (i == 3) this->SetHairColor(trait);
			if (i == 4) this->SetEyeColor(trait);
		}
			//susTraitVec.push_back(trait);
		
	

	//suspectFile.close();

	//for (std::vector<std::string>::iterator it = susTraitVec.begin(); it != susTraitVec.end(); it += 5)
	//{

	//	suspects[*it] = { (*(it + 1)), (*(it + 2)), (*(it + 3)), (*(it + 4)) };


	//}

}
