#pragma once
#include"State_M.h"
class Monster;
//�ƶ�״̬������
class RunState_M : public State_M
{
public:
	virtual void execute(Monster*monster);
private:

};

//��Ϣ״̬
class RestState_M :public State_M
{
public:
	virtual void execute(Monster*monster);

private:

};



