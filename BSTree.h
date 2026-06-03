#pragma once

#include <iostream>
#include <stdexcept>
#include "List.h"
#include "DLinkedList.h"
#include "BSTNode.h"

using std::cout;
using std::runtime_error;

template <typename E>
class BSTree {
private:
	BSTNode<E>* root;
	int size;

	BSTNode<E>* insertAux(BSTNode<E>* current, E element) {
		if (current == nullptr)
			return new BSTNode<E>(element);
		if (element == current->element)
			throw runtime_error("Duplicated element.");

		if (element < current->element)
			current->left = insertAux(current->left, element);
		else
			current->right = insertAux(current->right, element);

		return current;
	}
	BSTNode<E>* removeAux(BSTNode<E>* current, E element, E* result) {
		if (current == nullptr)
			throw runtime_error("Element not found.");
		
		if (element < current->element) {
			current->left = removeAux(current->left, element, result);
			return current;
		}
		else if (element > current->element) {
			current->right = removeAux(current->right, element, result);
			return current;
		}
		
		*result = current->element;
		if (current->childrenCount() == 0) {
			delete current;
			return nullptr;
		}
		else if (current->childrenCount() == 1) {
			BSTNode<E>* child = current->getOnlyChild();
			delete current;
			return child;
		}
		BSTNode<E>* successor = getSuccessor(current);
		swap(successor, current);
		current->right = removeAux(current->right, element, result);
		return current;
	}
	void clearAux(BSTNode<E>* current) {
		if (current == nullptr) return;
		clearAux(current->left);
		clearAux(current->right);
		delete current;
	}
	BSTNode<E>* getSuccessor(BSTNode<E>* current) {
		BSTNode<E>* successor = current->right;
		while (successor->left != nullptr)
			successor = successor->left;
		return successor;
	}
	void swap(BSTNode<E>* n1, BSTNode<E>* n2) {
		E temp = n1->element;
		n1->element = n2->element;
		n2->element = temp;
	}
	void getElementsAux(BSTNode<E>* current, List<E>* elements) {
		if (current == nullptr) return;
		getElementsAux(current->left, elements);
		elements->append(current->element);
		getElementsAux(current->right, elements);
	}
	void printAux(BSTNode<E>* current) {
		if (current == nullptr) return;
		printAux(current->left);
		cout << current->element << " ";
		printAux(current->right);
	}
	int height(BSTNode<E>* current) {
		if (current == nullptr)
			return 0;
		int lh = height(current->left);
		int rh = height(current->right);
		return (lh > rh ? lh : rh) + 1;
	}

public:
	BSTree() {
		root = nullptr;
		size = 0;
	}
	~BSTree() {
		clear();
	}
	void insert(E element) {
		root = insertAux(root, element);
		size++;
	}
	E find(E element) {
		BSTNode<E>* current = root;
		while (current != nullptr) {
			if (element == current->element)
				return current->element;
			else if (element < current->element)
				current = current->left;
			else
				current = current->right;
		}
		throw runtime_error("Element not found.");
	}
	E remove(E element) {
		E result{};
		root = removeAux(root, element, &result);
		size--;
		return result;
	}
	bool contains(E element) {
		BSTNode<E>* current = root;
		while (current != nullptr) {
			if (element == current->element)
				return true;
			else if (element < current->element)
				current = current->left;
			else
				current = current->right;
		}
		return false;
	}
	void clear() {
		clearAux(root);
		root = nullptr;
		size = 0;
	}
	List<E>* getElements() {
		List<E>* elements = new DLinkedList<E>();
		getElementsAux(root, elements);
		return elements;
	}
	int getSize() {
		return size;
	}
	bool isEmpty() {
		return size == 0;
	}
	void print() {
		printAux(root);
	}
	int getHeight() {
		return height(root);
	}
};