#pragma once
#include "Task4.h"
class Lose : public cocos2d::CCLayer
{
public:
	Lose(void);
	~Lose(void);
	virtual bool init();  
	static cocos2d::CCScene* scene();
	CREATE_FUNC(Lose);

	void GameCallBack(CCObject* pSender);
	void MenuCallBack(CCObject* pSender);
};