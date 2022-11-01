class Solution {
public:
    vector<int> dailyTemperatures(vector<int>& temperatures) {
        //单调栈
        stack<int> st;//
        vector<int> next(temperatures.size(),0);//保存天数  //默认 全是 没有  后续大于该元素的  所以下标0
        for(int i = 0;i<temperatures.size();i++)
        {
            while((!st.empty())&&temperatures[st.top()]<temperatures[i])
            {
                //说明找到啦   那么 i 指向 那个 大于 他的  元素 
                int k = st.top();
                st.pop();//拿出来处理
                next[k] = (i - k);      //当成数组来用 next[k] 直接赋值 天数 i - k i 指向 那个 大于 他的  元素  k为该元素

            }
            st.push(i);
        }
        //储存在栈里面的就是后面没有大于他的

        
        return next;
    }
};