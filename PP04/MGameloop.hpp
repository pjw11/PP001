#pragma once
#include <iostream>
#include <chrono>
#include <thread>
#include <Windows.h>
#include "MConsolUtill.hpp"

using namespace std;

namespace MuSeoum_Engine
{
	class MGameLoop
	{
	private:
		bool _isGameRunning;
		MConsoleRenderer cRenderer;

	public:
		MGameLoop()	{ _isGameRunning = false; }
		~MGameLoop() {}

		void Run()
		{
			_isGameRunning = true;
			Initialize();

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

		void Initialize() 
		{
			//SetCursorState(false);
			//p = new Player();
		}
		void Release()
		{
			/*delete(p);*/
		}

		void Input()
		{
			/*if (GetAsyncKeyState(VK_SPACE) == -0x8000 || GetAsyncKeyState(VK_SPACE) == -0x8001)
			{
				p->transform.y = 10;
			}
			else 
			{
				p->transform.y = 15;
			}*/
		}

		void Update() 
		{
			
		}
		void Render() 
		{
			chrono::system_clock::time_point startRenderTimePoint = chrono::system_clock::now();

			cRenderer.Clear();
			cRenderer.MoveCursor(10, 20);

			chrono::duration<double> renderDuration = chrono::system_clock::now() - startRenderTimePoint;

			string fps = "FPS(seconds) : " + to_string(renderDuration.count() * 1000.0);
			cRenderer.DrawString(fps);

			
		}
		////cout << "Randering speed : " << renderDurationtimePoint.count() << "sec" << endl;

			//int remainingFrameTime = 100 - (int)(renderDurationtimePoint.count() * 1000.0);
			//if (remainingFrameTime > 0)
			//	this_thread::sleep_for(chrono::milliseconds(remainingFrameTime));
	};
}