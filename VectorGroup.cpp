#include"Matrix.cpp"
#define Elemtype float
class VectorGroup :public Matrix
{
	int Number;
	Elemtype     **a, **zhi;
	VectorGroup(int x1, int y1){
	
		Number = 0;
		x = x1;
		y = y1;
		a = (Elemtype **)malloc(sizeof(Elemtype *)*x);

		for (int i = 0; i < x; i++)
		{
			*(a + i) = (Elemtype  *)malloc(sizeof(int)*y);
		}
		for (int i = 0; i < x; i++)
		{
			for (int j = 0; j < y; j++){
				a[i][j] = 0;
			}

		}
		zhi = a;
	}
	template<class T>
	Status set(T &p){

		int len = sizeof(p) / sizeof(p[0]);
		if (x != len){
			cout << "向量长度不对" << endl;
			return Error;
		}
		for (int j = 0; j < x; j++){
			a[j][shulian] = *(p + j);
		}
		shulian++;
		return Ok;
	}
	bool iffill(){
		if (Number == y)return true;
		else return false;
	}
	Status show(){
		cout << "向量组" << endl;
		cout << "---------------------------" << endl;
		for (int i = 0; i < 500000000; i++);
		for (int i = 0; i < x; i++){
			for (int j = 0; j < y; j++){
				cout << zhi[i][j] << " ";
			}
			cout << endl;
		}
		cout << endl;
		cout << "---------------------------" << endl;
		return Ok;
	}
	int getrank(){
		int rank = x;
		int p = 0;
		for (int j = 0; j < y; j++){
			if (zhi[j - p][j] != 0){
				Elemtype k1 = zhi[j - p][j];
				for (int ind = j; ind < y; ind++){//自身置一
					zhi[j - p][ind] /= k1;
				}
				for (int i = 0; i < j - p; i++){//将上面置零
					k1 = zhi[i][j];
					if (zhi[i][j] != 0){
						for (int ind = j; ind < y; ind++){
							zhi[i][ind] -= k1 * zhi[j - p][ind];
						}
					}
				}
				for (int i = j + 1 - p; i < x; i++){//将下面置零
					k1 = zhi[i][j];
					if (zhi[i][j] != 0){
						for (int ind = j; ind < y; ind++){
							zhi[i][ind] -= k1 * zhi[j - p][ind];
						}
					}
					show();
				}show();
			}
			else{
				bool all = false;
				int jishu = j + 1;//标记一下这个位置
				for (int ind = j + 1; ind < x; ind++){//查找下面第一个不为零的数
					if (zhi[ind][j] != 0){
						all = true;
						if (all){
						}
						for (int ind1 = j; ind1 < y; ind1++){//两行互换
							Elemtype temp = zhi[j][ind1];
							zhi[j][ind1] = zhi[ind][ind1];
							zhi[ind][ind1] = temp;
						}
						break;
					}
				}
				show();
				if (all){
					j--;
				}
				else{
					p++;
				}
				//再循环此地方
			}
			if (x<y&&j == x - 1){//如果列比行多 那么运行到这里 向量组的秩为行数
				break;
			}
		}
		for (int i = 0; i < x; i++){
			for (int j = 0; j < y; j++){
				if (zhi[x - i - 1][j] != 0){
					goto next;
				}
			}
			rank--;
		}
	next:
		return rank;
	}
	Status jie(){

		if (y - x != 1){
			return Error;
		}
		VectorGroup xlz2(x, x);
		for (int i = 0; i < x; i++){
			for (int j = 0; j < x; j++){
				xlz2.a[i][j] = a[i][j];
			}
		}
		//xlz2.show();
		if (getrank() != xlz2.getrank()){
			cout << "该方程无解" << endl;
		}
		else{
			if (getrank() != x){
				cout << "该方程有无穷解" << endl;
			}
			else{
				cout << "方程组的解为：" << endl;
				for (int i = 0; i < x; i++){
					cout << "x" << i + 1 << ":" << zhi[i][y - 1] << endl;
				}
			}
		}
		return Ok;
	}
	static Status jie(VectorGroup xlz1){

		if (xlz1.y - xlz1.x != 1){
			return Error;
		}
		VectorGroup xlz2(xlz1.x, xlz1.x);
		for (int i = 0; i < xlz1.x; i++){
			for (int j = 0; j < xlz1.x; j++){
				xlz2.a[i][j] = xlz1.a[i][j];
			}
		}
		//xlz2.show();
		if (xlz1.getrank() != xlz2.getrank()){
			cout << "该方程无解" << endl;
		}
		else{
			if (xlz1.getrank() != xlz1.x){
				cout << "该方程有无穷解" << endl;
			}
			else{
				cout << "方程组的解为：" << endl;
				for (int i = 0; i < xlz1.x; i++){
					cout << "x" << i + 1 << ":" << xlz1.zhi[i][xlz1.y - 1] << endl;
				}
			}
		}
		return Ok;
	}
};