#pragma once

//장치관련 클래스?
//인력사무소??
//GPU와 핑퐁하는 부분

class Device
{
public:
	//초기화
	void Init();

	//get
	ComPtr<IDXGIFactory>	GetDXGI() { return _dxgi; }
	ComPtr<ID3D12Device>	GetDevice() { return _device; }

private:
	//ComPtr???
	//COM(Component Object Model)
	ComPtr<ID3D12Debug>		_debugController;
	ComPtr<IDXGIFactory>	_dxgi;			//화면 관련 기능
	ComPtr<ID3D12Device>	_device;		//각종 객체 생성

	// 해당 부분에서 _device를 왜 만드는지 이해를 하고 넘어가야 이후 왜 device를 받는지 이해할듯하다


};

