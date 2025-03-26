#pragma once

#include <iostream>
#include <vector>
#include <string>
#include <fstream>
#include <sstream>
#include <iomanip>



class HighScore
{

private:
	std::string m_name; 
	int m_score; 
	std::vector<HighScore> m_scores;

public: 

	HighScore()
	{
		m_name = ""; 
		m_score = 0; 
	}

	HighScore(std::string scoreStr, char scoreDelimiter)
	{
		Deserialize(scoreStr, scoreDelimiter);
	}

	void Deserialize(std::string scoreStr, char scoreDelimiter); 

	//serialize function here

	void LoadHighScores(const std::string file, const char scoreDelimiter);

	void PrintHighScores();

	void AddHighScore(std::string name, int score);


	//Getters and setters
	const std::string GetName() const
	{
		return m_name; 
	}

	void SetName(const std::string& newName)
	{
		m_name = newName; 
	}

	const int GetScore() const
	{
		return m_score;
	}

	void SetScore(const int newScore)
	{
		m_score = newScore;
	}

	std::vector<HighScore>& GetHighScores() 
	{
		return m_scores;
	}

	void SetHighScores(const std::vector<HighScore>& newScores)
	{
		m_scores = newScores;
	}

	


};

