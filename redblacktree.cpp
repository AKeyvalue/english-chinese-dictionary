#include"RedBlackTree.h"

RedBlackTree::RedBlackTree(){
	root = nullptr;
	num = 0;
	fileInsert();
	cout << "�ʿ⽨����Ϲ���" <<  number() << "������" << endl;;
} 

RedBlackTree::~RedBlackTree(){
 	clear(root);
}

void RedBlackTree::fileInsert(){
		char File[26][50] = { "D://Dictionary/a.txt","D://Dictionary/b.txt","D://Dictionary/c.txt","D://Dictionary/d.txt",
						  "D://Dictionary/e.txt","D://Dictionary/f.txt","D://Dictionary/g.txt","D://Dictionary/h.txt",
						  "D://Dictionary/i.txt","D://Dictionary/j.txt","D://Dictionary/k.txt","D://Dictionary/l.txt",
						  "D://Dictionary/m.txt","D://Dictionary/n.txt","D://Dictionary/o.txt","D://Dictionary/p.txt",
						  "D://Dictionary/q.txt","D://Dictionary/r.txt","D://Dictionary/s.txt","D://Dictionary/t.txt",
						  "D://Dictionary/u.txt","D://Dictionary/v.txt","D://Dictionary/w.txt","D://Dictionary/x.txt",
						  "D://Dictionary/y.txt","D://Dictionary/z.txt" };
						  
		int i;
		char en[50];
		char me[50];
		for(i = 0; i < 26; i++){
			ifstream infile;
			infile.open(File[i]);
			if(!infile){
				cerr << "���ļ�" << File[i] << "ʧ��" << endl;
				exit(1);
			}
			while(infile.getline(en, sizeof(en), ' ')){
				infile.getline(me, sizeof(me));
				insert(en, me);
			}
			infile.close();
		}
}


//�����½ڵ� 

void RedBlackTree::insert(string word, string meaning){
	Node *newNode = new Node(word, meaning);
	Node *x = root;
	Node *y = nullptr;
	while(x != nullptr){
		y = x;
		if(newNode->word == x->word){
			cout << x->word << "�����Ѵ���" << "����ʧ��" << endl;
			return;
		}
		else if(newNode->word < x->word){
			x = x->left;
		}
		else{
			x = x->right;
		}
	}
	
	newNode->parent = y;
	if(y == nullptr){
		root = newNode;
	}
	else if(newNode->word < y->word){
		y->left = newNode;
	}
	else{
		y->right = newNode;
	}
	num++;
	insertFix(newNode);
}

//�������� 
void RedBlackTree::insertFix(Node *z){
	while(z->parent != nullptr && z->parent->color == Red){
		if(z->parent == z->parent->parent->left){
			Node *y = z->parent->parent->right;
			if(y != nullptr && y->color == Red){
				z->parent->color = Black;
				y->color = Black;
				z->parent->parent->color = Red;
				z = z->parent->parent;
			}
			else{
				if(z == z->parent->right){
					z = z->parent;
					leftRotate(z);
				}
				z->parent->color = Black;
				z->parent->parent->color = Red;
				rightRotate(z->parent->parent);
			}
		}
		else{
			Node *y = z->parent->parent->left;
			if(y != nullptr && y->color == Red){
				z->parent->color = Black;
				y->color = Black;
				z->parent->parent->color = Red;
				z = z->parent->parent;
			}
			else{
				if(z == z->parent->left){
					z = z->parent;
					rightRotate(z);
				}
				
					z->parent->color = Black;
					z->parent->parent->color = Red;
					leftRotate(z->parent->parent);
				
			}
		}
		
	}
	root->color = Black;
}

//���� 
string RedBlackTree::search(string word){
	Node *current = root;
	while(current != nullptr){
		if(word == current->word){
			return current->meaning;
		}
		else if(word < current->word){
			current = current->left;
		}
		else{
			current = current->right;
		}
	}
	return "None";
}

//���� 
void RedBlackTree::leftRotate(Node *x){
	Node *y = x->right;
	x->right = y->left;
	if(y->left != nullptr){
		y->left->parent = x;
	}
	if(y != nullptr){
		y->parent = x->parent;
	}
	if(x->parent == nullptr){
		root = y;
	}
	else if(x->parent->left == x){
		x->parent->left = y;
	}
	else{
		x->parent->right = y;
	}
	y->left = x;
	if(x != nullptr){
		x->parent = y;
	}
	
}

//���� 
void RedBlackTree::rightRotate(Node *y){
	Node *x = y->left;
	y->left = x->right;
	if(x->right != nullptr){
		x->right->parent = y;
	}
	if(x != nullptr){
		x->parent = y->parent;
	}
	if(y->parent == nullptr){
		root = x;
	}
	else if(y == y->parent->left){
		y->parent->left = x;
	}
	else{
		y->parent->right = x;
	}
	x->right = y;
	if(y != nullptr){
		y->parent = x;
	}

}



//ɾ�� 
void RedBlackTree::remove(string word) {
    Node *z = searchNode(root, word);

    if (z == nullptr) {
        cout << "����" << word << "�����ڣ��޷�ɾ��" << endl;
        system("pause");
        return;
    }

    deleteNode(z);
    cout << "ɾ���ɹ�" << endl;
	system("pause"); 
}

// ���ݵ��ʲ��ҽڵ�
Node* RedBlackTree::searchNode(Node* node, string word) {
    while (node != nullptr) {
        if (word == node->word) {
            return node;
        } else if (word < node->word) {
            node = node->left;
        } else {
            node = node->right;
        }
    }
    return nullptr;
}

// ɾ���ڵ�
void RedBlackTree::deleteNode(Node* z) {
    Node* y = z;
    Node* x;
    Color y_original_color = y->color;

    if (z->left == nullptr) {
        x = z->right;
        transplant(z, z->right);
    } else if (z->right == nullptr) {
        x = z->left;
        transplant(z, z->left);
    } else {
        y = minimum(z->right);
        y_original_color = y->color;
        x = y->right;
        if (y->parent != z) {
            transplant(y, y->right);
            y->right = z->right;
            y->right->parent = y;
        }
        transplant(z, y);
        y->left = z->left;
        y->left->parent = y;
        y->color = z->color;
    }

    if (y_original_color == Black) {
        deleteFix(x);
    }
    
    delete z;
}

//��v����u 
void RedBlackTree::transplant(Node* u, Node* v) {
    if (u->parent == nullptr) {
        root = v;
    } else if (u == u->parent->left) {
        u->parent->left = v;
    } else {
        u->parent->right = v;
    }
    if (v != nullptr) {
        v->parent = u->parent;
    }
}

// ��С�ڵ�
Node* RedBlackTree::minimum(Node* node) {
    while (node->left != nullptr) {
        node = node->left;
    }
    return node;
}

// ɾ������
void RedBlackTree::deleteFix(Node* x) {
    while (x != nullptr && x != root && x->color == Black) {
              if (x == x->parent->left) {
            Node* w = x->parent->right;
            if (w->color == Red) {
                w->color = Black;
                x->parent->color = Red;
                leftRotate(x->parent);
                w = x->parent->right;
            }
            if (w->left->color == Black && w->right->color == Black) {
                w->color = Red;
                x = x->parent;
            } else {
                if (w->right->color == Black) {
                    w->left->color = Black;
                    w->color = Red;
                    rightRotate(w);
                    w = x->parent->right;
                }
                w->color = x->parent->color;
                x->parent->color = Black;
                w->right->color = Black;
                leftRotate(x->parent);
                x = root;
            }
        } else {
            Node* w = x->parent->left;
            if (w->color == Red) {
                w->color = Black;
                x->parent->color = Red;
                rightRotate(x->parent);
                w = x->parent->left;
            }
            if (w->right->color == Black && w->left->color == Black) {
                w->color = Red;
                x = x->parent;
            } else {
                if (w->left->color == Black) {
                    w->right->color = Black;
                    w->color = Red;
                    leftRotate(w);
                    w = x->parent->left;
                }
                w->color = x->parent->color;
                x->parent->color = Black;
                w->left->color = Black;
                rightRotate(x->parent);
                x = root;
            }
        }
    }
    
    if (x != nullptr) {
        x->color = Black;
    }
}


void RedBlackTree::clear(Node *node){
	if(node != nullptr){
		clear(node->left);
		clear(node->right);
		delete node;
	}
}


