#pragma once

#include "cocos2d.h"
#include "Management.h"

using namespace cocos2d;

class GameOverScene : public Layer
{
public:
	static cocos2d::Scene* createScene();

	virtual bool init();
	
	void initLabel();
	void initSprite();
	void initButton();

	void go2StartCallback(Ref* pSender);

	Label* lab_highscore;
	Label* lab_result_score;

	Sprite* spr_bg_gameover;
	Sprite* spr_go2start;
	Sprite* spr_go2start_sel;

	Menu* menu_gameover;
	MenuItemSprite* menui_go2start;

	CREATE_FUNC(GameOverScene);
};
