#include <iostream>
#include <fstream>
#include <vector>
#include <cmath>
#include <cstdlib>
#include <time.h>

/**
 * Graph class
 * 
 * Consists of two-dimensional std::vector of ints
 * 
 * Table represents graph nodes and ways between them
*/
class Graph {
private:
	unsigned int size;
	std::vector <std::vector <int>> table;

public:
	Graph(int size = 0) {
		this->size = size;
	}

	void AddNode();

	void ReadFromFile(const std::string& filename);

	void WriteToFile(const std::string& filename);

	void PrintGraph(void);

};

void Graph::AddNode() {
	std::vector <int> tmp;
	size += 1;
	table.push_back(tmp);
	for (unsigned int i = 0; i < size; i++) {
		if (i == size - 1)
			table[size - 1].push_back(0);
		else {
			int val;
			val = rand() % 9 + 1;
			table[size - 1].push_back(val);
			table[i].push_back(val);
		}
	}
}

void Graph::ReadFromFile(const std::string& filename) {
	std::fstream file;
	file.open(filename);
	while (true) {
		char c;
		file >> c;
		unsigned new_size = (int)c - 48;
		if (new_size < size)
			break;
		size = new_size;
	}
	for (unsigned int i = 0; i < size; i++) {
		if (i != 0) {
			int trash;
			file >> trash;
		}
		std::vector <int> tmp;
		table.push_back(tmp);
		for (unsigned int j = 0; j < size; j++) {
			int val;
			file >> val;
			table[i].push_back(val);
		}
	}
	file.close();
}

void Graph::WriteToFile(const std::string& filename) {
	std::ofstream file;
	file.open(filename);
	file << " ";
	for (unsigned int i = 0; i < size; i++)
		file << "  " << i + 1;
	file << std::endl;
	for (unsigned int i = 0; i < size; i++) {
		file << i + 1 << "  ";
		for (unsigned int j = 0; j < size; j++)
			file << table[i][j] << "  ";
		file << std::endl;
	}
	file.close();
}

void Graph::PrintGraph(void) {
	std::cout << std::endl << " ";
	for (unsigned int i = 0; i < size; i++)
		std::cout << "  " << i + 1;
	std::cout << std::endl;
	for (unsigned int i = 0; i < size; i++) {
		std::cout << i + 1 << "  ";
		for (unsigned int j = 0; j < size; j++)
			std::cout << table[i][j] << "  ";
		std::cout << std::endl;
	}
}

int main(void) {
	srand((unsigned int)time(0));
	Graph res;
	for (unsigned int i = 0; i < 9; i++)
		res.AddNode();
	res.PrintGraph();
	res.WriteToFile("graph.txt");
	res.ReadFromFile("graph.txt");
	res.PrintGraph();
	return 0;
}