#include "Task4.h"
#define IMG_LENGTH 50
#define IMG_HEIGHT 68

Game_easy::Game_easy()
{
}

Game_easy::~Game_easy()
{
}

CCScene* Game_easy::scene()
{
	CCScene* scene = CCScene::create();

	Game_easy* layer = Game_easy::create();

	scene->addChild(layer);

	return scene;
}

bool Game_easy::init()
{
	bool bRet = false;
	srand((unsigned)time(0));
	Card_num = -1;
	Change = false;

	do 
	{
		this->setTouchEnabled(true);

		if(Global::isMusicOn)
		{
			CocosDenshion::SimpleAudioEngine::sharedEngine()->playBackgroundMusic("Audio_bgm_startup_cg.mp3",true);
		}
		Global::isGame = true;
		line_pre = -1;
		row_pre = -1;
		times = 0;
		CCSprite* bgSprite=CCSprite::create("Startup_bg.jpg");
		bgSprite->setAnchorPoint(ccp(0,0));
		bgSprite->setPosition(ccp(0,0));

		addChild(bgSprite);

		for(int i = 0; i < LINE; i++)
		{
			for(int j = 0; j < LINE; j++)
			{
				Card_Sort[i][j] = 0;
			}
		}

		//随机化卡片位置
		for(int i = 0; i < LINE*LINE/2; i++)
		{
			int x = random();
			int y = random();
			while(Card_Sort[x][y] != 0)
			{
				x = random();
				y = random();
			}
			Card_Sort[x][y] = i;

			x = random();
			y = random();
			while(Card_Sort[x][y] != 0)
			{
				x = random();
				y = random();
			}
			Card_Sort[x][y] = i;
		}

		//初始化卡片背景
		for(int i = 0; i < LINE; i++)
		{
			for(int j = 0; j < LINE; j++)
			{
				Card_Back[j+i*LINE] = CCSprite::create("beimian.png");
				Card_Back[j+i*LINE]->setPosition(ccp(100+j*IMG_LENGTH, 60+i*IMG_HEIGHT));
				addChild(Card_Back[j+i*LINE]);
			}
		}

		//CCTexture2D* texture = CCTextureCache::sharedTextureCache()->addImage("Cards/Card0.png");
		//Card_Back[6]->setTexture(texture);

		CCMenuItemImage *Back = CCMenuItemImage::create("Option_btn_back_zh.png", "Option_btn_back_pressed_zh.png", this, menu_selector(Game_easy::BackMenuCallback));
		CCMenuItemImage *Setting = CCMenuItemImage::create("Startup_lbl_option_zh.png", "Startup_lbl_option_pressed_zh.png", this, menu_selector(Game_easy::SettingCallback));
		CCMenu* pMenu = CCMenu::create(Back, Setting, NULL);
		Back->setPosition(ccp(650, 80));
		Setting->setPosition(ccp(660, 160));
		pMenu->setPosition(CCPointZero);
		addChild(pMenu);

		//进度条
		numsTTF=CCLabelTTF::create("0", "arial", 30);  
		numsTTF->setPosition(ccp(560, 450));  
		numsTTF->setColor(ccc3(2, 2, 2));
		this->addChild(numsTTF, 1);  
		this->scheduleUpdate(); 

		pr = CCProgressTimer::create(CCSprite::create("Timer.png"));
		pr->setPosition(ccp(360,450));
		pr->setType(kCCProgressTimerTypeBar);
		pr->setPercentage(100);
		pr->setMidpoint(ccp(0,0.5));
		CCProgressTo * to1= CCProgressTo::create(Global::Game_Time, 100);
		pr->setReverseProgress(true);
		pr->runAction(CCRepeatForever::create(to1));
		addChild(pr);

		this->scheduleOnce(schedule_selector(Game_easy::Lose_Result), Global::Game_Time);

		//设置替换图片
		for(int i = Global::Img_Beg; i < Global::Img_Beg+LINE*LINE/2; i++)
		{
			string temp;
			char num[10];
			temp = "Cards/Card";
			_itoa(i, num, 10);
			temp = temp+num+".png";

			texture[i-Global::Img_Beg] = CCTextureCache::sharedTextureCache()->addImage(temp.c_str());
		}
		texture_back = CCTextureCache::sharedTextureCache()->addImage("beimian.png");

		bRet = true;
	} while (0);


	return bRet;
}

int Game_easy::random()
{
	return 0+LINE*rand()/(RAND_MAX+1.0);
}

void Game_easy::ccTouchesEnded (cocos2d::CCSet *pTouches, cocos2d::CCEvent *pEvent)
{
	CCSize size = CCDirector::sharedDirector()->getWinSize();
	CCTouch *touch = (CCTouch*)pTouches->anyObject();
	CCPoint location = touch->getLocationInView();
	location = CCDirector::sharedDirector()->convertToGL(location);

	int row_now, line_now;

	if(location.x >=76 && location.x <= 372)
	{
		if(location.y >=30 && location.y <= 433)
		{
			line_now = (location.y-30)/IMG_HEIGHT;
			row_now = (location.x-75)/IMG_LENGTH;
			bool flag = ((Card_Sort[line_now][row_now] != -1) && (Card_Sort[line_pre][row_pre] != -1));
			if(((Card_Sort[line_now][row_now] != -1) && (Card_Sort[line_pre][row_pre] != -1)) || Change == true)
			{
				if(Card_Sort[line_now][row_now] != -1)
				{
					Card_Back[line_now*LINE+row_now]->setTexture(texture[Card_Sort[line_now][row_now]]);
				}

				Change = false;

				if(Card_num == -1)
				{
					Card_num = Card_Sort[line_now][row_now];
				}
				else if((Card_num == Card_Sort[line_now][row_now]) && ((line_now != line_pre) || (row_now != row_pre)))
				{
					if(Global::isEffectOn)
					{
						CocosDenshion::SimpleAudioEngine::sharedEngine()->playEffect("Audio_gold.mp3");
					}
					times++;
					Card_Sort[line_pre][row_pre] = -1;
					Card_Sort[line_now][row_now] = -1;
					Card_num = -1;
					Change = true;
				}
				else
				{
					Card_num = -1;
					Card_Back[line_now*LINE+row_now]->setTexture(texture_back);
					Card_Back[line_pre*LINE+row_pre]->setTexture(texture_back);
				}
			}

			line_pre = line_now;
			row_pre = row_now;
		}
	}

	if(times == LINE*LINE/2)
	{
		CCScene* WinScene = Victory::scene();

		CCDirector::sharedDirector()->pushScene(CCTransitionSlideInR::create(1, WinScene));
	}
}

void Game_easy::BackMenuCallback(CCObject* pSender)
{
	CCScene* MenuScene = HelloWorld::scene();

	CCDirector::sharedDirector()->pushScene(CCTransitionSlideInR::create(1, MenuScene));
}

void Game_easy::SettingCallback(CCObject* pSender)
{
	CCScene* SeetingScene = OptionScene::scene();

	CCDirector::sharedDirector()->pushScene(CCTransitionSlideInR::create(1, SeetingScene));
}

void Game_easy::Lose_Result(float dt)
{
	CCScene* LoseScene = Lose::scene();

	CCDirector::sharedDirector()->pushScene(CCTransitionSlideInR::create(1, LoseScene));
}

void Game_easy::update(float t)  
{  
	float cu = pr->getPercentage();

	cu=cu+0.1f;  

	pr->setPercentage(cu);  

	CCString *str = CCString::createWithFormat("%.2f%%",cu);  

	numsTTF->setString(str->getCString());  
} 