#include"framework.h"
#include "cObjLoader.h"
#include "cMtlTex.h"
#include "cGroup.h"

using namespace std;

cObjLoader::cObjLoader()
{

}

cObjLoader::~cObjLoader()
{

}

void cObjLoader::Load(OUT std::vector<cGroup*>& vecGroup, IN char* szFolder, IN char* szFile)
{
	vector<D3DXVECTOR3> vecV;
	vector<D3DXVECTOR2> vecVT;
	vector<D3DXVECTOR3> vecVN;
	vector<ST_PNT_VERTEX> vecVertex;

	string sFullPath(szFolder);
	sFullPath += (string("/") + string(szFile));

	FILE* fp;
	fopen_s(&fp, sFullPath.c_str(), "r"); 

	string sMtrlName;
	
	while (true)
	{
		if (feof(fp)) 
			break;

		char szTemp[1024];
		fgets(szTemp, 1024, fp);
		if (szTemp[0] == '#')
		{
			continue;
		} // << : �ּ� �ǳʶ�
		else if (szTemp[0] == 'm')
		{
			char szMtlFile[1024];
			sscanf_s(szTemp, "%*s ./%s", szMtlFile, 1024);
			LoadMtlLib(szFolder, szMtlFile);
		} // << : material
		else if (szTemp[0] == 'g')
		{
			if (!vecVertex.empty())
			{
				cGroup* pGroup = new cGroup;
				pGroup->SetVertex(vecVertex);
				pGroup->SetMtlTex(m_mapMtlTex[sMtrlName]);
				vecGroup.push_back(pGroup);
				vecVertex.clear();
			}
		} // << : group
		else if (szTemp[0] == 'v')
		{
			if (szTemp[1] == ' ')
			{
				float x, y, z;
				sscanf_s(szTemp, "%*s %f %f %f", &x, &y, &z);
				vecV.push_back(D3DXVECTOR3(x, y, z));

			}
			else if (szTemp[1] == 't') // texture
			{
				float u, v;
				sscanf_s(szTemp, "%*s %f %f %*f", &u, &v);
				vecVT.push_back(D3DXVECTOR2(u, v));
			}
			else if (szTemp[1] == 'n') // normal
			{
				float x, y, z;
				sscanf_s(szTemp, "%*s %f %f %f", &x, &y, &z);
				vecVN.push_back(D3DXVECTOR3(x, y, z));
			}
		} // << : vertex
		else if (szTemp[0] == 'u')
		{
			char szMtlName[1024];
			sscanf_s(szTemp, "%*s %s", szMtlName, 1024);
			sMtrlName = string(szMtlName);
		}
		else if (szTemp[0] == 'f')
		{
			int nIndex[3][3];
			sscanf_s(szTemp, "%*s %d/%d/%d %d/%d/%d %d/%d/%d",
				&nIndex[0][0], &nIndex[0][1], &nIndex[0][2],
				&nIndex[1][0], &nIndex[1][1], &nIndex[1][2],
				&nIndex[2][0], &nIndex[2][1], &nIndex[2][2]
			);

			for (int i = 0; i < 3; ++i)
			{
				ST_PNT_VERTEX v;
				v.p = vecV[nIndex[i][0] - 1];
				v.t = vecVT[nIndex[i][1] - 1];
				v.n = vecVN[nIndex[i][2] - 1];
				vecVertex.push_back(v);
			}
		} // << : fragment? << : if
	}

	fclose(fp);

	for (auto it : m_mapMtlTex)
	{
		Safe_Release(it.second);
	}
	m_mapMtlTex.clear();
}

void cObjLoader::LoadMtlLib(char* szFolder, char* szFile)
{
	string sFullPath(szFolder);
	sFullPath += (string("/") + string(szFile));

	FILE* fp;
	fopen_s(&fp, sFullPath.c_str(), "r");

	string sMtrlName;

	while (true)
	{
		if (feof(fp)) 
			break;

		char szTemp[1024];
		fgets(szTemp, 1024, fp);
		if (szTemp[0] == '#')
		{
			continue;
		} // << : �ּ� �ǳʶ�
		else if (szTemp[0] == 'n')
		{

			char szMtlName[1024];
			sscanf_s(szTemp, "%*s %s", szMtlName, 1024);
			sMtrlName = string(szMtlName);
			if (m_mapMtlTex.find(sMtrlName) == m_mapMtlTex.end())
				m_mapMtlTex[sMtrlName] = new cMtlTex;
		}
		else if (szTemp[0] == 'k')
		{
			if (szTemp[1] == 'a')
			{
				float r, g, b;
				sscanf_s(szTemp, "%*s %f %f %f", &r, &g, &b);
				m_mapMtlTex[sMtrlName]->GetMaterial().Ambient.r = r;
				m_mapMtlTex[sMtrlName]->GetMaterial().Ambient.g = g;
				m_mapMtlTex[sMtrlName]->GetMaterial().Ambient.b = b;
				m_mapMtlTex[sMtrlName]->GetMaterial().Ambient.a = 1.0;
			}
			else if (szTemp[1] == 'd')
			{
				float r, g, b;
				sscanf_s(szTemp, "%*s %f %f %f", &r, &g, &b);
				m_mapMtlTex[sMtrlName]->GetMaterial().Diffuse.r = r;
				m_mapMtlTex[sMtrlName]->GetMaterial().Diffuse.g = g;
				m_mapMtlTex[sMtrlName]->GetMaterial().Diffuse.b = b;
				m_mapMtlTex[sMtrlName]->GetMaterial().Diffuse.a = 1.0;
			}
			else if (szTemp[1] == 's')
			{
				float r, g, b;
				sscanf_s(szTemp, "%*s %f %f %f", &r, &g, &b);
				m_mapMtlTex[sMtrlName]->GetMaterial().Specular.r = r;
				m_mapMtlTex[sMtrlName]->GetMaterial().Specular.g = g;
				m_mapMtlTex[sMtrlName]->GetMaterial().Specular.b = b;
				m_mapMtlTex[sMtrlName]->GetMaterial().Specular.a = 1.0;
			}
		}
		else if (szTemp[0] == 'd')
		{
			float d;
			sscanf_s(szTemp, "%*s %f", &d);
			m_mapMtlTex[sMtrlName]->GetMaterial().Power = d;
		}
		else if (szTemp[0] == 'm')
		{
			char szTexFile[1024];
			sscanf_s(szTemp, "%*s %s", szTexFile, 1024);
			sFullPath = string(szFolder);
			sFullPath += (string("/") + string(szTexFile));
			LPDIRECT3DTEXTURE9 pTexture = 
				g_pTextureManager->GetTexture(sFullPath);
			m_mapMtlTex[sMtrlName]->SetTexture(pTexture);
		}
	}

	fclose(fp);
}


