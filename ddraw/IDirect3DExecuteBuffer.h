#pragma once

class m_IDirect3DExecuteBuffer : public IDirect3DExecuteBuffer, public AddressLookupTableObject
{
private:
	IDirect3DExecuteBuffer *ProxyInterface;
	REFIID WrapperID = IID_IDirect3DExecuteBuffer;

public:
	m_IDirect3DExecuteBuffer(IDirect3DExecuteBuffer *aOriginal) : ProxyInterface(aOriginal)
	{
		ProxyAddressLookupTable.SaveAddress(this, ProxyInterface);
	}
	~m_IDirect3DExecuteBuffer()
	{
		ProxyAddressLookupTable.DeleteAddress(this);
	}

	DWORD GetDirectXVersion() { return 1; }
	REFIID GetWrapperType() { return WrapperID; }
	IDirect3DExecuteBuffer *GetProxyInterface() { return ProxyInterface; }
	m_IDirect3DExecuteBuffer *GetWrapperInterface() { return this; }

	/*** IUnknown methods ***/
	STDMETHOD(QueryInterface)(THIS_ REFIID riid, LPVOID * ppvObj);
	STDMETHOD_(ULONG, AddRef)(THIS);
	STDMETHOD_(ULONG, Release)(THIS);

	/*** IDirect3DExecuteBuffer methods ***/
	STDMETHOD(Initialize)(THIS_ LPDIRECT3DDEVICE, LPD3DEXECUTEBUFFERDESC);
	STDMETHOD(Lock)(THIS_ LPD3DEXECUTEBUFFERDESC);
	STDMETHOD(Unlock)(THIS);
	STDMETHOD(SetExecuteData)(THIS_ LPD3DEXECUTEDATA);
	STDMETHOD(GetExecuteData)(THIS_ LPD3DEXECUTEDATA);
	STDMETHOD(Validate)(THIS_ LPDWORD, LPD3DVALIDATECALLBACK, LPVOID, DWORD);
	STDMETHOD(Optimize)(THIS_ DWORD);
};
