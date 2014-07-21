#include "HelloWorldScene.h"
#include "SimpleAudioEngine.h"
#include "Task4.h"
USING_NS_CC;

CCScene* HelloWorld::scene()
{
    CCScene *scene = CCScene::create();
    
    HelloWorld *layer = HelloWorld::create();

    scene->addChild(layer);

    return scene;
}

// on "init" you need to initialize your instance
bool HelloWorld::init()
{
	bool bRet = false;

	do 
	{
		Global::isGame = false;
		CCSprite* bg = CCSprite::create("Startup_bg.jpg");
		bg->setAnchorPoint(ccp(0,0));
		bg->setPosition(ccp(0,0));
		addChild(bg);

		CCSprite* bg2=CCSprite::create("Startup_frame.png");
		CCSize size = CCDirector::sharedDirector()->getWinSize();
		bg2->setPosition(ccp(size.width / 2, size.height/2));
		addChild(bg2);

		CCMenuItemImage *startItem = CCMenuItemImage::create(
			"Startup_lbl_start_zh.png",
			"Startup_lbl_start_pressed_zh.png",
			this,
			menu_selector(HelloWorld::startButtonCallback));
		CC_BREAK_IF(! startItem);

		startItem->setPosition(ccp(400,250));
		CCMenu* pMenu = CCMenu::create(startItem, NULL);
		pMenu->setPosition(CCPointZero);
		addChild(pMenu);

		CCMenuItemImage *aboutItem = CCMenuItemImage::create(
			"Menu_lbl_about.png",
			"Menu_lbl_about_pressed.png",
			this,
			menu_selector(HelloWorld::aboutItemCallback));
		CC_BREAK_IF(! aboutItem);
		aboutItem->setPosition(ccp(300,150));
		CCMenu* aboutItemMenu = CCMenu::create(aboutItem, NULL);
		aboutItemMenu->setPosition(CCPointZero);
		addChild(aboutItemMenu);

		CCMenuItemImage *optionItem = CCMenuItemImage::create(
			"Startup_lbl_option_zh.png",
			"Startup_lbl_option_pressed_zh.png",
			this,
			menu_selector(HelloWorld::optionItemCallback));
		CC_BREAK_IF(! optionItem );

		optionItem ->setPosition(ccp(500,150));
		CCMenu* optionItemMenu = CCMenu::create(optionItem , NULL);
		optionItemMenu->setPosition(CCPointZero);
		addChild(optionItemMenu);
		CocosDenshion::SimpleAudioEngine::sharedEngine()->playBackgroundMusic("Audio_bgm_home.mp3",true);

		bRet = true;
	} while (0);
	
	return bRet;
}

void HelloWorld::startButtonCallback(CCObject* pSender)
{
	CCScene* GameScene = Game_Select::scene();

	CCDirector::sharedDirector()->pushScene(CCTransitionSlideInR::create(1, GameScene));
}

void HelloWorld::aboutItemCallback(CCObject* pSender)
{
	CCScene* aboutScene = AboutScene::scene();

	CCDirector::sharedDirector()->pushScene(CCTransitionSlideInR::create(1, aboutScene));
}

void HelloWorld::optionItemCallback(CCObject *pSender)
{
	CCScene* optionScene = OptionScene::scene();

	CCDirector::sharedDirector()->pushScene(CCTransitionSlideInR::create(1, optionScene));
}