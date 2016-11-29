#include "Map.h"
Map::Map(type t)
{
	switch (t){
	case 0:typeOfMap = "有向图";
		break;
	case 1:typeOfMap = "无向图";
		break;
	case 2:typeOfMap = "有向网";
		break;
	case 3:typeOfMap = "无向网";
		break;
	default: cout << "输入有误" << endl;
		return;
	}
	//typeOfMap = t;
	NumOfNode = 0;
	NumOfEdge = 0;
	NMAX = 20;
	EMAX = 50;
	NP = (MNode *)malloc(sizeof(MNode)* 20);
	EP = (MEdge *)malloc(sizeof(MEdge)* 50);
}
Map::Map(type t, Matrix shu){
	if (shu.x != shu.y){
		return;
	}
	mex = shu;
	switch (t){
	case 0:typeOfMap = "有向图";
		break;
	case 1:typeOfMap = "无向图";
		break;
	case 2:typeOfMap = "有向网";
		break;
	case 3:typeOfMap = "无向网";
		break;
	default: cout << "输入有误" << endl;
		return;
	}
	NumOfNode = shu.x;//点默认赋值
	NMAX = NumOfNode + 10;
	NP = (MNode *)malloc(sizeof(MNode)* NMAX);
	for (int i = 0; i < NumOfNode; i++){
		NP[i].key = i;
		NP[i].value = i;
	}
	if (t == 0){//有向图 边数为所有数相加
		int sum = 0;
		for (int i = 0; i < shu.x; i++){
			for (int j = 0; j < shu.x; j++){
				sum += shu.a[i][j];
			}
		}
		NumOfEdge = sum;

		EMAX = NumOfEdge + 20;
		EP = (MEdge *)malloc(sizeof(MEdge)* EMAX);//边赋值
		int ii = 0;
		for (int i = 0; i < shu.x; i++){
			for (int j = 0; j < shu.x; j++){
				for (int k = 0; k < shu.a[i][j]; k++){
					EP[ii].ekey = ii;
					EP[ii].n11 = i;
					EP[ii].n22 = j;
					EP[ii].Quan1 = 1;
					ii++;
				}
			}
		}
	}
	else if (t == 1){//无向图  先判断是否对称 边数为所有数相加除以2
		int sum = 0;
		for (int i = 0; i < shu.x; i++){
			for (int j = i; j < shu.x; j++){
				if (shu.a[i][j] != shu.a[j][i]){
					return;
				}
				sum += shu.a[i][j];
			}
		}
		NumOfEdge = sum;
		EMAX = NumOfEdge + 20;
		EP = (MEdge *)malloc(sizeof(MEdge)* EMAX);//边赋值
		int ii = 0;
		for (int i = 0; i < shu.x; i++){
			for (int j = i; j < shu.x; j++){
				for (int k = 0; k < shu.a[i][j]; k++){
					EP[ii].ekey = ii;
					EP[ii].n11 = i;
					EP[ii].n22 = j;
					EP[ii].Quan1 = 1;
					ii++;
				}
			}
		}

	}
	if (t == 3){//有向网 数不为0 边数++
		int sum = 0;
		for (int i = 0; i < shu.x; i++){
			for (int j = 0; j < shu.x; j++){
				if (shu.a[i][j]){
					sum++;
				}
			}
		}
		NumOfEdge = sum;

		EMAX = NumOfEdge + 20;
		EP = (MEdge *)malloc(sizeof(MEdge)* EMAX);//边赋值
		int ii = 0;
		for (int i = 0; i < shu.x; i++){
			for (int j = i; j < shu.x; j++){
				if (shu.a[i][j] != 0){
					EP[ii].ekey = ii;
					EP[ii].n11 = i;
					EP[ii].n22 = j;
					EP[ii].Quan1 = shu.a[i][j];
					ii++;
				}
			}
		}

	}
	else if (t == 4){//无向网  先判断是否对称 数不为0 边数++
		int sum = 0;
		for (int i = 0; i < shu.x; i++){
			for (int j = i; j < shu.x; j++){
				if (shu.a[i][j] != shu.a[j][i]){
					return;
				}
				if (shu.a[i][j] != 0){
					sum++;
				}
			}
		}
		NumOfEdge = sum;
		EMAX = NumOfEdge + 20;
		EP = (MEdge *)malloc(sizeof(MEdge)* EMAX);//边赋值
		int ii = 0;
		for (int i = 0; i < shu.x; i++){
			for (int j = i; j < shu.x; j++){
				if (shu.a[i][j] != 0){
					EP[ii].ekey = ii;
					EP[ii].n11 = i;
					EP[ii].n22 = j;
					EP[ii].Quan1 = shu.a[i][j];
					ii++;
				}
			}
		}
	}
}
Map::~Map()
{
}
Status Map::addNode(Elemtype1 key, Elemtype2 value){
	for (int i = 0; i < NumOfNode; i++){
		if (NP[i].key == key){
			cout << "key值重复无法添加" << endl;
			return Error;
		}
	}
	NP[NumOfNode].key = key;
	NP[NumOfNode].value = value;
	NumOfNode++;
	if (NMAX - NumOfNode < 5){
		NMAX += 10;
		//NP = (MNode *)realloc(sizeof(MNode)*NMAX);
	}
	return Ok;
}
Status Map::showMap(){
	cout << "-------------------------------------" << endl;
	cout << "图的类型为："<<typeOfMap<< endl;
	cout << "图的点为" << endl;
	for (int i = 0; i < NumOfNode; i++){
		cout << "key:" << NP[i].key << "  value:" << NP[i].value << endl;
	}
	cout << "图的边为" << endl;
	for (int i = 0; i < NumOfEdge; i++){
		cout << "key:" << EP[i].ekey << "  n1:" << EP[i].n11 << "  n2:" << EP[i].n22 << "  权重:" << EP[i].Quan1 << endl;
	}
	cout << "图的邻接矩阵为" << endl;
	for (int i = 0; i < mex.x; i++){
		for (int j = 0; j < mex.y; j++){
			cout << mex.a[i][j] << "\t";
		}
		cout << endl;
	}
	cout << "--------------------------------------" << endl;
	return Ok;
}
Status Map::addEdge(Elemtype3 ekey, Elemtype1 n1, Elemtype2 n2){
	int havee = 0, haven1 = 0, haven2 = 0;
	for (int i = 0; i < NumOfNode; i++){
		if (NP[i].key == n1){
			haven1++;
		}
	}if (haven1 == 0)return Error;
	for (int i = 0; i < NumOfNode; i++){
		if (NP[i].key == n2){
			haven2++;
		}
	}if (haven2 == 0)return Error;
	for (int i = 0; i < NumOfEdge; i++){
		if (EP[i].ekey == ekey){
			havee++;
		}
	}
	if (havee > 0)return Error;

	EP[NumOfEdge] = MEdge(ekey, n1, n2, 1);
	NumOfEdge++;
	if (EMAX - NumOfEdge < 10){
		EMAX += 20;
		//EP = (MEdge *)realloc(sizeof(MEdge)*EMAX);
	}
	return Ok;
}
Status Map::addEdge(Elemtype3 ekey, Elemtype1 n1, Elemtype2 n2, int Quan){
	int havee = 0, haven1 = 0, haven2 = 0;
	for (int i = 0; i < NumOfNode; i++){
		if (NP[i].key == n1){
			haven1++;
		}
	}if (haven1 == 0)return Error;
	for (int i = 0; i < NumOfNode; i++){
		if (NP[i].key == n2){
			haven2++;
		}
	}if (haven2 == 0)return Error;
	for (int i = 0; i < NumOfEdge; i++){
		if (EP[i].ekey == ekey){
			havee++;
		}
	}
	if (havee > 0)return Error;
	if (typeOfMap == "有向图" || typeOfMap == "无向图"){
		Quan = 1;
	}
	EP[NumOfEdge] = MEdge(ekey, n1, n2, Quan);
	NumOfEdge++;
	if (EMAX - NumOfEdge < 10){
		EMAX += 20;
		//EP = (MEdge *)realloc(sizeof(MEdge)*EMAX);
	}
	return Ok;
}
Status Map::deleteE(Elemtype3 key){
	int havee = 0;
	for (int i = 0; i < NumOfEdge; i++){
		if (EP[i].ekey == key){
			for (int j = i; j < NumOfEdge; j++){
				EP[j - 1] = EP[j];
			}
			NumOfEdge--;
			havee++;
		}
	}if (havee == 0)return Error;


	return Ok;
}
Status Map::deleteN(Elemtype1 key){
	int haven = 0;
	for (int i = 0; i < NumOfNode; i++){
		if (NP[i].key == key){
			for (int j = i; j < NumOfNode; j++){
				NP[j - 1] = NP[j];
			}
			NumOfNode--;
			haven++;
		}
	}if (haven == 0)return Error;
	for (int i = 0; i < NumOfEdge; i++){
		if (EP[i].n11 == key || EP[i].n22 == key){
			for (int j = i; j < NumOfEdge; j++){
				EP[j - 1] = EP[j];
			}
			NumOfEdge--;
		}
	}

	return Ok;
}
bool Map::haveCircle(){
	if (NumOfEdge >= NumOfNode) return true;
	return false;
}
Status Map::setMatrix(){
	if (NumOfNode == 0){
		return Error;
	}
	mex = Matrix(NumOfNode, NumOfNode);
	if (typeOfMap == "有向网"){
		for (int i = 0; i < NumOfEdge; i++){
			int in1 = -1, in2 = -1;
			for (int j = 0; j < NumOfNode; j++){
				if (NP[j].key == EP[i].n11){
					in1 = j;
				}
				if (NP[j].key == EP[i].n22){
					in2 = j;
				}
			}
			if (in1 != -1 && in2 != -1){
				mex.a[in1][in2] = EP[i].Quan1;
			}
		}
	}
	if (typeOfMap == "无向网"){
		for (int i = 0; i < NumOfEdge; i++){
			int in1 = -1, in2 = -1;
			for (int j = 0; j < NumOfNode; j++){
				if (NP[j].key == EP[i].n11){
					in1 = j;
				}
				if (NP[j].key == EP[i].n22){
					in2 = j;
				}
			}
			if (in1 != -1 && in2 != -1){
				mex.a[in1][in2] = EP[i].Quan1;
				mex.a[in2][in1] = EP[i].Quan1;
			}
		}
	}
	if (typeOfMap == "无向图"){
		for (int i = 0; i < NumOfEdge; i++){
			int in1 = -1, in2 = -1;
			for (int j = 0; j < NumOfNode; j++){
				if (NP[j].key == EP[i].n11){
					in1 = j;
				}
				if (NP[j].key == EP[i].n22){
					in2 = j;
				}
			}
			if (in1 != -1 && in2 != -1){
				mex.a[in1][in2] = 1;
				mex.a[in2][in1] = 1;
			}
		}
	}
	if (typeOfMap == "有向图"){
		for (int i = 0; i < NumOfEdge; i++){
			int in1 = -1, in2 = -1;
			for (int j = 0; j < NumOfNode; j++){
				if (NP[j].key == EP[i].n11){
					in1 = j;
				}
				if (NP[j].key == EP[i].n22){
					in2 = j;
				}
			}
			if (in1 != -1 && in2 != -1){
				mex.a[in1][in2] = 1;
			}
		}
	}
	return Ok;
}
//Status Map::BFS(){
//	
//}
bool Map::ifQianlian(){
	Matrix keda = Matrix::linToKe(mex);//邻接矩阵转换为可达矩阵  如果可达矩阵处处为一  则为强连通
	bool bol = true;
	for (int i = 0; i < keda.x; i++){
		for (int j = 0; j < keda.y; j++){
			if (keda.a[i][j] == 0){
				bol = false;
			}
		}
	}
	return bol;
}
bool Map::ifDanlian(){
	Matrix keda = Matrix::linToKe(mex);//邻接矩阵转换为可达矩阵  如果可达矩阵加他的转置矩阵处处不为零  则为单向连通
	Matrix zhuan = Matrix::zhuanZhi(keda);
	Matrix danx = Matrix::add(keda, zhuan);
	bool bol = true;
	for (int i = 0; i < keda.x; i++){
		for (int j = 0; j < keda.y; j++){
			if (danx.a[i][j] == 0)return false;
		}
	}
	return bol;
}
bool Map::haveOulaCircle(){
	if (typeOfMap == "无向图"){//无向图是欧拉图当且仅当图是连通图且没有奇度顶点
		if (ifQianlian() == false)return false;
		for (int i = 0; i < mex.x; i++){
			int sum = 0;
			for (int j = 0; j < mex.y; j++){
				sum += mex.a[i][j];
			}
			if (sum % 2 == 1)return false;
		}
		return true;
	}
	if (typeOfMap == "无向网"){
		if (ifQianlian() == false)return false;
		for (int i = 0; i < mex.x; i++){
			int sum = 0;
			for (int j = 0; j < mex.y; j++){
				if (mex.a[i][j] != 0){
					sum++;
				}
			}
			if (sum % 2 == 1)return false;
		}
		return true;
	}
	if (typeOfMap == "有向图"){//有向图有向图是欧拉图当且仅当图是强连通图且每个顶点的入度等于出度
		if (ifQianlian() == false)return false;
		for (int i = 0; i < NumOfNode; i++){
			int sum1 = 0, sum2 = 0;
			for (int j = 0; j < NumOfNode; j++){
				sum1 += mex.a[i][j];
			}
			for (int j = 0; j < NumOfNode; j++){
				sum2 += mex.a[j][i];
			}
			if (sum1 != sum2)return false;
		}
		return true;
	}
	if (typeOfMap == "有向网"){
		if (ifQianlian() == false)return false;
		if (ifQianlian() == false)return false;
		for (int i = 0; i < NumOfNode; i++){
			int sum1 = 0, sum2 = 0;
			for (int j = 0; j < NumOfNode; j++){
				if (mex.a[i][j] != 0)sum1++;

			}
			for (int j = 0; j < NumOfNode; j++){
				if (mex.a[j][i] != 0)sum2++;
			}
			if (sum1 != sum2)return false;
		}
		return true;
	}
	else{
		cout << "未知错误 返回false" << endl;
		return false;
	}
}
bool Map::haveOulaTong(){
	if (typeOfMap == "无向图"){//无向图是欧拉图当且仅当图是连通图且恰有两个奇度顶点
		if (ifQianlian() == false)return false;
		int Numberofji = 0;
		for (int i = 0; i < mex.x; i++){
			int sum = 0;
			for (int j = 0; j < mex.y; j++){
				sum += mex.a[i][j];
			}
			if (sum % 2 == 1)Numberofji++;
		}
		if (Numberofji != 2)return false;
		return true;
	}
	if (typeOfMap == "无向网"){
		if (ifQianlian() == false)return false;
		int Numberofji = 0;
		for (int i = 0; i < mex.x; i++){
			int sum = 0;
			for (int j = 0; j < mex.y; j++){
				if (mex.a[i][j] != 0){
					sum++;
				}
			}
			if (sum % 2 == 1)Numberofji++;
		}
		if (Numberofji != 2)return false;
		return true;
	}

	if (typeOfMap == "有向图"){//有向图有向图是欧拉图当且仅当图是单向连通图且有两个奇度顶点 一个入度比出度大一 一个出度比入度大一
		if (ifDanlian() == false)return false;
		struct InAndOut//入度和出度
		{
			int in;
			int out;
			int sum;
		};
		InAndOut *ioP = (InAndOut*)malloc(sizeof(InAndOut)*NumOfNode);
		for (int i = 0; i < NumOfNode; i++){
			ioP[i].in = 0; ioP[i].out = 0; ioP[i].sum = 0;
			for (int j = 0; j < NumOfNode; j++){
				ioP[i].out += mex.a[i][j];
			}
			for (int j = 0; j < NumOfNode; j++){
				ioP[i].in += mex.a[j][i];
			}
			ioP[i].sum += ioP[i].in + ioP[i].out;
		}
		int NumOfji = 0;
		int ii = -1;
		int oi = -1;
		for (int i = 0; i < NumOfNode; i++){
			if (ioP[i].sum % 2 != 0) {
				if (ioP[i].in - 1 == ioP[i].out)ii = i;
				if (ioP[i].out - 1 == ioP[i].in)oi = i;
				NumOfji++;
			}
		}if (NumOfji == 2 && ii != -1 && oi != -1)return true;
		else{
			return false;
		}
	}
	if (typeOfMap == "有向网"){
		if (ifDanlian() == false)return false;
		struct InAndOut//入度和出度
		{
			int in;
			int out;
			int sum;
		};
		InAndOut *ioP = (InAndOut*)malloc(sizeof(InAndOut)*NumOfNode);
		for (int i = 0; i < NumOfNode; i++){
			ioP[i].in = 0; ioP[i].out = 0; ioP[i].sum = 0;
			for (int j = 0; j < NumOfNode; j++){
				if (mex.a[i][j] != 0)ioP[i].out++;
			}
			for (int j = 0; j < NumOfNode; j++){
				if (mex.a[j][i] != 0)ioP[i].in++;
			}
			ioP[i].sum += ioP[i].in + ioP[i].out;
		}
		int NumOfji = 0;
		int ii = -1;
		int oi = -1;
		for (int i = 0; i < NumOfNode; i++){
			if (ioP[i].sum % 2 != 0) {
				if (ioP[i].in - 1 == ioP[i].out)ii = i;
				if (ioP[i].out - 1 == ioP[i].in)oi = i;
				NumOfji++;
			}
		}if (NumOfji == 2 && ii != -1 && oi != -1)return true;
		else{
			return false;
		}
	}
	cout << "不知道图的类型 无法判断" << endl;
	return false;
}
bool Map::haveHamiCircle(){//任意不相邻的顶点均有d(u)+d(v）>=n图中存在哈密顿回路
	if (typeOfMap == "无向图"){
		int *duOfNode = (int *)malloc(sizeof(int)*NumOfNode);
		for (int i = 0; i < mex.x; i++){
			for (int j = i; j < mex.x; j++){
				duOfNode[i] += mex.a[i][j];
			}
		}
		for (int i = 0; i < mex.x; i++){
			for (int j = i; j < mex.x; j++){
				if (mex.a[i][j] == 0 && duOfNode[i] + duOfNode[j]<NumOfNode){//前面的条件判断是否相邻 后面判断是否度数和大于阶数
					return false;
				}
			}
		}
		return true;
	}
	if (typeOfMap == "无向网"){
		int *duOfNode = (int *)malloc(sizeof(int)*NumOfNode);
		for (int i = 0; i < mex.x; i++){
			for (int j = i; j < mex.x; j++){
				if (mex.a[i][j] != 0)duOfNode[i]++;
			}
		}
		for (int i = 0; i < mex.x; i++){
			for (int j = i; j < mex.x; j++){
				if (mex.a[i][j] == 0 && duOfNode[i] + duOfNode[j]<NumOfNode){//前面的条件判断是否相邻 后面判断是否度数和大于阶数
					return false;
				}
			}
		}
		return true;
	}
	else{
		cout << "无法判断" << endl;
		return false;
	}
}
bool Map::haveHamiTong(){//任意不相邻的顶点均有d(u)+d(v）>=n-1图中存在哈密顿回路
	if (typeOfMap == "无向图"){
		int *duOfNode = (int *)malloc(sizeof(int)*NumOfNode);
		for (int i = 0; i < mex.x; i++){
			for (int j = i; j < mex.x; j++){
				duOfNode[i] += mex.a[i][j];
			}
		}
		for (int i = 0; i < mex.x; i++){
			for (int j = i; j < mex.x; j++){
				if (mex.a[i][j] == 0 && duOfNode[i] + duOfNode[j]<NumOfNode - 1){//前面的条件判断是否相邻 后面判断是否度数和大于阶数减一
					return false;
				}
			}
		}
		return true;
	}
	if (typeOfMap == "无向网"){
		int *duOfNode = (int *)malloc(sizeof(int)*NumOfNode);
		for (int i = 0; i < mex.x; i++){
			for (int j = i; j < mex.x; j++){
				if (mex.a[i][j] != 0)duOfNode[i]++;
			}
		}
		for (int i = 0; i < mex.x; i++){
			for (int j = i; j < mex.x; j++){
				if (mex.a[i][j] == 0 && duOfNode[i] + duOfNode[j]<NumOfNode - 1){//前面的条件判断是否相邻 后面判断是否度数和大于阶数减一
					return false;
				}
			}
		}
		return true;
	}
	else{
		cout << "无法判断" << endl;
		return false;
	}
}
