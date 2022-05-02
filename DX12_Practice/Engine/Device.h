#pragma once

//��ġ���� Ŭ����?
//�η»繫��??
//GPU�� �����ϴ� �κ�

class Device
{
public:
	//�ʱ�ȭ
	void Init();

	//get
	ComPtr<IDXGIFactory>	GetDXGI() { return _dxgi; }
	ComPtr<ID3D12Device>	GetDevice() { return _device; }

private:
	//ComPtr???
	//COM(Component Object Model)
	ComPtr<ID3D12Debug>		_debugController;
	ComPtr<IDXGIFactory>	_dxgi;			//ȭ�� ���� ���
	ComPtr<ID3D12Device>	_device;		//���� ��ü ����

};

