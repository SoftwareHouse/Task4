#pragma once
#include "Task4.h"
class Game_Select :public cocos2d::CCLayer
{
public:
	Game_Select(void);
	~Game_Select(void);

	bool MusicSwitch;
	bool EffectSwitch;
	CCSprite* Music_Diaplay;
	CCSprite* Effect_Diaplay;

	virtual bool init();
	static CCScene* scene();
	CREATE_FUNC(Game_Select);

	void EasyCallback(CCObject* pSender);
	void NormalCallback(CCObject* pSender);
	void HardCallback(CCObject* pSender);
	void TopCallback(CCObject* pSender);
};
