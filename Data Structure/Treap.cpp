struct node {
  int64 key, rnk, cnt;
	node *le, *ri;

	node (int64 key = 0, int64 rnk = rand ()) : key (key), rnk (rnk), cnt (1), le (0), ri (0) {}
};

class treap {
	typedef node* pNode;
	pNode root;

    int64 count (pNode cur) { return cur ? cur -> cnt : 0; }
    void updateCnt (pNode cur) { if (cur) cur -> cnt = 1 + count (cur -> le) + count (cur -> ri); }

	void split (pNode cur, pNode &le, pNode &ri, int64 key) {
		if (!cur) { le = ri = 0; return; }
        if (key < cur -> key ) split (cur -> le, le, cur -> le, key), ri = cur;
        else split (cur -> ri, cur -> ri, ri, key), le = cur;
        updateCnt (cur);
    }

    void merge (pNode &cur, pNode le, pNode ri) {
        if (!le || !ri) cur = le ? le : ri;
        else if (le -> rnk > ri -> rnk) merge (le -> ri, le -> ri, ri), cur = le;
        else merge (ri -> le, le, ri -> le), cur = ri;
        updateCnt (cur);
    }

    void insert (pNode &cur, pNode it) {
        if (!cur) cur = it;
        else if (it -> rnk > cur -> rnk) split (cur, it -> le, it -> ri, it -> key), cur = it;
        else insert ((it -> key < cur -> key) ? cur -> le : cur -> ri, it);
        updateCnt (cur);
    }

    void erase (pNode &cur, int64 key, int64 rnk) {
        if (!cur) return;
        if (cur -> key == key) {
        	if (rnk == -1) rnk = cur -> rnk;
        	if (rnk == cur -> rnk) merge (cur, cur -> le, cur -> ri);
        	else erase (cur -> ri, key, rnk);
        } else erase ((key < cur -> key) ? cur -> le : cur -> ri, key, rnk);
        updateCnt (cur);
    }

    int64 countLess (pNode cur, int64 key) {
        if (!cur) return 0;
        if (key <= cur -> key) return countLess (cur -> le, key);
        return 1 + count (cur -> le) + countLess (cur -> ri, key);
    }

    int64 countLessEqual (pNode cur, int64 key) {
        if (!cur) return 0;
        if (key < cur -> key) return countLessEqual (cur -> le, key);
        return 1 + count (cur -> le) + countLess (cur -> ri, key);
    }

    int64 countEqual (pNode cur, int64 key) {
    	if (!cur) return 0;
    	if (key == cur -> key) return 1 + countEqual (cur -> ri, key);
    	return countEqual (key < cur -> key ? cur -> le : cur -> ri, key);
    }

    pNode kThElement (pNode cur, const int kTh) {
        if (!cur or kTh >= count (cur)) return 0;
        if (kTh == count (cur -> le)) return cur;
        return kTh < count (cur -> le) ? kThElement (cur -> le, kTh) : kThElement (cur -> ri, kTh - (count (cur -> le) + 1));
    }

    void clear (pNode cur) {
        if (cur -> le) free (cur -> le);
        if (cur -> ri) free (cur -> ri);
        free (cur);
    }

public:
	treap () { root = 0; srand (time (0)); }
	int64 size () { return count (root); }
    void clear () { clear (root); root = 0; }
	bool find (int64 key) { return countEqual (root, key) ? true : false; }
	void insert (int64 key, int64 rnk = rand ()) { insert (root, new node (key, rnk)); }
	void insert_unique (int64 key, int64 rnk = rand ()) { if (!countEqual (root, key)) insert (root, new node (key, rnk)); }
	void erase (int64 key, int64 rnk = -1) { erase (root, key, rnk); }
	int64 operator [] (const int idx) { pNode cur = kThElement (root, idx); return cur ? cur -> key : LLONG_MIN; }
};
