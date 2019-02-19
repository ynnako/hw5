#include "vec.h"
#include "mat.h"
#include "sq_mat.h"
#include <iostream>
#include "complex.h"

using namespace std;

void test1() 
{
	unsigned int stage;

//	// Stage 1: vector interface
//	stage = 1;
//	cout << "Stage "<< stage << endl;
//	cout << "----------" << endl;
//	try
//	{
//		Vec<double> v1 = (Vec<double>(3), 5, 8, Vec<double>(6), 7, 15);
//		const Vec<double> v2 = v1[Vec<unsigned int>(1), 5, 0, 2, 4, 3];
//		cout << "v1 = " << v1 << endl;
//        cout << "v1 * 4 = " << v1 * 4 << endl;
//        cout << "4 * v1 = " << 4.0 * v1 << endl;
//		cout << "v2 = " << v2 << endl;
//		Vec<double> v3 = (double)2 * v2 + v1 * 3.0;
//		cout << "v3 = " << v3 << endl;
//		Vec<double> v4 = (Vec<double>(0), 0);
//		v4[0] = v1[2];
//		v4[1] = v2[5];
//		cout << "v4 = " << v4 << endl;
//		cout << endl;
//	}
//	catch (exception& e)
//	{
//		cout << "Error in stage " << stage << ": " << e.what() << endl;
//		cout << endl;
//	}
//
//	// Stage 2: ExceptionWrongDimensions
//	stage = 2;
//	cout << "Stage "<< stage << endl;
//	cout << "----------" << endl;
//	try
//	{
//		Vec<unsigned int> v1 = range((unsigned int)0, 5) + Vec<unsigned int>(3);
//		cout << "v1 = " << v1 << endl;
//		cout << endl;
//	}
//	catch (exception& e)
//	{
//		cout << "Error in stage " << stage << ": " << e.what() << endl;
//		cout << endl;
//	}
//
//	// Stage 3: ExceptionEmptyOperand
//	stage = 3;
//	cout << "Stage "<< stage << endl;
//	cout << "----------" << endl;
//	try
//	{
//		Vec<unsigned int> v;
//		cout << v << endl;
//		cout << endl;
//	}
//	catch (exception& e)
//	{
//		cout << "Error in stage " << stage << ": " << e.what() << endl;
//		cout << endl;
//	}
//
//	// Stage 4: ExceptionIndexExceed
//	stage = 4;
//	cout << "Stage "<< stage << endl;
//	cout << "----------" << endl;
//	try
//	{
//		Vec<double> v1 = range(5.1, 8);
//		cout << "v1 = " << v1 << endl;
//		cout << endl;
//	}
//	catch (exception& e)
//	{
//		cout << "Error in stage " << stage << ": " << e.what() << endl;
//		cout << endl;
//	}
//
//	// Stage 5: matrix interface
//	stage = 5;
//	cout << "Stage "<< stage << endl;
//	cout << "----------" << endl;
//	try
//	{
//		Mat<double> m1 = ( Mat<double>( range(1.0, 5) ), range(-3.0, 5), range(7.0, 5) );
//		cout << "m1 = " << endl << m1 << endl;
//		cout << "transpose(m1) = " << m1.transpose() << endl ;
//		cout << "m1 * transpose(m1) = " << endl << m1 * m1.transpose() << endl;
//		Mat<double> m2 = ( Mat<double>( (Vec<double>(3), 7, 5) ), range((double)1, 3) );
//		cout << "m2 = " << endl << m2 << endl;
//		cout << "3 * m2 * (0.5) = " << endl << 3.0 * m2 * (0.5) << endl;
//		cout << endl;
//		Vec<unsigned int> ind = (Vec<unsigned int>(0));
//		Mat<double> mm = m1.get_rows(ind);
//
//		cout << "ind_vec is: " << ind << endl << "mm is: " << mm << endl ;
//		Mat<double> m7 = (Mat<double>( range(1.0,4)) , range(7.0,4) , range(3.0,4) , range(-1.0,4));
//		cout << "first m7 is:" << m7;
//
//        Vec<unsigned int> ind1 = (Vec<unsigned int>(3) , 1 , 2, 5);
//		m7 = m7.get_cols(ind1);
//		cout << "m7 is: " << m7;
//
//		//Mat<int> ex_mat(5);
//		//ex_mat = 5 * ex_mat;
//	}
//	catch (exception& e)
//	{
//		cout << "Error in stage " << stage << ": " << e.what() << endl;
//		cout << endl;
//	}

//
//
//	// Stage 6: square matrix interface
//	stage = 6;
//	cout << "Stage "<< stage << endl;
//	cout << "----------" << endl;
//	try
//	{
//		SqMat<double> m1 = SqMat<double>( (
//												  Mat<double>( ( Vec<double>(1), 1, -1, -2, -2 ) ),
//														  Mat<double>( ( Vec<double>(-3), -1, 1, 1, -2 ) ),
//														  Mat<double>( ( Vec<double>(2), 0, -1, 2, -5 ) ),
//														  Mat<double>( ( Vec<double>(-2), 2, 1, 0, 3 ) ),
//														  Mat<double>( ( Vec<double>(-2), 3, 1, 5, 3 ) )
//										  ) );
//		cout << "m1 = " << endl << m1 << endl;
//		cout << "det(m1) = " << m1.determinant() << endl;
//		cout << endl;
//	}
//	catch (exception& e)
//	{
//		cout << "Error in stage " << stage << ": " << e.what() << endl;
//		cout << endl;
//	}
//
//	// Stage 7: sorting
//	stage = 7;
//	cout << "Stage "<< stage << endl;
//	cout << "----------" << endl;
//	try
//	{
//		norm_inf_comp<double> vec_cmp;
//		Mat<double> m1 = (
//			Mat<double>( ( Vec<double>(-25), 14, -12, -15, 0 ) ),
//			Mat<double>( ( Vec<double>(-44), 6, 3, -16, 23 ) ),
//			Mat<double>( ( Vec<double>(-7), 8, -33, 10, 0 ) )
//			).transpose();
//		cout << "m1 = " << endl << m1 << endl;
//		m1.sort(vec_cmp);
//		cout << "after sorting m1 = " << endl << m1 << endl;
//		cout << endl;
//	}
//	catch (exception& e)
//	{
//		cout << endl;
//		cout << "Error in stage " << stage << ": " << e.what() << endl;
//	}

	// Stage 8: complex numbers
	stage = 8;
	cout << "Stage "<< stage << endl;
	cout << "----------" << endl;
	try
	{
//		double d = 6.5;
//		int i = 2 ;
//		float f = 1.5;
//		unsigned int u = 6;
//		long long int l = 16;
//		Complex c1(3, 7);
//		Complex c2(5, 10);
//		Complex c3(d);
//		Complex c4(i);
//		Complex c5(f);
//		Complex c6(u);
//		Complex c7(l);
//
//		cout << "c1 - c2 = " << c1 - c2 << endl;
//		cout << "c2 - i = " << c2 - i << endl;
//		cout << "c3 - d = " << c3 - d << endl;
//		cout << "c4 - l = " << c4 - l << endl;
//		cout << "i - c5 = " << i - c5 << endl;
//		cout << "c6 = " << c6 << endl;
//		cout << "c7 = " << c7 << endl;

//		cout <<"c1 * d = " << c1 * d <<endl;
//		cout <<"c1 * i = " << c1 * i <<endl;
//		cout <<"c1 * f = " << c1 * f <<endl;
//		cout <<"c1 * u = " << c1 * u <<endl;
//        cout <<"d * c1 = " << d * c1 <<endl;
//		Complex c12 = (1, 3.5);
//		cout << "c2 = " << c2 << endl;
		Mat<Complex> m1 = ( Mat<Complex>( range(Complex(-1, -2.5), 5) ), range(Complex(-2, 2.5), 5), range(Complex(-3, -1), 5) );
		Mat<int> mii = (Mat<int>(range((int)1,3)) , range((int)3,3) , range((int)2,3) , range((int)-4,3) , range((int)1.5 ,3));
		Mat<int> mi2 = (Mat<int>(range((int)1,2)) , range((int)-4,2) , range((int)1.5 ,2));
		Mat<int> mi3 = (Mat<int>(range((int)1,5)) , range((int)-4,5) );
		cout <<"m1 = " << m1 <<endl;
		cout <<"mii = " << mii <<endl;
		cout << "mii * mi2 * mi3 = " << mii * mi2 * mi3;

		//Mat<Complex> mi= (Mat<Complex>(range((Complex) 44 , 5)) , range((Complex) 2 ,5) ,range((Complex)  3 , 5));
//		cout << "m1 = " << endl << m1 << endl;
//		cout << "mi = " << endl << mi << endl;
//		cout << "m1 + mi = " << endl << m1 + mi << endl;
//        Vec<Complex> r1(Complex(1,1));
//        Vec<Complex> r2(Complex(0,2));
//        Vec<Complex> r3(Complex(2,2));
//        r1 = (r1,Complex(3,1),Complex(0,1));
//        r2 = (r2,Complex(3),Complex(3,2));
//        r3 = (r3,Complex(3,1),Complex(3,3));
//        SqMat<Complex> mc = (Mat<Complex>(r1) , r2, r3) ;
//        cout << " mc = " << mc << endl;
//        cout << "det(mc) = " << mc.determinant() << endl;
//        cout << "det(mc * mc') = " << mc * mc.determinant() << endl;
//        cout << "det(mc * mc') = " <<  SqMat<Complex>(mc * mc.transpose()).determinant() << endl;
//		cout << "m1 * transpose(mi) = " << endl << m1 * mi.transpose() << endl;
//		cout << "m1 * transpose(m1) = " << endl << m1 * m1.transpose() << endl;
//		cout << "det(m1 * transpose(m1)) = " << SqMat<Complex>(m1 * m1.transpose()).determinant() << endl;
//		cout << "det(m1 * transpose(mi)) = " << SqMat<Complex>(m1 * mi.transpose()).determinant() << endl;
//		Mat<Complex> m2 = (
//			Mat<Complex>( ( Vec<Complex>( Complex(-25, 1) ), Complex(14, 3), Complex(-12, 7), Complex(-15, 0 ) ) ),
//			Mat<Complex>( ( Vec<Complex>( Complex(-44, 2) ), Complex(6, 0), Complex(3, 0), Complex(-16, 23 ) ) )
//			).transpose();
//		cout << "m2 = " << endl << m2 << endl;
//		norm_inf_comp<Complex> vec_cmp;
//		m2.sort(vec_cmp);
//		cout << "after sorting m2 = " << endl << m2 << endl;
//		cout << endl;
	}
	catch (exception& e)
	{
		cout << "Error in stage " << stage << ": " << e.what() << endl;
		cout << endl;
	}
}

int main()
{
	test1();

	return 0;
}