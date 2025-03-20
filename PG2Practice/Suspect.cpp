#include "Suspect.h"


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
