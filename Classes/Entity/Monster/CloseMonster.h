#pragma once
#include"Entity/Entity.h"
#include"cocos2d.h"
USING_NS_CC;
//��ս������
class CloseMonster : public Entity
{
public:
	void move();
	bool isaround(float Px, float Py);//�ж�����Ƿ��ڸ���
	void bindScene(Scene* scene);
	void takingDamage(int damage);//�����յ��˺�
	void iswall();

private:
	int mhp;
	Scene* mscene;
};