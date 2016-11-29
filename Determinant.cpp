#include"Matrix.cpp"
class Determinant :public Matrix
{
	Determinant(){
		ifQuan = true;
		x = y = 0;
	}
	Determinant(int x1){
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
	Determinant(int x1, int y1){
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

	* 函数名：gethlsvalue

	* 作者：Luo

	* 日期：获取行列式的值

	**/
	int gethlsvalue(Determinant in){

		int i = 0, j = 0, c = 0; /*i，j为行与列,c为数组b的行*/



		if (in.x == 1){
			//cout <<" in.a[0][0]:"<< in.a[0][0] << endl;
			return in.a[0][0];
		}

		
		Determinant out(in.x - 1);/*定义数组b并初始化*/

		int p = 0, q = 0;/*p,q为中间变量*/
		int sum = 0;/*sum为行列式的值*/


		for (i = 0; i < in.x; i++)/*此处大循环实现将余子式存入数组out.a中*/

		{
			for (c = 0; c < in.x - 1; c++)
			{
				if (c < i)    /*借助c判断每行的移动方法*/
					p = 0;

				else
					p = 1;

				for (j = 0; j < in.x - 1; j++)
				{
					out.a[c][j] = in.a[c + p][j + 1];
				}
				//cout << "out:" << endl;
				//out.show();
			}
			if (i % 2 == 0)  q = 1;
			else  q = (-1);
			cout << "sum1:" << sum << endl;
			cout << "in.a[i][0]:" << in.a[i][0] << endl;
			cout << "q:" << q << endl;
			cout << "out:" << endl;
			out.show();
			sum = sum + in.a[i][0] * q*gethlsvalue(out);
			cout << "sum2:" << sum << endl << endl << endl << endl << endl;
		}
		return sum;
	}
	/**

		* 函数名：getYuShi

		* 作者：Luo

		* 日期：得到所在位置的余子式的值

		**/
	int getyuzishi(int x1, int y1){
		Determinant out(x - 1);/*定义数组b并初始化*/
		int q = 0;
		int x2 = 0, y2 = 0;
		for (int i = 0; i < x - 1; i++){
			for (int j = 0; j < x - 1; j++){
				if (i >= x1){
					x2 = 1;
				}
				else{
					x2 = 0;
				}
				if (j >= y1){
					y2 = 1;
				}
				else{
					y2 = 0;
				}
				out.a[i][j] = a[i + x2][j + y2];

			}
		}
		if (x1 % 2 == 0)  q = 1;
		else  q = (-1);
		return q*gethlsvalue(*this);



	}

};