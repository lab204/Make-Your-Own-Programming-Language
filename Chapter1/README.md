语法分析
===================

## 基本语法如下：

```
基本数据类型
* 整型 （1，4，5，6，666）
* 实数型 （1.0， 99999999.)
* 字符串 ( "hello", 'hello')
* 布尔型 (true, false)

基本结构

print("hello world")

a = 3
b = 4

if(a > b) {
  print("hello world")
}

函数最后的表达式的值即为返回值
function hello() {
  5
}

闭包
function world() {
  function() {
    print("hello world")
  }
}

a = world()
a()

```