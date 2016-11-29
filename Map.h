#pragma once
#include<string>
#include"Matrix.cpp"
#include"Queue.h"
#include"Tree.cpp"
#define Elemtype1 int//点key
#define Elemtype2 int //点value
#define Elemtype3 int //边value
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

	* 函数名：Map

	* 作者：Luo

	* 日期：构造函数 产生一个只有无点的图 此时并不是真正的图 不能输出 开辟点集和边集空间 点默认空间是20 边默认空间是50

	**/
	Map(type t);
	Map(type t, Matrix shu);
	~Map();
	/**

	* 函数名：addNode

	* 作者：Luo

	* 日期：添加一个点 输入一个key（用来操作点），一个value ：点的属性

	**/
	Status addNode(Elemtype1 key, Elemtype2 value);
	/**

	* 函数名：showMap

	* 作者：Luo

	* 日期：显示图的点边和矩阵

	**/
	Status showMap();
	/**

	* 函数名：addEdge

	* 作者：Luo

	* 日期：添加图的边 边的权重默认为1 一般为无权图使用

	**/
	Status addEdge(Elemtype3 ekey, Elemtype1 n1, Elemtype2 n2);
	/**

	* 函数名：addEdge

	* 作者：Luo

	* 日期：添加一条边 通过输入两点的key值和边的权值 如果图是无权图 则Quan=1

	**/
	Status addEdge(Elemtype3 ekey, Elemtype1 n1, Elemtype2 n2, int Quan);
	/**

	* 函数名：deleteE

	* 作者：Luo

	* 日期：删除一条边 通过边的key值

	**/
	Status deleteE(Elemtype3 key);
	/**

	* 函数名：deleteN

	* 作者：Luo

	* 日期：删除点 通过点的key值

	**/
	Status deleteN(Elemtype1 key);
	/**

	* 函数名：haveCircle

	* 作者：Luo

	* 日期：返回是否有环路

	**/
	bool haveCircle();
	/**

		* 函数名：setMatrix

		* 作者：Luo

		* 日期：作用

		**/
	Status setMatrix();
	/**

		* 函数名：DFS

		* 作者：Luo

		* 日期：深度优先搜索遍历

		**/
	//Status DFSOne(){//未完成
	//}
	//Status DFS(){//未完成
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

		* 函数名：BFS

		* 作者：Luo

		* 日期：广度优先搜索

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
	//				for (int j = 0; j < NumOfEdge; i++){//由于还没有加哈希算法 这里的复杂度特别的高
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

		* 函数名：linkNumber

		* 作者：Luo

		* 日期：返回图的连通分支

		**/
	int linkNumber(){//未完成

	}
	/**

	* 函数名：ifQianlian

	* 作者：Luo

	* 日期：返回是否是强连通图

	**/
	bool ifQianlian();
	/**

		* 函数名：ifDanlian

		* 作者：Luo

		* 日期：是否是单连通图 注意 强连通图也是单连通图

		**/
	bool ifDanlian();
	/**

	* 函数名：haveOulaCircle

	* 作者：Luo

	* 日期：返回是否有欧拉回路

	**/
	bool haveOulaCircle();
	/**

	* 函数名：haveOulaTong

	* 作者：Luo

	* 日期：返回是否有欧拉通路

	**/
	bool haveOulaTong();
	/**

	* 函数名：haveHamiCircle

	* 作者：Luo

	* 日期：返回是否有哈密顿回路

	**/
	bool haveHamiCircle();
	/**

	* 函数名：haveHamiTong

	* 作者：Luo

	* 日期：返回是否有哈密顿通路

	**/
	bool haveHamiTong();
};

