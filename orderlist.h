#pragma once
#include<iostream>
#include<string>
#include<fstream>

using namespace std;

class orderlist {
private:
	string word[10000];
	string mean[10000];
	int word_length[26];//��¼ÿ�ֵ����ʼλ�á�
	int num;//���ʸ�����
public:
	orderlist();

	void fileInsert();//�ļ��ж�ȡ���ʡ�

	int search(string n, int low, int high);//���ֲ��ҡ�

	void wordFind();//���ʲ���

	void Insert(); //���ʲ���

	void Delete(); //����ɾ��

	void FileWriter(int num); //�ļ�д�롣


};
