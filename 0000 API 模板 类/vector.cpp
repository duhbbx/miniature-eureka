#include <algorithm>
����� sort ������, ����д comp �������
������д������������пӵ�, �ȽϺ�������ö���Ҫ�õ��ں�
// ����ȽϺ���
bool compare(int a, int b) {
    // ��������, �����Ϊ return a>b, ��Ϊ����
    return a < b;
}

// ����
sort(a, a + 20, compare);