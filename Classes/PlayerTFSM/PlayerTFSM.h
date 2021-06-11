#pragma once
#include"cocos2d.h"
class State;
class Player;
USING_NS_CC;
/*
* ����״̬��
* �����ṩ���ﶯ��״̬���л��͵���
*/
class PlayerTFSM :public Node
{
public:
	virtual bool init();
	virtual void update(float dt);
	void changeState(State* mCurState);
	void bindPlayer(Player* player);
	State* getmCurState();
	CREATE_FUNC(PlayerTFSM);
private:
	State* mCurState;
	Player* mplayer;
};