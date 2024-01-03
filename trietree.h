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
	};//���캯��
	~Word() {

	}//��������

	void setEnglish(string e) {
		this->english = e;
	}//����Ӣ�ġ�
	void setChinese(string c) {
		this->chinese = c;
	}//�������Ľ��͡�
	void setE(bool e) {
		this->existence = e;
	};//�����Ƿ���ڡ�

	bool isexistence() {
		return existence;
	}//�����Ƿ���ڡ�
	string getEnglish() {
		return english;
	}//��ȡӢ�ġ�
	string getChinese() {
		return chinese;
	};//��ȡ���Ľ��͡�
};

class tiretree {
private:
	Word* root;//���ڵ㡣
	int num;//����������
	void filewrite(Word* node, medium* &bt);//��������д������
	void Dele(Word* node);//�ͷ��ڴ�
public:

	tiretree();//���췽����

	~tiretree();//��������

	bool insert(char eng[], char chi[]);//���뵥��

	Word* search(char word[]);//���ҵ��ʡ�

	bool dele(char word[]);//ɾ�����ʡ�

	bool change(char word[]);//�޸ĵ��ʡ�

	void fileread(string File);//�ļ���ȡ��

	void fileread();//��ȡ�ļ� 

	int order(char a);//������

	void filewrite(int i);//������д���ļ���

	int number() {
		return num;//���ص�����Ŀ��
	}
	
	

};
