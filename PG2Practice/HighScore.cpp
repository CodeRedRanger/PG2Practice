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

void HighScore::Serialize(std::ofstream& outFile, char scoreDelimiter, std::vector<HighScore>& scores)
{
	for (HighScore score : scores)
	{
		outFile << score.GetName() << scoreDelimiter << score.GetScore() << "\n";
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


void HighScore::AddHighScore(HighScore& newScore, std::string HSFile, char scoreDelimiter)
{
	std::vector<HighScore> scores = this->GetHighScores(); 

	if (newScore.GetScore() > scores.at(9).GetScore())
	{

		for (std::vector<HighScore>::iterator iter = scores.begin();
			iter != scores.end(); ++iter)
		{	

			if (newScore.GetScore() > iter->GetScore())
			{
				scores.insert(iter, newScore);
				scores.erase(scores.end() - 1);
				this->SetHighScores(scores);
				this->SaveHighScores(HSFile, this->GetHighScores(), scoreDelimiter);
				this->PrintHighScores();
				break;
			}

		}


	}

}

void HighScore::SaveHighScores(std::string file, std::vector<HighScore> scores, char scoreDelimiter)
{
	std::ofstream outFile(file);

	if (outFile.is_open())
	{
		//file open
	}
	else
	{
		std::cout << file << " was not opened!\n" << std::endl; 
	}

	this->Serialize(outFile, scoreDelimiter, scores); 


	outFile.close(); 

}
