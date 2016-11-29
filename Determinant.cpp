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

	* ��������gethlsvalue

	* ���ߣ�Luo

	* ���ڣ���ȡ����ʽ��ֵ

	**/
	int gethlsvalue(Determinant in){

		int i = 0, j = 0, c = 0; /*i��jΪ������,cΪ����b����*/



		if (in.x == 1){
			//cout <<" in.a[0][0]:"<< in.a[0][0] << endl;
			return in.a[0][0];
		}

		
		Determinant out(in.x - 1);/*��������b����ʼ��*/

		int p = 0, q = 0;/*p,qΪ�м����*/
		int sum = 0;/*sumΪ����ʽ��ֵ*/


		for (i = 0; i < in.x; i++)/*�˴���ѭ��ʵ�ֽ�����ʽ��������out.a��*/

		{
			for (c = 0; c < in.x - 1; c++)
			{
				if (c < i)    /*����c�ж�ÿ�е��ƶ�����*/
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

		* ��������getYuShi

		* ���ߣ�Luo

		* ���ڣ��õ�����λ�õ�����ʽ��ֵ

		**/
	int getyuzishi(int x1, int y1){
		Determinant out(x - 1);/*��������b����ʼ��*/
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