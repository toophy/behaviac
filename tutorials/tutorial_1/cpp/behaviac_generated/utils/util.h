#pragma once

#include <iostream>     
#include <string>     
#include <fstream>     
#include <windows.h> 
#include <chrono>
#include <ctime>  
#include <map>
#include <set>


int Rand_int(int nMin, int nMax);

int Rand_int_mirror(int nMin, int nMax);




std::string GBKToUTF8(std::string& strGBK);

std::string UTF8ToGBK(const std::string& strUTF8);

class Screen
{
public:
	Screen();
	~Screen();

public:
	bool Init(std::string screenName,float screenLenght,float bodyWidth);
	Role* GetRole(std::string name);
	Body* GetBody(int id);

private:
	Body* MakeBody(int x,int height);

private:
	std::string m_Name;
	float m_BodyWidth;
	float m_Lenght;

	std::map<std::string, Role*> m_Roles;
	std::map<int, Body*> m_Bodys;
};

Screen::Screen()
{
}

Screen::~Screen()
{
}

class Body
{
public:
	Body();
	~Body();

private:
	int m_ID;
	std::string m_RoleName;
	float m_Width;
	float m_Height;
	float m_CurrPos;
	float m_Speed;
	float m_Inertia;
};

Body::Body()
{
}

Body::~Body()
{
}

class Role
{
public:
	Role(Screen* s);
	~Role();
	std::string GetName();
	void RunLeft();// ������߿�ʼ�ƶ�
	void RunRight();// �����ұ߿�ʼ�ƶ�
	void Stop();// ����ֹͣ
	void Split();// �������, Խ��, ���ѵ�Խ��
	// ��ȡ���������Body, �鿴body���, ������ôӦ��

private:
	Screen* m_Screen;
	std::string m_Name;
	std::set<int> m_Bodys;
};

Role::Role(Screen* s)
{
}

Role::~Role()
{
}
