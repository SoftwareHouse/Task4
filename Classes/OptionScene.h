#pragma once
#include "Task4.h"
class OptionScene :public cocos2d::CCLayer
{
public:
	OptionScene(void);
	~OptionScene(void);

	bool MusicSwitch;
	bool EffectSwitch;
	CCSprite* Music_Diaplay;
	CCSprite* Effect_Diaplay;

	virtual bool init();
	static CCScene* scene();
	CREATE_FUNC(OptionScene);

	void menuItemCallback(CCObject* pSender);
	void ccTouchesEnded (cocos2d::CCSet *pTouches, cocos2d::CCEvent *pEvent);
};

