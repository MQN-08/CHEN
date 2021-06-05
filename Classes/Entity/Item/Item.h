#pragma once
#include"Entity.h"
USING_NS_CC;
class Player;
class Item :public Entity
{
public:
	virtual bool init();
	virtual void Interact();
	virtual void update(float dt);
	bool isAround();	//�жϳ����������Ƿ�����Χ
	void bindScene(Scene* scene);
	void bindPlayer(Player* player);
	CREATE_FUNC(Item);
protected:

	Scene* mScene;
	Player* mPlayer;
};