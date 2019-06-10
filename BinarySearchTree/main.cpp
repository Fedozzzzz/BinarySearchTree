#include "BinarySearchTree.h"
#include <iostream>
using namespace std;

int main() {

	BinarySearchTree <int> t; // создаем пустое дерево
							  // добавляем узлы 
	t.insert(10);
	t.insert(3);
	t.insert(20);
	t.insert(15);
	t.insert(30);
	t.insert(2);
	t.insert(5);
	t.insert(32);
	t.insert(22);

	// Вывод узлов дерева в выходной поток 
	t.print(cout);
	//cout << t;
	t.printTree();
	t.deleteKey(2);
	t.print(cout);
	
	// Поиск в дереве по ключу
	
	int  keyFound = t.iterativeSearch(15); // поиск должен быть успешным
	cout << "Key " << 15 <<
		(keyFound ? " found successfully" : " not found") <<
		" in the tree" << endl;
	keyFound = t.iterativeSearch(23);      // поиск должен быть неудачным
	cout << "Key " << 23 <<
		(keyFound ? " found successfully" : " not found") <<
		" in the tree" << endl;
	// определение высоты и количества узлов дерева
	cout << "height = " << t.height() << endl;
	cout << "count =  " << t.count() << endl;
	
	BinarySearchTree<int> emptyTree;
	emptyTree.deleteKey(0);
	emptyTree.print(cout);
	emptyTree.printTree();
	keyFound = emptyTree.iterativeSearch(12);
	cout << "Key " << 12 <<
		(keyFound ? " found successfully" : " not found") <<
		" in the tree" << endl;
	cout << "height = " << emptyTree.height() << endl;
	cout << "count =  " << emptyTree.count() << endl;
	BinarySearchTree<int> bigTree;
	for (int i = 0; i < 50; i++)
		bigTree.insert(rand());
	bigTree.print(cout);
	keyFound = bigTree.iterativeSearch(41);
	cout << "Key " << 41 <<
		(keyFound ? " found successfully" : " not found") <<
		" in the tree" << endl;
	keyFound = bigTree.iterativeSearch(149);
	cout << "Key " << 149 <<
		(keyFound ? " found successfully" : " not found") <<
		" in the tree" << endl;
	cout << "height = " << bigTree.height() << endl;
	cout << "count =  " << bigTree.count() << endl;
	bigTree.deleteKey(41);
	bigTree.print(cout);
	bigTree.printTree();
	keyFound = bigTree.iterativeSearch(41);
	cout << "Key " << 41 <<
		(keyFound ? " found successfully" : " not found") <<
		" in the tree" << endl;
	cout << "height = " << bigTree.height() << endl;
	cout << "count =  " << bigTree.count() << endl;
	BinarySearchTree<int> sameTree;
	for (int i = 0; i < 10; i++)
		sameTree.insert(10);
	sameTree.print(cout);
	cout << "height = " << sameTree.height() << endl;
	cout << "count =  " << sameTree.count() << endl;
	system("pause");
	return 0;
}
