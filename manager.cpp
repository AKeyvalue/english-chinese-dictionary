#include"manager.h"

void manager::menu() {
	cout << "_________________________" << endl;
	cout << "|     ʹ��˵��          |" << endl;
	cout << "|1�����ҵ��� 2��ɾ������|" << endl;
	cout << "|3����ӵ��� 4���رմʵ�|" << endl;
	cout << "|                       |" << endl;
	cout << "|���Һ�ɾ��ֻ������Ӣ�� |" << endl;
	cout << "|�����Ҫ�������ĺ�Ӣ�� |" << endl;
	cout << "|_______________________|" << endl;
}

void manager::manage1() {
	tiretree a;
	
	int j = 1;
	char v;
	char data1[50], data2[50];
	while (j) {
		menu();
		cout << "������ѡ�����" << endl;
		cin >> v;
		switch (v) {
		case '1':
		{
			cout << "������Ҫ���ҵĵ���" << endl;
			cin >> data1;
			Word* y = a.search(data1);
			if (y == NULL) {
				cout << "�����ڸõ���" << endl << "�Ƿ����õ��ʣ�(�ǣ�1�� ��0)" << endl;
				int i;
				cin >> i;
				if (i == 1) {
					cout << "������Ҫ��ӵ���˼��";
					cin >> data2;
					bool v = a.insert(data1, data2);
					if (v == true) {
						cout << "����ɹ�" << endl;
					}
					else {
						cout << "����ʧ��" << endl;
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
			cout << "������Ҫɾ���ĵ���" << endl;
			cin >> data1;
			bool c = a.dele(data1);
			if (c) {
				cout << "ɾ���ɹ�" << endl;
			}
			else {
				cout << "ɾ��ʧ��" << endl;
			}
			system("pause");
			system("cls");
			break;
		}
		case '3':
		{
			cout << "������Ҫ��ӵĵ���ƴд��";
			cin >> data1;
			cout << "������Ҫ��ӵ���˼��";
			cin >> data2;
			bool v = a.insert(data1, data2);
			if (v == true) {
				cout << "����ɹ�" << endl;
			}
			else {
				cout << "����ʧ��" << endl;
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
			cout << "����Ƿ�" << endl;
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
		cout << "������ѡ�����" << endl;
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
			cout << "����Ƿ�" << endl;
			break;
		}
		}
	}
}