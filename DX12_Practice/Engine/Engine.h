/*
* 가장 핵심이 되는 부분
*/
#pragma once

#include "Device.h"
#include "CommandQueue.h"
#include "SwapChain.h"

#include "Mesh.h"
#include "Shader.h"
#include "Texture.h"

#include "RootSignature.h"
#include "ConstantBuffer.h"
#include "TableDescriptorHeap.h"

//header에 header는 별조 좋지 않지만
//자주 바뀌고 양이 방대한 양이 아니기 때문에 사용해도 큰 문제가 없는듯하다



class Engine
{
public:
	void Init(const WindowInfo& info);
	void Render();

public:
	void RenderBegin();
	void RenderEnd();

	void ResizeWindow(int32 width, int32 height	);

public:
	shared_ptr<Device>				GetDevice() { return _device; }
	shared_ptr<CommandQueue>		GetCmdQueue() { return _cmdQueue; }
	shared_ptr<SwapChain>			GetSwapChain() { return _swapChain; }
	shared_ptr<RootSignature>		GetRootSignature() { return _rootSignature; }
	shared_ptr<ConstantBuffer>		GetCB() { return _cb; }
	shared_ptr<TableDescriptorHeap> GetTableDescHeap() { return _tableDescHeap; }

private:
	//화면 관련 
	WindowInfo		_info;
	D3D12_VIEWPORT	_viewport = {};
	D3D12_RECT		_scissorRect = {};

	//
	shared_ptr<Device>				_device;
	shared_ptr<CommandQueue>		_cmdQueue;
	shared_ptr<SwapChain>			_swapChain;
	shared_ptr<RootSignature>		_rootSignature;
	shared_ptr<ConstantBuffer>		_cb;
	shared_ptr<TableDescriptorHeap> _tableDescHeap;

};

