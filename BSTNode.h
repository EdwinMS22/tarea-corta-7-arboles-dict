#pragma once

template <typename E>
class BSTNode {
public:
	E element;
	BSTNode<E>* left;
	BSTNode<E>* right;
	
	BSTNode(E element, BSTNode<E>* left, BSTNode<E>* right) {
		this->element = element;
		this->left = left;
		this->right = right;
	}
	BSTNode(E element) {
		this->element = element;
		left = right = nullptr;
	}
	int childrenCount() {
		return (left != nullptr ? 1 : 0) + (right != nullptr ? 1 : 0);
	}
	BSTNode<E>* getOnlyChild() {
		return left != nullptr ? left : right;
	}
};