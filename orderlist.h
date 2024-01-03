#pragma once
#include<iostream>
#include<string>
#include<fstream>

using namespace std;

class orderlist {
private:
	string word[10000];
	string mean[10000];
	int word_length[26];//记录每种单词最开始位置。
	int num;//单词个数。
public:
	orderlist();

	void fileInsert();//文件中读取单词。

	int search(string n, int low, int high);//二分查找。

	void wordFind();//单词查找

	void Insert(); //单词插入

	void Delete(); //单词删除

	void FileWriter(int num); //文件写入。


};
