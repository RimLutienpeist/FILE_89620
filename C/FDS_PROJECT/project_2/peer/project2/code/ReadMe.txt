看到这个代码的同学 
    你好，这个题目确实非常的难 我利用相应的操作 但是整体并没有做到完完全全的自动求导 因为很多的复杂的化简以我的能力没办法进行 我这个也没有写bonus的部分 所以你测试的时候 不能输入那些数学函数 并且如果你使用次方测试的话 次方上面的那个内容也不能太复杂  但是我按照老师给出的三个例子来做 都是可以成功的 并且在另一个方面 化简的层面 题目只要求有两条自己的化简方式 我没有写合并同类项的部分 我只是写了化简+0 0+ 1* *1 *0 0*这几个部分的内容 这就是我的化简 所以你测试的时候 如果发现并没有合并同类项 这是正常的.
    你编译 然后执行之后输入表达式就行了 注意表达式之中不要有空格 不然scanf就会漏读
    一些理想的测试数据供你进行测试（直接复制表达式就行）：
      输入：
	a+b^c*d
	结果：
	a:1
	b:c*b^(c-1)*d
	c:b^c*ln(b)*d
	d:b^c
	
    输入：a*10*b+2^a/a
	结果：
	a:10*b+(2^a*ln(2)*a/a^2)-(2^a/a^2)
	b:a*10

    输入：xx^2/xy*xy+a^a
	结果：
	xx:(2*xx^(2-1)*xy/xy^2))*xy
	xy:-(xx^2/xy^2)*xy+xx^2/xy
	a:a^a*(1+ln(a))

    希望你能提出宝贵的意见 谢谢你的观看


	Hello, this problem is really very difficult, I use the corresponding operation, but the whole is not completely automatic, because a lot of complex simplification is not possible with my ability, I don't write the bonus part, so when you test, you can't enter those mathematical functions, and if you use the power test, the content above the power can't be too complicated, but I follow the three examples given by the teacher, all of them can be successful, and in another way, the level of simplification The question only requires two ways to simplify the same kind of items I didn't write the part that merged the same kind of items, I just wrote the content of the parts of simplification +0 0+ 1* *1 *0 0* This is my simplification, so when you test it, if you find that you don't merge the same kind of items, that's normal 
	I hope you can give your valuable comments Thank you for watching