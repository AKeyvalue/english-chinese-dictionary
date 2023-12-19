#include"manager.h"

void manager::menu() {
	cout << "_________________________" << endl;
	cout << "|     使用说明          |" << endl;
	cout << "|1、查找单词 2、删除单词|" << endl;
	cout << "|3、添加单词 4、关闭词典|" << endl;
	cout << "|                       |" << endl;
	cout << "|查找和删除只需输入英文 |" << endl;
	cout << "|添加需要输入中文和英文 |" << endl;
	cout << "|_______________________|" << endl;
}

void manager::manage1() {
	tiretree a;
	
	int j = 1;
	char v;
	char data1[50], data2[50];
	while (j) {
		menu();
		cout << "请输入选择序号" << endl;
		cin >> v;
		switch (v) {
		case '1':
		{
			cout << "请输入要查找的单词" << endl;
			cin >> data1;
			Word* y = a.search(data1);
			if (y == NULL) {
				cout << "不存在该单词" << endl << "是否插入该单词？(是：1， 否：0)" << endl;
				int i;
				cin >> i;
				if (i == 1) {
					cout << "请输入要添加的意思：";
					cin >> data2;
					bool v = a.insert(data1, data2);
					if (v == true) {
						cout << "插入成功" << endl;
					}
					else {
						cout << "插入失败" << endl;
					}
				}
			}
			else {
				cout << y->getEnglish() << endl << y->getChinese() << endl;
			}
			system("pause");
			system("cls");
			break;
		}
		case '2':
		{
			cout << "请输入要删除的单词" << endl;
			cin >> data1;
			bool c = a.dele(data1);
			if (c) {
				cout << "删除成功" << endl;
			}
			else {
				cout << "删除失败" << endl;
			}
			system("pause");
			system("cls");
			break;
		}
		case '3':
		{
			cout << "请输入要添加的单词拼写：";
			cin >> data1;
			cout << "请输入要添加的意思：";
			cin >> data2;
			bool v = a.insert(data1, data2);
			if (v == true) {
				cout << "插入成功" << endl;
			}
			else {
				cout << "插入失败" << endl;
			}
			system("pause");
			system("cls");
			break;
		}
		case '4':
		{
			j = 0;
			break;
		}
		default:{
			cout << "输入非法" << endl;
			system("pause");
			system("cls");
			break;
		}
		}
	}
}

void manager::manage2() {
	orderlist dict;
	char choose;
	int j = 1;
	while (j) {
		menu();
		cout << "请输入选择序号" << endl;
		cin >> choose;
		switch (choose) {
		case '1':{
			dict.wordFind();
			system("cls");
			break;
			}
		case '2': {
			dict.Delete();
			system("cls");
			break;
		}
		case '3': {
			dict.Insert();
			system("cls");
			break;
		}
		case '4': {
			j = 0;
			break;
		}
		default: {
			cout << "输入非法" << endl;
			break;
		}
		}
	}
}