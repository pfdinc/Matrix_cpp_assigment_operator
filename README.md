 Given a header file matrix.h which declares a class Matrix. Write a  file matrix.cpp which implements the class.


The header declares multiple constructors, a destructor, some methods, and various operators which are described below. Do not add any additional public methods. You are, however, allowed to add private methods to avoid redundancy in your code.
The elements of the matrix are stored in dynamic allocated memory, namely in the private member double values**whichisusedastwo-dimensionalarray.Therefore,whenimplementingtheclass, make sure that your implementation handles dynamic allocated memory appropriately. For example, make a copy or delete it if needed.


The Class Matrix Constructors


Matrix(): Creates an empty matrix of size 0 × 0.

Matrix(int size): Creates an identity matrix of size size × size.


Matrix(int height, int width): Creates a matrix of size height × width  lled with 0s. 

Matrix(Matrix&): Copy constructor.


Matrix(Matrix&&): Move constructor.




			 			  1 0 0
	Matrix(3) = 		  [0 1 0]
			              [0 0 1]
			              
			              
			       		  0 0
	Matrix(3,2) = 		  [0 0]
			              [0 0]
			              
			              
Methods 
			              
int getWidth(), int getHeight(): Returns the width or height of the matrix, respectively. void resize(int height, int width): Changes the size of the matrix to height × width.

 Existing  elds keep their value and new  elds are set to 0. Note that it changes the matrix and
does not create a copy.


void transpose(): Changes the matrix to its transposition. Note that it changes the matrix and
does not create a copy.


	  1 2
	  [4 3]  =
	  [5 6]		              		              
			       		  1 2 0
	.resize(2,3) = 		  [4 3 0]
	
	  1 2
	  [4 3]  = 
	  [5 6]
			
						   1 4 5
	.transpose() = 		  [2 3 6]              
	
	
	
	Operators
	
Matrix& operator= (Matrix&): Copy assignment.

Matrix& operator= (Matrix&&): Move assignment.

double& operator()(int row, int col): Returns or sets the value at the speci ed position in
the matrix. Rows and columns start counting at 0, i. e., the top left element is at position (0, 0). Matrix 

operator+(Matrix&): Creates a new matrix which is the sum of this and another given matrix. This does not change the current matrix. If the size ob both matrices is not matching, the
resulting matrix has the dimensions of the largest intersection of both given matrices.

Matrix& operator+=(Matrix&): Adds a given matrix to the current. Note that it changes the matrix and does not create a copy. If the size ob both matrices is not matching, it changes the
dimensions of the current matrix to the largest intersection of both matrices.

Matrix operator*(Matrix&): Creates a new matrix which is the product of this and another given matrix. This does not change the current matrix. If the size ob both matrices is not matching, it uses the largest sub-matrices which work (the top left element is always included).
Note that matrix multiplication is not a symmetric operation, i. e., in general for two matrices A and B, AB ̸= BA. When multiplying two matrices, the *-operator of the left matrix is called.


Matrix& operator*=(Matrix&): Multiplies a given matrix with the current. Note that it changes the matrix and does not create a copy. If the size ob both matrices is not matching, it uses the largest sub-matrices which work (the top left element is always included).
Note that matrix multiplication is not a symmetric operation, i. e., in general for two matrices A and B, AB ̸= BA. When multiplying two matrices, the *-operator of the left matrix is called.


Matrix operator*(double): Createsanewmatrixwhichistheproductofthismatrixandagiven number. This does not change the current matrix.
Matrix& operator*=(double): Multiplies the current with a given number. Note that it changes the matrix and does not create a copy.



bool operator==(Matrix&): Determines if two matrices are equal. Two matrices are equal if they have the same height, the same width, and all corresponding elements are equal in both matrices.

Members
int width, int height: Store the width or height of the matrix, respectively.
double** values: Stores the elements of the matrix (as two-dimensional array).


