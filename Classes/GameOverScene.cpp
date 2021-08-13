#pragma execution_character_set("utf-8")

#include "Defines.h"
#include "MainScene.h"
#include "GameOverScene.h"
#include "SimpleAudioEngine.h"

USING_NS_CC;

Scene* GameOverScene::createScene()
{
	auto scene = Scene::create();

	auto layer = GameOverScene::create();

	scene->addChild(layer);

	return scene;
}

bool GameOverScene::init()
{
	if (!Layer::init())
	{
		return false;
	}

	initLabel();
	initSprite();
	initButton();

	return true;
}

void GameOverScene::initLabel()
{
	lab_highscore = Label::createWithSystemFont(StringUtils::format("최고점수 : %d", Management::getInstance()->highscore), "BM DoHyeon", 30, Size(300, 200), TextHAlignment::LEFT, TextVAlignment::CENTER);
	lab_highscore->setPosition(200, 500);
	this->addChild(lab_highscore, 10);

	lab_result_score = Label::createWithSystemFont(StringUtils::format("점수 : %d", Management::getInstance()->result_score), "BM DoHyeon", 30, Size(300, 200), TextHAlignment::LEFT, TextVAlignment::CENTER);
	lab_result_score->setPosition(200, 450);
	this->addChild(lab_result_score, 10);
}

void GameOverScene::initSprite()
{
	spr_bg_gameover = Sprite::create("bg_gameover.png");
	spr_bg_gameover->setPosition(SCREEN_WIDTH / 2, SCREEN_HEIGHT / 2);
	spr_bg_gameover->setScale(5.0f);
	spr_bg_gameover->getTexture()->setAliasTexParameters();
	this->addChild(spr_bg_gameover);

	spr_go2start = Sprite::create("button_go2start.png");
	spr_go2start->getTexture()->setAliasTexParameters();
	spr_go2start_sel = Sprite::create("button_go2start_sel.png");
}

void GameOverScene::initButton()
{
	menui_go2start = MenuItemSprite::create(spr_go2start, spr_go2start, CC_CALLBACK_1(GameOverScene::go2StartCallback, this));
	menui_go2start->setPosition(SCREEN_WIDTH / 2, SCREEN_HEIGHT / 2);
	menui_go2start->setScale(5.5f);
	menui_go2start->setPosition(SCREEN_WIDTH / 2, SCREEN_HEIGHT / 2 - 50);
	
	menu_gameover = Menu::create(menui_go2start, NULL);
	menu_gameover->setPosition(0, 0);

	this->addChild(menu_gameover);
}


void GameOverScene::go2StartCallback(Ref* pSender)
{
	auto scene_start = MainScene::createScene();
	Director::getInstance()->replaceScene(scene_start);
}
