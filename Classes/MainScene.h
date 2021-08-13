#pragma once

#include "cocos2d.h"

using namespace cocos2d;

class MainScene : public Layer
{
public:
    static Scene* createScene();

    virtual bool init();

	//게임 화면 
	void initGameUI();
	void initGameUISpr();
	void pauseCallback(Ref* pSender);
	//

	//옵션에서 사용
	void createOption();
	void initOption();
	void initOptionSpr();
	void initCredit();
	void optionCallback(Ref * pSender);
	//

	//공통
	virtual bool onTouchBegan(Touch *touch, Event *unused_event);
	virtual void onTouchMoved(Touch *touch, Event *unused_event);
	virtual void onTouchEnded(Touch *touch, Event *unused_event);
	//

	Layer* layer_game;
	LayerColor* layer_option;
	LayerColor* layer_credit;

	//게임 화면에서 사용
	Sprite* spr_touch2start;
	Sprite* spr_pause;
	Sprite* spr_pause_sel;

	Menu* menu_pause;
	MenuItemSprite* menui_pause;
	//

	//옵션 화면에서 사용
	Sprite* spr_option_box;
	Sprite* spr_option_box_bgm;
	Sprite* spr_option_box_fx;
	Sprite* spr_option_box_credit;
	Sprite* spr_cross;
	Sprite* spr_cross_sel;
	Sprite* spr_credit_cross;
	Sprite* spr_credit_cross_sel;
	Sprite* spr_bgm_on;
	Sprite* spr_bgm_off;
	Sprite* spr_fx_on;
	Sprite* spr_fx_off;
	Sprite* spr_credit;
	Sprite* spr_credit_sel;
	Sprite* spr_bgm;
	Sprite* spr_fx;

	Menu* menu_option;
	Menu* menu_credit;
	MenuItemSprite* menui_credit_cross;
	MenuItemSprite* menui_cross;
	MenuItemSprite* menui_bgm;
	MenuItemSprite* menui_fx;
	MenuItemSprite* menui_credit;
	//

	//크레딧에서 사용
	Sprite* spr_credit_box;

	Label* lab_credit_makers;
	//

    CREATE_FUNC(MainScene);
};


