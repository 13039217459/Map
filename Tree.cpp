#include<iostream>
using namespace std;
#define Elemtype int
#define True  1
#define False 0
#define Ok    1
#define Error 0
#define Infeasible -1
#define Overflow   -2
typedef int Status;
#define NULL 0


class TreeNode{
public:

	int weizhi;
	TreeNode *lChide;
	TreeNode *rChide;
	
	Elemtype v;
	TreeNode( int weizhi1, Elemtype v1){
		lChide = NULL;
		rChide = NULL;
		weizhi = weizhi1;
		v = v1;
	}
	TreeNode( int weizhi1){
		lChide = NULL;
		rChide = NULL;
		weizhi = weizhi1;
		
	}
	TreeNode(){
		lChide = NULL;
		rChide = NULL;
	}
	
};
/**

* ����������������

* ���ߣ�Luo

* ���ڣ����������й���������  valueĬ����0  ������MInһ�� ����б�Ҫ��Ҫ��һ��

**/
class HaffuNode{
public:
	Elemtype v;
	int son1;
	int son2;
	int father;

};
class haffumantable{
public:
	HaffuNode *base;
	int len;
	haffumantable(int length){
		len = length;
		base = (HaffuNode *)malloc(sizeof(HaffuNode)*length);
		for (int i = 0; i < length; i++){
			base[i].v = 0;
			base[i].father = -1;
			base[i].son1 = -1;
			base[i].son2 = -1;
		}
	}
	
};
class Tree{
public:
	int length;
	TreeNode* base;
	
	Tree(){
		length = 0;
		base=new TreeNode(1);//λ��Ĭ��Ϊ1
	}
	template<int Fuck>
	Status setTree(TreeNode *nodep, int(&p)[Fuck]){
		int len = sizeof(p) / sizeof(p[0]);
		if (nodep->v == NULL&&nodep->weizhi<=len){
			nodep->v = p[nodep->weizhi-1];	
		}
		if (nodep->weizhi * 2<=len){
			nodep->lChide= new TreeNode(nodep->weizhi * 2, p[nodep->weizhi * 2-1]);
		//	cout << "������֮��" <<nodep->lChide->weizhi<< endl;
			setTree(nodep->lChide, p);
		}
		if (nodep->weizhi * 2 +1<=len){
			nodep->rChide = new TreeNode(nodep->weizhi * 2 + 1, p[nodep->weizhi * 2 ]);
			//cout << "����������" << nodep->rChide->weizhi << endl;
			setTree(nodep->rChide, p);
		}
		return Ok;
	}
	Status setTree1(TreeNode *nodep, haffumantable p,int root){
		if (nodep->v == NULL){
			nodep->v = p.base[root].v;
		}
		if (p.base[root].son1!=-1){
			nodep->lChide = new TreeNode(nodep->weizhi * 2, p.base[p.base[root].son1].v);			
			setTree1(nodep->lChide,p,p.base[root].son1);
		}
		if (p.base[root].son2 != -1){
			cout << p.base[p.base[root].son2].v << endl;
			nodep->rChide = new TreeNode(nodep->weizhi * 2, p.base[p.base[root].son2].v);		
			setTree1(nodep->rChide, p, p.base[root].son2);
		}
		return Ok;
	}
	Status xianxu(TreeNode node){
		cout << node.v << endl;
	
		if (node.lChide != NULL){
			xianxu(*node.lChide);
		}
		if (node.rChide != NULL){
			xianxu(*node.rChide);
		}
		return Ok;
	}
	Status zhonxu(TreeNode node){
		if (node.lChide != NULL){
			xianxu(*node.lChide);
		}
		cout << node.v << endl;
		if (node.rChide != NULL){
			xianxu(*node.rChide);
		}
		return Ok;
	}
	Status houxu(TreeNode node){
		if (node.lChide != NULL){
			xianxu(*node.lChide);
		}
		if (node.rChide != NULL){
			xianxu(*node.rChide);
		}
		cout << node.v << endl;
	}
	
};

/**

		* ��������Min
				
		* ���ߣ�Luo

		* ���ڣ���ȡ������С��  ��С����ʼʱĬ����0  

		**/
class  Min
{
public:
	int min1;
	int min2;
	int minp1;
	int minp2;

	Min(){
		min1 = 0;
		min2 = 0;
		minp1 = -1;
		minp2 = -1;
	}
};
template<class T>
Tree getHuffman(T &p){
	int len = sizeof(p) / sizeof(p[0]);
	haffumantable table(len*2);	
	for (int i = 0; i < len; i++){
		table.base[i].v = p[i];
	}//�������Ա���и�ֵ���� �������0  ˵���Ѿ���ֵ
	Min min;
	while (1){
		int ii = 0;
		for (int i = 0; i < len; i++){
			if (table.base[i].father == -1){
				ii++;
			}
		}
		if (ii < 2){
			cout << "ȡ��Сֵ������ת" << endl;
			break;
		}
		min.min1 = 100000;
		min.min2 = 100000;
		int mini;
		for(int i=0;i<len;i++){//ȡ������Сֵ
			if (table.base[i].father != -1){
				continue;
			}
			Elemtype temp = table.base[i].v;
			if (min.min1>temp){
				swap(min.min1,temp);
				min.minp1 = i;
				mini = i;
			}
		}
		for (int i = 0; i<len; i++){
			bool bol = table.base[i].father != -1;
			if (bol||mini == i){//�����ظ�
				continue;
			}
			Elemtype temp = table.base[i].v;
			if (min.min2>temp){
					swap(min.min2,temp);
					min.minp2 = i;
			}
		}		
		table.base[len ].v = min.min1 + min.min2;
		table.base[len ].son1 = min.minp1;//��ֵ�ӽڵ�͸��ڵ�
		table.base[len ].son2 = min.minp2;
		table.base[min.minp1].father = len ;
		table.base[min.minp2].father = len ;
		len++;		
	}cout << " -------------------------" << endl;
		for (int i = 0; i < len; i++){
			cout <<i<<"  " << table.base[i].v <<"  "<< table.base[i].father<<"   "<<table.base[i].son1<<"   "<<table.base[i].son2<< endl;
		}
	cout << " -------------------------" << endl;
	Tree tree;
	tree.base->v = table.base[len-1].v;
	
	tree.setTree1(tree.base,table, len-1);
	return tree;
}

//void main(){
//	int p[] = {1,2,3,4,5,6,7};
//	Tree tree=getHuffman(p);
//	tree.xianxu(*tree.base);
//}