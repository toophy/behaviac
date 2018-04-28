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
	void RunLeft();// 从最左边开始移动
	void RunRight();// 从最右边开始移动
	void Stop();// 反方停止
	void Split();// 正向分裂, 越大, 分裂的越多
	// 获取两侧最近的Body, 查看body情况, 决定怎么应对

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
