#pragma once
#include"State.h"
class Player;
//�ƶ�״̬������
class RunState : public State
{
public:
	virtual void execute(Player* player);
private:

};
//�ƶ������� Flip��Ϊ��ת
class RunState_Flip : public State
{
public:
	virtual void execute(Player* player);
private:

};
//��Ϣ״̬
class RestState :public State
{
public:
	virtual void execute(Player* player);

private:

};
//��Ϣ������
class RestState_Flip :public State
{
public:
	virtual void execute(Player* player);

private:

};


