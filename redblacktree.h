#pragma once
#include<iostream>
#include<fstream>
#include<string>
using namespace std;

enum Color{Red, Black};

struct Node{
	string word;
	string meaning;
	Color color;
	Node *left, *right, *parent;
	
	Node(string w, string m) : word(w), meaning(m){
		color = Red;
		left = right = parent = nullptr;
	}
};

class RedBlackTree{
	private:
		Node *root;
		int num;
		void Dele();
	public:
		RedBlackTree();//��ʼ�� 
		
		~RedBlackTree();//���� 
		
		string search(string word);//���ҵ��� 
		
		void leftRotate(Node *x);//���� 
		
		void rightRotate(Node *y);//���� 
		
		void insertFix(Node *z);//������������� 
		
		void fileInsert();//�ļ���ȡ 
		
		void insert(string word, string meaning);//���� 
		
		int number(){
			return num;
		}
		
		
		void remove(string word);//ɾ����� 
		
		Node *searchNode(Node* node, string word);//��ѯ�ڵ㣬���ض�Ӧ��� 
		
		void deleteNode(Node* z);//ɾ����� 
		
		void transplant(Node* u, Node* v);//���ת�� 
		
		Node *minimum(Node* node);//��С��� 
		
		void deleteFix(Node* x);//ɾ������ 
		
		void clear(Node *node);//�����ڴ��ͷ� 
};


