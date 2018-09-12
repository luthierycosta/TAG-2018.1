#include "grafo.h"
#include <iostream>
#include <algorithm>	// max
#include <exception>
#include <iterator>

using namespace std;

Grafo::Grafo(){}

Grafo::Grafo(int n) {
	for(int i = 1; i <= n; i++)
		addVertice(i);
}


void Grafo::addVertice(int id) {
	vertices.push_back(Vertice(id));
}

Vertice& Grafo::getVertice(int id) {
	
	vector<Vertice>::iterator it;
	for (it = vertices.begin(); it != vertices.end(); it++)
		if((*it).id == id)
			return *it;

	throw "Argumento invalido."; 
}

void Grafo::addAresta(int id_a, int id_b) {

	if (!existeAresta(id_a, id_b)) {
		(getVertice(id_a)).push_back(&getVertice(id_b));
		(getVertice(id_b)).push_back(&getVertice(id_a));
	}
}

bool Grafo::existeAresta(int id_a, int id_b) {	
	return  ((getVertice(id_a)).existeAresta(&getVertice(id_b)));
}

int Grafo::grau() {
	int res = 0;
	for (Vertice v: vertices)
		res = max(res, v.grau());

	return res;
}

bool Grafo::conectado() {
	for (Vertice v: vertices)
		if (!v.conectado())
			return false;

	return true;
}

void Grafo::imprime() {
	cout << "\nGRAFO:\n";
	for(Vertice v: vertices)
		v.imprime();

	cout << endl;
}

void Grafo::imprimeGraus() {
	cout << "GRAUS DOS VÉRTICES" << endl; 
	for(Vertice v: vertices)
		cout << "Vértice "<< v.id <<" tem grau "<< v.grau() << endl;

	cout << "Grau do grafo: "<< this->grau() << endl;
}