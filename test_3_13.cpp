//���캯��+static��Ա����
class Sum
{
    friend class Solution;
public:
    Sum()
    {
        _ret += _i;
        ++_i;
    }
    static int GetRet()
    {
        return _ret;
    }
private:
    static int _i;
    static int _ret;
};
int Sum::_i = 1;
int Sum::_ret = 0;
class Solution {
public:
    int Sum_Solution(int n) {
        Sum::_i = 1;
        Sum::_ret = 0;
        //Sum arr[n]; //c99֧��, �䳤����
        Sum *p = new Sum[n]; //����n�������Ķ���Ҳ���Ǳ������˼ӷ���
        return Sum::GetRet();
    }
};
