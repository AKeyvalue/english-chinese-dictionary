#include"trietree.h"
#include<fstream>
#include<string.h>
using namespace std;
tiretree::tiretree() {//��ʼ��
	this->root = new Word;
	num = 0;
	fileread();
	cout << "�ʿ⽨����Ϲ���" << number() << "������" << endl;
}

tiretree::~tiretree() {
	for (int i = 0; i < 26; i++) {
		filewrite(i);//������д���Ӧ�����ļ���
	}
	Dele(root);//�ͷ��ڴ档
}

//�������
bool tiretree::insert(char eng[], char chi[]) {
	Word* node = root;
	int i, j;
	for (i = 0; i < strlen(eng); i++) {
		j = order(eng[i]);
		if (j == -1) {
			cout << "����Ƿ�" << endl;
			return false;
		}
		if (node->next[j] == NULL) {
			node->next[j] = new Word;
		}
		node = node->next[j];
	}
	if (node->isexistence()) {
		cout << node->getEnglish() << endl;
		cout << node->getChinese() << endl;
		cout << "�˵����Ѵ���" << endl;
		return false;
	}
	else {
		node->setE(true);
		node->setChinese(chi);
		node->setEnglish(eng);
		num++;
		return true;
	}
}

//���Ҳ���
Word* tiretree::search(char word[]) {
	Word* node = root;
	int i, j;
	for (i = 0; i < strlen(word); i++) {
		j = order(word[i]);
		if (j == -1) {
			cout << "����Ƿ�" << endl;
			return NULL;
		}
		if (node->next[j] == NULL) {
			node = node->next[j];
			break;
		}
		else {
			node = node->next[j];
		}
	}
	if (node == NULL) {
		return node;
	}
	else {
		if (node->isexistence()) {
			return node;
		}
		else {
			return NULL;
		}
	}
	
}

//ɾ������
bool tiretree::dele(char word[]) {
	Word* node = search(word);
	if (node == NULL)return false;
	node->setChinese("no find");
	node->setEnglish("no find");
	node->setE(false);
	return true;
}

//�޸ĺ���
bool tiretree::change(char word[]) {
	Word* node = search(word);
	if (node == NULL)return false;
	string a;
	cout << "�������޸ĺ���˼" << endl;
	cin >> a;
	node->setChinese(a);
	return true;
}

//�����ļ���ȡ
void tiretree::fileread(string File) {
	ifstream infile(File, ios::in);
	if (!infile) {
		cerr << "���ļ�ʧ��" << endl;
		exit(1);
	}
	char str1[1024];
	char str2[1204];
	while (infile.getline(str1, sizeof(str1),' ')) {
		infile.getline(str2, sizeof(str2));
		cout << str1 << endl << str2 << endl;
		insert(str1,str2);
	}	
}


void tiretree::fileread() {
	
	char File[26][50] = { "D://Dictionary/a.txt","D://Dictionary/b.txt","D://Dictionary/c.txt","D://Dictionary/d.txt",
						  "D://Dictionary/e.txt","D://Dictionary/f.txt","D://Dictionary/g.txt","D://Dictionary/h.txt",
						  "D://Dictionary/i.txt","D://Dictionary/j.txt","D://Dictionary/k.txt","D://Dictionary/l.txt",
						  "D://Dictionary/m.txt","D://Dictionary/n.txt","D://Dictionary/o.txt","D://Dictionary/p.txt",
						  "D://Dictionary/q.txt","D://Dictionary/r.txt","D://Dictionary/s.txt","D://Dictionary/t.txt",
						  "D://Dictionary/u.txt","D://Dictionary/v.txt","D://Dictionary/w.txt","D://Dictionary/x.txt",
						  "D://Dictionary/y.txt","D://Dictionary/z.txt" };

	for (int c = 0; c < 26; c++) {

		ifstream infile;
		infile.open(File[c]);
		if (!infile) {
			cerr << "���ļ�" << File[c] << "ʧ��" << endl;
			exit(1);
		}
		char str1[1024];
		char str2[1204]; 
		while (infile.getline(str1, sizeof(str1),' ')) {
			infile.getline(str2, sizeof(str2));
			insert(str1, str2);
		}
		infile.close();
	}
}

//����д�뵥����
void tiretree::filewrite(Word* node, medium* &bt) {
	if (node == NULL)return;
	else {
		if (node->isexistence()) {
			medium* p = new medium;
			p->data1 = node->getEnglish();
			p->data2 = node->getChinese();
			p->next = NULL;
			bt->next = p;
			bt = bt->next;
		}
		for (int i = 0; i < 30; i++) {
			filewrite(node->next[i], bt);
		}
	}
}

//�Ƚ��������еĵ�����Ϣд������Ȼ����뵽txt�ļ��� 
void tiretree::filewrite(int i) {
	medium* bt = new medium;
	medium* re = bt;
	char File[26][50] = { "D://Dictionary/a.txt","D://Dictionary/b.txt","D://Dictionary/c.txt","D://Dictionary/d.txt",
								 "D://Dictionary/e.txt","D://Dictionary/f.txt","D://Dictionary/g.txt","D://Dictionary/h.txt",
								"D://Dictionary/i.txt","D://Dictionary/j.txt","D://Dictionary/k.txt","D://Dictionary/l.txt",
								"D://Dictionary/m.txt","D://Dictionary/n.txt","D://Dictionary/o.txt","D://Dictionary/p.txt",
								"D://Dictionary/q.txt","D://Dictionary/r.txt","D://Dictionary/s.txt","D://Dictionary/t.txt",
								"D://Dictionary/u.txt","D://Dictionary/v.txt","D://Dictionary/w.txt","D://Dictionary/x.txt",
								"D://Dictionary/y.txt","D://Dictionary/z.txt" };
	ofstream ot(File[i], ios::out);
	filewrite(root->next[i], re);
	re = bt->next;
	while (re) {
		ot << re->data1 << ' ';
		ot << re->data2 << endl;
		re = re->next;
	}
	while (bt) {
		re = bt->next;
		delete bt;
		bt = re;
	}
}

//�ͷ��ڴ�
void tiretree::Dele(Word* node) {
	if (node == NULL)return;
	int i;
	for (i = 0; i < 30; i++) {
		Dele(node->next[i]);
	}
	delete node;
}


//���ַ����д��� 
int tiretree::order(char c) {
	if (c >= 'a' && c <= 'z')
	{
		int j = c - 'a';
		return j;
	}else if(c)
	if (c == '.') return 26;
	if (c == '/') return 27;
	if (c == '-') return 28;
	if (c == '\'') return 29;
	return -1;
}
