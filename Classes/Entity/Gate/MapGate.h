#pragma once
#include"Entity.h"
class Player;
class MapGate : public Entity
{
public:
	virtual bool init();
	virtual void update(float delta);
	bool isAround(float Px, float Py);//�������Ƿ�������Χ
	void bindPlayer(Player* mPlayer);
	void notice();//��ʾ��'E'
	void  IsAble(bool able);
	bool getAble();
	CREATE_FUNC(MapGate);
private:
	Player* player;
	Label* noticeLabel;
	bool Able=1;
};