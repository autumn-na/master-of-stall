#pragma once
#pragma execution_character_set("utf-8")

#include "MainScene.h"
#include "Defines.h"
#include "Management.h"

void MainScene::initOption()
{
	initOptionSpr();
	initCredit();

	menui_cross = MenuItemSprite::create(spr_cross, spr_cross_sel, CC_CALLBACK_1(MainScene::optionCallback, this));
	menui_cross->setPosition(SCREEN_WIDTH - 97.5, 203);
	menui_cross->setScale(5.0f);
	menui_cross->setName("CROSS");

	menui_bgm = MenuItemSprite::create(spr_bgm, spr_bgm, CC_CALLBACK_1(MainScene::optionCallback, this));
	menui_bgm->setPosition(SCREEN_WIDTH / 2, spr_option_box_bgm->getPositionY());
	menui_bgm->setScale(5.0f);
	menui_bgm->setName("BGM");

	menui_fx = MenuItemSprite::create(spr_fx, spr_fx, CC_CALLBACK_1(MainScene::optionCallback, this));
	menui_fx->setPosition(SCREEN_WIDTH / 2, spr_option_box_fx->getPositionY());
	menui_fx->setScale(5.0f);
	menui_fx->setName("FX");

	menui_credit = MenuItemSprite::create(spr_credit, spr_credit, CC_CALLBACK_1(MainScene::optionCallback, this));
	menui_credit->setPosition(SCREEN_WIDTH / 2, spr_option_box_credit->getPositionY());
	menui_credit->setScale(5.0f);
	menui_credit->setName("CREDIT");

	menu_option = Menu::create(menui_cross, menui_fx, menui_bgm, menui_credit, NULL);
	menu_option->setPosition(0, 0);

	layer_option->addChild(menu_option);
}

void MainScene::initCredit()
{
	spr_credit_box = Sprite::create("credit_box.png");
	spr_credit_box->setPosition(SCREEN_WIDTH / 2, SCREEN_HEIGHT / 2);
	spr_credit_box->setScale(4.f);
	spr_credit_box->getTexture()->setAliasTexParameters();
	layer_credit->addChild(spr_credit_box);

	spr_credit_cross = Sprite::create("button_cross.png");
	spr_credit_cross->getTexture()->setAliasTexParameters();

	spr_credit_cross_sel = Sprite::create("button_cross_sel.png");
	spr_credit_cross_sel->getTexture()->setAliasTexParameters();

	menui_credit_cross = MenuItemSprite::create(spr_credit_cross, spr_credit_cross_sel, CC_CALLBACK_1(MainScene::optionCallback, this));
	menui_credit_cross->setPosition(SCREEN_WIDTH - 60, 140);
	menui_credit_cross->setScale(5.0f);
	menui_credit_cross->setName("CREDIT_CROSS");

	menu_credit = Menu::create(menui_credit_cross, NULL);
	menu_credit->setPosition(0, 0);

	lab_credit_makers = Label::createWithSystemFont("제작자\n한국게임과학고등학교\n팀장 고현성\n       김건희\n       나민형\n       나현강\n", "BM DoHyeon", 26, Size(300, 200),TextHAlignment::CENTER, TextVAlignment::CENTER);
	lab_credit_makers->setPosition(SCREEN_WIDTH / 2, SCREEN_HEIGHT / 2 + 100);
	layer_credit->addChild(lab_credit_makers);

	layer_credit->addChild(menu_credit, 10);
}

void MainScene::initOptionSpr()
{
	spr_option_box = Sprite::create("option_box.png");
	spr_option_box->setPosition(SCREEN_WIDTH / 2, SCREEN_HEIGHT / 2);
	spr_option_box->setScale(5.0f);
	spr_option_box->getTexture()->setAliasTexParameters();
	layer_option->addChild(spr_option_box);

	spr_option_box_bgm = Sprite::create("option_box_bgm.png");
	spr_option_box_bgm->setPosition(SCREEN_WIDTH / 2, 406);
	spr_option_box_bgm->setScale(5.0f);
	spr_option_box_bgm->getTexture()->setAliasTexParameters();
	layer_option->addChild(spr_option_box_bgm);

	spr_option_box_fx = Sprite::create("option_box_fx.png");
	spr_option_box_fx->setPosition(SCREEN_WIDTH / 2, 331);
	spr_option_box_fx->setScale(5.0f);
	spr_option_box_fx->getTexture()->setAliasTexParameters();
	layer_option->addChild(spr_option_box_fx);

	spr_option_box_credit = Sprite::create("option_box_credit.png");
	spr_option_box_credit->setPosition(SCREEN_WIDTH / 2, 255.2);
	spr_option_box_credit->setScale(5.0f);
	spr_option_box_credit->getTexture()->setAliasTexParameters();
	layer_option->addChild(spr_option_box_credit);

	spr_cross = Sprite::create("button_cross.png");
	spr_cross->getTexture()->setAliasTexParameters();

	spr_cross_sel = Sprite::create("button_cross_sel.png");
	spr_cross_sel->getTexture()->setAliasTexParameters();

	spr_bgm_on = Sprite::create("button_bgm_on.png");
	spr_bgm_on->setVisible(false);
	spr_bgm_on->getTexture()->setAliasTexParameters();
	layer_option->addChild(spr_bgm_on);

	spr_bgm_off = Sprite::create("button_bgm_off.png");
	spr_bgm_off->setVisible(false);
	spr_bgm_off->getTexture()->setAliasTexParameters();
	layer_option->addChild(spr_bgm_off);

	spr_fx_on = Sprite::create("button_fx_on.png");
	spr_fx_on->setVisible(false);
	spr_fx_on->getTexture()->setAliasTexParameters();
	layer_option->addChild(spr_fx_on);

	spr_fx_off = Sprite::create("button_fx_off.png");
	spr_fx_off->setVisible(false);
	spr_fx_off->getTexture()->setAliasTexParameters();
	layer_option->addChild(spr_fx_off);

	spr_credit = Sprite::create("button_credit.png");
	spr_credit->getTexture()->setAliasTexParameters();

	spr_bgm = Sprite::createWithSpriteFrame(spr_bgm_on->getSpriteFrame());
	spr_fx = Sprite::createWithSpriteFrame(spr_fx_on->getSpriteFrame());
}

void MainScene::optionCallback(Ref * pSender)
{
	if (((Node*)pSender)->getName() == "CROSS")
	{
		layer_option->setVisible(false);
		menu_pause->setVisible(true);
		this->setTouchEnabled(true);
	}

	if (((Node*)pSender)->getName() == "BGM")
	{
		if (Management::getInstance()->bgm_status == true)
		{
			spr_bgm->setSpriteFrame(spr_bgm_off->getSpriteFrame());
			Management::getInstance()->bgm_status = false;
		}
		else if (Management::getInstance()->bgm_status == false)
		{
			spr_bgm->setSpriteFrame(spr_bgm_on->getSpriteFrame());
			Management::getInstance()->bgm_status = true;
		}
	}

	if (((Node*)pSender)->getName() == "FX")
	{
		if (Management::getInstance()->fx_status == true)
		{
			spr_fx->setSpriteFrame(spr_fx_off->getSpriteFrame());
			Management::getInstance()->fx_status = false;
		}
		else if (Management::getInstance()->fx_status == false)
		{
			spr_fx->setSpriteFrame(spr_fx_on->getSpriteFrame());
			Management::getInstance()->fx_status = true;
		}
	}

	if (((Node*)pSender)->getName() == "CREDIT")
	{
		layer_option->setVisible(false);
		layer_credit->setVisible(true);
	}

	if (((Node*)pSender)->getName() == "CREDIT_CROSS")
	{
		layer_option->setVisible(true);
		layer_credit->setVisible(false);
	}
}