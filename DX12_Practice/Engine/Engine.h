/*
* ���� �ٽ��� �Ǵ� �κ�
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

//header�� header�� ���� ���� ������
//���� �ٲ�� ���� ����� ���� �ƴϱ� ������ ����ص� ū ������ ���µ��ϴ�



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
	//ȭ�� ���� 
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

