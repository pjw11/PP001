#pragma once
#include "MCommand.hpp"

class JumpCommand : public Musoum::MCommand
{
public:
	void Execute()
	{
		std::cout << "¾Ñ½Î Á¡ÇÁ!!";
	}
};

class RunCommand : public Musoum::MCommand
{
public:
	void Execute()
	{
		std::cout << "¾Ñ½Î ´Þ¸®±â!!";
	}
};

class LeftCommand : public Musoum::MCommand
{
public:
	void Execute()
	{
		std::cout << "¾Ñ½Î ¿ÞÂÊ!!";
	}
};

class RightCommand : public Musoum::MCommand
{
public:
	void Execute()
	{
		std::cout << "¸¾¸¶ÀÌ¾ß ¿À¸¥ÂÊ!!";
	}
};

class DownCommand : public Musoum::MCommand
{
public:
	void Execute()
	{
		std::cout << "ÀÚÁ¸½É µûÀ© ¾ø´Ù ¾¥±¸¸®!!";
	}
};