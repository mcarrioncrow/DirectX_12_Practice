#include "pch.h"
#include "Engine.h"

//초기화
void Engine::Init(const WindowInfo& info)
{
	_info = info;

	//그려질 화면 크기를 설정
	_viewport		= { 0, 0, static_cast<FLOAT>(info.width), static_cast<FLOAT>(info.height), 0.0f, 1.0f, }; 
					//{FLOAT TopLeftX, FLOAT TopLeftY, FLOAT Width, FLOAT Height, FLOAT MinDepth, FLOAT MaxDepth} 
					//Depth???
	_scissorRect	= CD3DX12_RECT(0, 0, info.width, info.height);



	// Shader_Ptr 선언
	_device			= make_shared<Device>();
	_cmdQueue		= make_shared<CommandQueue>();
	_swapChain		= make_shared<SwapChain>();
	_rootSignature	= make_shared<RootSignature>();
	_cb				= make_shared<ConstantBuffer>();
	_tableDescHeap	= make_shared<TableDescriptorHeap>();

	// Init
	_device->Init();
	_cmdQueue->Init(_device->GetDevice(), _swapChain);
	_swapChain->Init(info, _device->GetDevice(), _device->GetDXGI(), _cmdQueue->GetCmdQueue());
	_rootSignature->Init();
	_cb->Init(sizeof(Transform), 256);
	_tableDescHeap->Init(256);

}

void Engine::Render()
{
	RenderBegin();

	// TODO : 나머지 물체들 그려준다

	RenderEnd();
}

void Engine::RenderBegin()
{
	_cmdQueue->RenderBegin(&_viewport, &_scissorRect);
}

void Engine::RenderEnd()
{
	_cmdQueue->RenderEnd();
}

void Engine::ResizeWindow(int32 width, int32 height)
{
	//Window 창크기 조절
	_info.width		= width;
	_info.height	= height;

	RECT rect = { 0, 0, width, height};
	::AdjustWindowRect(&rect, WS_OVERLAPPEDWINDOW, false);		//AdjustWindowRect??? (Window API)return bool - https://docs.microsoft.com/en-us/windows/win32/api/winuser/nf-winuser-adjustwindowrect
	::SetWindowPos(_info.hWnd, 0, 100, 100, width, height, 0);	

}
