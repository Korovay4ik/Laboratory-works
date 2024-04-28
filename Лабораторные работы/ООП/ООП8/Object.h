#pragma once

class Object
{
public:
	Object() {}
	virtual ~Object() {}
	virtual void Show(bool) = 0;
	virtual void Input() = 0;
};