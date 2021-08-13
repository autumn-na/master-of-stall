#pragma once

#include "cocos2d.h"

using namespace cocos2d;

class Management
{
private:
	Management() {}
	~Management() {}
	static Management* inst;

public:
	static Management* getInstance()
	{
		if (inst == nullptr)
		{
			inst = new Management();
		}
		return inst;
	}

public:
	bool bgm_status = true;
	bool fx_status = true;
	bool isPlaying = false;

	int present_score;
	int result_score = 0;
	int highscore = 1;
};