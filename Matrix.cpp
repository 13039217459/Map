#include"Shuzhu.cpp"

#ifndef MATRIX_CPP
#define MATRIX_CPP

class Matrix :public Shuzhu
{
public:
	bool ifQuan;
	Matrix(){
		ifQuan =true;
		x = y = 0;
	}
	Matrix(int x1){
		ifQuan = true;
		x = x1;
		y = x1;
		a = (int **)malloc(sizeof(int *)*x);
		for (int i = 0; i < x; i++)
			*(a + i) = (int  *)malloc(sizeof(int)*y);
		for (int i = 0; i < x; i++)
			for (int j = 0; j < y; j++)
				a[i][j] = 0;
	}
	Matrix(int x1, int y1){
		ifQuan = true;
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

		* 函数名：linToKe

		* 作者：Luo

		* 日期：邻接矩阵到可达矩阵

		**/
	static Matrix linToKe(Matrix linjie){
		int x = linjie.x;
		Matrix R = Matrix::R(x);
		linjie.add(R);
		while (Matrix::comp(Matrix::chen(linjie, linjie), linjie)){
			linjie.chen(linjie);
		}
		return linjie;
	}
	/**

		* 函数名：guanToLin

		* 作者：Luo

		* 日期：关联矩阵到邻接矩阵

		**/
	static Matrix guanToLin(Matrix guanlian){
		int a, b;
		Matrix linjie(guanlian.x, guanlian.x);
		//扫描每一行中  如果为正 取这一列中正数的行数为行数  取那一列中负数的行数为列数  加一
		for (int i = 0; i < guanlian.y; i++){
			for (int j = 0; j < guanlian.x; j++){
				if (guanlian.a[j][i] == 1){
					a = j;;
				}
				if (guanlian.a[j][i] == -1){
					b = j;
				}
			}
			linjie.a[a][b]++;
		}
		return linjie;
	}
	Status setQuan(bool ifQ){
		ifQuan = ifQ;
	}
	/**

	* 函数名：zhuanzhi

	* 作者：Luo

	* 日期：输入一个矩阵或者数组 输出一个转置矩阵

	**/
	Matrix zhuanZhi()
	{

		Matrix rs(y, x);
		for (int i = 0; i < x; i++){
			for (int j = 0; j < y; j++){
				rs.a[j][i] = a[i][j];
			}
		}
		return rs;

	}
	static Matrix zhuanZhi(Shuzhu s)
	{

		Matrix rs(s.y, s.x);
		for (int i = 0; i < s.x; i++){
			for (int j = 0; j < s.y; j++){
				rs.a[j][i] = s.a[i][j];
			}
		}
		return rs;

	}
	static Matrix zhuanZhi(Matrix s)
	{

		Matrix rs(s.y, s.x);
		for (int i = 0; i < s.x; i++){
			for (int j = 0; j < s.y; j++){
				rs.a[j][i] = s.a[i][j];
			}
		}
		return rs;

	}
	/**

	* 函数名：comp

	* 作者：Luo

	* 日期：比较两个矩阵是否相同

	**/
	static bool comp(Shuzhu s1, Shuzhu s2){
		if (s1.x != s2.x || s1.y != s2.y){
			cout << "矩阵无法比较" << endl;
			return false;
		}
		else{
			Shuzhu rs(s1.x, s2.y);
			for (int i = 0; i < s1.x; i++){
				for (int j = 0; j < s1.y; j++){
					if (s1.a[i][j] != s2.a[i][j])return false;
				}
			}
		}
		return true;
	}
	bool comp(Shuzhu s1){
		if (s1.x != x || s1.y != y){
			cout << "矩阵无法比较" << endl;
			return false;
		}
		else{
			for (int i = 0; i < s1.x; i++){
				for (int j = 0; j < s1.y; j++){
					if (s1.a[i][j] != a[i][j])
						return false;
				}
			}
		}
		return true;
	}
	/**

	* 函数名：R

	* 作者：Luo

	* 日期：得到一个x阶的单位矩阵

	**/
	static Matrix R(int x){
		Matrix rs(x, x);
		for (int i = 0; i < x; i++){
			rs.a[i][i] = 1;
		}
		return rs;
	}
	/**

	* 函数名：add

	* 作者：Luo

	* 日期：返回两矩阵相加得到的新矩阵

	**/
	static Matrix add(Matrix s1, Matrix s2){
		if (s1.x != s2.x || s1.y != s2.y){
			cout << "矩阵无法相加" << endl;
			return Matrix(0, 0);
		}
		else{
			Matrix rs(s1.x, s2.y);
			for (int i = 0; i < s1.x; i++){
				for (int j = 0; j < s1.y; j++){
					rs.a[i][j] = s1.a[i][j] + s2.a[i][j];
				}
			}
			return rs;
		}
	}
	Matrix add(Matrix s1){
		if (s1.x != x || s1.y != y){
			cout << "矩阵无法相加" << endl;
			return Matrix(0, 0);
		}
		else{
			Matrix rs(s1.x, y);
			for (int i = 0; i < s1.x; i++){
				for (int j = 0; j < s1.y; j++){
					rs.a[i][j] = s1.a[i][j] + a[i][j];
				}
			}
			return rs;
		}
	}
	/**

	* 函数名：jian

	* 作者：Luo

	* 日期：得到两矩阵相减的新矩阵

	**/
	static Matrix jian(Matrix s1, Matrix s2){
		if (s1.x != s2.x || s1.y != s2.y){
			cout << "矩阵无法相减" << endl;
			return Matrix(0, 0);
		}
		else{
			Matrix rs(s1.x, s2.y);
			for (int i = 0; i < s1.x; i++){
				for (int j = 0; j < s1.y; j++){
					rs.a[i][j] = s1.a[i][j] - s2.a[i][j];
				}
			}
			return rs;
		}
	}
	 Matrix jian(Matrix s1){
		if (s1.x != x || s1.y != y){
			cout << "矩阵无法相减" << endl;
			return Matrix(0, 0);
		}
		else{
			Matrix rs(s1.x, y);
			for (int i = 0; i < s1.x; i++){
				for (int j = 0; j < s1.y; j++){
					rs.a[i][j] = s1.a[i][j] - a[i][j];
				}
			}
			return rs;
		}
	}
	 /**

	 * 函数名：chen

	 * 作者：Luo

	 * 日期：得到两矩阵相乘的新矩阵 这个矩阵所有大于1的值都为1  用于邻接矩阵和关联矩阵的计算

	 **/
	 static Matrix chen(Matrix s1, Matrix s2){
		 if (s1.y != s2.x){
			 cout << "矩阵无法相乘" << endl;
			 return Matrix(0, 0);
		 }
		 else{
			 Matrix rs(s1.x, s2.y);
			 for (int i = 0; i < s1.x; i++){
				 for (int j = 0; j < s2.y; j++){
					 int q = 0;
					 for (int k = 0; k < s1.y; k++){
						 q += s1.a[i][j] * s2.a[j][i];
					 }
					 if (q != 0 && s1.ifQuan == false && s2.ifQuan == false)q = 1;
					 rs.a[i][j] = q;
				 }
			 }
			 return rs;
		 }
	 }
	 Matrix chen(Matrix s1){
		 if (s1.y != x){
			 cout << "矩阵无法相乘" << endl;
			 return Matrix(0, 0);
		 }
		 else{
			 Matrix rs(s1.x, y);
			 for (int i = 0; i < s1.x; i++){
				 for (int j = 0; j < y; j++){
					 int q = 0;
					 for (int k = 0; k < s1.y; k++){
						 q += s1.a[i][j] * a[j][i];
					 }
					 if (q != 0 && s1.ifQuan == false && ifQuan == false)q = 1;
					 rs.a[i][j] = q;
				 }
			 }
			 return rs;
		 }
	 }
};



#endif