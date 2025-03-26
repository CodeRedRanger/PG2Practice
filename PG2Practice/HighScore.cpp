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

	std::cout << "\n-----HIGH SCORES-----\n";

	for (HighScore hs : scores)
	{
		std::string name = hs.GetName();
		int score = hs.GetScore();
		std::cout << std::left << std::setw(20) << name << std::right << score << std::endl;

	}

	std::cout << std::endl;


}


//void HighScore::AddHighScore(std::string name, int score)
void HighScore::AddHighScore(HighScore& newScore)
{
	std::vector<HighScore> scores = this->GetHighScores(); 

	if (newScore.GetScore() > scores.at(9).GetScore())
	{

		//scores.at(9).SetName(name);
		//scores.at(9).SetScore(score); 

		//int temp; 
		//std::string tempName; 
		for (std::vector<HighScore>::iterator iter = scores.begin();
			iter != scores.end(); ++iter)
		{	

		/*	if (score >= iter->GetScore())
			{
				temp = iter->GetScore();
				tempName = iter->GetName(); 
				iter->SetScore(score); 
				iter->SetName(name); 
				score = temp; 
				name = tempName; 
			}*/

			if (newScore.GetScore() > iter->GetScore())
			{
				scores.insert(iter, newScore);
				scores.erase(scores.end() - 1);
				this->SetHighScores(scores);
				//HighScore::SaveHighScores(highScoreFile, highScores); Serialize
				this->PrintHighScores();
				break;
			}


		}



		//this->SetHighScores(scores); 
		//this->PrintHighScores(); 

	}

}
/*
 
			  {
				  highScores.insert(i, newHighScore);
				  highScores.erase(highScores.end() - 1);
				  HighScore::SaveHighScores(highScoreFile, highScores);
				  HighScore::ShowHighScores(highScores);
				  break;
			  }

*/