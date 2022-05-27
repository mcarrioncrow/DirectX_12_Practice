#pragma once


#define _HAS_STD_BYTE 0

//..include
#include <windows.h>
#include <tchar.h>
#include <memory>
#include <string>
#include <vector>
#include <array>
#include <list>
#include <map>
using namespace std;

#include <filesystem>
namespace fs = std::filesystem;

//DirectX
#include "d3dx12.h"
#include <d3d12.h>
#include <wrl.h>
#include <d3dcompiler.h>
#include <dxgi.h>
#include <DirectXMath.h>
#include <DirectXPackedVector.h>
#include <DirectXColors.h>
using namespace DirectX;
using namespace DirectX::PackedVector;
using namespace Microsoft::WRL;


// - Texture Mapping

#include <DirectXTex/DirectXTex.h>
#include <DirectXTex/DirectXTex.inl>


//..lib
#pragma comment(lib, "d3d12")
#pragma comment(lib, "dxgi")
#pragma comment(lib, "dxguid")
#pragma comment(lib, "d3dcompiler")

//..typedef
using int8		= __int8;
using int16		= __int16;
using int32		= __int32;
using int64		= __int64;
using uint8		= unsigned __int8;
using uint16	= unsigned __int16;
using uint32	= unsigned __int32;
using uint64	= unsigned __int64;
using Vec2		= XMFLOAT2;
using Vec3		= XMFLOAT3;
using Vec4		= XMFLOAT4;
using Matrix	= XMMATRIX;

//ConstantBufferView 관리를 위한 enum Class
enum class CBV_REGISTER : uint8
{
	b0,
	b1,
	b2,
	b3,
	b4,

	END
};

enum class SRV_REGISTER : uint8
{
	t0 = static_cast<uint8>(CBV_REGISTER::END),
	t1,
	t2,
	t3,
	t4,

	END
};

enum
{
	SWAP_CHAIN_BUFFER_COUNT = 2,

	CBV_REGISTER_COUNT = CBV_REGISTER::END,
	SRV_REGISTER_COUNT = SRV_REGISTER::END,
	REGISTER_COUNT = CBV_REGISTER::END

};



#define DEVICE				GEngine->GetDevice()->GetDevice()
#define CMD_LIST			GEngine->GetCmdQueue()->GetCmdList()
#define RESOURCE_CMD_LIST	GEngine->GetCmdQueue()->GetCmdList()
#define ROOT_SIGNATURE		GEngine->GetRootSignature()->GetSignature()


struct WindowInfo
{
	HWND	hWnd; // 출력 윈도우
	int32	width; // 너비
	int32	height; // 높이
	bool	windowed; // 창모드 or 전체화면
};

struct Vertex
{
	Vec3 pos;	//X,Y,Z
	Vec4 color; //RGBA
	Vec2 uv;
};

struct Transform
{
	Vec4 offset;
};



//class Engine - 전방선언
//extern을 이용해서 전역선언 - https://docs.microsoft.com/ko-kr/cpp/cpp/extern-cpp?view=msvc-170
extern unique_ptr<class Engine> GEngine;

