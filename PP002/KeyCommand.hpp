#pragma once
#include "MCommand.hpp"

class JumpCommand : public Musoum::MCommand
{
public:
	void Execute()
	{
		std::cout << "�ѽ� ����!!";
	}
};

class RunCommand : public Musoum::MCommand
{
public:
	void Execute()
	{
		std::cout << "�ѽ� �޸���!!";
	}
};

class LeftCommand : public Musoum::MCommand
{
public:
	void Execute()
	{
		std::cout << "�ѽ� ����!!";
	}
};

class RightCommand : public Musoum::MCommand
{
public:
	void Execute()
	{
		std::cout << "�����̾� ������!!";
	}
};

class DownCommand : public Musoum::MCommand
{
public:
	void Execute()
	{
		std::cout << "������ ���� ���� ������!!";
	}
};