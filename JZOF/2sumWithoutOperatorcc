class Solution {
public:
    int Add(int num1, int num2)
    {
        while(num2 != 0){ //没有进位的时候可以停止迭代
            int temp = num1 ^ num2; //不考虑进位的加法
            num2 = (num1 & num2) << 1; //进位值储存在num2中
            num1 = temp;//将不考虑进位的加法储存在num1中，下次再次计算num1+num2
        }
        return num1;
    }
};
