#pragma once
#include "DaneProblemu.h"

class Problem
{
public:
	static size_t id;

private:
	DaneProblemu dane;

public:
	Problem(DaneProblemu dane);
	~Problem();

	void aktualizuj(int nowyStatus);

protected:
	void powiadomOAktualizacji();
};

