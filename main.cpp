#include"manager.h"

using namespace std;

int main() {
	manager men;
	char choose;
	int i = 1;
	while (i) {
		cout << "------------��ӭʹ��С��Ӣ���ʵ�--------------" << endl;
		cout << "������ʵ����ж�Ӧ���ݽṹ�����" << endl;
		cout << "�ֵ�����1----------------------------˳���2" << endl;
		cout << "���� 3 �˳�����" << endl;
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
			cout << "����Ƿ�" << endl;
			system("pause");
			system("cls");
			break;
		}
		}
	}
	return 0;
}





