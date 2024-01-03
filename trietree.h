#pragma once
#include<iostream>
#include<fstream>
using namespace std;
typedef struct mid {
	string data1;
	string data2;
	struct mid* next;
}medium;

class Word {
private:
	string english;
	string chinese;
	bool existence;
public:
	Word* next[30];

	Word() {
		string english = "no find";
		string chinese = "no find";
		existence = false;
		for (int i = 0; i < 30; i++) {
			this->next[i] = NULL;
		}
	};//构造函数
	~Word() {

	}//析构函数

	void setEnglish(string e) {
		this->english = e;
	}//设置英文。
	void setChinese(string c) {
		this->chinese = c;
	}//设置中文解释。
	void setE(bool e) {
		this->existence = e;
	};//设置是否存在。

	bool isexistence() {
		return existence;
	}//返回是否存在。
	string getEnglish() {
		return english;
	}//获取英文。
	string getChinese() {
		return chinese;
	};//获取中文解释。
};

class tiretree {
private:
	Word* root;//根节点。
	int num;//单词数量。
	void filewrite(Word* node, medium* &bt);//单词升序写入链表
	void Dele(Word* node);//释放内存
public:

	tiretree();//构造方法。

	~tiretree();//析构函数

	bool insert(char eng[], char chi[]);//插入单词

	Word* search(char word[]);//查找单词。

	bool dele(char word[]);//删除单词。

	bool change(char word[]);//修改单词。

	void fileread(string File);//文件读取。

	void fileread();//读取文件 

	int order(char a);//处理函数

	void filewrite(int i);//将数据写入文件。

	int number() {
		return num;//返回单词数目。
	}
	
	

};
