#pragma once
//#include <stdafx.h>
#include <time.h>

int delay(int mseconds) {
	clock_t goal = mseconds + clock();
	while (goal > clock());
	return mseconds;
}