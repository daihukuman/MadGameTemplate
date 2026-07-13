#include <Windows.h>

#include <chrono>
#include <format>
#include <thread>

#include <mfapi.h>
#include <mfplay.h>

#include "App.h"

int WINAPI WinMain(HINSTANCE hInst, HINSTANCE, LPSTR, int nCmdShow) {

	MFStartup(MF_VERSION);

	timeBeginPeriod(1);

	float target = 1.0f / 60.0f;

	App app(hInst, nCmdShow);

	auto last = std::chrono::high_resolution_clock::now();

	float smoothdelta = 0.f;

	MSG msg{};
	msg.message = WM_NULL;
	while (msg.message != WM_QUIT)
	{
		if (PeekMessageW(&msg, NULL, 0, 0, PM_REMOVE)) {
			TranslateMessage(&msg);
			DispatchMessageW(&msg);
		}
		else {

			auto framestart = std::chrono::high_resolution_clock::now();
			float deltaTime = std::chrono::duration<float>(framestart - last).count();

			last = framestart;

			smoothdelta = smoothdelta * 0.9f + deltaTime * 0.1f;

			app.game->Think(smoothdelta);
			app.game->Render();

			std::this_thread::sleep_for(std::chrono::duration<float>(target / 3.f));

			while (true) {
				auto now = std::chrono::steady_clock::now();
				float elapsed = std::chrono::duration<float>(now - framestart).count();
				if (elapsed >= (target)) break;
			}

		}
	}

	timeEndPeriod(1);

	MFShutdown();

	PostQuitMessage(0);
	return 0;

}