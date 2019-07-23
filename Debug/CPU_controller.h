#ifndef __CPU_CONTROLLER_H__
#define __CPU_CONTROLLER_H__
#pragma warning(disable : 4996)
#include "CPU_view.h"


class CPU_controller {
private:
	CPU_view * pView;

public:
	CPU_controller() {

	}

	CPU_controller(CPU_view *pView);
	~CPU_controller() {
	}

	void RunGame();
};

#endif