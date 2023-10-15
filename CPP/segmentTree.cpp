class segtree{
    vector<int> arr;
    int size;
    void update(int ind, int val, int i, int l, int r){
        if(l == r){
            arr[i] = val;
            return;
        }
        int m = (l + r)/2;
        if(ind <= m){
            update(ind, val, 2*i + 1, l, m);
        }
        else update(ind, val, 2*i + 2, m + 1, r);
        arr[i] = min(arr[2*i + 1],arr[2*i + 2]);
    }
    int cal(int l, int r, int i, int lx, int rx){
        if(r < lx || rx < l) return INT_MAX;
        if(l <= lx && rx <= r) return arr[i];
        int m = (lx + rx)/2;
        int left = cal(l, r, 2*i + 1, lx, m);
        int right = cal(l, r, 2*i + 2, m + 1, rx);
        return min(left, right);
    }
public:
    segtree(int n){
        size = 1;
        while(size < n){
            size *= 2;
        }
        arr.assign(2*size, 0);
    }

    void update(int ind, int val){
        update(ind, val, 0, 0, size - 1);
        // for(int i = 0; i < 2*size; i++) cout << arr[i] << " ";
        // cout << endl;
    }

    int cal(int l, int r){
        return cal(l, r, 0, 0, size - 1);
    }
};
