#include"orderlist.h"

using namespace std;

orderlist::orderlist() {
	fileInsert();//��ȡ�����ļ�
	cout << "�ʿ⽨����Ϲ���" << num << "������" << endl;
}

void orderlist::fileInsert() {
	num = 0;
	char File[26][50] = { "D://Dictionary/a.txt","D://Dictionary/b.txt","D://Dictionary/c.txt","D://Dictionary/d.txt",
						  "D://Dictionary/e.txt","D://Dictionary/f.txt","D://Dictionary/g.txt","D://Dictionary/h.txt",
						  "D://Dictionary/i.txt","D://Dictionary/j.txt","D://Dictionary/k.txt","D://Dictionary/l.txt",
						  "D://Dictionary/m.txt","D://Dictionary/n.txt","D://Dictionary/o.txt","D://Dictionary/p.txt",
						  "D://Dictionary/q.txt","D://Dictionary/r.txt","D://Dictionary/s.txt","D://Dictionary/t.txt",
						  "D://Dictionary/u.txt","D://Dictionary/v.txt","D://Dictionary/w.txt","D://Dictionary/x.txt",
						  "D://Dictionary/y.txt","D://Dictionary/z.txt" };
	int i, j, k;
	char buff[150];
	char en[150] = "";
	char me[150] = "";
	ifstream infile;
	int n[26];
	word_length[0] = 0;
	for (i = 0; i < 26; i++) {
		infile.open(File[i]);
		if (!infile) {
			cerr << "���ļ�" << File[i] << "ʧ��" << endl;
			exit(1);
		}
		while (infile.getline(en, sizeof(en), ' ')) {
			infile.getline(me, sizeof(me));
			word[num] = en;
			mean[num] = me;
			num++;
		}
		n[i] = num;
		infile.close();
	}
	for (i = 1; i < 26; i++) {
		word_length[i] = n[i - 1];
		
	}
}
//���ж��ֲ��� 
int orderlist::search(string n, int low, int high) {
	int middle = (low + high) / 2;
	if (low > high) {
		return -1;
	}
	if (word[middle] == n) {
		return middle;
	}
	else if (word[middle] > n) {
		high = middle - 1;
		return search(n, low, high);
	}
	else if (word[middle] < n) {
		low = middle + 1;
		return search(n, low, high);
	}
}

void orderlist::wordFind() {
	char choose;
	string w;
	cout << "������Ҫ���ҵĵ���" << endl;
	cin >> w;
	int judge = search(w, 0, num);
	if (judge == -1) {
		cout << "δ�鵽�õ����Ƿ�������" << endl;
		cout << "�ǣ�1����������������2" << endl;
		cin >> choose;
		if (choose == '1') {
			Insert();
		}
		else if (choose == '2') {
			return;
		}
		else {
			cout << "��������ȷ��ѡ��" << endl;
			system("pause");
			return;
		}
	}
	else {
		cout << "�õ��ʵ���˼�ǣ�" << endl;
		cout << mean[judge] << endl;
		system("pause");
		return;
	}
}

void orderlist::Insert() {
	int i, j, k;
	string w, c;
	cout << "������Ҫ����ĵ���";
	cin >> w;
	if (search(w, 0, num)!= -1) {
		cout << "�õ����Ѿ�����" << endl;
		system("pause");
		return;
	}
	cout << "������õ��ʵĽ��� ��ʽΪ������+��˼" << endl;
	cin >> c;
	
	for (i = 0; i < num; i++) {
		if (word[i] > w) {
			for (j = num; j > i; j--) {
				word[j] = word[j - 1];
				mean[j] = mean[j - 1];
			}
			word[i] = w;
			mean[i] = c;
			num++;
			for (k = (int)w[0] - 97+1; k <= 25; k++) {
				word_length[k]++;
			}
			FileWriter((int)w[0] - 97);
			fileInsert();
			cout << "���ʲ���ɹ�" << endl;
			system("pause");
			return;
		}
	}
}

void orderlist::Delete() {
	int i, j, k;
	int temp;
	string w;
	cout << "������Ҫɾ���ĵ���" << endl;
	cin >> w;
	temp = search(w, 0, num);
	if (temp == -1) {
		cout << "δ�ҵ��õ���" << endl;
		system("pause");
		return;
	}
	for (j = temp; j < num - 1; j++) {
		word[j] = word[j + 1];
		mean[j] = mean[j + 1];
	}
	num--;
	for (k = (int)w[0] - 97+1; k <= 25; k++) {
		word_length[k]--;
		
	}
	FileWriter((int)w[0] - 97);
	cout << "�õ���ɾ���ɹ�" << endl;
	system("pause");
}

void orderlist::FileWriter(int nu) {//�����ļ�����
	char File[26][50] = { "D://Dictionary/a.txt","D://Dictionary/b.txt","D://Dictionary/c.txt","D://Dictionary/d.txt",
						  "D://Dictionary/e.txt","D://Dictionary/f.txt","D://Dictionary/g.txt","D://Dictionary/h.txt",
						  "D://Dictionary/i.txt","D://Dictionary/j.txt","D://Dictionary/k.txt","D://Dictionary/l.txt",
						  "D://Dictionary/m.txt","D://Dictionary/n.txt","D://Dictionary/o.txt","D://Dictionary/p.txt",
						  "D://Dictionary/q.txt","D://Dictionary/r.txt","D://Dictionary/s.txt","D://Dictionary/t.txt",
						  "D://Dictionary/u.txt","D://Dictionary/v.txt","D://Dictionary/w.txt","D://Dictionary/x.txt",
						  "D://Dictionary/y.txt","D://Dictionary/z.txt" };
	int i;
	ofstream out(File[nu]);
	if (out.is_open()){
		for (i = word_length[nu]; i < word_length[nu + 1]; i++) {
			out << word[i] << ' ';
			out << mean[i] << endl;
		}
		out.close();
	}
	cout << "�ʵ�������" << endl;
	system("pause");
}

