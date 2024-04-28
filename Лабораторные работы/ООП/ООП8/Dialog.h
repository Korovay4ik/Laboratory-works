#pragma once
#include "Vector.h"
#include "Event.h"
#include "Print.h"
#include "Magazin.h"

class Dialog : public Vector
{
protected:
	int EndState;
public:
	Dialog();
	~Dialog() {}
	void GetEvent(TEvent&);
	bool is_command(char);
	int Execute();
	void HandleEvent(TEvent&);
	void ClearEvent(TEvent&);
	int Valid();
	void EndExec();
};