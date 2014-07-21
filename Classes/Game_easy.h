#pragma once
#include "Task4.h"
#define LINE 6
class Game_easy:public cocos2d::CCLayer
{
public:
	Game_easy(void);
	~Game_easy(void);


	int Card_Sort[LINE][LINE];

	virtual bool init();
	static CCScene* scene();
	int Card_num, row_pre, line_pre;
	int times;
	bool Change;
	CCLabelTTF* numsTTF;
	CCProgressTimer * pr;
	CCTexture2D* texture[LINE*LINE/2];
	CCTexture2D* texture_back;
	CCSprite* Card_Back[LINE*LINE];
	CREATE_FUNC(Game_easy);

	int random();
	void ccTouchesEnded (cocos2d::CCSet *pTouches, cocos2d::CCEvent *pEvent);
	void BackMenuCallback(CCObject* pSender);
	void SettingCallback(CCObject* pSender);
	void Lose_Result(float dt);
	void update(float t);
};

