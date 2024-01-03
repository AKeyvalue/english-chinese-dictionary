#include"trietree.h"
#include<fstream>
#include<string.h>
using namespace std;
tiretree::tiretree() {//初始化
	this->root = new Word;
	num = 0;
	fileread();
	cout << "词库建立完毕共有" << number() << "条单词" << endl;
}

tiretree::~tiretree() {
	for (int i = 0; i < 26; i++) {
		filewrite(i);//将数据写入对应磁盘文件。
	}
	Dele(root);//释放内存。
}

//插入操作
bool tiretree::insert(char eng[], char chi[]) {
	Word* node = root;
	int i, j;
	for (i = 0; i < strlen(eng); i++) {
		j = order(eng[i]);
		if (j == -1) {
			cout << "输入非法" << endl;
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
		cout << "此单词已存在" << endl;
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

//查找操作
Word* tiretree::search(char word[]) {
	Word* node = root;
	int i, j;
	for (i = 0; i < strlen(word); i++) {
		j = order(word[i]);
		if (j == -1) {
			cout << "输入非法" << endl;
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

//删除单词
bool tiretree::dele(char word[]) {
	Word* node = search(word);
	if (node == NULL)return false;
	node->setChinese("no find");
	node->setEnglish("no find");
	node->setE(false);
	return true;
}

//修改函数
bool tiretree::change(char word[]) {
	Word* node = search(word);
	if (node == NULL)return false;
	string a;
	cout << "请输入修改后意思" << endl;
	cin >> a;
	node->setChinese(a);
	return true;
}

//磁盘文件读取
void tiretree::fileread(string File) {
	ifstream infile(File, ios::in);
	if (!infile) {
		cerr << "打开文件失败" << endl;
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
			cerr << "打开文件" << File[c] << "失败" << endl;
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

//数据写入单链表
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

//先将升序排列的单词信息写入链表，然后存入到txt文件中 
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

//释放内存
void tiretree::Dele(Word* node) {
	if (node == NULL)return;
	int i;
	for (i = 0; i < 30; i++) {
		Dele(node->next[i]);
	}
	delete node;
}


//对字符进行处理 
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
