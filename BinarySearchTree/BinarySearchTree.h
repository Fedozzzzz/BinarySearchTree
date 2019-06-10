#ifndef __BINARY_SEARCH_TREE_H
#define __BINARY_SEARCH_TREE_H

#include <iostream>
using namespace std;

template <class Type>
class BinarySearchTree {
private:
	// �������� ��������� ���� �� �������� �� �����
	struct Node {
		Type  key_;              // �������� �����, ������������ � ����
		Node *left_;     // ��������� �� ����� ���������
		Node *right_;   // ��������� �� ������ ���������
		Node *p_;        // ��������� �� �� �������� !!! �� ������������
						 // ����������� ����
		Node(const Type& key, Node *left = NULL, Node *right = NULL, Node *p = NULL) :
			key_(key), left_(left), right_(right), p_(p)
		{  }
	};
	// ������ ����������� � ���� ��������� �� �������� ����.
	Node *root_;
public:
	// ����������� "�� ���������" ������� ������ ������
	BinarySearchTree() : root_(NULL) {}
	// ���������� ����������� ������, ������� ������ ������
	~BinarySearchTree() { deleteSubtree(root_); }
	// ������ ���������� ����������� ������ � �������� ����� out
	void print(ostream & out) 
	{
		printNode(out, root_); 
		out << endl;
	}
	// ������� ������ �� ����� � �������� ������ ������
	bool iterativeSearch(const Type & key)  const 
	{
		return (iterativeSearchNode(key) != 0);
	}
	// ������� ������ �������� � ������, �� ���������� �������
	// ���������. ������� ������������ � ���� ������
	void insert(const Type & key)
	{
		if (iterativeSearch(key))
			return;
		Node* tempNode = root_;
		Node* tempParent = NULL;
		if (tempNode == NULL)
			root_ = new Node(key);
		else {
			while (tempNode != 0) {
				tempParent = tempNode;
				if (key < tempNode->key_)
					tempNode = tempNode->left_;
				else
					tempNode = tempNode->right_;
			}
			if (key < (tempParent->key_))
				tempParent->left_ = new Node(key, NULL, NULL, tempParent);
			else
				tempParent->right_ = new Node(key, NULL, NULL, tempParent);
		}
	}
// �������� �������� �� ������, �� ���������� ������� ���������
	void deleteKey(const Type & key)
	{
		if (root_ != NULL)
		{
			Node * tempNode = iterativeSearchNode(key);
			if (tempNode)//
			{
				if (tempNode->left_ == NULL)
				{
					if (tempNode->right_ != NULL)
					{
						Node* rightNode = tempNode->right_;
						tempNode->key_ = rightNode->key_;
						tempNode->left_ = rightNode->left_;
						tempNode->right_ = rightNode->right_;
						delete rightNode;
					}
					else
					{
						if (tempNode == root_)
							root_ = NULL;
						else
							if (tempNode == (tempNode->p_)->left_)
								(tempNode->p_)->left_ = NULL;
							else
								(tempNode->p_)->right_ = NULL;
						delete tempNode;
					}
				}
				else
				{
					if (tempNode->right_ == NULL)
					{
						Node* leftNode = tempNode->left_;
						tempNode->key_ = leftNode->key_;
						tempNode->left_ = leftNode->left_;
						tempNode->right_ = leftNode->right_;
						delete leftNode;
					}
					else
					{
						Node* min = minNode(tempNode->right_);
						tempNode->key_ = min->key_;
						if (min != tempNode->right_)
							min->p_->left_ = min->right_;
						else
							tempNode->right_ = min->right_;
						delete min;
					}
				}
			}
		}
	}

	// ����������� ���������� ����� ������
	int count() const {
		return countSubTree(this->root_);
	}
	// ����������� ������ ������
	int height() const {
		return heightSubTree(this->root_);
	}
	//friend ostream &operator<<(ostream& out, BinarySearchTree& tree)
	//{
	//	if (tree.root_)
	//		out << *(tree.root_);
	//	return out;
	//}
	void printTree()
{
		if (root_)
			printNode(root_, 0);
}
private:
	void printNode(Node * p, int level)
	{
		if (p)
		{
			printNode(p->right_, level + 1);
			for (int i = 0; i< level; i++) cout << "   ";
			cout << p->key_ << endl;
			printNode(p->left_, level + 1);
		}
	}
	// ������� ������ ������ ���� �� ����� � �������� ������ ������
	Node * iterativeSearchNode(const Type & key) const
	{
		Node* temp = root_;
		while (temp != 0 && key != temp->key_) {
			if (key < temp->key_)
				temp = temp->left_;
			else
				temp = temp->right_;
		}
		return temp;
	}
	//
	// ����������� �������, ��������������  
	// ����������� ���� �������� ������������ �������
	
	//friend ostream & operator<<(ostream& out, Node& node)
	//{
	//	// ������� ������ ����� �������
	//	if (node.left_)
	//		out << *(node.left_);
	//	out << node.key_<< endl;//��� value ������ ���� ��������� operator<<
	//	if (node.right_)
	//		out << *(node.right_);
	//	return out;
	//}

	// ����������� ������� ��� ������������ ������
	void deleteSubtree(Node *node) {
		if (node != 0) {
			deleteSubtree(node->left_);
			deleteSubtree(node->right_);
			delete node;
		}
	}
	// ����������� ������� ����������� ���������� ����� ������
	int countSubTree(Node *node) const {
		if (node == NULL)
			return 0;
		return (1 + countSubTree(node->left_) +
			countSubTree(node->right_));
	}
	// ����������� ������� ����������� ������ ������
	int heightSubTree(Node *node) const {
		if (node != 0) {
			int left = heightSubTree(node->left_);
			int right = heightSubTree(node->right_);
			return left > right ? left + 1 : right + 1;
		}
		return 0;
	}
	// ����������� ������� ��� ������ ����������� ������ � �������� �����
	void printNode(ostream & out, Node *root) const {
		// ����������� ������ ����������� � ������� ������.
		out << '(';
		if (root) {
			// ��� ����� ������ ������ ���� ���������� (��� ��������������)
			// �������� ������ � �������� ����� <<
			out << root->key_;
			printNode(out, root->left_);
			printNode(out, root->right_);
		}
		out << ')';
	}
	// ����������� ������� ��� ����������� ������ ����� ������.
	void inorderWalk(Node *node) const {
		if (node != 0) {
			inorderWalk(node->left_);
			cout << node->key_ << " ";
			inorderWalk(node->right_);
		}
	}
	Node* minNode(Node *node) {
		if (node != 0) {
			while (node->left_ != 0)
				node = node->left_;
		}
		return node;
	}
	Node* maxNode(Node *node) {
		if (node != 0) {
			while (node->right_ != 0)
				node = node->right_;
		}
		return node;
	}
}; // ����� ������� ������ TreeBinarySearchTree
#endif
