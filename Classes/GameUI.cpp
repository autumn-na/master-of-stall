#include "MainScene.h"
#include "Defines.h"

void MainScene::initGameUI()
{
	initGameUISpr();

	menui_pause = MenuItemSprite::create(spr_pause, spr_pause, CC_CALLBACK_1(MainScene::pauseCallback, this));
	menui_pause->setPosition(SCREEN_WIDTH - 70, SCREEN_HEIGHT - 100);
	menui_pause->setVisible(false);

	menu_pause = Menu::create(menui_pause, NULL);
	menu_pause->setPosition(0, 0);

	this->addChild(menu_pause);
}

void MainScene::initGameUISpr()
{
	spr_touch2start = Sprite::create("touch2start.png");
	spr_touch2start->setPosition(Vec2(SCREEN_WIDTH / 2, SCREEN_HEIGHT / 2));
	spr_touch2start->setScale(5.0f);
	this->addChild(spr_touch2start, 1);

	spr_pause = Sprite::create("button_pause.png");
	spr_pause_sel = Sprite::create("button_pause_sel.png");
}

void MainScene::pauseCallback(Ref * pSender)
{
	layer_option->setVisible(true);
	menu_pause->setVisible(false);

	this->setTouchEnabled(false);
}