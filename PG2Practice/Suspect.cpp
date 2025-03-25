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

void Suspect::AddSuspect(std::string file)
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
					std::cout << "\n" << iter3->second.GetName() << " has all the same characteristics as " <<
						name << "!\n";
					std::cout << "It is recommended that you remove one of these characters from the suspect list.\n";
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

			char delimiter = '*';
			std::ofstream outFile(file);

			for (std::map<std::string, Suspect>::iterator iter2 = suspects2.begin();
				iter2 != suspects2.end(); ++iter2)
			{
				iter2->second.Serialize(outFile, delimiter);
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
