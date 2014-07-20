#include "Task4.h"

Victory::Victory()
{
}

Victory::~Victory()
{
}

CCScene* Victory::scene()
{
	CCScene* scene = CCScene::create();

	Victory* layer = Victory::create();

	scene->addChild(layer);

	return scene;
}

bool Victory::init()
{
	bool bRet = false;

	do 
	{
		CCSprite* bg = CCSprite::create("Startup_bg.jpg");
		bg->setAnchorPoint(ccp(0,0));
		bg->setPosition(ccp(0,0));
		addChild(bg);

		CCSprite* bg2 = CCSprite::create("Result.png");
		bg2->setAnchorPoint(ccp(0,0));
		bg2->setPosition(ccp(140,80));
		addChild(bg2);

		CCSprite* result = CCSprite::create("Navigator_win_text.png");
		result->setPosition(ccp(390, 280));
		addChild(result);

		CCMenuItemImage* Back_Game = CCMenuItemImage::create("Btn_replay.png", "Btn_replay_pressed.png", this, menu_selector(Victory::GameCallBack));
		CCMenuItemImage* Back_Menu = CCMenuItemImage::create("Thumb_back.png", "Thumb_back_pressed.png", this, menu_selector(Victory::MenuCallBack));
		Back_Menu->setPosition(ccp(330, 160));
		Back_Game->setPosition(ccp(490, 160));
		CCMenu* pMenu = CCMenu::create(Back_Game, Back_Menu, NULL);
		pMenu->setPosition(CCPointZero);
		addChild(pMenu);

		bRet = true;
	} while (0);

	return bRet;
}

void Victory::MenuCallBack(CCObject* pSender)
{
	CCScene* scene = HelloWorld::scene();

	CCDirector::sharedDirector()->pushScene(CCTransitionSlideInR::create(1, scene));
}

void Victory::GameCallBack(CCObject* pSender)
{
	CCScene* scene = Game_easy::scene();

	CCDirector::sharedDirector()->pushScene(CCTransitionSlideInR::create(1, scene));
}