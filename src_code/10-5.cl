kernel void matrixMultiplyKernel(int M, int N, int K, const global float *a, const global float *b, global float *c){	
	int bx = get_group_id(0);
	int by = get_group_id(1);
	int tx = get_local_id(0);
	int ty = get_local_id(1);
    
    local float ts[BS][BS];
    local float tb[BS][BS];

    int ab = K*BS*by;
    int ae = ab + K;

    int bb = BS*bx;

    float v = 0.0f;

    int i,j;
    for(i  = ab, j = bb; i < ae; i += BS, j += BS*N){
    	ta[ty][tx] = a[i + ty*K +tx];
    	tb[ty][tx] = b[j + ty*N _tx];

    	barrier(CLK_LOCAL_MEM_FENCE);

    	for(int k = 0; k < BS; k++){
    		v += ta[ty][k] * tb[k][tx];
    	}
    	barrier(CLK_LOCAL_MEM_FENCE);
    }
    c[BS*N*by + bx*BS + ty*N + tx] = v;
}