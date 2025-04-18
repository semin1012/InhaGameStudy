#pragma once

class cMtlTex;
class cGroup;

class cObjLoader
{
public:
	cObjLoader();
	~cObjLoader();

private:
	std::map<std::string, cMtlTex*> m_mapMtlTex;

public:
	void Load(OUT std::vector<cGroup*>& vecGroup, IN char* szFolder, IN char* szFile);
	void LoadMtlLib(IN char* szFolder, IN char* szFile);
};

