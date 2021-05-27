#pragma once
#include"NormalScene.h"
#include"Player.h"
USING_NS_CC;
/*
* ��
* ����
* ������
* ���
*/
class SafeScene : public NormalScene
{
public:
	
	virtual bool init();
	virtual void update(float dt);
	bool isCanReach(float x,float y);
	CREATE_FUNC(SafeScene);
private:
	TMXTiledMap* map;
	Player* player;
};