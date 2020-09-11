# LeetCode 39 组合总和  

## 题目描述  

```
给定一个无重复元素的数组 candidates 和一个目标数 target ，找出 candidates 中所有可以使数字和为 target 的组合。

candidates 中的数字可以无限制重复被选取。

说明：

所有数字（包括 target）都是正整数。
解集不能包含重复的组合。 
示例 1：

输入：candidates = [2,3,6,7], target = 7,
所求解集为：
[
  [7],
  [2,2,3]
]
示例 2：

输入：candidates = [2,3,5], target = 8,
所求解集为：
[
  [2,2,2,2],
  [2,3,3],
  [3,5]
]

来源：力扣（LeetCode）
链接：https://leetcode-cn.com/problems/combination-sum
著作权归领扣网络所有。商业转载请联系官方授权，非商业转载请注明出处。
```    

## 题解  

难度：中等  

从给定范围内寻求所有可行解，可以使用**搜索回溯**来解决。  

题中已说明`candidates`中的元素可以无限制重复使用，那么最直观的方法就是直接`for`循环遍历一遍，看能不能找到两个元素构成`target`，不行的话再来一遍，看能不能找的三个元素构成`target`，直到执行了`candidates.size()`个`for`循环。这时候，**递归可以解决这样的多层for循环**。  

伪代码如下：  

``` c++
dfs ()
{
  if target == 0
  {
    保存结果；
    返回；
  }
  for(auto num : candidates)
  {
    元素存入缓存
    dfs()
    弹出缓存中最后一个元素，继续
  }
}
```


---

> 声明：本作品采用[署名-非商业性使用-相同方式共享 4.0 国际 (CC BY-NC-SA 4.0)](https://creativecommons.org/licenses/by-nc-sa/4.0/deed.zh)进行许可，使用时请注明出处。  

---