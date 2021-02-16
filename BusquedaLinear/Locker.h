#pragma once
#ifndef LOCKER_H
#define LOCKER_H

class Locker {
public:
	Locker(int);
	int linearSearch(int);
	void imprimir();

	int* arrayLockers;
private:
	int const Tamanio;
};


#endif