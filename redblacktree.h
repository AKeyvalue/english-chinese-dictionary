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
		RedBlackTree();//初始化 
		
		~RedBlackTree();//析构 
		
		string search(string word);//查找单词 
		
		void leftRotate(Node *x);//左旋 
		
		void rightRotate(Node *y);//右旋 
		
		void insertFix(Node *z);//插入后调整红黑树 
		
		void fileInsert();//文件读取 
		
		void insert(string word, string meaning);//插入 
		
		int number(){
			return num;
		}
		
		
		void remove(string word);//删除结点 
		
		Node *searchNode(Node* node, string word);//查询节点，返回对应结点 
		
		void deleteNode(Node* z);//删除结点 
		
		void transplant(Node* u, Node* v);//结点转换 
		
		Node *minimum(Node* node);//最小结点 
		
		void deleteFix(Node* x);//删除修正 
		
		void clear(Node *node);//进行内存释放 
};


