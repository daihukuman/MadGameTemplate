#include "Game.h"
#include <utility>

#include "PaintUtil.h"

#include "MediaUtil.h"

#include "resource.h"

bool Pausing = false;

Game::Game(HINSTANCE hInstance, ID2D1Factory* facto) : hInst(hInstance), factory(facto) {

	WNDCLASSW wc{};

	if (!GetClassInfoW(hInstance, L"GameWnd", &wc)) {
		wc.lpszClassName = L"GameWnd";
		wc.hInstance = hInstance;
		wc.lpfnWndProc = Game::GameProc;
		wc.hCursor = LoadCursorW(NULL, IDC_CROSS);

		RegisterClassW(&wc);

	}

	DWriteCreateFactory(
		DWRITE_FACTORY_TYPE_SHARED,
		__uuidof(Shared_data::DWrite::p_WriteFactory),
		reinterpret_cast<IUnknown**>(&Shared_data::DWrite::p_WriteFactory)
	);

}

Game::~Game() {
	for (Entity* entity : Shared_data::Entities) {
		delete entity;
	}
	factory->Release();
	Shared_data::Rendertarget->Release();
	brush->Release();
	white->Release();
}

void Game::Activate() {

	ma_engine_init(NULL, &Shared_data::Sound::engine);
	
	Shared_data::DWrite::p_MSGothic = PaiUtil::CreateTextFormat(
		Shared_data::DWrite::p_WriteFactory,
		L"MS UI gothic",
		24.f
	);

}

HRESULT Game::CreateGraphicResource() {
	HRESULT hr = S_OK;

	RECT rect;
	GetClientRect(GameWnd, &rect);

	if (!Shared_data::Rendertarget) {
		hr = factory->CreateHwndRenderTarget(
			D2D1::RenderTargetProperties(),
			D2D1::HwndRenderTargetProperties(
				GameWnd,
				D2D1::SizeU(rect.right - rect.left, rect.bottom - rect.top)
			),
			&Shared_data::Rendertarget
		);
		if (Shared_data::Rendertarget) {
			if (SUCCEEDED(hr)) {
				hr = Shared_data::Rendertarget->CreateSolidColorBrush(
					D2D1::ColorF(D2D1::ColorF::Black),
					&brush
				);
			}
			if (SUCCEEDED(hr)) {
				hr = Shared_data::Rendertarget->CreateSolidColorBrush(
					D2D1::ColorF(D2D1::ColorF::White),
					&white
				);
			}
		}
		Activate();
	}

	return hr;
}

void Game::WindowCreate(int x, int y, int width, int height, HWND Parent) {

	ParentWnd = Parent;

	CreateWindowExW(
		0,
		L"GameWnd",
		L"",
		WS_CHILD | WS_BORDER | WS_VISIBLE,
		x, y, width, height,
		Parent, NULL, hInst, this
	);

}

LRESULT CALLBACK Game::GameProc(HWND hWnd, UINT msg, WPARAM wp, LPARAM lp) {
	if (msg == WM_NCCREATE) {
		CREATESTRUCTW* cs = (CREATESTRUCTW*)lp;
		Game* game = (Game*)cs->lpCreateParams;
		SetWindowLongPtrW(hWnd, GWLP_USERDATA, (LONG_PTR)game);
		game->GameWnd = hWnd;
	}
	Game* game = (Game*)GetWindowLongPtrW(hWnd, GWLP_USERDATA);
	switch (msg)
	{
	case WM_CREATE:
		Shared_data::p_Window = hWnd;
		break;
	case WM_KEYDOWN:
	{
		Shared_data::Input::p_keys[wp] = true;
	}
	break;
	case WM_KEYUP:
	{
		Shared_data::Input::p_keys[wp] = false;
	}
	break;
	case WM_LBUTTONDOWN:
	{
		Shared_data::Input::Mouse::p_LButton = true;
	}
	break;
	case WM_LBUTTONUP:
	{
		Shared_data::Input::Mouse::p_LButton = false;
	}
	break;
	case WM_RBUTTONDOWN:
	{
		Shared_data::Input::Mouse::p_RButton = true;
	}
	break;
	case WM_RBUTTONUP:
	{
		Shared_data::Input::Mouse::p_RButton = false;
	}
	break;
	case WM_PAINT:
	{

		SetFocus(hWnd);

		PAINTSTRUCT ps{};

		HDC hdc = BeginPaint(hWnd, &ps);

		game->Render();

		EndPaint(hWnd, &ps);

	}
	break;
	case WM_SIZE:
	{
		if (game && Shared_data::Rendertarget) {
			UINT width = LOWORD(lp);
			UINT height = HIWORD(lp);

			Shared_data::Rendertarget->Resize(D2D1::SizeU(width, height));

		}
	}
	break;
	default:
		return DefWindowProcW(hWnd, msg, wp, lp);
	}
	return 0;
}

void Game::Render() {

	HRESULT hr = CreateGraphicResource();

	if (Pausing) { return; }

	Shared_data::Rendertarget->BeginDraw();

	Shared_data::Rendertarget->Clear(D2D1::ColorF(D2D1::ColorF::Black));

	for (Entity* ents : Shared_data::p_Entities) {
		if (ents) {
			ents->Render();
		}
	}

	Shared_data::Rendertarget->EndDraw();

}

void Game::Think(const float deltatime) {

	if (!Pausing) {
		for (Entity* ents : Shared_data::p_Entities) {
			if (ents) {
				ents->Think(deltatime);
			}
		}
	}
}