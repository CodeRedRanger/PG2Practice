#include "HighScore.h"

void HighScore::Deserialize(std::string scoreStr, char scoreDelimiter)
{

	std::stringstream nameScore(scoreStr);
	std::string nameOrScoreStr; 
	int counter = 0; 

	while (std::getline(nameScore, nameOrScoreStr, scoreDelimiter))
	{
		if (counter == 0)
		{
			this->SetName(nameOrScoreStr); 
			counter++; 
		}

		else
		{
			this->SetScore(stoi(nameOrScoreStr));
			counter = 0; 
		}


	}	


}

void HighScore::LoadHighScores(const std::string file, const char scoreDelimiter)
{
	std::cout << "\n-----HIGH SCORES-----\n"; 

	std::ifstream HighScores(file);

	if (HighScores.is_open())
	{
		//File open
	}

	else
	{
		std::cout << file << " could not be opened.\n" << std::endl;
	}

	std::string nameAndScore;
	std::vector<HighScore> scores; 

	while (std::getline(HighScores, nameAndScore))
	{
		
		//new highScore is doesn't have variables set
		HighScore highScore(nameAndScore, scoreDelimiter); 
		scores.push_back(highScore);		

	}

	HighScores.close();

	this->SetHighScores(scores); 


}

void HighScore::PrintHighScores() 
{
	std::vector<HighScore> scores = this->GetHighScores(); 

	for (HighScore hs : scores)
	{
		std::string name = hs.GetName();
		int score = hs.GetScore();
		std::cout << std::left << std::setw(20) << name << std::right << score << std::endl;

	}

	std::cout << std::endl;


}



void HighScore::AddHighScore(int score)
{

}
