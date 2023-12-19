#include"orderlist.h"

using namespace std;

orderlist::orderlist() {
	fileInsert();//读取磁盘文件
	cout << "词库建立完毕共有" << num << "条单词" << endl;
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
	word_length[0] = 0;//单词a开始
	for (i = 0; i < 26; i++) {
		infile.open(File[i]);
		if (!infile) {
			cerr << "打开文件" << File[i] << "失败" << endl;
			exit(1);
		}
		while (infile.getline(en, sizeof(en), ' ')) {//读取文件
			infile.getline(me, sizeof(me));
			word[num] = en;
			mean[num] = me;
			//cout << "word" << "[" << num << ']' << en << endl;
			num++;
		}
		n[i] = num;//记录位置
		infile.close();
	}
	for (i = 1; i < 26; i++) {
		word_length[i] = n[i - 1];
		//cout << word_length[i] << endl;
	}
}

int orderlist::search(string n, int low, int high) {//二分查找前提单词有序排列
	int middle = (low + high) / 2;
	if (low > high) {
		return -1;//未找到。返回-1；
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
	cout << "请输入要查找的单词" << endl;
	cin >> w;
	int judge = search(w, 0, num);//折半查找返回单词所在地址
	if (judge == -1) {
		cout << "未查到该单词是否将它插入" << endl;
		cout << "是：1———————否：2" << endl;//判断是否插入
		cin >> choose;
		if (choose == '1') {
			Insert();//调用插入函数
		}
		else if (choose == '2') {
			return;
		}
		else {
			cout << "请输入正确的选项" << endl;//错误提示
			system("pause");
			return;
		}
	}
	else {
		cout << "该单词的意思是：" << endl;//查找成功
		cout << mean[judge] << endl;
		system("pause");
		return;
	}
}

void orderlist::Insert() {
	int i, j, k;
	string w, c;
	cout << "请输入要插入的单词";
	cin >> w;
	if (search(w, 0, num)!= -1) {
		cout << "该单词已经存在" << endl;
		system("pause");
		return;
	}
	cout << "请输入该单词的解释 形式为：词性+意思" << endl;
	cin >> c;
	
	for (i = 0; i < num; i++) {
		if (word[i] > w) {
			for (j = num; j > i; j--) {//找到插入位置整体后移一位
				word[j] = word[j - 1];
				mean[j] = mean[j - 1];
			}
			word[i] = w;//插入拼写
			mean[i] = c;//插入意思
			num++;//单词总数加一
			for (k = (int)w[0] - 97+1; k <= 25; k++) {
				word_length[k]++;
				//cout << word_length[k] << endl;//该单词之后每个单词开始的地方后裔一位
			}
			FileWriter((int)w[0] - 97);
			fileInsert();
			cout << "单词插入成功" << endl;//成功提示
			system("pause");
			return;
		}
	}
}

void orderlist::Delete() {
	int i, j, k;
	int temp;
	string w;
	cout << "请输入要删除的单词" << endl;
	cin >> w;
	temp = search(w, 0, num);//找到单词位置
	if (temp == -1) {
		cout << "未找到该单词" << endl;
		system("pause");
		return;
	}
	for (j = temp; j < num - 1; j++) {//单词前移覆盖
		word[j] = word[j + 1];
		mean[j] = mean[j + 1];
	}
	num--;//单词总数减1
	for (k = (int)w[0] - 97+1; k <= 25; k++) {//每个开头起始位置前移
		word_length[k]--;
		//cout << word_length[k] << endl;
	}
	FileWriter((int)w[0] - 97);
	cout << "该单词删除成功" << endl;
	system("pause");
}

void orderlist::FileWriter(int nu) {//磁盘文件更新
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
	cout << "词典更新完毕" << endl;
	system("pause");
}

