// 模板来源 https://leetcode.cn/circle/discuss/mOr1u6/
template<typename T, typename F>
class LazySegmentTree {
    // 注：也可以去掉 template<typename T, typename F>，改在这里定义 T 和 F
    // using T = pair<int, int>;
    // using F = pair<int, int>;

    // 懒标记初始值
    const F TODO_INIT = 0; // **根据题目修改**

    struct Node {
        // 当前区间的值是 val
        T val;
        // 当前区间每个元素待更新的值是 todo
        F todo;
    };

    int n;
    vector<Node> tree;

    // 合并两个 val
    T merge_val(const T& a, const T& b) const {
        return a + b; // **根据题目修改**
    }

    // 合并两个懒标记
    F merge_todo(const F& a, const F& b) const {
        return a + b; // **根据题目修改**
    }

    // 把懒标记作用到 node 子树（本例为区间加）
    void apply(int node, int l, int r, F todo) {
        Node& cur = tree[node];
        // 计算 tree[node] 区间的整体变化
        cur.val += todo * (r - l + 1); // **根据题目修改**
        cur.todo = merge_todo(todo, cur.todo);
    }

    // 把当前节点的懒标记下传给左右儿子
    void spread(int node, int l, int r) {
        Node& cur = tree[node];
        F todo = cur.todo;
        if (todo == TODO_INIT) { // 没有需要下传的信息
            return;
        }
        int m = (l + r) / 2;
        apply(node * 2, l, m, todo);
        apply(node * 2 + 1, m + 1, r, todo);
        cur.todo = TODO_INIT; // 下传完毕
    }

    // 合并左右儿子的 val 到当前节点的 val
    void maintain(int node) {
        tree[node].val = merge_val(tree[node * 2].val, tree[node * 2 + 1].val);
    }

    // 用 a 初始化线段树
    // 时间复杂度 O(n)
    void build(const vector<T>& a, int node, int l, int r) {
        Node& cur = tree[node];
        cur.todo = TODO_INIT;
        if (l == r) { // 叶子
            cur.val = a[l]; // 初始化叶节点的值
            return;
        }
        int m = (l + r) / 2;
        build(a, node * 2, l, m); // 初始化左子树
        build(a, node * 2 + 1, m + 1, r); // 初始化右子树
        maintain(node);
    }

    void update(int node, int l, int r, int ql, int qr, F f) {
        if (ql <= l && r <= qr) { // 当前子树完全在 [ql, qr] 内
            apply(node, l, r, f);
            return;
        }
        spread(node, l, r);
        int m = (l + r) / 2;
        if (ql <= m) { // 更新左子树
            update(node * 2, l, m, ql, qr, f);
        }
        if (qr > m) { // 更新右子树
            update(node * 2 + 1, m + 1, r, ql, qr, f);
        }
        maintain(node);
    }

    T query(int node, int l, int r, int ql, int qr) {
        if (ql <= l && r <= qr) { // 当前子树完全在 [ql, qr] 内
            return tree[node].val;
        }
        spread(node, l, r);
        int m = (l + r) / 2;
        if (qr <= m) { // [ql, qr] 在左子树
            return query(node * 2, l, m, ql, qr);
        }
        if (ql > m) { // [ql, qr] 在右子树
            return query(node * 2 + 1, m + 1, r, ql, qr);
        }
        T l_res = query(node * 2, l, m, ql, qr);
        T r_res = query(node * 2 + 1, m + 1, r, ql, qr);
        return merge_val(l_res, r_res);
    }

public:
    // 线段树维护一个长为 n 的数组（下标从 0 到 n-1），元素初始值为 init_val
    LazySegmentTree(int n, T init_val = 0) : LazySegmentTree(vector<T>(n, init_val)) {}

    // 线段树维护数组 a
    LazySegmentTree(const vector<T>& a) : n(a.size()), tree(2 << bit_width(a.size() - 1)) {
        build(a, 1, 0, n - 1);
    }

    // 用 f 更新 [ql, qr] 中的每个 a[i]
    // 0 <= ql <= qr <= n-1
    // 时间复杂度 O(log n)
    void update(int ql, int qr, F f) {
        update(1, 0, n - 1, ql, qr, f);
    }

    // 返回用 merge_val 合并所有 a[i] 的计算结果，其中 i 在闭区间 [ql, qr] 中
    // 0 <= ql <= qr <= n-1
    // 时间复杂度 O(log n)
    T query(int ql, int qr) {
        return query(1, 0, n - 1, ql, qr);
    }
};

int main() {
    LazySegmentTree<long long, long long> t(8); // 默认值为 0
    t.update(3, 5, 100);
    t.update(4, 6, 10);
    cout << t.query(0, 7) << endl;

    vector<long long> nums = {3, 1, 4, 1, 5, 9, 2, 6};
    LazySegmentTree<long long, long long> t2(nums);
    t2.update(3, 5, 1);
    t2.update(4, 6, 1);
    cout << t2.query(0, 7) << endl;
    return 0;
}


// oi-wiki version

// [l, r] 为修改区间, c 为被修改的元素的变化量, [s, t] 为当前节点包含的区间, p
// 为当前节点的编号
void update(int l, int r, int c, int s, int t, int p) {
  // 当前区间为修改区间的子集时直接修改当前节点的值,然后打标记,结束修改
  if (l <= s && t <= r) {
    d[p] += (t - s + 1) * c, b[p] += c;
    return;
  }
  int m = s + ((t - s) >> 1);
  if (b[p] && s != t) {
    // 如果当前节点的懒标记非空,则更新当前节点两个子节点的值和懒标记值
    d[p * 2] += b[p] * (m - s + 1), d[p * 2 + 1] += b[p] * (t - m);
    b[p * 2] += b[p], b[p * 2 + 1] += b[p];  // 将标记下传给子节点
    b[p] = 0;                                // 清空当前节点的标记
  }
  if (l <= m) update(l, r, c, s, m, p * 2);
  if (r > m) update(l, r, c, m + 1, t, p * 2 + 1);
  d[p] = d[p * 2] + d[p * 2 + 1];
}



class SegmentTree {
private:
    vector<int> tree;  // 线段树数组
    vector<int> lazy;  // 懒标记数组
    
    // 下传懒标记
    void pushDown(int node, int l, int r) {
        if (lazy[node] != 0) {  // 如果有标记
            int mid = (l + r) / 2;
            
            // 1. 更新左子节点的值
            tree[2*node+1] += lazy[node] * (mid - l + 1);
            lazy[2*node+1] += lazy[node];  // 标记继续传递
            
            // 2. 更新右子节点的值
            tree[2*node+2] += lazy[node] * (r - mid);
            lazy[2*node+2] += lazy[node];
            
            // 3. 清除当前节点的标记
            lazy[node] = 0;
        }
    }
    
public:
    // 区间更新
    void updateRange(int node, int l, int r, int ql, int qr, int val) {
        if (ql > r || qr < l) return;  // 不重叠
        
        if (ql <= l && r <= qr) {  // 完全包含
            // 只更新当前节点，不打扰子节点
            tree[node] += val * (r - l + 1);
            lazy[node] += val;  // 标记一下，子节点还没更新
            return;
        }
        
        // 部分重叠，需要下传标记后才能继续递归
        pushDown(node, l, r);
        
        int mid = (l + r) / 2;
        updateRange(2*node+1, l, mid, ql, qr, val);
        updateRange(2*node+2, mid+1, r, ql, qr, val);
        
        // 更新父节点
        tree[node] = tree[2*node+1] + tree[2*node+2];
    }
    
    // 区间查询
    int query(int node, int l, int r, int ql, int qr) {
        if (ql > r || qr < l) return 0;
        
        if (ql <= l && r <= qr) {
            return tree[node];  // 直接返回当前节点值
        }
        
        // 关键：查询前先下传标记
        pushDown(node, l, r);
        
        int mid = (l + r) / 2;
        int leftSum = query(2*node+1, l, mid, ql, qr);
        int rightSum = query(2*node+2, mid+1, r, ql, qr);
        
        return leftSum + rightSum;
    }
};


// lazy update funciton
inline void f(ll p,ll l,ll r,ll k){
   tag[p]=tag[p]+k;
   ans[p]=ans[p]+k*(r-l+1);
   //由于是这个区间统一改变，所以ans数组要加元素个数次啦 
}
//我们可以认识到，f函数的唯一目的，就是记录当前节点所代表的区间 

// push_down the lazy tag
inline void push_down(ll p,ll l,ll r){
   ll mid=(l+r)>>1;
   f(ls(p),l,mid,tag[p]);
   f(rs(p),mid+1,r,tag[p]);
   tag[p]=0;
   //每次更新两个儿子节点。以此不断向下传递 
}

// 本质上不是拆掉要更新的区间 , 其是总体的区间早都被拆分好了 , 只是找合适的块拼出要更新的区间
inline void update(ll nl,ll nr,ll l,ll r,ll p,ll k) {
   //nl,nr为要修改的区间
    //l,r,p为当前节点所存储的区间以及节点的编号 
    //这里区间被完全包裹的时候没有被记录直接更新了

    // 如果要更新的范围包裹了现在这个范围
   if(nl<=l&&r<=nr)
   {
   	ans[p]+=k*(r-l+1);
   	tag[p]+=k;
   	return ;
   }
   push_down(p,l,r);
   //回溯之前（也可以说是下一次递归之前，因为没有递归就没有回溯） 
   //由于是在回溯之前不断向下传递，所以自然每个节点都可以更新到 
   ll mid=(l+r)>>1;
   if(nl<=mid)update(nl,nr,l,mid,ls(p),k);
   if(nr>mid) update(nl,nr,mid+1,r,rs(p),k);
   push_up(p);
   //回溯之后 
}

ll query(ll q_x,ll q_y,ll l,ll r,ll p)
{
	ll res=0;
	if(q_x<=l&&r<=q_y)return ans[p];
	ll mid=(l+r)>>1;
	push_down(p,l,r);
	if(q_x<=mid)res+=query(q_x,q_y,l,mid,ls(p));
	if(q_y>mid) res+=query(q_x,q_y,mid+1,r,rs(p));
	return res;
}
