#pragma once
#include "Task4.h"
class Victory : public cocos2d::CCLayer
{
public:
	Victory(void);
	~Victory(void);
	virtual bool init();  
	static cocos2d::CCScene* scene();
	CREATE_FUNC(Victory);

	void GameCallBack(CCObject* pSender);
	void MenuCallBack(CCObject* pSender);
};
