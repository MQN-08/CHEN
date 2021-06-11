#pragma once
#include"Entity.h"
class Player;
class NormalScene;
USING_NS_CC;
/*
*Gate������
* ��ҿ�����ʱ������Ӧ
* ��ʾ��E���д���
* 
*/
class Gate :public Entity
{
public:
	virtual bool init();
	virtual void update(float delta);
	bool isAround(float Px,float Py);//�������Ƿ�������Χ
	void bindPlayer(Player* mPlayer);
	void bindStart(NormalScene* mScene);//��ʼ��
	void bindDestination(NormalScene* mScene);//Ŀ�ĵ�
	void notice();//��ʾ��'E'
	NormalScene* getStart();
	NormalScene* getDestination();
	CREATE_FUNC(Gate);
private:
	Player* player;
	NormalScene* start;
	NormalScene* destination;
	Label* noticeLabel;
	std::string Content;
	bool isOn=0;
};