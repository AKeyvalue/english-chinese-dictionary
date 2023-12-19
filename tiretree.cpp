#include"tiretree.h"
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
		j = order(eng[i]);//寻找对应分支。
		if (j == -1) {
			cout << "输入非法" << endl;
			return false;
		}
		if (node->next[j] == NULL) {
			node->next[j] = new Word;
		}
		node = node->next[j];//工作指针指向对应下一分支。
	}
	if (node->isexistence()) {//查看单词是否已经存在。
		cout << node->getEnglish() << endl;
		cout << node->getChinese() << endl;
		cout << "此单词已存在" << endl;
		return false;
	}
	else {//不存在设置单词属性
		node->setE(true);
		node->setChinese(chi);
		node->setEnglish(eng);
		num++;
		return true;
	}
}

//查找操作
Word* tiretree::search(char word[]) {//查找函数, 返回单词类地址。
	Word* node = root;//工作指针
	int i, j;
	for (i = 0; i < strlen(word); i++) {
		j = order(word[i]);//查找对应分支。
		if (j == -1) {//检测非法输入单词
			cout << "输入非法" << endl;
			return NULL;
		}
		if (node->next[j] == NULL) {//节点为空不存在该单词
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
	Word* node = search(word);//找到对应单词地址
	if (node == NULL)return false;//如果该地址为空，则词库中不存在该单词删除失败
	node->setChinese("no find");//查找成功修改节点信息。
	node->setEnglish("no find");
	node->setE(false);
	return true;
}

//修改函数
bool tiretree::change(char word[]) {
	Word* node = search(word);//搜索到要修改的地址
	if (node == NULL)return false;
	string a;//因为字典树每一条路径对应的字符串唯一所以不可以修改单词拼写。
	cout << "请输入修改后意思" << endl;
	cin >> a;
	node->setChinese(a);
	return true;
}

//磁盘文件读取
void tiretree::fileread(string File) {
	ifstream infile(File, ios::in);
	if (!infile) {
		cerr << "打开文件失败" << endl;//异常提示
		exit(1);//异常退出
	}
	char str1[1024];
	char str2[1204];
	while (infile.getline(str1, sizeof(str1),' ')) {
		infile.getline(str2, sizeof(str2));
		cout << str1 << endl << str2 << endl;
		insert(str1,str2);
	}	
}

//文件读取操作重载
void tiretree::fileread() {
	//创建数组存储对应文件路径。
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
		while (infile.getline(str1, sizeof(str1),' ')) {//将数据从磁盘中读取到程序里
			infile.getline(str2, sizeof(str2));
			//cout << str1 << endl << str2 << endl; //测试用部分。
			insert(str1, str2);//将数据插入到字典树。
		}
		infile.close();
	}
}

//数据写入单链表
void tiretree::filewrite(Word* node, medium* &bt) {//递归前序遍历，将信息写入链表再将链表信息写入磁盘。
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

//数据写入对应序号文件
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
	filewrite(root->next[i], re);//升序排序的单词及信息写入链表 bt。
	re = bt->next;
	while (re) {
		ot << re->data1 << ' ';//将链表信息写入磁盘。
		ot << re->data2 << endl;
		re = re->next;
	}
	while (bt) {//释放链表占用内存
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

int tiretree::order(char c) {//处理字符。
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
