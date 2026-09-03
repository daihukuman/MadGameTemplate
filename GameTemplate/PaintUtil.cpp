#include "PaintUtil.h"
#include <wincodec.h>
#include "Shared_data.h"

namespace fs = std::filesystem;

namespace PaiUtil {
	ID2D1Bitmap* GetBitmapFromFilename(fs::path filepath) {
		IWICImagingFactory* wic = nullptr;
		CoCreateInstance(
			CLSID_WICImagingFactory,
			NULL,
			CLSCTX_INPROC_SERVER,
			IID_PPV_ARGS(&wic)
		);

		IWICBitmapDecoder* decoder = nullptr;
		wic->CreateDecoderFromFilename(filepath.c_str(), NULL,
			GENERIC_READ, WICDecodeMetadataCacheOnLoad, &decoder);

		IWICBitmapFrameDecode* frame = nullptr;
		decoder->GetFrame(0, &frame);

		IWICFormatConverter* convert = nullptr;
		wic->CreateFormatConverter(
			&convert
		);
		convert->Initialize(
			frame,
			GUID_WICPixelFormat32bppPBGRA,
			WICBitmapDitherTypeNone,
			NULL,
			0.0f,
			WICBitmapPaletteTypeCustom
		);

		ID2D1Bitmap* bitmap = nullptr;
		Shared_data::Rendertarget->CreateBitmapFromWicBitmap(
			convert,
			NULL,
			&bitmap
		);

		wic->Release();
		wic = nullptr;
		decoder->Release();
		decoder = nullptr;
		frame->Release();
		frame = nullptr;
		convert->Release();
		convert = nullptr;

		return bitmap;

	}

	ID2D1Bitmap* GetBitmapFromResource(HINSTANCE hInst, int resourceID, const wchar_t *resourceType) {
		IWICImagingFactory* wic = nullptr;
		CoCreateInstance(
			CLSID_WICImagingFactory,
			NULL,
			CLSCTX_INPROC_SERVER,
			IID_PPV_ARGS(&wic)
		);

		HRSRC res = FindResourceW(hInst, MAKEINTRESOURCE(resourceID), resourceType);
		HGLOBAL resData = LoadResource(hInst, res);
		void* pData = LockResource(resData);
		DWORD size = SizeofResource(hInst, res);

		IWICStream* stream = nullptr;
		wic->CreateStream(&stream);
		stream->InitializeFromMemory((BYTE*)pData, size);

		IWICBitmapDecoder* decoder = nullptr;
		wic->CreateDecoderFromStream(stream, NULL, WICDecodeMetadataCacheOnLoad, &decoder);

		IWICBitmapFrameDecode* frame = nullptr;
		decoder->GetFrame(0, &frame);

		IWICFormatConverter* convert = nullptr;
		wic->CreateFormatConverter(
			&convert
		);
		convert->Initialize(
			frame,
			GUID_WICPixelFormat32bppPBGRA,
			WICBitmapDitherTypeNone,
			NULL,
			0.0f,
			WICBitmapPaletteTypeCustom
		);

		ID2D1Bitmap* bitmap = nullptr;
		Shared_data::Rendertarget->CreateBitmapFromWicBitmap(
			convert,
			NULL,
			&bitmap
		);

		wic->Release();
		wic = nullptr;
		decoder->Release();
		decoder = nullptr;
		frame->Release();
		frame = nullptr;
		convert->Release();
		convert = nullptr;

		return bitmap;

	}

	IDWriteTextFormat* CreateTextFormat(IDWriteFactory* factory, const wchar_t* FontName, float FontSize) {

		IDWriteTextFormat* format = nullptr;

		factory->CreateTextFormat(
			FontName,
			nullptr,
			DWRITE_FONT_WEIGHT_NORMAL,
			DWRITE_FONT_STYLE_NORMAL,
			DWRITE_FONT_STRETCH_NORMAL,
			FontSize,
			L"ja-jp",
			&format
		);

		return format;
	}

}