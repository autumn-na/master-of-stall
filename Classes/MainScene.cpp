#include "Defines.h"
#include "GameOverScene.h"
#include "MainScene.h"
#include "SimpleAudioEngine.h"
#include "Management.h"

USING_NS_CC;

Scene* MainScene::createScene()
{
    auto scene = Scene::create();
    
    auto layer = MainScene::create();

    scene->addChild(layer);

    return scene;
}

bool MainScene::init()
{
    if ( !Layer::init() )
    {
        return false;
    }

	initGameUI();
	createOption();

	setTouchEnabled(true);
	setTouchMode(Touch::DispatchMode::ONE_BY_ONE);

    return true;
}

void MainScene::createOption()
{
	layer_option = LayerColor::create(Color4B(0, 0, 0, 100));
	layer_option->setVisible(false);
	this->addChild(layer_option, 1);

	layer_credit = LayerColor::create(Color4B(0, 0, 0, 100));
	layer_credit->setVisible(false);
	this->addChild(layer_credit, 1);

	initOption();
}

bool MainScene::onTouchBegan(Touch * touch, Event * unused_event)
{
	if (Management::getInstance()->isPlaying == false)
	{
		menu_pause->setVisible(true);
		spr_touch2start->setVisible(false);
		menui_pause->setVisible(true);
		Management::getInstance()->isPlaying = true;

		return true;
	}

	if (Management::getInstance()->isPlaying == true)
	{
		auto scene_gameover = GameOverScene::createScene();
		Director::getInstance()->replaceScene(scene_gameover);
		Management::getInstance()->isPlaying = false;

		return true;
	}
}

void MainScene::onTouchMoved(Touch * touch, Event * unused_event)
{
}

void MainScene::onTouchEnded(Touch * touch, Event * unused_event)
{
}
