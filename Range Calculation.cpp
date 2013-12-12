// matrix must be 1 indexed

// for 2D Matrix 

void add(int r, int c , int x) {
	int ret = x ;
	ret += Sum[r-1][c];
	ret += Sum[r][c-1];
	ret -= Sum[r-1][c-1];
	Sum[r][c] = ret ;
}

int getSum(int r1 , int c1 , int r2 , int c2){
    int ret = 0 ;
    ret += Sum[r2][c2];
    ret -= Sum[r1-1][c2];
    ret -= Sum[r2][c1-1];
    ret += Sum[r1-1][c1-1];
    return  ret ;
}


// for 3D Matrix 

void add(int x , int y , int z , int v ){
    int Sum = 0 ;
    Sum += tree[x-1][y-1][z-1];
    Sum += tree[x][y][z-1];
    Sum += tree[x][y-1][z];
    Sum += tree[x-1][y][z];
    Sum -= tree[x-1][y-1][z];
    Sum -= tree[x][y-1][z-1];
    Sum -= tree[x-1][y][z-1];
    Sum += v ;
    tree[x][y][z] = Sum ;
}


int getSum(int x1 , int y1 , int z1 , int x2 , int y2 , int z2 ){
    int Sum = 0;
    Sum += tree[x2][y2][z2];
    Sum -= tree[x2][y2][z1-1];
    Sum -= tree[x2][y1-1][z2];
    Sum -= tree[x1-1][y2][z2];
    Sum += tree[x2][y1-1][z1-1];
    Sum += tree[x1-1][y2][z1-1];
    Sum += tree[x1-1][y1-1][z2];
    Sum -= tree[x1-1][y1-1][z1-1];
    return Sum;
}
