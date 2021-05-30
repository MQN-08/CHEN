#pragma once
#include"NormalScene.h"
#include"Player.h"
#include"Gate.h"
class CloseMonster_1;

USING_NS_CC;
/*
*ս���ĵ�ͼ
* ����
*���������ͼ����
*�������������
*��ɹؿ�����ִ����Ž�����һ��
*�ɽ������������塢ǿ��ҩ����������Ʒ������
*/
class BattleScene:public NormalScene
{
public:
	virtual bool init();
	virtual void update(float dt);
	void test(float dt);
	CREATE_FUNC(BattleScene);
private:
	TMXTiledMap* map;
	Gate* safeGate;
	CloseMonster_1* Monster_1;
};