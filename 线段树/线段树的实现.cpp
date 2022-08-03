

#include <iostream>
#include <cstdio>
#include <cmath>
#include <cstring>

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
        int pushup(int o) {
            minv[o] = _min(minv[lson], minv[rson]);
            maxv[o] = _max(maxv[lson], maxv[rson]);
            sumv[o] = sumv[lson] + sumv[rson];
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
         * @param o
         * @param l
         * @param r
         * @return
         */
        int Build(int o, int l, int r) {
            addv[o] = 0;
            if (l == r) {
                maxv[o] = arr[l];
                minv[o] = arr[l];
                sumv[o] = arr[l];
                return 0;
            }
            Build(lson, l, mid);
            Build(rson, mid + 1, r);
            pushup(o);
            return 0;
        }

    public :
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