void solve_tridiagonal(vector<double > &x,vector<double > a,vector<double > b,vector<double > c) {
    /* unsigned integer of same size as pointer */
    int in , N = x.size();
    /*
     solves Ax = v where A is a tridiagonal matrix consisting of vectors a, b, c
     note that contents of input vector c will be modified, making this a one-time-use function
     x[] - initially contains the input vector v, and returns the solution x. indexed from [0, ..., N - 1]
     N — number of equations
     a[] - subdiagonal (means it is the diagonal below the main diagonal) -- indexed from [1, ..., N - 1]
     b[] - the main diagonal, indexed from [0, ..., N - 1]
     c[] - superdiagonal (means it is the diagonal above the main diagonal) -- indexed from [0, ..., N - 2]
     */

    c[0] = c[0] / b[0];
    x[0] = x[0] / b[0];

    /* loop from 1 to N - 1 inclusive */
    for (in = 1; in < N; in++) {
        double m = 1.0 / (b[in] - a[in] * c[in - 1]);
        c[in] = c[in] * m;
        x[in] = (x[in] - a[in] * x[in - 1]) * m;
    }

    /* loop from N - 2 to 0 inclusive, safely testing loop end condition */
    for (in = N - 1; in-- > 0; )
        x[in] = x[in] - c[in] * x[in + 1];
}



In numerical linear algebra, the tridiagonal matrix algorithm, also known as the Thomas algorithm (named after Llewellyn Thomas),
is a simplified form of Gaussian elimination that can be used to solve tridiagonal systems of equations. 
A tridiagonal system for n unknowns may be written as ::


A[i] * X[i-1] + B[i] * X[i] + C[i] * X[i+1] = D[i]

where A[1] = 0 and C[n] = 0 

|b1 c1            |  | X[1] |     | d1 |
|a2 b2 c2	        |  | X[2] |     | d2 |
|   a3 b3  .      |  | X[3] |     | d3 |
|    .. ..        |  | ...  |  =  | .. |
|       .. ..     |  | ...  |     | .. |
|	        ..  cn-1|  | ...  |     | .. |
|0         an   bn|  | X[n] |     | dn |


For such systems, the solution can be obtained in O(n) operations instead of O(n^3) required by Gaussian elimination.
A first sweep eliminates the a_i's, and then an (abbreviated) backward substitution produces the solution. Examples of such matrices commonly arise from the discretization of 1D Poisson equation (e.g., the 1D diffusion problem) and natural cubic spline interpolation.


Source :: http://en.wikipedia.org/wiki/Tridiagonal_matrix_algorithm
