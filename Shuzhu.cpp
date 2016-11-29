#include<iostream>
using namespace std;
#define True  1
#define False 0
#define Ok    1
#define Error 0
#define Infeasible -1
#define Overflow   -2
typedef int Status;
#ifndef SHUZHU_CPP
#define SHUZHU_CPP

class Shuzhu{
public:
	int     **a;
	int     x, y;
	Shuzhu(){
		x = y = 0;

	}
	Shuzhu(int x1){
		x = x1;
		y = x1;
		a = (int **)malloc(sizeof(int *)*x);

		for (int i = 0; i < x; i++)
		{
			*(a + i) = (int  *)malloc(sizeof(int)*y);
		}
		for (int i = 0; i < x; i++)
		{
			for (int j = 0; j < y; j++){
				a[i][j] = 0;
			}

		}
	}
	Shuzhu(int x1, int y1){
		x = x1;
		y = y1;
		a = (int **)malloc(sizeof(int *)*x);

		for (int i = 0; i < x; i++)
		{
			*(a + i) = (int  *)malloc(sizeof(int)*y);
		}
		for (int i = 0; i < x; i++)
		{
			for (int j = 0; j < y; j++){
				a[i][j] = 0;
			}

		}
	}

	/**
	* 函数名：set
	* 作者：Luo
	* 日期：输入一个数组中所有的数  为其分配到数组中所有的位置
	**/
	template<int Fuck>
	int  set(int(&p)[Fuck]){                                    //想要获取传进来的数组的长度只有这种方法
		//而数组名其实是一个常量指针。sizeof对待这两者是不一样的。
		int len = sizeof(p) / sizeof(p[0]);
		int ii = 0;
		if (len%x == 0){
			for (int i = 0; i < len / x; i++){
				for (int j = 0; j < y; j++){
					a[i][j] = p[i*y + j];
					ii++;
					if (ii == len){
						return 0;
					}
				}
				//cout << "执行了shang" << endl;
			}
		}
		else{
			for (int i = 0; i < (len / x) + 1; i++){
				for (int j = 0; j < y; j++){
					a[i][j] = p[i*y + j];
					ii++;
					if (ii == len){
						return 0;
					}
				}
				//cout << "执行了xia" << endl;
			}
		}
		return 0;
	}
	/**

	* 函数名：show

	* 作者：Luo

	* 日期：显示数组中所有的数据

	**/
	void show(){
		for (int i = 0; i < x; i++){
			for (int j = 0; j < y; j++){
				cout << a[i][j] << "\t";
			}
			cout << endl;
		}
	}
};

#endif