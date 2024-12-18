int x[N];
vector<vector<int>> sgt(4*N, vector<int>(2)); // {min, 2nd min}

vector<int> combine(vector<int> &l, vector<int> &r){
	vector<int> res = {l[0],l[1],r[0],r[1]};
	sort(res.begin(), res.end());
	return {res[0], res[1]};
}

void op(int idx){
	vector<int> l = sgt[2*idx];
	vector<int> r = sgt[2*idx+1];
	sgt[idx] = combine(l,r);
}

void build(int idx, int l, int r){
	if(l==r){
		sgt[idx] = {x[l], INT_MAX};
		return;
	}
	int mid = (l+r)/2;
	build(2*idx, l, mid);
	build(2*idx+1, mid+1,r);
	op(idx);
}

void update(int idx, int l, int r, int tIdx, int tVal){
	if(l==r){
		sgt[idx]= {tVal, INT_MAX};
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


vector<int> query(int idx, int l, int r, int tSt, int tEnd){
	// complete overlap
	if (l >= tSt && r <= tEnd) {
		return sgt[idx];
	}
	// no overlap
	if (r < tSt || l > tEnd) {
	    return {INT_MAX,INT_MAX};
	}
	// partial overlap
	int mid = (l+r)/2;
	vector<int> x = query(2*idx,l,mid,tSt,tEnd);
	vector<int> y = query(2*idx+1,mid+1,r,tSt,tEnd);
	return combine(x,y);
}
