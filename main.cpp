#include"manager.h"

using namespace std;

int main() {
	manager men;
	char choose;
	int i = 1;
	while (i) {
		cout << "------------欢迎使用小型英汉词典--------------" << endl;
		cout << "请输入词典运行对应数据结构的序号" << endl;
		cout << "字典树：1----------------------------顺序表：2" << endl;
		cout << "输入 3 退出程序" << endl;
		cin >> choose;
		switch (choose) {
		case'1': {
			men.manage1();
			system("cls");
			break;
		}
		case '2': {
			men.manage2();
			system("cls");
			break;
		}
		case '3': {
			i = 0;
			break;
		}
		default: {
			cout << "输入非法" << endl;
			system("pause");
			system("cls");
			break;
		}
		}
	}
	return 0;
}





