#include "framework.h"
#include "DevScene.h"

DevScene::DevScene()
{

}

DevScene::~DevScene()
{

}

void DevScene::Init()
{
	Super::Init();
}

void DevScene::Update()
{
	Super::Update();

}

void DevScene::Render(HDC hdc)
{
	Super::Render(hdc);
	uint64 _frequency = 0;
	uint64 _prevCount = 0;
	::QueryPerformanceFrequency(reinterpret_cast<LARGE_INTEGER*>(&_frequency));
	::QueryPerformanceCounter(reinterpret_cast<LARGE_INTEGER*>(&_prevCount));
	int x = 100;
	int y = 100;
	int w = 250;
	int h = 250;
	for (int i = 0; i < h; i++) {
		for (int j = 0; j < w; j++) {
			SetPixel(hdc, x + j, y+ i, RGB(255, 0, 0));
		}
	}
	uint64 currentCount;
	::QueryPerformanceCounter(reinterpret_cast<LARGE_INTEGER*>(&currentCount));
	wstring str = std::format(L"TWICE DUPE LOOP DELAY({0} ms)", ((currentCount-_prevCount) / static_cast<float>(_frequency)) * 1000);
	::TextOut(hdc, 100, 50, str.c_str(), static_cast<int32>(str.size()));
	::QueryPerformanceFrequency(reinterpret_cast<LARGE_INTEGER*>(&_frequency));
	::QueryPerformanceCounter(reinterpret_cast<LARGE_INTEGER*>(&_prevCount));
	w = 250;
	h = 250;
	x = 500;
	y = 100;
	for (int i = 0; i < w; i++) {
		SetPixel(hdc, x + i, y, RGB(0, 255, 255));
	}
	for (int i = 0; i < h; i++) {
		BitBlt(hdc, x, y+i, w, 1, hdc, x, y, SRCCOPY);
	}
	
	::QueryPerformanceCounter(reinterpret_cast<LARGE_INTEGER*>(&currentCount));
	str = std::format(L"BITBLT COPY DELAY({0} ms)", ((currentCount - _prevCount) / static_cast<float>(_frequency)) * 1000);
	::TextOut(hdc, x, 50, str.c_str(), static_cast<int32>(str.size()));
}

