

#include <iostream>
#include <cstdio>
#include <cmath>
#include <cstring>

#define or ||
#define and &&

using namespace std;

namespace SegTree {
#define maxn 1000000

    class SegmentTree {

#define lson (o<<1)     // 左孩
#define rson (o<<1|1)   // 右孩
#define mid ((l+r)>>1)  // 中间值

    public :
        int addv[maxn], maxv[maxn], minv[maxn], sumv[maxn];
        int arr[maxn];
        int N;

    private:
        int _max(const int &a, const int &b) { return a > b ? a : b; }

    private:
        int _min(const int &a, const int &b) { return a < b ? a : b; }

    public :
        /**
         *
         * @param o 区间的编号
         * @return
         */
        int pushup(int o) {
            // lson 和 rson 都是根据 o 计算的堆上左子节点和右子节点
            // 感觉 minv, maxv 和 sumv 相当于三个指标, 比如区间求和, 求最大最小会用到
            // 这样感觉就好理解了
            minv[o] = _min(minv[lson], minv[rson]); // 计算区间最大值
            maxv[o] = _max(maxv[lson], maxv[rson]); // 计算区间最小值
            sumv[o] = sumv[lson] + sumv[rson];             // 计算区间之和
            return 0;
        }

    public :
        int pushdown(int o, int l, int r) {

            if (addv[o] == 0) return -1;

            addv[lson] += addv[o];
            addv[rson] += addv[o];
            minv[lson] += addv[o];
            minv[rson] += addv[o];
            maxv[lson] += addv[o];
            maxv[rson] += addv[o];
            sumv[lson] += addv[o] * (mid - l + 1);
            sumv[rson] += addv[o] * (r - mid);
            addv[o] = 0;

            return 0;
        }

    public :
        /**
         *
         * @param o 完全二叉堆的节点位置, 0 是根节点
         * @param l 区间的左边序号
         * @param r 区间的右边序号
         * @return
         */
        int Build(int o, int l, int r) {
            addv[o] = 0;            // 懒更新?
            if (l == r) {           // l 等于 r 说明这个区间只剩一个点了
                maxv[o] = arr[l];
                minv[o] = arr[l];
                sumv[o] = arr[l];
                return 0;
            }

            // mid 是 l 和 r 的中间值，相当于把区间二分了
            Build(lson, l, mid);        // 区间的左半部分
            Build(rson, mid + 1, r);    // 区间的右半部分
            pushup(o);                         // 将结果(指标)上推到父节点
            return 0;
        }

    public :

        /**
         *
         * @param o 节点索引, 相当于指针了
         * @param l 节点对应的区间的左边起始位置
         * @param r 节点对应的区间的右边结束位置
         * @param ql 查询区间的左边起始
         * @param qr 查询区间的右边起始
         * @param addval 给 [ql, qr] 区间增加的值
         * @return
         */
        int optadd(int o, int l, int r, int ql, int qr, int addval) {
            if (ql > r or qr < l) return 0;
            if (ql <= l and r <= qr) {
                addv[o] += addval;
                sumv[o] += addval * (r - l + 1);
                return 0;
            }
            pushdown(o, l, r);
            optadd(lson, l, mid, ql, qr, addval);
            optadd(rson, mid + 1, r, ql, qr, addval);
            pushup(o);

            return 0;
        }

    public :
        /**
         * 查询区间的和
         * @param o 节点的序号，相当于树节点的指针
         * @param l
         * @param r
         * @param ql
         * @param qr
         * @return
         */
        int query_sum(int o, int l, int r, int ql, int qr) {
            if (ql > r or qr < l) return 0;
            if (ql <= l and r <= qr) {
                return sumv[o];
            }
            pushdown(o, l, r);
            return query_sum(lson, l, mid, ql, qr) +
                   query_sum(rson, mid + 1, r, ql, qr);
        }

    public :
        /**
         * 查询区间的最小值
         * @param o
         * @param l
         * @param r
         * @param ql
         * @param qr
         * @return
         */
        int query_min(int o, int l, int r, int ql, int qr) {
            if (ql > r or qr < l) return 0;
            if (ql <= l and r <= qr) {
                return minv[o];
            }
            pushdown(o, l, r);
            return _min(query_min(lson, l, mid, ql, qr),
                        query_min(rson, mid + 1, r, ql, qr));
        }

    public :
        /**
         * 查询区间的最大值
         * @param o
         * @param l
         * @param r
         * @param ql
         * @param qr
         * @return
         */
        int query_max(int o, int l, int r, int ql, int qr) {
            if (ql > r or qr < l) return 0;
            if (ql <= l and r <= qr) {
                return maxv[o];
            }
            pushdown(o, l, r);
            return _max(query_max(lson, l, mid, ql, qr),
                        query_max(rson, mid + 1, r, ql, qr));
        }
    };
}
//End of SegmentTree
using namespace SegTree;

int main() {
    cout << "hello, world" << endl;
    return 0;
}