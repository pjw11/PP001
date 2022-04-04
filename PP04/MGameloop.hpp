#pragma once
#include <iostream>
#include <chrono>
#include <Windows.h>
#include <thread>

using namespace std;

namespace MuSeoum_Engine
{
	class MGameLoop
	{
	public:
		bool _isGameRunning;

		MGameLoop()
		{
			_isGameRunning = false;
		}
		~MGameLoop() {}

		void Run()
		{
			_isGameRunning = true;

			Initalize();


			while (_isGameRunning)
			{
				Input();
				Update();
				Render();
			}
			Release();
		}

		void Stop()
		{
			_isGameRunning = false;
		}

	private:

		void Initalize() 
		{
			SetCursorState(false);
		}

		void Input()
		{
			if (GetAsyncKeyState(VK_SPACE) == -0x8000 || GetAsyncKeyState(VK_SPACE) == -0x8001)
			{

			}
			else 
			{

			}
		}

		void Update() 
		{
			
		}
		void Render() 
		{
			chrono::system_clock::time_point startRenderTimePoint = chrono::system_clock::now();
			//system("cls");

			cout << "Randering...";
			chrono::duration<double> renderDurationtimePoint = chrono::system_clock::now() - startRenderTimePoint;

			cout << "Randering speed : " << renderDurationtimePoint.count() << "sec" << endl;

			int remainingFrameTime = 100 - (int)(renderDurationtimePoint.count() * 1000.0);

			if (remainingFrameTime > 0)
				this_thread::sleep_for(chrono::milliseconds(remainingFrameTime));
		}

		void Release() {}

	private: //게임 사용 함수
		void MoveCursor(short x, short y)
		{
			COORD position = { x , y };
			SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), position);
		}
		
		void SetCursorState(bool visible)
		{
			HANDLE hConsole;
			hConsole = GetStdHandle(STD_OUTPUT_HANDLE);

			CONSOLE_CURSOR_INFO consoleCursorinfo;
			consoleCursorinfo.bVisible = visible;
			consoleCursorinfo.dwSize = 1;
			SetConsoleCursorInfo(GetStdHandle(STD_OUTPUT_HANDLE), &consoleCursorinfo);
		}
	};
}