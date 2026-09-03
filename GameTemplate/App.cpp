#include "App.h"
#include <cwchar>

App::App(HINSTANCE hInstance, int nCmdShow) : hInst(hInstance), showcode(nCmdShow) {

	D2D1CreateFactory(
		D2D1_FACTORY_TYPE_SINGLE_THREADED,
		&factory
	);

	WNDCLASSW wc{};
	wc.lpszClassName = L"daihukuman";
	wc.lpfnWndProc = App::WndProc;
	wc.hbrBackground = (HBRUSH)(COLOR_WINDOW + 1);
	wc.hCursor = LoadCursorW(NULL, IDC_ARROW);

	RegisterClassW(&wc);

	MainWnd = CreateWindowExW(
		0,
		L"daihukuman",
		L"Window",
		WS_SYSMENU | WS_CAPTION | WS_CLIPCHILDREN,
		CW_USEDEFAULT, CW_USEDEFAULT, CW_USEDEFAULT, CW_USEDEFAULT,
		NULL, NULL, hInstance, this
	);

	ShowWindow(MainWnd, SW_MAXIMIZE);

	RECT rect;
	GetClientRect(MainWnd, &rect);

	game->WindowCreate(0, 0, rect.right - rect.left, rect.right - rect.left, MainWnd);

}

LRESULT CALLBACK App::WndProc(HWND hWnd, UINT msg, WPARAM wp, LPARAM lp) {
	if (msg == WM_NCCREATE) {
		CREATESTRUCTW* cs = (CREATESTRUCTW*)lp;
		App* app = (App*)cs->lpCreateParams;
		app->MainWnd = hWnd;
		SetWindowLongPtrW(hWnd, GWLP_USERDATA, (LONG_PTR)app);
	}
	App* app = (App*)GetWindowLongPtrW(hWnd, GWLP_USERDATA);
	switch (msg)
	{
	case WM_CREATE:
	{
		app->game = std::make_unique<Game>(app->hInst, app->factory);
	}
	break;
	case WM_SIZE:
	{
		HDWP dwp = BeginDeferWindowPos(1);

		UINT width = LOWORD(lp);
		UINT height = HIWORD(lp);

		DeferWindowPos(
			dwp,
			app->game->GameWnd, nullptr,
			0, 0, width, height,
			SWP_NOZORDER
		);

		EndDeferWindowPos(dwp);
	}
	break;
	case WM_DESTROY:
		PostQuitMessage(0);
		break;
	default:
		return DefWindowProcW(hWnd, msg, wp, lp);
	}
	return 0;
}

