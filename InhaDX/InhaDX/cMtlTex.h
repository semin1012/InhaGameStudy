#pragma once
#include "cObject.h"
class cMtlTex : public cObject
{
public:
	cMtlTex();
	~cMtlTex();

private:
	Synthesize_Pass_By_Ref(D3DMATERIAL9, m_stMtl, Material);
	Synthesize_Add_Ref(LPDIRECT3DTEXTURE9, m_pTexture, Texture);
};

