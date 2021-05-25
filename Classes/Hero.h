#pragma once
#include"cocos2d.h"
USING_NS_CC;
enum hero_direction
{
	RIGHT_DOWN = 1,
	LEFT_DOWN = 2,
	LEFT_UP = 3,
	RIGHT_UP = 4,
	DOWN = 5,
	LEFT = 6,
	UP = 7,
	RIGHT = 8
};
class Hero :public Node//��hero�Ķ���
{
public:
	int direction;			//���﷽��
	Point position;			//��������
	Sprite* sprite;

	void initHeroSprite(int direction, Point position);//�����ʼ��
	void heroMove(int direction);						//�����ƶ���
	
	Animate* createAnimate(int direction, const char* action, int num);		//��ȡ����
	CREATE_FUNC(Hero);
};