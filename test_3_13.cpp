//构造函数+static成员变量
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
        //Sum arr[n]; //c99支持, 变长数组
        Sum *p = new Sum[n]; //创建n次这个类的对象，也就是变相做了加法。
        return Sum::GetRet();
    }
};
