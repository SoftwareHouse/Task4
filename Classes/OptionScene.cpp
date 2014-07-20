#include "Task4.h"


OptionScene::OptionScene(void)
{
}


OptionScene::~OptionScene(void)
{
}

CCScene* OptionScene::scene()
{
	CCScene * scene = NULL;
	do 
	{
		scene = CCScene::create();
		CC_BREAK_IF(! scene);

		OptionScene *layer = OptionScene::create();
		CC_BREAK_IF(! layer);

		scene->addChild(layer);
	} while (0);

	return scene;
}

bool OptionScene::init()
{
	bool bRet = false;

	do 
	{
		CCSprite *bg = CCSprite::create("Startup_bg.jpg");
		bg->setAnchorPoint(ccp(0,0));
		bg->setPosition(ccp(0,0));
		addChild(bg);

		this->setTouchEnabled(true);
		MusicSwitch = Global::isMusicOn;
		EffectSwitch = Global::isEffectOn;

		CCSprite* bg2=CCSprite::create("Startup_frame.png");
		CCSize size = CCDirector::sharedDirector()->getWinSize();
		bg2->setPosition(ccp(size.width / 2, size.height/2));
		addChild(bg2);

		CCSprite* Music = CCSprite::create("Option_lbl_music_zh.png");
		Music->setPosition(ccp(300, 300));
		addChild(Music);

		CCSprite* Effect = CCSprite::create("Option_lbl_sound_zh.png");
		Effect->setPosition(ccp(300, 200));
		addChild(Effect);

		CCMenuItemImage* Option_Back = CCMenuItemImage::create("Option_btn_back_zh.png",
			"Option_btn_back_pressed_zh.png",
			this,
			menu_selector(OptionScene::menuItemCallback));
		Option_Back->setPosition(ccp(size.width/2,120));
		CCMenu* Back = CCMenu::create(Option_Back, NULL);
		Back->setPosition(CCPointZero);
		addChild(Back);

		if(MusicSwitch)
		{
			Music_Diaplay = CCSprite::create("Switch_on.png");
		}
		else
		{
			Music_Diaplay = CCSprite::create("Switch_off.png");
		}

		if(EffectSwitch)
		{
			Effect_Diaplay = CCSprite::create("Switch_on.png");
		}
		else
		{
			Effect_Diaplay = CCSprite::create("Switch_off.png");
		}

		Music_Diaplay->setPosition(ccp(500, 300));
		Effect_Diaplay->setPosition(ccp(500, 200));
		addChild(Music_Diaplay);
		addChild(Effect_Diaplay);

		bRet=true;
	}while(0);
	return bRet;

}

void OptionScene::menuItemCallback(CCObject* pSender)
{
	CCDirector::sharedDirector()->popScene();
}

void OptionScene::ccTouchesEnded(cocos2d::CCSet *pTouches, cocos2d::CCEvent *pEvent)
{
	CCSize size = CCDirector::sharedDirector()->getWinSize();
	CCTouch* touch = (CCTouch*)pTouches->anyObject();
	CCPoint location = touch->getLocationInView();

	location = CCDirector::sharedDirector()->convertToGL(location);

	if(location.x > 435 && location.x < 565 && location.y > 270 && location.y < 330)
	{
		if(MusicSwitch)
		{
			CocosDenshion::SimpleAudioEngine::sharedEngine()->stopBackgroundMusic();
			Global::isMusicOn = false;
			MusicSwitch = false;
			CCTexture2D* texture = CCTextureCache::sharedTextureCache()->addImage("Switch_off.png");
			Music_Diaplay->setTexture(texture);
		}
		else
		{
			if(Global::isGame)
			{
				CocosDenshion::SimpleAudioEngine::sharedEngine()->playBackgroundMusic("Audio_bgm_startup_cg.mp3");
			}
			else
			{
				CocosDenshion::SimpleAudioEngine::sharedEngine()->playBackgroundMusic("Audio_bgm_home.mp3");
			}
			Global::isMusicOn = true;
			MusicSwitch = true;
			CCTexture2D* texture = CCTextureCache::sharedTextureCache()->addImage("Switch_on.png");
			Music_Diaplay->setTexture(texture);
		}
	}

	if(location.x > 435 && location.x < 565 && location.y > 170 && location.y < 230)
	{
		if(EffectSwitch)
		{
			Global::isEffectOn = false;
			EffectSwitch = false;
			CCTexture2D* texture = CCTextureCache::sharedTextureCache()->addImage("Switch_off.png");
			Effect_Diaplay->setTexture(texture);
		}
		else
		{
			Global::isEffectOn = true;
			EffectSwitch = true;
			CCTexture2D* texture = CCTextureCache::sharedTextureCache()->addImage("Switch_on.png");
			Effect_Diaplay->setTexture(texture);
		}
	}
}
