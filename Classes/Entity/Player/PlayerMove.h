#pragma once
#include"cocos2d.h"
class Player;
USING_NS_CC;
/*
* ������ҵ��ƶ������һ��Player
* Player��update����������ƶ���������update��ˬ��Щ��
*/
class PlayerMove:public Node
{
public:
	void bindPlayer(Player* player);//�����
	void Move();//�����ƶ��ĺ���
	Player* getPlayer();

	CREATE_FUNC(PlayerMove);
private:
	Player* mPlayer;
};