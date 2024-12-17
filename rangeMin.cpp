int x[N];
vector<int> sgt(2*N);

void op(int idx){
	sgt[idx] = min(sgt[2*idx],sgt[2*idx+1]);
}

void build(int idx, int l, int r){
	if(l==r){
		sgt[idx] = x[l];
		return;
	}
	int mid = (l+r)/2;
	build(2*idx, l, mid);
	build(2*idx+1, mid+1,r);
	op(idx);
}

void update(int idx, int l, int r, int tIdx, int tVal){
	if(l==r){
		sgt[idx]= tVal;
		return;
	}
	int mid = (l+r)/2;
	if(tIdx > mid){
		update(2*idx+1, mid+1,r,tIdx,tVal);
	}
	else{
		update(2*idx, l,mid,tIdx,tVal);
	}
	op(idx);
}


int getMin(int idx, int l, int r, int tSt, int tEnd){
	// complete overlap
	if (l >= tSt && r <= tEnd) {
	    return sgt[idx];
	}
	// no overlap
	if (r < tSt || l > tEnd) {
	    return INT_MAX;
	}
	// partial overlap
	int mid = (l+r)/2;
	return min(getMin(2*idx,l,mid,tSt,tEnd),getMin(2*idx+1,mid+1,r,tSt,tEnd));
}
