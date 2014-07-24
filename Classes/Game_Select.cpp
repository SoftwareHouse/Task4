#include "Game_Select.h"


Game_Select::Game_Select(void)
{
}


Game_Select::~Game_Select(void)
{
}

CCScene* Game_Select::scene()
{
	CCScene * scene = NULL;
	do 
	{
		scene = CCScene::create();
		CC_BREAK_IF(! scene);

		Game_Select *layer = Game_Select::create();
		CC_BREAK_IF(! layer);

		scene->addChild(layer);
	} while (0);

	return scene;
}

bool Game_Select::init()
{
	bool bRet = false;
	do 
	{
		CCSprite* bgSprite=CCSprite::create("Startup_bg.jpg");
		bgSprite->setAnchorPoint(ccp(0,0));
		bgSprite->setPosition(ccp(0,0));

		addChild(bgSprite);

		CCMenuItemImage *EasyItem = CCMenuItemImage::create(
			"Easy.png",
			"Easy_pressed.png",
			this,
			menu_selector(Game_Select::EasyCallback));
		EasyItem->setPosition(ccp(400,400));

		CCMenuItemImage *NormalItem = CCMenuItemImage::create(
			"Normal.png",
			"Normal_pressed.png",
			this,
			menu_selector(Game_Select::NormalCallback));
		NormalItem->setPosition(ccp(400,300));

		CCMenuItemImage *HardItem = CCMenuItemImage::create(
			"Hard.png",
			"Hard_pressed.png",
			this,
			menu_selector(Game_Select::HardCallback));
		HardItem->setPosition(ccp(400,200));

		CCMenuItemImage *TopItem = CCMenuItemImage::create(
			"Top.png",
			"Top_pressed.png",
			this,
			menu_selector(Game_Select::TopCallback));
		TopItem->setPosition(ccp(400,100));

		CCMenu* pMenu = CCMenu::create(EasyItem, NormalItem, HardItem, TopItem, NULL);
		pMenu->setPosition(CCPointZero);
		addChild(pMenu);
		bRet=true;

	}while(0);
	return bRet;
}

void Game_Select::EasyCallback(CCObject* pSender)
{
	Global::Game_Time = 360;

	Global::Img_Beg = 0;

	CCScene* GameScene = Game_easy::scene();

	CCDirector::sharedDirector()->pushScene(CCTransitionSlideInR::create(1, GameScene));
}

void Game_Select::NormalCallback(CCObject* pSender)
{
	Global::Game_Time = 180;

	Global::Img_Beg = 0+(LINE*LINE/2);

	CCScene* GameScene = Game_easy::scene();

	CCDirector::sharedDirector()->pushScene(CCTransitionSlideInR::create(1, GameScene));
}

void Game_Select::HardCallback(CCObject* pSender)
{
	Global::Game_Time = 80;

	Global::Img_Beg = 0+(LINE*LINE/2)*2;

	CCScene* GameScene = Game_easy::scene();

	CCDirector::sharedDirector()->pushScene(CCTransitionSlideInR::create(1, GameScene));
}

void Game_Select::TopCallback(CCObject* pSender)
{
	Global::Game_Time = 60;

	Global::Img_Beg = 0+(LINE*LINE/2)*3;

	CCScene* GameScene = Game_easy::scene();

	CCDirector::sharedDirector()->pushScene(CCTransitionSlideInR::create(1, GameScene));
}