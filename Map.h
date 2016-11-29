#pragma once
#include<string>
#include"Matrix.cpp"
#include"Queue.h"
#include"Tree.cpp"
#define Elemtype1 int//��key
#define Elemtype2 int //��value
#define Elemtype3 int //��value
enum type{ YXT, WXT, YXW, WXW };
class MNode{
public:
	Elemtype1 key;
	Elemtype2 value;
	MNode(){

	}
	MNode(Elemtype1 key1, Elemtype2 value1){
		key = key1;
		value = value1;
	}
};
class MEdge{
public:
	Elemtype3 ekey;
	Elemtype1 n11;
	Elemtype1 n22;
	int Quan1;
	MEdge(){

	}
	MEdge(Elemtype3 ekey1, Elemtype1 n1, Elemtype1 n2, int Quan){
		ekey = ekey1;
		n11 = n1;
		n22 = n2;
		Quan1 = Quan;
	}
};

class Map
{
public:
	string typeOfMap;
	int NumOfNode;
	int NMAX;
	int EMAX;
	int NumOfEdge;
	MNode *NP;
	MEdge *EP;
	Matrix mex;
	/**

	* ��������Map

	* ���ߣ�Luo

	* ���ڣ����캯�� ����һ��ֻ���޵��ͼ ��ʱ������������ͼ ������� ���ٵ㼯�ͱ߼��ռ� ��Ĭ�Ͽռ���20 ��Ĭ�Ͽռ���50

	**/
	Map(type t);
	Map(type t, Matrix shu);
	~Map();
	/**

	* ��������addNode

	* ���ߣ�Luo

	* ���ڣ����һ���� ����һ��key�����������㣩��һ��value ���������

	**/
	Status addNode(Elemtype1 key, Elemtype2 value);
	/**

	* ��������showMap

	* ���ߣ�Luo

	* ���ڣ���ʾͼ�ĵ�ߺ;���

	**/
	Status showMap();
	/**

	* ��������addEdge

	* ���ߣ�Luo

	* ���ڣ����ͼ�ı� �ߵ�Ȩ��Ĭ��Ϊ1 һ��Ϊ��Ȩͼʹ��

	**/
	Status addEdge(Elemtype3 ekey, Elemtype1 n1, Elemtype2 n2);
	/**

	* ��������addEdge

	* ���ߣ�Luo

	* ���ڣ����һ���� ͨ�����������keyֵ�ͱߵ�Ȩֵ ���ͼ����Ȩͼ ��Quan=1

	**/
	Status addEdge(Elemtype3 ekey, Elemtype1 n1, Elemtype2 n2, int Quan);
	/**

	* ��������deleteE

	* ���ߣ�Luo

	* ���ڣ�ɾ��һ���� ͨ���ߵ�keyֵ

	**/
	Status deleteE(Elemtype3 key);
	/**

	* ��������deleteN

	* ���ߣ�Luo

	* ���ڣ�ɾ���� ͨ�����keyֵ

	**/
	Status deleteN(Elemtype1 key);
	/**

	* ��������haveCircle

	* ���ߣ�Luo

	* ���ڣ������Ƿ��л�·

	**/
	bool haveCircle();
	/**

		* ��������setMatrix

		* ���ߣ�Luo

		* ���ڣ�����

		**/
	Status setMatrix();
	/**

		* ��������DFS

		* ���ߣ�Luo

		* ���ڣ����������������

		**/
	//Status DFSOne(){//δ���
	//}
	//Status DFS(){//δ���
	//	struct haveRead
	//	{
	//		Elemtype1 key;
	//		bool have = true;
	//	};
	//	haveRead Ntable[100];
	//	for (int i = 0; i < NumOfNode; i++){
	//		Ntable[i].key = NP[i].key;
	//		Ntable[i].have = false;
	//	}
	//	return Ok;
	//}
	/**

		* ��������BFS

		* ���ߣ�Luo

		* ���ڣ������������

		**/
	//Status BFS(){
	//	struct haveRead
	//	{
	//		Elemtype1 key;
	//		bool have = true;
	//	};
	//	haveRead Ntable[100];
	//	for (int i = 0; i < NumOfNode; i++){
	//		Ntable[i].key = NP[i].key;
	//		Ntable[i].have = false;
	//	}
	//	Queue q1;
	//	for (int i = 0; i < NumOfNode; i++){
	//		if (Ntable[i].have == false){
	//			q1.push(Ntable[i].key);
	//			while (q1.length != 0){
	//				Elemtype1 back = q1.back();
	//				for (int j = 0; j < NumOfNode; j++){
	//					if (NP[j].key == back){
	//						cout << NP[i].value;
	//					}
	//				}
	//				for (int j = 0; j < NumOfEdge; i++){//���ڻ�û�мӹ�ϣ�㷨 ����ĸ��Ӷ��ر�ĸ�
	//					if (EP[i].n11 == back){
	//						for (int k = 0; k < NumOfNode; k++){
	//							if (Ntable[k].key == EP[i].n22&&Ntable[k].have == false) q1.push(EP[i].n22);
	//						}
	//					}
	//					if (EP[i].n22 == back){
	//						for (int k = 0; k < NumOfNode; k++){
	//							if (Ntable[k].key == EP[i].n11&&Ntable[k].have == false) q1.push(EP[i].n11);
	//						}
	//					}
	//				}
	//			}

	//		}
	//	}
	//	return Ok;
	//}
	/**

		* ��������linkNumber

		* ���ߣ�Luo

		* ���ڣ�����ͼ����ͨ��֧

		**/
	int linkNumber(){//δ���

	}
	/**

	* ��������ifQianlian

	* ���ߣ�Luo

	* ���ڣ������Ƿ���ǿ��ͨͼ

	**/
	bool ifQianlian();
	/**

		* ��������ifDanlian

		* ���ߣ�Luo

		* ���ڣ��Ƿ��ǵ���ͨͼ ע�� ǿ��ͨͼҲ�ǵ���ͨͼ

		**/
	bool ifDanlian();
	/**

	* ��������haveOulaCircle

	* ���ߣ�Luo

	* ���ڣ������Ƿ���ŷ����·

	**/
	bool haveOulaCircle();
	/**

	* ��������haveOulaTong

	* ���ߣ�Luo

	* ���ڣ������Ƿ���ŷ��ͨ·

	**/
	bool haveOulaTong();
	/**

	* ��������haveHamiCircle

	* ���ߣ�Luo

	* ���ڣ������Ƿ��й��ܶٻ�·

	**/
	bool haveHamiCircle();
	/**

	* ��������haveHamiTong

	* ���ߣ�Luo

	* ���ڣ������Ƿ��й��ܶ�ͨ·

	**/
	bool haveHamiTong();
};

