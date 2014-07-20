#pragma once
#include "Task4.h"
class AboutScene : public cocos2d::CCLayer
{
public:
	AboutScene(void);
	~AboutScene(void);
	virtual bool init();  
	static cocos2d::CCScene* scene();
	CREATE_FUNC(AboutScene);

	void musicItemCallback(CCObject* pSender);
};

