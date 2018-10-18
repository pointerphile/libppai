#pragma once
#include "PPSingleton.h"
#include "PPFood.h"
class PPObjectManager : public PP::PPSingleton<PPObjectManager>
{
public:
	std::list<PP::PPFood> m_listObject;
public:
	PPObjectManager();
	~PPObjectManager();
};

